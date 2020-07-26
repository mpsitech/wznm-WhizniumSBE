/**
	* \file WznmopdEngsrv.cpp
	* engine server for Wznm operation daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "Wznmopd.h"

#include "WznmopdEngsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmopdEngsrv
 ******************************************************************************/

MHD_Daemon* WznmopdEngsrv::start(
			XchgWznmopd* xchg
		) {
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwznmopd.engsrvportbase + xchg->stgwznmopd.engsrvportofs, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void WznmopdEngsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int WznmopdEngsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int WznmopdEngsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWznmopd* xchg = (XchgWznmopd*) cls;

	MHD_Response* response;
	int retval = MHD_YES;

	ReqopWznm* req = NULL;

	ReqopWznm* prcreq = NULL;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string scrOref;

	uint ixWznmVDpch;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s;

	if (*con_cls == NULL) {
		// new request
		addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

		if (addr->sa_family == AF_INET) {
#ifdef _WIN32
			ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
			inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
			ip = ipstr;
#endif
		};

		// only allow requests from engine
		if (ip == xchg->stgwznmopd.engip) {
			s = string(url);

			if (strcmp(method, "GET") == 0) {
				if (s.find("/poll") != string::npos) {
					// always "/poll/abcd1234efgh5678"
					req = new ReqopWznm(ReqopWznm::VecVBasetype::POLL, ReqopWznm::VecVState::RECEIVE);
					*con_cls = req;

					scrOref = s.substr(s.find("/poll/")+6);
				};

			} else if (strcmp(method, "POST") == 0) {
				if (s.find("/dpch") != string::npos) {
					// always "/dpch"
					req = new ReqopWznm(ReqopWznm::VecVBasetype::DPCHINV, ReqopWznm::VecVState::RECEIVE);
					*con_cls = req;

					// prepare POST processor
					req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);
					retval = MHD_YES;
				};
			};
		};

		if (req == NULL) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			if (req->ixVBasetype == ReqopWznm::VecVBasetype::POLL) {
				// send return dispatch or progress update
				prcreq = xchg->getPrcreqByScrOref(scrOref);
				
				if (prcreq) {
					if (prcreq->ixVState == ReqopWznm::VecVState::REPLY) {
						xchg->pullPrcreq(scrOref);
						delete req;

						req = prcreq;
						*con_cls = req;

					} else {
						req->dpchret = new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, prcreq->dpchinv->scrOref, prcreq->dpchinv->scrJref, VecOpVOpres::PROGRESS, prcreq->pdone);
					};
					prcreq->cReady.unlockMutex("WznmopdEngsrv", "MhdCallback");

				} else {
					req->dpchret = new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, scrOref, "", VecOpVOpres::PROGRESS, 0);
				};

				if (req->dpchret) {
					writeDpchRet(req);
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				} else {
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active request (GET: should not go through here ; POST: DPCHINV)
		req = (ReqopWznm*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

				retval = MHD_YES;

			} else {
				// POST done
				// cout << "MhdCallback() request complete" << endl;

				if (req->request) {
					//cout << string(req->request, req->requestlen) << endl;
					ixWznmVDpch = readDpchInv(req);

					if (ixWznmVDpch == VecWznmVDpch::DPCHWZNMDQUIT) {
						writeDpchAck(req);
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

						// notify main thread by signalling termination condition
						xchg->cTerm.signal("WznmopdEngsrv", "MhdCallback");

					} else if (req->dpchinv) {
						// pass to opprc
						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WznmopdEngsrv", "MhdCallback");
						if (req->ixVState != ReqopWznm::VecVState::REPLY) req->cReady.timedwait(5000000, "WznmopdEngsrv", "MhdCallback");

						if (req->ixVState == ReqopWznm::VecVState::REPLY) {
							xchg->pullPrcreq(req->dpchinv->scrOref);

							req->cReady.unlockMutex("WznmopdEngsrv", "MhdCallback");

						} else {
							prcreq = req;

							req = new ReqopWznm(ReqopWznm::VecVBasetype::POLL, ReqopWznm::VecVState::REPLY);
							*con_cls = req;

							req->dpchret = new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, prcreq->dpchinv->scrOref, prcreq->dpchinv->scrJref, VecOpVOpres::PROGRESS, prcreq->pdone);

							prcreq->cReady.unlockMutex("WznmopdEngsrv", "MhdCallback");
						};

						if (req->dpchret) {
							writeDpchRet(req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

				} else {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};
	};

	return retval;
};

int WznmopdEngsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqopWznm* req = (ReqopWznm*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	// copy data into req->request (append if required)
	if (strcmp(key, "xml") != 0) return MHD_NO;

	if (size > 0) {
		if (!req->request) {
			req->request = new char[size];
			memcpy(req->request, data, size);
			req->requestlen = size;

		} else {
			olddata = req->request;

			req->request = new char[req->requestlen + size];
			memcpy(req->request, olddata, req->requestlen);
			memcpy(&(req->request[req->requestlen]), data, size);
			req->requestlen = req->requestlen + size;

			delete[] olddata;
		};
	};

	return MHD_YES;
};

void WznmopdEngsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqopWznm* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqopWznm*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

uint WznmopdEngsrv::readDpchInv(
			ReqopWznm* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixWznmVDpch = VecWznmVDpch::getIx(extractRoot(doc));

	if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNM) {
		req->dpchinv = new DpchInvWznm();
		((DpchInvWznm*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRWEB) {
		req->dpchinv = new DpchInvWznmCtpWrweb();
		((DpchInvWznmCtpWrweb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSRV) {
		req->dpchinv = new DpchInvWznmCtpWrsrv();
		((DpchInvWznmCtpWrsrv*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSTKIT) {
		req->dpchinv = new DpchInvWznmCtpWrstkit();
		((DpchInvWznmCtpWrstkit*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENUI) {
		req->dpchinv = new DpchInvWznmCtpGenui();
		((DpchInvWznmCtpGenui*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENJTR) {
		req->dpchinv = new DpchInvWznmCtpGenjtr();
		((DpchInvWznmCtpGenjtr*) (req->dpchinv))->readXML(docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWznmVDpch;
};

void WznmopdEngsrv::writeDpchAck(
			ReqopWznm* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		DpchWznmopdAck::writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

void WznmopdEngsrv::writeDpchRet(
			ReqopWznm* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		req->dpchret->writeXML(wr);
	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

