/**
	* \file WznmopdEngsrv.cpp
	* engine server for Wznm operation daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

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

MHD_Result WznmopdEngsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

MHD_Result WznmopdEngsrv::MhdCallback(
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
	MHD_Result retval = MHD_YES;

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

MHD_Result WznmopdEngsrv::MhdPostrecv(
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
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBBASE) {
		req->dpchinv = new DpchInvWznmWrwebBase();
		((DpchInvWznmWrwebBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBCRD) {
		req->dpchinv = new DpchInvWznmWrwebCrd();
		((DpchInvWznmWrwebCrd*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDEPLOY) {
		req->dpchinv = new DpchInvWznmWrwebDeploy();
		((DpchInvWznmWrwebDeploy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDLG) {
		req->dpchinv = new DpchInvWznmWrwebDlg();
		((DpchInvWznmWrwebDlg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBPNL) {
		req->dpchinv = new DpchInvWznmWrwebPnl();
		((DpchInvWznmWrwebPnl*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEBASE) {
		req->dpchinv = new DpchInvWznmWrvueBase();
		((DpchInvWznmWrvueBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUECRD) {
		req->dpchinv = new DpchInvWznmWrvueCrd();
		((DpchInvWznmWrvueCrd*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEDLG) {
		req->dpchinv = new DpchInvWznmWrvueDlg();
		((DpchInvWznmWrvueDlg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVUEPNL) {
		req->dpchinv = new DpchInvWznmWrvuePnl();
		((DpchInvWznmWrvuePnl*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVISDBSTR) {
		req->dpchinv = new DpchInvWznmWrvisDbstr();
		((DpchInvWznmWrvisDbstr*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRVISIMPEXP) {
		req->dpchinv = new DpchInvWznmWrvisImpexp();
		((DpchInvWznmWrvisImpexp*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVBASE) {
		req->dpchinv = new DpchInvWznmWrsrvBase();
		((DpchInvWznmWrsrvBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCMBENGBASE) {
		req->dpchinv = new DpchInvWznmWrsrvCmbengbase();
		((DpchInvWznmWrsrvCmbengbase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCRD) {
		req->dpchinv = new DpchInvWznmWrsrvCrd();
		((DpchInvWznmWrsrvCrd*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDDS) {
		req->dpchinv = new DpchInvWznmWrsrvDds();
		((DpchInvWznmWrsrvDds*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDEPLOY) {
		req->dpchinv = new DpchInvWznmWrsrvDeploy();
		((DpchInvWznmWrsrvDeploy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDLG) {
		req->dpchinv = new DpchInvWznmWrsrvDlg();
		((DpchInvWznmWrsrvDlg*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVENGBASE) {
		req->dpchinv = new DpchInvWznmWrsrvEngbase();
		((DpchInvWznmWrsrvEngbase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVIEX) {
		req->dpchinv = new DpchInvWznmWrsrvIex();
		((DpchInvWznmWrsrvIex*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVINIXML) {
		req->dpchinv = new DpchInvWznmWrsrvInixml();
		((DpchInvWznmWrsrvInixml*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVJOB) {
		req->dpchinv = new DpchInvWznmWrsrvJob();
		((DpchInvWznmWrsrvJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOP) {
		req->dpchinv = new DpchInvWznmWrsrvOp();
		((DpchInvWznmWrsrvOp*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPENGBASE) {
		req->dpchinv = new DpchInvWznmWrsrvOpengbase();
		((DpchInvWznmWrsrvOpengbase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPK) {
		req->dpchinv = new DpchInvWznmWrsrvOpk();
		((DpchInvWznmWrsrvOpk*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPNL) {
		req->dpchinv = new DpchInvWznmWrsrvPnl();
		((DpchInvWznmWrsrvPnl*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPREF) {
		req->dpchinv = new DpchInvWznmWrsrvPref();
		((DpchInvWznmWrsrvPref*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVQRY) {
		req->dpchinv = new DpchInvWznmWrsrvQry();
		((DpchInvWznmWrsrvQry*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVROOTSESS) {
		req->dpchinv = new DpchInvWznmWrsrvRootsess();
		((DpchInvWznmWrsrvRootsess*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVUA) {
		req->dpchinv = new DpchInvWznmWrsrvUa();
		((DpchInvWznmWrsrvUa*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVVEC) {
		req->dpchinv = new DpchInvWznmWrsrvVec();
		((DpchInvWznmWrsrvVec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIBASE) {
		req->dpchinv = new DpchInvWznmWrswapiBase();
		((DpchInvWznmWrswapiBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIJOB) {
		req->dpchinv = new DpchInvWznmWrswapiJob();
		((DpchInvWznmWrswapiJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIQTB) {
		req->dpchinv = new DpchInvWznmWrswapiQtb();
		((DpchInvWznmWrswapiQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSWAPIVEC) {
		req->dpchinv = new DpchInvWznmWrswapiVec();
		((DpchInvWznmWrswapiVec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIBASE) {
		req->dpchinv = new DpchInvWznmWrpyapiBase();
		((DpchInvWznmWrpyapiBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIJOB) {
		req->dpchinv = new DpchInvWznmWrpyapiJob();
		((DpchInvWznmWrpyapiJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIQTB) {
		req->dpchinv = new DpchInvWznmWrpyapiQtb();
		((DpchInvWznmWrpyapiQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRPYAPIVEC) {
		req->dpchinv = new DpchInvWznmWrpyapiVec();
		((DpchInvWznmWrpyapiVec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIBASE) {
		req->dpchinv = new DpchInvWznmWrjapiBase();
		((DpchInvWznmWrjapiBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIJOB) {
		req->dpchinv = new DpchInvWznmWrjapiJob();
		((DpchInvWznmWrjapiJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIQTB) {
		req->dpchinv = new DpchInvWznmWrjapiQtb();
		((DpchInvWznmWrjapiQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIVEC) {
		req->dpchinv = new DpchInvWznmWrjapiVec();
		((DpchInvWznmWrjapiVec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDBS) {
		req->dpchinv = new DpchInvWznmWrdbsDbs();
		((DpchInvWznmWrdbsDbs*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDEPLOY) {
		req->dpchinv = new DpchInvWznmWrdbsDeploy();
		((DpchInvWznmWrdbsDeploy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDIFFSQL) {
		req->dpchinv = new DpchInvWznmWrdbsDiffsql();
		((DpchInvWznmWrdbsDiffsql*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSSQL) {
		req->dpchinv = new DpchInvWznmWrdbsSql();
		((DpchInvWznmWrdbsSql*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSTBL) {
		req->dpchinv = new DpchInvWznmWrdbsTbl();
		((DpchInvWznmWrdbsTbl*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIBASE) {
		req->dpchinv = new DpchInvWznmWrcsapiBase();
		((DpchInvWznmWrcsapiBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIJOB) {
		req->dpchinv = new DpchInvWznmWrcsapiJob();
		((DpchInvWznmWrcsapiJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIQTB) {
		req->dpchinv = new DpchInvWznmWrcsapiQtb();
		((DpchInvWznmWrcsapiQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRCSAPIVEC) {
		req->dpchinv = new DpchInvWznmWrcsapiVec();
		((DpchInvWznmWrcsapiVec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPDOM) {
		req->dpchinv = new DpchInvWznmWrappDom();
		((DpchInvWznmWrappDom*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPMAIN) {
		req->dpchinv = new DpchInvWznmWrappMain();
		((DpchInvWznmWrappMain*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPSTDVEC) {
		req->dpchinv = new DpchInvWznmWrappStdvec();
		((DpchInvWznmWrappStdvec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIBASE) {
		req->dpchinv = new DpchInvWznmWrapiBase();
		((DpchInvWznmWrapiBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIDEPLOY) {
		req->dpchinv = new DpchInvWznmWrapiDeploy();
		((DpchInvWznmWrapiDeploy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIJOB) {
		req->dpchinv = new DpchInvWznmWrapiJob();
		((DpchInvWznmWrapiJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIQTB) {
		req->dpchinv = new DpchInvWznmWrapiQtb();
		((DpchInvWznmWrapiQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT) {
		req->dpchinv = new DpchInvWznmPrctreeExtract();
		((DpchInvWznmPrctreeExtract*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE) {
		req->dpchinv = new DpchInvWznmPrctreeMerge();
		((DpchInvWznmPrctreeMerge*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE) {
		req->dpchinv = new DpchInvWznmPrctreeValidate();
		((DpchInvWznmPrctreeValidate*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT) {
		req->dpchinv = new DpchInvWznmPrcfileConcat();
		((DpchInvWznmPrcfileConcat*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL) {
		req->dpchinv = new DpchInvWznmPrcfilePlhrpl();
		((DpchInvWznmPrcfilePlhrpl*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENBASE) {
		req->dpchinv = new DpchInvWznmGenBase();
		((DpchInvWznmGenBase*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCAL) {
		req->dpchinv = new DpchInvWznmGenCal();
		((DpchInvWznmGenCal*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCHK) {
		req->dpchinv = new DpchInvWznmGenChk();
		((DpchInvWznmGenChk*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENDETUI) {
		req->dpchinv = new DpchInvWznmGenDetui();
		((DpchInvWznmGenDetui*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENJOB) {
		req->dpchinv = new DpchInvWznmGenJob();
		((DpchInvWznmGenJob*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENQTB) {
		req->dpchinv = new DpchInvWznmGenQtb();
		((DpchInvWznmGenQtb*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENSYSVEC) {
		req->dpchinv = new DpchInvWznmGenSysvec();
		((DpchInvWznmGenSysvec*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLVISDBSTR) {
		req->dpchinv = new DpchInvWznmComplvisDbstr();
		((DpchInvWznmComplvisDbstr*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLVISIMPEXP) {
		req->dpchinv = new DpchInvWznmComplvisImpexp();
		((DpchInvWznmComplvisImpexp*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI) {
		req->dpchinv = new DpchInvWznmComplBscui();
		((DpchInvWznmComplBscui*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLCTPCPY) {
		req->dpchinv = new DpchInvWznmComplCtpcpy();
		((DpchInvWznmComplCtpcpy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDBS) {
		req->dpchinv = new DpchInvWznmComplDbs();
		((DpchInvWznmComplDbs*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDEPLOY) {
		req->dpchinv = new DpchInvWznmComplDeploy();
		((DpchInvWznmComplDeploy*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLIEX) {
		req->dpchinv = new DpchInvWznmComplIex();
		((DpchInvWznmComplIex*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLJTR) {
		req->dpchinv = new DpchInvWznmComplJtr();
		((DpchInvWznmComplJtr*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLVISDBSTR) {
		req->dpchinv = new DpchInvWznmComplvisDbstr();
		((DpchInvWznmComplvisDbstr*) (req->dpchinv))->readXML(docctx, "/", true);
	} else if (ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLVISIMPEXP) {
		req->dpchinv = new DpchInvWznmComplvisImpexp();
		((DpchInvWznmComplvisImpexp*) (req->dpchinv))->readXML(docctx, "/", true);
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
