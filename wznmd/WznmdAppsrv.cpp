/**
	* \file WznmdAppsrv.cpp
	* application server for Wznm daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "Wznmd.h"

#include "WznmdAppsrv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmdAppsrv
 ******************************************************************************/

MHD_Daemon* WznmdAppsrv::start(
			XchgWznmd* xchg
		) {
	if (xchg->stgwznmappsrv.https) {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL | MHD_USE_SSL, xchg->stgwznmappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_HTTPS_MEM_KEY, xchg->key.c_str(), MHD_OPTION_HTTPS_MEM_CERT, xchg->cert.c_str(), MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	} else {
		return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION | MHD_USE_POLL, xchg->stgwznmappsrv.port, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
	};
};

void WznmdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int WznmdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int WznmdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgWznm* xchg = (XchgWznm*) cls;

	MHD_Response* response;
	int retval = MHD_YES;

	ReqWznm* req;
	uint ixVBasetype = ReqWznm::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	uint ixWznmVDpch;

	ubigint jrefNotify;

	DcolWznm* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s == "/") {
				ixVBasetype = ReqWznm::VecVBasetype::REDIRECT;

			} else if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/web/CrdWznmNav/CrdWznmNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgwznmpath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqWznm::VecVBasetype::WEB;
						// cout << "MhdCallback() WEB request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678"
				ixVBasetype = ReqWznm::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678"
				ixVBasetype = ReqWznm::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678"
				ixVBasetype = ReqWznm::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqWznm::VecVBasetype::DPCHAPP;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqWznm::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqWznm::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else if (ixVBasetype == ReqWznm::VecVBasetype::REDIRECT) {
			response = MHD_create_response_from_buffer(0, NULL, MHD_RESPMEM_PERSISTENT);
			MHD_add_response_header(response, "Location", "/web/CrdWznmStart/CrdWznmStart.html");
			retval = MHD_queue_response(connection, MHD_HTTP_MOVED_PERMANENTLY, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqWznm(ixVBasetype, ReqWznm::VecVState::RECEIVE, ip);
			*con_cls = req;

			if (req->ixVBasetype == ReqWznm::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgwznmpath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecWznmVMimetype::getTitle(VecWznmVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecWznmVMimetype::getTitle(VecWznmVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					jrefNotify = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFNOTIFY, req->jref);

					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) {
						dcol = xchg->addDcol(req->jref);
						if (dcol) jrefNotify = req->jref;
					};

					valid = dcol;
				};

				if (valid) {
					req->ixWznmVLocale = dcol->ixWznmVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngWznmAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("WznmdAppsrv", "MhdCallback[1]");

						} else if (jrefNotify != dcol->jref) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngWznmSuspend(req->jref);

							dcol->unlockAccess("WznmdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngWznmAck(req->jref);
							dcol->req = req;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							req->cReady.lockMutex("WznmdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("WznmdAppsrv", "MhdCallback[3]");
							req->cReady.timedwait(15000000, "WznmdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							req->cReady.unlockMutex("WznmdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("WznmdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngWznmConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqWznm::VecVState::REPLY;

						// send reply ; note that the result of timedwait() doesn't matter
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("WznmdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqWznm::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixWznmVLocale = dcol->ixWznmVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngWznmAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("WznmdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqWznm::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgwznmpath.tmppath + "/" + Tmp::newfile(xchg->stgwznmpath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req);

					xchg->addReq(req);

					// wait for reply
					req->cReady.lockMutex("WznmdAppsrv", "MhdCallback[2]");
					if (req->ixVState != ReqWznm::VecVState::REPLY) req->cReady.wait("WznmdAppsrv", "MhdCallback[1]");
					req->cReady.unlockMutex("WznmdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: DPCHAPP, UPLOAD)
		req = (ReqWznm*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() DPCHAPP request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << string(req->request, req->requestlen) << endl;
						ixWznmVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixWznmVDpch == VecWznmVDpch::DPCHAPPROOTWZNMLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply
						req->cReady.lockMutex("WznmdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqWznm::VecVState::REPLY) req->cReady.wait("WznmdAppsrv", "MhdCallback[2]");
						req->cReady.unlockMutex("WznmdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req);

						xchg->addReq(req);

						// wait for reply (usually empty)
						req->cReady.lockMutex("WznmdAppsrv", "MhdCallback[4]");
						if (req->ixVState != ReqWznm::VecVState::REPLY) req->cReady.wait("WznmdAppsrv", "MhdCallback[3]");
						req->cReady.unlockMutex("WznmdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_buffer(req->replylen, req->reply, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_buffer(strlen(empty), empty, MHD_RESPMEM_PERSISTENT);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_buffer(strlen(invalid), invalid, MHD_RESPMEM_PERSISTENT);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int WznmdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t WznmdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqWznm* req = (ReqWznm*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int WznmdAppsrv::MhdPostrecv(
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
	ReqWznm* req = (ReqWznm*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		// --- copy data into req->request (append if required)
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

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void WznmdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqWznm* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqWznm*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool WznmdAppsrv::validateIp(
			XchgWznmd* xchg
			, ReqWznm* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		if (xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMSUSPSESS, req->jref))
					if (req->jref != xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFSESS, req->jref)) retval = false;

		if (retval) {
			ip = xchg->getTxtvalPreset(VecWznmVPreset::PREWZNMIP, req->jref);
			if (ip != req->ip) retval = false;
		};
	};

	return retval;
};

bool WznmdAppsrv::validateJrefNotify(
			XchgWznmd* xchg
			, ReqWznm* req
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolWznm* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecWznmVPreset::PREWZNMJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval) xchg->triggerIxRefCall(NULL, VecWznmVCall::CALLWZNMREFPRESET, dcol->jref, VecWznmVPreset::PREWZNMJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("WznmdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint WznmdAppsrv::readDpchApp(
			XchgWznmd* xchg
			, ReqWznm* req
		) {
	uint ixWznmVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(req->request, req->requestlen, &doc, &docctx);

		ixWznmVDpch = VecWznmVDpch::getIx(extractRoot(doc));

		if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPIMPSTRDATA) {
			req->dpchapp = new DlgWznmAppImpstr::DpchAppData();
			((DlgWznmAppImpstr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPIMPSTRDO) {
			req->dpchapp = new DlgWznmAppImpstr::DpchAppDo();
			((DlgWznmAppImpstr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDATA) {
			req->dpchapp = new DlgWznmAppNew::DpchAppData();
			((DlgWznmAppNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPNEWDO) {
			req->dpchapp = new DlgWznmAppNew::DpchAppDo();
			((DlgWznmAppNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPWRITEDATA) {
			req->dpchapp = new DlgWznmAppWrite::DpchAppData();
			((DlgWznmAppWrite::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMAPPWRITEDO) {
			req->dpchapp = new DlgWznmAppWrite::DpchAppDo();
			((DlgWznmAppWrite::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMFILDOWNLOADDO) {
			req->dpchapp = new DlgWznmFilDownload::DpchAppDo();
			((DlgWznmFilDownload::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDATA) {
			req->dpchapp = new DlgWznmFilNew::DpchAppData();
			((DlgWznmFilNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMFILNEWDO) {
			req->dpchapp = new DlgWznmFilNew::DpchAppDo();
			((DlgWznmFilNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVLOAINIDATA) {
			req->dpchapp = new DlgWznmNavLoaini::DpchAppData();
			((DlgWznmNavLoaini::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVLOAINIDO) {
			req->dpchapp = new DlgWznmNavLoaini::DpchAppDo();
			((DlgWznmNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDATA) {
			req->dpchapp = new DlgWznmNavMnglic::DpchAppData();
			((DlgWznmNavMnglic::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMNAVMNGLICDO) {
			req->dpchapp = new DlgWznmNavMnglic::DpchAppDo();
			((DlgWznmNavMnglic::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJIMPEXDATA) {
			req->dpchapp = new DlgWznmPrjImpex::DpchAppData();
			((DlgWznmPrjImpex::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJIMPEXDO) {
			req->dpchapp = new DlgWznmPrjImpex::DpchAppDo();
			((DlgWznmPrjImpex::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDATA) {
			req->dpchapp = new DlgWznmPrjNew::DpchAppData();
			((DlgWznmPrjNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMPRJNEWDO) {
			req->dpchapp = new DlgWznmPrjNew::DpchAppDo();
			((DlgWznmPrjNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDATA) {
			req->dpchapp = new DlgWznmRlsFinreptr::DpchAppData();
			((DlgWznmRlsFinreptr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSFINREPTRDO) {
			req->dpchapp = new DlgWznmRlsFinreptr::DpchAppDo();
			((DlgWznmRlsFinreptr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDATA) {
			req->dpchapp = new DlgWznmRlsStareptr::DpchAppData();
			((DlgWznmRlsStareptr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSSTAREPTRDO) {
			req->dpchapp = new DlgWznmRlsStareptr::DpchAppDo();
			((DlgWznmRlsStareptr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDATA) {
			req->dpchapp = new DlgWznmRlsWrite::DpchAppData();
			((DlgWznmRlsWrite::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMRLSWRITEDO) {
			req->dpchapp = new DlgWznmRlsWrite::DpchAppDo();
			((DlgWznmRlsWrite::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUSRMNGKEYPAIRDO) {
			req->dpchapp = new DlgWznmUsrMngkeypair::DpchAppDo();
			((DlgWznmUsrMngkeypair::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLEXTRIPDATA) {
			req->dpchapp = new DlgWznmUtlExtrip::DpchAppData();
			((DlgWznmUtlExtrip::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLEXTRIPDO) {
			req->dpchapp = new DlgWznmUtlExtrip::DpchAppDo();
			((DlgWznmUtlExtrip::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDATA) {
			req->dpchapp = new DlgWznmUtlIexconv::DpchAppData();
			((DlgWznmUtlIexconv::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLIEXCONVDO) {
			req->dpchapp = new DlgWznmUtlIexconv::DpchAppDo();
			((DlgWznmUtlIexconv::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDATA) {
			req->dpchapp = new DlgWznmUtlMrgip::DpchAppData();
			((DlgWznmUtlMrgip::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMUTLMRGIPDO) {
			req->dpchapp = new DlgWznmUtlMrgip::DpchAppDo();
			((DlgWznmUtlMrgip::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERBSCUIDATA) {
			req->dpchapp = new DlgWznmVerBscui::DpchAppData();
			((DlgWznmVerBscui::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERBSCUIDO) {
			req->dpchapp = new DlgWznmVerBscui::DpchAppDo();
			((DlgWznmVerBscui::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJOBDATA) {
			req->dpchapp = new DlgWznmVerCustjob::DpchAppData();
			((DlgWznmVerCustjob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJOBDO) {
			req->dpchapp = new DlgWznmVerCustjob::DpchAppDo();
			((DlgWznmVerCustjob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJTRDATA) {
			req->dpchapp = new DlgWznmVerCustjtr::DpchAppData();
			((DlgWznmVerCustjtr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTJTRDO) {
			req->dpchapp = new DlgWznmVerCustjtr::DpchAppDo();
			((DlgWznmVerCustjtr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTUIDATA) {
			req->dpchapp = new DlgWznmVerCustui::DpchAppData();
			((DlgWznmVerCustui::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERCUSTUIDO) {
			req->dpchapp = new DlgWznmVerCustui::DpchAppDo();
			((DlgWznmVerCustui::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERDBSTRDATA) {
			req->dpchapp = new DlgWznmVerDbstr::DpchAppData();
			((DlgWznmVerDbstr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERDBSTRDO) {
			req->dpchapp = new DlgWznmVerDbstr::DpchAppDo();
			((DlgWznmVerDbstr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERDEPLOYDATA) {
			req->dpchapp = new DlgWznmVerDeploy::DpchAppData();
			((DlgWznmVerDeploy::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERDEPLOYDO) {
			req->dpchapp = new DlgWznmVerDeploy::DpchAppDo();
			((DlgWznmVerDeploy::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERFINMODDO) {
			req->dpchapp = new DlgWznmVerFinmod::DpchAppDo();
			((DlgWznmVerFinmod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENJTRDATA) {
			req->dpchapp = new DlgWznmVerGenjtr::DpchAppData();
			((DlgWznmVerGenjtr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENJTRDO) {
			req->dpchapp = new DlgWznmVerGenjtr::DpchAppDo();
			((DlgWznmVerGenjtr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDATA) {
			req->dpchapp = new DlgWznmVerGenui::DpchAppData();
			((DlgWznmVerGenui::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGENUIDO) {
			req->dpchapp = new DlgWznmVerGenui::DpchAppDo();
			((DlgWznmVerGenui::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGLOBALDATA) {
			req->dpchapp = new DlgWznmVerGlobal::DpchAppData();
			((DlgWznmVerGlobal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERGLOBALDO) {
			req->dpchapp = new DlgWznmVerGlobal::DpchAppDo();
			((DlgWznmVerGlobal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERIMPEXPDATA) {
			req->dpchapp = new DlgWznmVerImpexp::DpchAppData();
			((DlgWznmVerImpexp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERIMPEXPDO) {
			req->dpchapp = new DlgWznmVerImpexp::DpchAppDo();
			((DlgWznmVerImpexp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDATA) {
			req->dpchapp = new DlgWznmVerNew::DpchAppData();
			((DlgWznmVerNew::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERNEWDO) {
			req->dpchapp = new DlgWznmVerNew::DpchAppDo();
			((DlgWznmVerNew::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVEROPPACKDATA) {
			req->dpchapp = new DlgWznmVerOppack::DpchAppData();
			((DlgWznmVerOppack::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVEROPPACKDO) {
			req->dpchapp = new DlgWznmVerOppack::DpchAppDo();
			((DlgWznmVerOppack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERWRSTKITDATA) {
			req->dpchapp = new DlgWznmVerWrstkit::DpchAppData();
			((DlgWznmVerWrstkit::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPDLGWZNMVERWRSTKITDO) {
			req->dpchapp = new DlgWznmVerWrstkit::DpchAppDo();
			((DlgWznmVerWrstkit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPROOTWZNMLOGIN) {
			req->dpchapp = new RootWznm::DpchAppLogin();
			((RootWznm::DpchAppLogin*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMALERT) {
			req->dpchapp = new DpchAppWznmAlert();
			((DpchAppWznmAlert*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPP1NRTJOBDATA) {
			req->dpchapp = new PnlWznmApp1NRtjob::DpchAppData();
			((PnlWznmApp1NRtjob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPP1NRTJOBDO) {
			req->dpchapp = new PnlWznmApp1NRtjob::DpchAppDo();
			((PnlWznmApp1NRtjob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPAPP1NSEQUENCEDATA) {
			req->dpchapp = new PnlWznmAppApp1NSequence::DpchAppData();
			((PnlWznmAppApp1NSequence::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPAPP1NSEQUENCEDO) {
			req->dpchapp = new PnlWznmAppApp1NSequence::DpchAppDo();
			((PnlWznmAppApp1NSequence::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPDETAILDATA) {
			req->dpchapp = new PnlWznmAppDetail::DpchAppData();
			((PnlWznmAppDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPDETAILDO) {
			req->dpchapp = new PnlWznmAppDetail::DpchAppDo();
			((PnlWznmAppDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPDO) {
			req->dpchapp = new CrdWznmApp::DpchAppDo();
			((CrdWznmApp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPLISTDATA) {
			req->dpchapp = new PnlWznmAppList::DpchAppData();
			((PnlWznmAppList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPLISTDO) {
			req->dpchapp = new PnlWznmAppList::DpchAppDo();
			((PnlWznmAppList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPRECDO) {
			req->dpchapp = new PnlWznmAppRec::DpchAppDo();
			((PnlWznmAppRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPREF1NFILEDATA) {
			req->dpchapp = new PnlWznmAppRef1NFile::DpchAppData();
			((PnlWznmAppRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMAPPREF1NFILEDO) {
			req->dpchapp = new PnlWznmAppRef1NFile::DpchAppDo();
			((PnlWznmAppRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLK1NRTDPCHDATA) {
			req->dpchapp = new PnlWznmBlk1NRtdpch::DpchAppData();
			((PnlWznmBlk1NRtdpch::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLK1NRTDPCHDO) {
			req->dpchapp = new PnlWznmBlk1NRtdpch::DpchAppDo();
			((PnlWznmBlk1NRtdpch::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKAITEMDATA) {
			req->dpchapp = new PnlWznmBlkAItem::DpchAppData();
			((PnlWznmBlkAItem::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKAITEMDO) {
			req->dpchapp = new PnlWznmBlkAItem::DpchAppDo();
			((PnlWznmBlkAItem::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKDETAILDATA) {
			req->dpchapp = new PnlWznmBlkDetail::DpchAppData();
			((PnlWznmBlkDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKDETAILDO) {
			req->dpchapp = new PnlWznmBlkDetail::DpchAppDo();
			((PnlWznmBlkDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKDO) {
			req->dpchapp = new CrdWznmBlk::DpchAppDo();
			((CrdWznmBlk::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKLISTDATA) {
			req->dpchapp = new PnlWznmBlkList::DpchAppData();
			((PnlWznmBlkList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKLISTDO) {
			req->dpchapp = new PnlWznmBlkList::DpchAppDo();
			((PnlWznmBlkList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKRECDO) {
			req->dpchapp = new PnlWznmBlkRec::DpchAppDo();
			((PnlWznmBlkRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKREF1NRTBLOCKDATA) {
			req->dpchapp = new PnlWznmBlkRef1NRtblock::DpchAppData();
			((PnlWznmBlkRef1NRtblock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMBLKREF1NRTBLOCKDO) {
			req->dpchapp = new PnlWznmBlkRef1NRtblock::DpchAppDo();
			((PnlWznmBlkRef1NRtblock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAL1NSENSITIVITYDATA) {
			req->dpchapp = new PnlWznmCal1NSensitivity::DpchAppData();
			((PnlWznmCal1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAL1NSENSITIVITYDO) {
			req->dpchapp = new PnlWznmCal1NSensitivity::DpchAppDo();
			((PnlWznmCal1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDETAILDATA) {
			req->dpchapp = new PnlWznmCalDetail::DpchAppData();
			((PnlWznmCalDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDETAILDO) {
			req->dpchapp = new PnlWznmCalDetail::DpchAppDo();
			((PnlWznmCalDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALDO) {
			req->dpchapp = new CrdWznmCal::DpchAppDo();
			((CrdWznmCal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALLISTDATA) {
			req->dpchapp = new PnlWznmCalList::DpchAppData();
			((PnlWznmCalList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALLISTDO) {
			req->dpchapp = new PnlWznmCalList::DpchAppDo();
			((PnlWznmCalList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALMNSTUBDATA) {
			req->dpchapp = new PnlWznmCalMNStub::DpchAppData();
			((PnlWznmCalMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALMNSTUBDO) {
			req->dpchapp = new PnlWznmCalMNStub::DpchAppDo();
			((PnlWznmCalMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCALRECDO) {
			req->dpchapp = new PnlWznmCalRec::DpchAppDo();
			((PnlWznmCalRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPAPARDATA) {
			req->dpchapp = new PnlWznmCapAPar::DpchAppData();
			((PnlWznmCapAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPAPARDO) {
			req->dpchapp = new PnlWznmCapAPar::DpchAppDo();
			((PnlWznmCapAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPDETAILDATA) {
			req->dpchapp = new PnlWznmCapDetail::DpchAppData();
			((PnlWznmCapDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPDETAILDO) {
			req->dpchapp = new PnlWznmCapDetail::DpchAppDo();
			((PnlWznmCapDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPDO) {
			req->dpchapp = new CrdWznmCap::DpchAppDo();
			((CrdWznmCap::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPLISTDATA) {
			req->dpchapp = new PnlWznmCapList::DpchAppData();
			((PnlWznmCapList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPLISTDO) {
			req->dpchapp = new PnlWznmCapList::DpchAppDo();
			((PnlWznmCapList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAPRECDO) {
			req->dpchapp = new PnlWznmCapRec::DpchAppDo();
			((PnlWznmCapRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAR1NDIALOGDATA) {
			req->dpchapp = new PnlWznmCar1NDialog::DpchAppData();
			((PnlWznmCar1NDialog::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCAR1NDIALOGDO) {
			req->dpchapp = new PnlWznmCar1NDialog::DpchAppDo();
			((PnlWznmCar1NDialog::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARCAR1NPANELDATA) {
			req->dpchapp = new PnlWznmCarCar1NPanel::DpchAppData();
			((PnlWznmCarCar1NPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARCAR1NPANELDO) {
			req->dpchapp = new PnlWznmCarCar1NPanel::DpchAppDo();
			((PnlWznmCarCar1NPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARDETAILDATA) {
			req->dpchapp = new PnlWznmCarDetail::DpchAppData();
			((PnlWznmCarDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARDETAILDO) {
			req->dpchapp = new PnlWznmCarDetail::DpchAppDo();
			((PnlWznmCarDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARDO) {
			req->dpchapp = new CrdWznmCar::DpchAppDo();
			((CrdWznmCar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARHK1NCONTROLDATA) {
			req->dpchapp = new PnlWznmCarHk1NControl::DpchAppData();
			((PnlWznmCarHk1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARHK1NCONTROLDO) {
			req->dpchapp = new PnlWznmCarHk1NControl::DpchAppDo();
			((PnlWznmCarHk1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARLISTDATA) {
			req->dpchapp = new PnlWznmCarList::DpchAppData();
			((PnlWznmCarList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARLISTDO) {
			req->dpchapp = new PnlWznmCarList::DpchAppDo();
			((PnlWznmCarList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCARRECDO) {
			req->dpchapp = new PnlWznmCarRec::DpchAppDo();
			((PnlWznmCarRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKDETAILDATA) {
			req->dpchapp = new PnlWznmChkDetail::DpchAppData();
			((PnlWznmChkDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKDETAILDO) {
			req->dpchapp = new PnlWznmChkDetail::DpchAppDo();
			((PnlWznmChkDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKDO) {
			req->dpchapp = new CrdWznmChk::DpchAppDo();
			((CrdWznmChk::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKLISTDATA) {
			req->dpchapp = new PnlWznmChkList::DpchAppData();
			((PnlWznmChkList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKLISTDO) {
			req->dpchapp = new PnlWznmChkList::DpchAppDo();
			((PnlWznmChkList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKRECDO) {
			req->dpchapp = new PnlWznmChkRec::DpchAppDo();
			((PnlWznmChkRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKREF1NCALLDATA) {
			req->dpchapp = new PnlWznmChkRef1NCall::DpchAppData();
			((PnlWznmChkRef1NCall::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCHKREF1NCALLDO) {
			req->dpchapp = new PnlWznmChkRef1NCall::DpchAppDo();
			((PnlWznmChkRef1NCall::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMP1NRELEASEDATA) {
			req->dpchapp = new PnlWznmCmp1NRelease::DpchAppData();
			((PnlWznmCmp1NRelease::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMP1NRELEASEDO) {
			req->dpchapp = new PnlWznmCmp1NRelease::DpchAppDo();
			((PnlWznmCmp1NRelease::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPDETAILDATA) {
			req->dpchapp = new PnlWznmCmpDetail::DpchAppData();
			((PnlWznmCmpDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPDETAILDO) {
			req->dpchapp = new PnlWznmCmpDetail::DpchAppDo();
			((PnlWznmCmpDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPDO) {
			req->dpchapp = new CrdWznmCmp::DpchAppDo();
			((CrdWznmCmp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPLISTDATA) {
			req->dpchapp = new PnlWznmCmpList::DpchAppData();
			((PnlWznmCmpList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPLISTDO) {
			req->dpchapp = new PnlWznmCmpList::DpchAppDo();
			((PnlWznmCmpList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPMNLIBRARYDATA) {
			req->dpchapp = new PnlWznmCmpMNLibrary::DpchAppData();
			((PnlWznmCmpMNLibrary::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPMNLIBRARYDO) {
			req->dpchapp = new PnlWznmCmpMNLibrary::DpchAppDo();
			((PnlWznmCmpMNLibrary::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPMNOPPACKDATA) {
			req->dpchapp = new PnlWznmCmpMNOppack::DpchAppData();
			((PnlWznmCmpMNOppack::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPMNOPPACKDO) {
			req->dpchapp = new PnlWznmCmpMNOppack::DpchAppDo();
			((PnlWznmCmpMNOppack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCMPRECDO) {
			req->dpchapp = new PnlWznmCmpRec::DpchAppDo();
			((PnlWznmCmpRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONAPARDATA) {
			req->dpchapp = new PnlWznmConAPar::DpchAppData();
			((PnlWznmConAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONAPARDO) {
			req->dpchapp = new PnlWznmConAPar::DpchAppDo();
			((PnlWznmConAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONDETAILDATA) {
			req->dpchapp = new PnlWznmConDetail::DpchAppData();
			((PnlWznmConDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONDETAILDO) {
			req->dpchapp = new PnlWznmConDetail::DpchAppDo();
			((PnlWznmConDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONDO) {
			req->dpchapp = new CrdWznmCon::DpchAppDo();
			((CrdWznmCon::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONFEDREF1NRTBLOCKDATA) {
			req->dpchapp = new PnlWznmConFedRef1NRtblock::DpchAppData();
			((PnlWznmConFedRef1NRtblock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONFEDREF1NRTBLOCKDO) {
			req->dpchapp = new PnlWznmConFedRef1NRtblock::DpchAppDo();
			((PnlWznmConFedRef1NRtblock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONLISTDATA) {
			req->dpchapp = new PnlWznmConList::DpchAppData();
			((PnlWznmConList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONLISTDO) {
			req->dpchapp = new PnlWznmConList::DpchAppDo();
			((PnlWznmConList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONRECDO) {
			req->dpchapp = new PnlWznmConRec::DpchAppDo();
			((PnlWznmConRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONSUP1NCONTROLDATA) {
			req->dpchapp = new PnlWznmConSup1NControl::DpchAppData();
			((PnlWznmConSup1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCONSUP1NCONTROLDO) {
			req->dpchapp = new PnlWznmConSup1NControl::DpchAppDo();
			((PnlWznmConSup1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTP1NTAGDATA) {
			req->dpchapp = new PnlWznmCtp1NTag::DpchAppData();
			((PnlWznmCtp1NTag::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTP1NTAGDO) {
			req->dpchapp = new PnlWznmCtp1NTag::DpchAppDo();
			((PnlWznmCtp1NTag::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPAPARDATA) {
			req->dpchapp = new PnlWznmCtpAPar::DpchAppData();
			((PnlWznmCtpAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPAPARDO) {
			req->dpchapp = new PnlWznmCtpAPar::DpchAppDo();
			((PnlWznmCtpAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPDETAILDATA) {
			req->dpchapp = new PnlWznmCtpDetail::DpchAppData();
			((PnlWznmCtpDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPDETAILDO) {
			req->dpchapp = new PnlWznmCtpDetail::DpchAppDo();
			((PnlWznmCtpDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPDO) {
			req->dpchapp = new CrdWznmCtp::DpchAppDo();
			((CrdWznmCtp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPKKEYDATA) {
			req->dpchapp = new PnlWznmCtpKKey::DpchAppData();
			((PnlWznmCtpKKey::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPKKEYDO) {
			req->dpchapp = new PnlWznmCtpKKey::DpchAppDo();
			((PnlWznmCtpKKey::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPKPARKEYDATA) {
			req->dpchapp = new PnlWznmCtpKParKey::DpchAppData();
			((PnlWznmCtpKParKey::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPKPARKEYDO) {
			req->dpchapp = new PnlWznmCtpKParKey::DpchAppDo();
			((PnlWznmCtpKParKey::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPLISTDATA) {
			req->dpchapp = new PnlWznmCtpList::DpchAppData();
			((PnlWznmCtpList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPLISTDO) {
			req->dpchapp = new PnlWznmCtpList::DpchAppDo();
			((PnlWznmCtpList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPRECDO) {
			req->dpchapp = new PnlWznmCtpRec::DpchAppDo();
			((PnlWznmCtpRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPTPL1NCAPABILITYDATA) {
			req->dpchapp = new PnlWznmCtpTpl1NCapability::DpchAppData();
			((PnlWznmCtpTpl1NCapability::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMCTPTPL1NCAPABILITYDO) {
			req->dpchapp = new PnlWznmCtpTpl1NCapability::DpchAppDo();
			((PnlWznmCtpTpl1NCapability::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGDETAILDATA) {
			req->dpchapp = new PnlWznmDlgDetail::DpchAppData();
			((PnlWznmDlgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGDETAILDO) {
			req->dpchapp = new PnlWznmDlgDetail::DpchAppDo();
			((PnlWznmDlgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGDO) {
			req->dpchapp = new CrdWznmDlg::DpchAppDo();
			((CrdWznmDlg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGHK1NCONTROLDATA) {
			req->dpchapp = new PnlWznmDlgHk1NControl::DpchAppData();
			((PnlWznmDlgHk1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGHK1NCONTROLDO) {
			req->dpchapp = new PnlWznmDlgHk1NControl::DpchAppDo();
			((PnlWznmDlgHk1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGLISTDATA) {
			req->dpchapp = new PnlWznmDlgList::DpchAppData();
			((PnlWznmDlgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGLISTDO) {
			req->dpchapp = new PnlWznmDlgList::DpchAppDo();
			((PnlWznmDlgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGMNQUERYDATA) {
			req->dpchapp = new PnlWznmDlgMNQuery::DpchAppData();
			((PnlWznmDlgMNQuery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGMNQUERYDO) {
			req->dpchapp = new PnlWznmDlgMNQuery::DpchAppDo();
			((PnlWznmDlgMNQuery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGRECDO) {
			req->dpchapp = new PnlWznmDlgRec::DpchAppDo();
			((PnlWznmDlgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGREF1NCONTROLDATA) {
			req->dpchapp = new PnlWznmDlgRef1NControl::DpchAppData();
			((PnlWznmDlgRef1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMDLGREF1NCONTROLDO) {
			req->dpchapp = new PnlWznmDlgRef1NControl::DpchAppDo();
			((PnlWznmDlgRef1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRDETAILDATA) {
			req->dpchapp = new PnlWznmErrDetail::DpchAppData();
			((PnlWznmErrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRDETAILDO) {
			req->dpchapp = new PnlWznmErrDetail::DpchAppDo();
			((PnlWznmErrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRDO) {
			req->dpchapp = new CrdWznmErr::DpchAppDo();
			((CrdWznmErr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRLISTDATA) {
			req->dpchapp = new PnlWznmErrList::DpchAppData();
			((PnlWznmErrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRLISTDO) {
			req->dpchapp = new PnlWznmErrList::DpchAppDo();
			((PnlWznmErrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMERRRECDO) {
			req->dpchapp = new PnlWznmErrRec::DpchAppDo();
			((PnlWznmErrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILDETAILDATA) {
			req->dpchapp = new PnlWznmFilDetail::DpchAppData();
			((PnlWznmFilDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILDETAILDO) {
			req->dpchapp = new PnlWznmFilDetail::DpchAppDo();
			((PnlWznmFilDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILDO) {
			req->dpchapp = new CrdWznmFil::DpchAppDo();
			((CrdWznmFil::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILLISTDATA) {
			req->dpchapp = new PnlWznmFilList::DpchAppData();
			((PnlWznmFilList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILLISTDO) {
			req->dpchapp = new PnlWznmFilList::DpchAppDo();
			((PnlWznmFilList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMFILRECDO) {
			req->dpchapp = new PnlWznmFilRec::DpchAppDo();
			((PnlWznmFilRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELDETAILDATA) {
			req->dpchapp = new PnlWznmIelDetail::DpchAppData();
			((PnlWznmIelDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELDETAILDO) {
			req->dpchapp = new PnlWznmIelDetail::DpchAppDo();
			((PnlWznmIelDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELDO) {
			req->dpchapp = new CrdWznmIel::DpchAppDo();
			((CrdWznmIel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELLISTDATA) {
			req->dpchapp = new PnlWznmIelList::DpchAppData();
			((PnlWznmIelList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELLISTDO) {
			req->dpchapp = new PnlWznmIelList::DpchAppDo();
			((PnlWznmIelList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIELRECDO) {
			req->dpchapp = new PnlWznmIelRec::DpchAppDo();
			((PnlWznmIelRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEX1NIMPEXPDATA) {
			req->dpchapp = new PnlWznmIex1NImpexp::DpchAppData();
			((PnlWznmIex1NImpexp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEX1NIMPEXPDO) {
			req->dpchapp = new PnlWznmIex1NImpexp::DpchAppDo();
			((PnlWznmIex1NImpexp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXDETAILDATA) {
			req->dpchapp = new PnlWznmIexDetail::DpchAppData();
			((PnlWznmIexDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXDETAILDO) {
			req->dpchapp = new PnlWznmIexDetail::DpchAppDo();
			((PnlWznmIexDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXDO) {
			req->dpchapp = new CrdWznmIex::DpchAppDo();
			((CrdWznmIex::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXHK1NVECTORDATA) {
			req->dpchapp = new PnlWznmIexHk1NVector::DpchAppData();
			((PnlWznmIexHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXHK1NVECTORDO) {
			req->dpchapp = new PnlWznmIexHk1NVector::DpchAppDo();
			((PnlWznmIexHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXLISTDATA) {
			req->dpchapp = new PnlWznmIexList::DpchAppData();
			((PnlWznmIexList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXLISTDO) {
			req->dpchapp = new PnlWznmIexList::DpchAppDo();
			((PnlWznmIexList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXRECDO) {
			req->dpchapp = new PnlWznmIexRec::DpchAppDo();
			((PnlWznmIexRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXREF1NDIALOGDATA) {
			req->dpchapp = new PnlWznmIexRef1NDialog::DpchAppData();
			((PnlWznmIexRef1NDialog::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIEXREF1NDIALOGDO) {
			req->dpchapp = new PnlWznmIexRef1NDialog::DpchAppDo();
			((PnlWznmIexRef1NDialog::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEDETAILDATA) {
			req->dpchapp = new PnlWznmImeDetail::DpchAppData();
			((PnlWznmImeDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEDETAILDO) {
			req->dpchapp = new PnlWznmImeDetail::DpchAppDo();
			((PnlWznmImeDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEDO) {
			req->dpchapp = new CrdWznmIme::DpchAppDo();
			((CrdWznmIme::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEHK1NVECTORDATA) {
			req->dpchapp = new PnlWznmImeHk1NVector::DpchAppData();
			((PnlWznmImeHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEHK1NVECTORDO) {
			req->dpchapp = new PnlWznmImeHk1NVector::DpchAppDo();
			((PnlWznmImeHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEIME1NIMPEXPCOLDATA) {
			req->dpchapp = new PnlWznmImeIme1NImpexpcol::DpchAppData();
			((PnlWznmImeIme1NImpexpcol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMEIME1NIMPEXPCOLDO) {
			req->dpchapp = new PnlWznmImeIme1NImpexpcol::DpchAppDo();
			((PnlWznmImeIme1NImpexpcol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMELISTDATA) {
			req->dpchapp = new PnlWznmImeList::DpchAppData();
			((PnlWznmImeList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMELISTDO) {
			req->dpchapp = new PnlWznmImeList::DpchAppDo();
			((PnlWznmImeList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMERECDO) {
			req->dpchapp = new PnlWznmImeRec::DpchAppDo();
			((PnlWznmImeRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMESUP1NIMPEXPDATA) {
			req->dpchapp = new PnlWznmImeSup1NImpexp::DpchAppData();
			((PnlWznmImeSup1NImpexp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMIMESUP1NIMPEXPDO) {
			req->dpchapp = new PnlWznmImeSup1NImpexp::DpchAppDo();
			((PnlWznmImeSup1NImpexp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMINIT) {
			req->dpchapp = new DpchAppWznmInit();
			((DpchAppWznmInit*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NMETHODDATA) {
			req->dpchapp = new PnlWznmJob1NMethod::DpchAppData();
			((PnlWznmJob1NMethod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NMETHODDO) {
			req->dpchapp = new PnlWznmJob1NMethod::DpchAppDo();
			((PnlWznmJob1NMethod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NRTJOBDATA) {
			req->dpchapp = new PnlWznmJob1NRtjob::DpchAppData();
			((PnlWznmJob1NRtjob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NRTJOBDO) {
			req->dpchapp = new PnlWznmJob1NRtjob::DpchAppDo();
			((PnlWznmJob1NRtjob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NSENSITIVITYDATA) {
			req->dpchapp = new PnlWznmJob1NSensitivity::DpchAppData();
			((PnlWznmJob1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOB1NSENSITIVITYDO) {
			req->dpchapp = new PnlWznmJob1NSensitivity::DpchAppDo();
			((PnlWznmJob1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBACMDDATA) {
			req->dpchapp = new PnlWznmJobACmd::DpchAppData();
			((PnlWznmJobACmd::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBACMDDO) {
			req->dpchapp = new PnlWznmJobACmd::DpchAppDo();
			((PnlWznmJobACmd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBAVARDATA) {
			req->dpchapp = new PnlWznmJobAVar::DpchAppData();
			((PnlWznmJobAVar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBAVARDO) {
			req->dpchapp = new PnlWznmJobAVar::DpchAppDo();
			((PnlWznmJobAVar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBDETAILDATA) {
			req->dpchapp = new PnlWznmJobDetail::DpchAppData();
			((PnlWznmJobDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBDETAILDO) {
			req->dpchapp = new PnlWznmJobDetail::DpchAppDo();
			((PnlWznmJobDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBDO) {
			req->dpchapp = new CrdWznmJob::DpchAppDo();
			((CrdWznmJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBHK1NVECTORDATA) {
			req->dpchapp = new PnlWznmJobHk1NVector::DpchAppData();
			((PnlWznmJobHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBHK1NVECTORDO) {
			req->dpchapp = new PnlWznmJobHk1NVector::DpchAppDo();
			((PnlWznmJobHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBJOB1NSTAGEDATA) {
			req->dpchapp = new PnlWznmJobJob1NStage::DpchAppData();
			((PnlWznmJobJob1NStage::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBJOB1NSTAGEDO) {
			req->dpchapp = new PnlWznmJobJob1NStage::DpchAppDo();
			((PnlWznmJobJob1NStage::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBLISTDATA) {
			req->dpchapp = new PnlWznmJobList::DpchAppData();
			((PnlWznmJobList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBLISTDO) {
			req->dpchapp = new PnlWznmJobList::DpchAppDo();
			((PnlWznmJobList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBMNOPDATA) {
			req->dpchapp = new PnlWznmJobMNOp::DpchAppData();
			((PnlWznmJobMNOp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBMNOPDO) {
			req->dpchapp = new PnlWznmJobMNOp::DpchAppDo();
			((PnlWznmJobMNOp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBMNOPPACKDATA) {
			req->dpchapp = new PnlWznmJobMNOppack::DpchAppData();
			((PnlWznmJobMNOppack::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBMNOPPACKDO) {
			req->dpchapp = new PnlWznmJobMNOppack::DpchAppDo();
			((PnlWznmJobMNOppack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBRECDO) {
			req->dpchapp = new PnlWznmJobRec::DpchAppDo();
			((PnlWznmJobRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBREF1NBLOCKDATA) {
			req->dpchapp = new PnlWznmJobRef1NBlock::DpchAppData();
			((PnlWznmJobRef1NBlock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBREF1NBLOCKDO) {
			req->dpchapp = new PnlWznmJobRef1NBlock::DpchAppDo();
			((PnlWznmJobRef1NBlock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBSUBMNJOBDATA) {
			req->dpchapp = new PnlWznmJobSubMNJob::DpchAppData();
			((PnlWznmJobSubMNJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBSUBMNJOBDO) {
			req->dpchapp = new PnlWznmJobSubMNJob::DpchAppDo();
			((PnlWznmJobSubMNJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBSUPMNJOBDATA) {
			req->dpchapp = new PnlWznmJobSupMNJob::DpchAppData();
			((PnlWznmJobSupMNJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMJOBSUPMNJOBDO) {
			req->dpchapp = new PnlWznmJobSupMNJob::DpchAppDo();
			((PnlWznmJobSupMNJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBAMAKEFILEDATA) {
			req->dpchapp = new PnlWznmLibAMakefile::DpchAppData();
			((PnlWznmLibAMakefile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBAMAKEFILEDO) {
			req->dpchapp = new PnlWznmLibAMakefile::DpchAppDo();
			((PnlWznmLibAMakefile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBAPKGLISTDATA) {
			req->dpchapp = new PnlWznmLibAPkglist::DpchAppData();
			((PnlWznmLibAPkglist::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBAPKGLISTDO) {
			req->dpchapp = new PnlWznmLibAPkglist::DpchAppDo();
			((PnlWznmLibAPkglist::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBDETAILDATA) {
			req->dpchapp = new PnlWznmLibDetail::DpchAppData();
			((PnlWznmLibDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBDETAILDO) {
			req->dpchapp = new PnlWznmLibDetail::DpchAppDo();
			((PnlWznmLibDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBDO) {
			req->dpchapp = new CrdWznmLib::DpchAppDo();
			((CrdWznmLib::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBLISTDATA) {
			req->dpchapp = new PnlWznmLibList::DpchAppData();
			((PnlWznmLibList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBLISTDO) {
			req->dpchapp = new PnlWznmLibList::DpchAppDo();
			((PnlWznmLibList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBMNCOMPONENTDATA) {
			req->dpchapp = new PnlWznmLibMNComponent::DpchAppData();
			((PnlWznmLibMNComponent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBMNCOMPONENTDO) {
			req->dpchapp = new PnlWznmLibMNComponent::DpchAppDo();
			((PnlWznmLibMNComponent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBMNOPPACKDATA) {
			req->dpchapp = new PnlWznmLibMNOppack::DpchAppData();
			((PnlWznmLibMNOppack::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBMNOPPACKDO) {
			req->dpchapp = new PnlWznmLibMNOppack::DpchAppDo();
			((PnlWznmLibMNOppack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBRECDO) {
			req->dpchapp = new PnlWznmLibRec::DpchAppDo();
			((PnlWznmLibRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBREF1NFILEDATA) {
			req->dpchapp = new PnlWznmLibRef1NFile::DpchAppData();
			((PnlWznmLibRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLIBREF1NFILEDO) {
			req->dpchapp = new PnlWznmLibRef1NFile::DpchAppDo();
			((PnlWznmLibRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCDETAILDATA) {
			req->dpchapp = new PnlWznmLocDetail::DpchAppData();
			((PnlWznmLocDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCDETAILDO) {
			req->dpchapp = new PnlWznmLocDetail::DpchAppDo();
			((PnlWznmLocDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCDO) {
			req->dpchapp = new CrdWznmLoc::DpchAppDo();
			((CrdWznmLoc::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCLISTDATA) {
			req->dpchapp = new PnlWznmLocList::DpchAppData();
			((PnlWznmLocList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCLISTDO) {
			req->dpchapp = new PnlWznmLocList::DpchAppDo();
			((PnlWznmLocList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCMNVERSIONDATA) {
			req->dpchapp = new PnlWznmLocMNVersion::DpchAppData();
			((PnlWznmLocMNVersion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCMNVERSIONDO) {
			req->dpchapp = new PnlWznmLocMNVersion::DpchAppDo();
			((PnlWznmLocMNVersion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMLOCRECDO) {
			req->dpchapp = new PnlWznmLocRec::DpchAppDo();
			((PnlWznmLocRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCH1NRELEASEDATA) {
			req->dpchapp = new PnlWznmMch1NRelease::DpchAppData();
			((PnlWznmMch1NRelease::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCH1NRELEASEDO) {
			req->dpchapp = new PnlWznmMch1NRelease::DpchAppDo();
			((PnlWznmMch1NRelease::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHAPARDATA) {
			req->dpchapp = new PnlWznmMchAPar::DpchAppData();
			((PnlWznmMchAPar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHAPARDO) {
			req->dpchapp = new PnlWznmMchAPar::DpchAppDo();
			((PnlWznmMchAPar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHDETAILDATA) {
			req->dpchapp = new PnlWznmMchDetail::DpchAppData();
			((PnlWznmMchDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHDETAILDO) {
			req->dpchapp = new PnlWznmMchDetail::DpchAppDo();
			((PnlWznmMchDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHDO) {
			req->dpchapp = new CrdWznmMch::DpchAppDo();
			((CrdWznmMch::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHLISTDATA) {
			req->dpchapp = new PnlWznmMchList::DpchAppData();
			((PnlWznmMchList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHLISTDO) {
			req->dpchapp = new PnlWznmMchList::DpchAppDo();
			((PnlWznmMchList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMCHRECDO) {
			req->dpchapp = new PnlWznmMchRec::DpchAppDo();
			((PnlWznmMchRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLDETAILDATA) {
			req->dpchapp = new PnlWznmMdlDetail::DpchAppData();
			((PnlWznmMdlDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLDETAILDO) {
			req->dpchapp = new PnlWznmMdlDetail::DpchAppDo();
			((PnlWznmMdlDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLDO) {
			req->dpchapp = new CrdWznmMdl::DpchAppDo();
			((CrdWznmMdl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLLISTDATA) {
			req->dpchapp = new PnlWznmMdlList::DpchAppData();
			((PnlWznmMdlList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLLISTDO) {
			req->dpchapp = new PnlWznmMdlList::DpchAppDo();
			((PnlWznmMdlList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLMDL1NCARDDATA) {
			req->dpchapp = new PnlWznmMdlMdl1NCard::DpchAppData();
			((PnlWznmMdlMdl1NCard::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLMDL1NCARDDO) {
			req->dpchapp = new PnlWznmMdlMdl1NCard::DpchAppDo();
			((PnlWznmMdlMdl1NCard::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLRECDO) {
			req->dpchapp = new PnlWznmMdlRec::DpchAppDo();
			((PnlWznmMdlRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLREF1NPANELDATA) {
			req->dpchapp = new PnlWznmMdlRef1NPanel::DpchAppData();
			((PnlWznmMdlRef1NPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMDLREF1NPANELDO) {
			req->dpchapp = new PnlWznmMdlRef1NPanel::DpchAppDo();
			((PnlWznmMdlRef1NPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDAINVPARDATA) {
			req->dpchapp = new PnlWznmMtdAInvpar::DpchAppData();
			((PnlWznmMtdAInvpar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDAINVPARDO) {
			req->dpchapp = new PnlWznmMtdAInvpar::DpchAppDo();
			((PnlWznmMtdAInvpar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDARETPARDATA) {
			req->dpchapp = new PnlWznmMtdARetpar::DpchAppData();
			((PnlWznmMtdARetpar::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDARETPARDO) {
			req->dpchapp = new PnlWznmMtdARetpar::DpchAppDo();
			((PnlWznmMtdARetpar::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDDETAILDATA) {
			req->dpchapp = new PnlWznmMtdDetail::DpchAppData();
			((PnlWznmMtdDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDDETAILDO) {
			req->dpchapp = new PnlWznmMtdDetail::DpchAppDo();
			((PnlWznmMtdDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDDO) {
			req->dpchapp = new CrdWznmMtd::DpchAppDo();
			((CrdWznmMtd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDLISTDATA) {
			req->dpchapp = new PnlWznmMtdList::DpchAppData();
			((PnlWznmMtdList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDLISTDO) {
			req->dpchapp = new PnlWznmMtdList::DpchAppDo();
			((PnlWznmMtdList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTDRECDO) {
			req->dpchapp = new PnlWznmMtdRec::DpchAppDo();
			((PnlWznmMtdRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTY1NMACHINEDATA) {
			req->dpchapp = new PnlWznmMty1NMachine::DpchAppData();
			((PnlWznmMty1NMachine::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTY1NMACHINEDO) {
			req->dpchapp = new PnlWznmMty1NMachine::DpchAppDo();
			((PnlWznmMty1NMachine::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYAMAKEFILEDATA) {
			req->dpchapp = new PnlWznmMtyAMakefile::DpchAppData();
			((PnlWznmMtyAMakefile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYAMAKEFILEDO) {
			req->dpchapp = new PnlWznmMtyAMakefile::DpchAppDo();
			((PnlWznmMtyAMakefile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYDETAILDATA) {
			req->dpchapp = new PnlWznmMtyDetail::DpchAppData();
			((PnlWznmMtyDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYDETAILDO) {
			req->dpchapp = new PnlWznmMtyDetail::DpchAppDo();
			((PnlWznmMtyDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYDO) {
			req->dpchapp = new CrdWznmMty::DpchAppDo();
			((CrdWznmMty::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYLISTDATA) {
			req->dpchapp = new PnlWznmMtyList::DpchAppData();
			((PnlWznmMtyList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYLISTDO) {
			req->dpchapp = new PnlWznmMtyList::DpchAppDo();
			((PnlWznmMtyList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMMTYRECDO) {
			req->dpchapp = new PnlWznmMtyRec::DpchAppDo();
			((PnlWznmMtyRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVADMINDATA) {
			req->dpchapp = new PnlWznmNavAdmin::DpchAppData();
			((PnlWznmNavAdmin::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVADMINDO) {
			req->dpchapp = new PnlWznmNavAdmin::DpchAppDo();
			((PnlWznmNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDATA) {
			req->dpchapp = new PnlWznmNavAppdev::DpchAppData();
			((PnlWznmNavAppdev::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVAPPDEVDO) {
			req->dpchapp = new PnlWznmNavAppdev::DpchAppDo();
			((PnlWznmNavAppdev::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVAUXFCTDO) {
			req->dpchapp = new PnlWznmNavAuxfct::DpchAppDo();
			((PnlWznmNavAuxfct::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVCOMPDATA) {
			req->dpchapp = new PnlWznmNavComp::DpchAppData();
			((PnlWznmNavComp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVCOMPDO) {
			req->dpchapp = new PnlWznmNavComp::DpchAppDo();
			((PnlWznmNavComp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDATA) {
			req->dpchapp = new PnlWznmNavDbstr::DpchAppData();
			((PnlWznmNavDbstr::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDBSTRDO) {
			req->dpchapp = new PnlWznmNavDbstr::DpchAppDo();
			((PnlWznmNavDbstr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDEPLOYDATA) {
			req->dpchapp = new PnlWznmNavDeploy::DpchAppData();
			((PnlWznmNavDeploy::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDEPLOYDO) {
			req->dpchapp = new PnlWznmNavDeploy::DpchAppDo();
			((PnlWznmNavDeploy::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVDO) {
			req->dpchapp = new CrdWznmNav::DpchAppDo();
			((CrdWznmNav::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDATA) {
			req->dpchapp = new PnlWznmNavGlobal::DpchAppData();
			((PnlWznmNavGlobal::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVGLOBALDO) {
			req->dpchapp = new PnlWznmNavGlobal::DpchAppDo();
			((PnlWznmNavGlobal::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVJOBDATA) {
			req->dpchapp = new PnlWznmNavJob::DpchAppData();
			((PnlWznmNavJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVJOBDO) {
			req->dpchapp = new PnlWznmNavJob::DpchAppDo();
			((PnlWznmNavJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVPREDO) {
			req->dpchapp = new PnlWznmNavPre::DpchAppDo();
			((PnlWznmNavPre::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDATA) {
			req->dpchapp = new PnlWznmNavProject::DpchAppData();
			((PnlWznmNavProject::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVPROJECTDO) {
			req->dpchapp = new PnlWznmNavProject::DpchAppDo();
			((PnlWznmNavProject::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVUIXDATA) {
			req->dpchapp = new PnlWznmNavUix::DpchAppData();
			((PnlWznmNavUix::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMNAVUIXDO) {
			req->dpchapp = new PnlWznmNavUix::DpchAppDo();
			((PnlWznmNavUix::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPK1NOPDATA) {
			req->dpchapp = new PnlWznmOpk1NOp::DpchAppData();
			((PnlWznmOpk1NOp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPK1NOPDO) {
			req->dpchapp = new PnlWznmOpk1NOp::DpchAppDo();
			((PnlWznmOpk1NOp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKAINVARGDATA) {
			req->dpchapp = new PnlWznmOpkAInvarg::DpchAppData();
			((PnlWznmOpkAInvarg::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKAINVARGDO) {
			req->dpchapp = new PnlWznmOpkAInvarg::DpchAppDo();
			((PnlWznmOpkAInvarg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKARETVALDATA) {
			req->dpchapp = new PnlWznmOpkARetval::DpchAppData();
			((PnlWznmOpkARetval::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKARETVALDO) {
			req->dpchapp = new PnlWznmOpkARetval::DpchAppDo();
			((PnlWznmOpkARetval::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKDETAILDATA) {
			req->dpchapp = new PnlWznmOpkDetail::DpchAppData();
			((PnlWznmOpkDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKDETAILDO) {
			req->dpchapp = new PnlWznmOpkDetail::DpchAppDo();
			((PnlWznmOpkDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKDO) {
			req->dpchapp = new CrdWznmOpk::DpchAppDo();
			((CrdWznmOpk::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKLISTDATA) {
			req->dpchapp = new PnlWznmOpkList::DpchAppData();
			((PnlWznmOpkList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKLISTDO) {
			req->dpchapp = new PnlWznmOpkList::DpchAppDo();
			((PnlWznmOpkList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNCOMPONENTDATA) {
			req->dpchapp = new PnlWznmOpkMNComponent::DpchAppData();
			((PnlWznmOpkMNComponent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNCOMPONENTDO) {
			req->dpchapp = new PnlWznmOpkMNComponent::DpchAppDo();
			((PnlWznmOpkMNComponent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNJOBDATA) {
			req->dpchapp = new PnlWznmOpkMNJob::DpchAppData();
			((PnlWznmOpkMNJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNJOBDO) {
			req->dpchapp = new PnlWznmOpkMNJob::DpchAppDo();
			((PnlWznmOpkMNJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNLIBRARYDATA) {
			req->dpchapp = new PnlWznmOpkMNLibrary::DpchAppData();
			((PnlWznmOpkMNLibrary::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKMNLIBRARYDO) {
			req->dpchapp = new PnlWznmOpkMNLibrary::DpchAppDo();
			((PnlWznmOpkMNLibrary::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKRECDO) {
			req->dpchapp = new PnlWznmOpkRec::DpchAppDo();
			((PnlWznmOpkRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKREF1NBLOCKDATA) {
			req->dpchapp = new PnlWznmOpkRef1NBlock::DpchAppData();
			((PnlWznmOpkRef1NBlock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKREF1NBLOCKDO) {
			req->dpchapp = new PnlWznmOpkRef1NBlock::DpchAppDo();
			((PnlWznmOpkRef1NBlock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKSQKMNSTUBDATA) {
			req->dpchapp = new PnlWznmOpkSqkMNStub::DpchAppData();
			((PnlWznmOpkSqkMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPKSQKMNSTUBDO) {
			req->dpchapp = new PnlWznmOpkSqkMNStub::DpchAppDo();
			((PnlWznmOpkSqkMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXAINVARGDATA) {
			req->dpchapp = new PnlWznmOpxAInvarg::DpchAppData();
			((PnlWznmOpxAInvarg::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXAINVARGDO) {
			req->dpchapp = new PnlWznmOpxAInvarg::DpchAppDo();
			((PnlWznmOpxAInvarg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXARETVALDATA) {
			req->dpchapp = new PnlWznmOpxARetval::DpchAppData();
			((PnlWznmOpxARetval::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXARETVALDO) {
			req->dpchapp = new PnlWznmOpxARetval::DpchAppDo();
			((PnlWznmOpxARetval::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXDETAILDATA) {
			req->dpchapp = new PnlWznmOpxDetail::DpchAppData();
			((PnlWznmOpxDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXDETAILDO) {
			req->dpchapp = new PnlWznmOpxDetail::DpchAppDo();
			((PnlWznmOpxDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXDO) {
			req->dpchapp = new CrdWznmOpx::DpchAppDo();
			((CrdWznmOpx::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXLISTDATA) {
			req->dpchapp = new PnlWznmOpxList::DpchAppData();
			((PnlWznmOpxList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXLISTDO) {
			req->dpchapp = new PnlWznmOpxList::DpchAppDo();
			((PnlWznmOpxList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXMNJOBDATA) {
			req->dpchapp = new PnlWznmOpxMNJob::DpchAppData();
			((PnlWznmOpxMNJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXMNJOBDO) {
			req->dpchapp = new PnlWznmOpxMNJob::DpchAppDo();
			((PnlWznmOpxMNJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXRECDO) {
			req->dpchapp = new PnlWznmOpxRec::DpchAppDo();
			((PnlWznmOpxRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXREF1NBLOCKDATA) {
			req->dpchapp = new PnlWznmOpxRef1NBlock::DpchAppData();
			((PnlWznmOpxRef1NBlock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXREF1NBLOCKDO) {
			req->dpchapp = new PnlWznmOpxRef1NBlock::DpchAppDo();
			((PnlWznmOpxRef1NBlock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXSQKMNSTUBDATA) {
			req->dpchapp = new PnlWznmOpxSqkMNStub::DpchAppData();
			((PnlWznmOpxSqkMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMOPXSQKMNSTUBDO) {
			req->dpchapp = new PnlWznmOpxSqkMNStub::DpchAppDo();
			((PnlWznmOpxSqkMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLDETAILDATA) {
			req->dpchapp = new PnlWznmPnlDetail::DpchAppData();
			((PnlWznmPnlDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLDETAILDO) {
			req->dpchapp = new PnlWznmPnlDetail::DpchAppDo();
			((PnlWznmPnlDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLDO) {
			req->dpchapp = new CrdWznmPnl::DpchAppDo();
			((CrdWznmPnl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLHK1NCONTROLDATA) {
			req->dpchapp = new PnlWznmPnlHk1NControl::DpchAppData();
			((PnlWznmPnlHk1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLHK1NCONTROLDO) {
			req->dpchapp = new PnlWznmPnlHk1NControl::DpchAppDo();
			((PnlWznmPnlHk1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLLISTDATA) {
			req->dpchapp = new PnlWznmPnlList::DpchAppData();
			((PnlWznmPnlList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLLISTDO) {
			req->dpchapp = new PnlWznmPnlList::DpchAppDo();
			((PnlWznmPnlList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLMNQUERYDATA) {
			req->dpchapp = new PnlWznmPnlMNQuery::DpchAppData();
			((PnlWznmPnlMNQuery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLMNQUERYDO) {
			req->dpchapp = new PnlWznmPnlMNQuery::DpchAppDo();
			((PnlWznmPnlMNQuery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPNLRECDO) {
			req->dpchapp = new PnlWznmPnlRec::DpchAppDo();
			((PnlWznmPnlRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJ1NVERSIONDATA) {
			req->dpchapp = new PnlWznmPrj1NVersion::DpchAppData();
			((PnlWznmPrj1NVersion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJ1NVERSIONDO) {
			req->dpchapp = new PnlWznmPrj1NVersion::DpchAppDo();
			((PnlWznmPrj1NVersion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJDETAILDATA) {
			req->dpchapp = new PnlWznmPrjDetail::DpchAppData();
			((PnlWznmPrjDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJDETAILDO) {
			req->dpchapp = new PnlWznmPrjDetail::DpchAppDo();
			((PnlWznmPrjDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJDO) {
			req->dpchapp = new CrdWznmPrj::DpchAppDo();
			((CrdWznmPrj::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJLISTDATA) {
			req->dpchapp = new PnlWznmPrjList::DpchAppData();
			((PnlWznmPrjList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJLISTDO) {
			req->dpchapp = new PnlWznmPrjList::DpchAppDo();
			((PnlWznmPrjList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJMNPERSONDATA) {
			req->dpchapp = new PnlWznmPrjMNPerson::DpchAppData();
			((PnlWznmPrjMNPerson::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJMNPERSONDO) {
			req->dpchapp = new PnlWznmPrjMNPerson::DpchAppDo();
			((PnlWznmPrjMNPerson::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRJRECDO) {
			req->dpchapp = new PnlWznmPrjRec::DpchAppDo();
			((PnlWznmPrjRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSADETAILDATA) {
			req->dpchapp = new PnlWznmPrsADetail::DpchAppData();
			((PnlWznmPrsADetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSADETAILDO) {
			req->dpchapp = new PnlWznmPrsADetail::DpchAppDo();
			((PnlWznmPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSDETAILDATA) {
			req->dpchapp = new PnlWznmPrsDetail::DpchAppData();
			((PnlWznmPrsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSDETAILDO) {
			req->dpchapp = new PnlWznmPrsDetail::DpchAppDo();
			((PnlWznmPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSDO) {
			req->dpchapp = new CrdWznmPrs::DpchAppDo();
			((CrdWznmPrs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSLISTDATA) {
			req->dpchapp = new PnlWznmPrsList::DpchAppData();
			((PnlWznmPrsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSLISTDO) {
			req->dpchapp = new PnlWznmPrsList::DpchAppDo();
			((PnlWznmPrsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSMNPROJECTDATA) {
			req->dpchapp = new PnlWznmPrsMNProject::DpchAppData();
			((PnlWznmPrsMNProject::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSMNPROJECTDO) {
			req->dpchapp = new PnlWznmPrsMNProject::DpchAppDo();
			((PnlWznmPrsMNProject::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPRSRECDO) {
			req->dpchapp = new PnlWznmPrsRec::DpchAppDo();
			((PnlWznmPrsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPST1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmPst1NQuerymod::DpchAppData();
			((PnlWznmPst1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPST1NQUERYMODDO) {
			req->dpchapp = new PnlWznmPst1NQuerymod::DpchAppDo();
			((PnlWznmPst1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTDETAILDATA) {
			req->dpchapp = new PnlWznmPstDetail::DpchAppData();
			((PnlWznmPstDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTDETAILDO) {
			req->dpchapp = new PnlWznmPstDetail::DpchAppDo();
			((PnlWznmPstDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTDO) {
			req->dpchapp = new CrdWznmPst::DpchAppDo();
			((CrdWznmPst::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTLISTDATA) {
			req->dpchapp = new PnlWznmPstList::DpchAppData();
			((PnlWznmPstList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTLISTDO) {
			req->dpchapp = new PnlWznmPstList::DpchAppDo();
			((PnlWznmPstList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMPSTRECDO) {
			req->dpchapp = new PnlWznmPstRec::DpchAppDo();
			((PnlWznmPstRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCODETAILDATA) {
			req->dpchapp = new PnlWznmQcoDetail::DpchAppData();
			((PnlWznmQcoDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCODETAILDO) {
			req->dpchapp = new PnlWznmQcoDetail::DpchAppDo();
			((PnlWznmQcoDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCODO) {
			req->dpchapp = new CrdWznmQco::DpchAppDo();
			((CrdWznmQco::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCOLISTDATA) {
			req->dpchapp = new PnlWznmQcoList::DpchAppData();
			((PnlWznmQcoList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCOLISTDO) {
			req->dpchapp = new PnlWznmQcoList::DpchAppDo();
			((PnlWznmQcoList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCORECDO) {
			req->dpchapp = new PnlWznmQcoRec::DpchAppDo();
			((PnlWznmQcoRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCOREF1NCONTROLDATA) {
			req->dpchapp = new PnlWznmQcoRef1NControl::DpchAppData();
			((PnlWznmQcoRef1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQCOREF1NCONTROLDO) {
			req->dpchapp = new PnlWznmQcoRef1NControl::DpchAppDo();
			((PnlWznmQcoRef1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDDETAILDATA) {
			req->dpchapp = new PnlWznmQmdDetail::DpchAppData();
			((PnlWznmQmdDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDDETAILDO) {
			req->dpchapp = new PnlWznmQmdDetail::DpchAppDo();
			((PnlWznmQmdDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDDO) {
			req->dpchapp = new CrdWznmQmd::DpchAppDo();
			((CrdWznmQmd::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDLISTDATA) {
			req->dpchapp = new PnlWznmQmdList::DpchAppData();
			((PnlWznmQmdList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDLISTDO) {
			req->dpchapp = new PnlWznmQmdList::DpchAppDo();
			((PnlWznmQmdList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQMDRECDO) {
			req->dpchapp = new PnlWznmQmdRec::DpchAppDo();
			((PnlWznmQmdRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRY1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmQry1NQuerymod::DpchAppData();
			((PnlWznmQry1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRY1NQUERYMODDO) {
			req->dpchapp = new PnlWznmQry1NQuerymod::DpchAppDo();
			((PnlWznmQry1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYACLAUSEDATA) {
			req->dpchapp = new PnlWznmQryAClause::DpchAppData();
			((PnlWznmQryAClause::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYACLAUSEDO) {
			req->dpchapp = new PnlWznmQryAClause::DpchAppDo();
			((PnlWznmQryAClause::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYAORDERDATA) {
			req->dpchapp = new PnlWznmQryAOrder::DpchAppData();
			((PnlWznmQryAOrder::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYAORDERDO) {
			req->dpchapp = new PnlWznmQryAOrder::DpchAppDo();
			((PnlWznmQryAOrder::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYDETAILDATA) {
			req->dpchapp = new PnlWznmQryDetail::DpchAppData();
			((PnlWznmQryDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYDETAILDO) {
			req->dpchapp = new PnlWznmQryDetail::DpchAppDo();
			((PnlWznmQryDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYDO) {
			req->dpchapp = new CrdWznmQry::DpchAppDo();
			((CrdWznmQry::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYLISTDATA) {
			req->dpchapp = new PnlWznmQryList::DpchAppData();
			((PnlWznmQryList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYLISTDO) {
			req->dpchapp = new PnlWznmQryList::DpchAppDo();
			((PnlWznmQryList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNDIALOGDATA) {
			req->dpchapp = new PnlWznmQryMNDialog::DpchAppData();
			((PnlWznmQryMNDialog::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNDIALOGDO) {
			req->dpchapp = new PnlWznmQryMNDialog::DpchAppDo();
			((PnlWznmQryMNDialog::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNPANELDATA) {
			req->dpchapp = new PnlWznmQryMNPanel::DpchAppData();
			((PnlWznmQryMNPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNPANELDO) {
			req->dpchapp = new PnlWznmQryMNPanel::DpchAppDo();
			((PnlWznmQryMNPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNTABLEDATA) {
			req->dpchapp = new PnlWznmQryMNTable::DpchAppData();
			((PnlWznmQryMNTable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYMNTABLEDO) {
			req->dpchapp = new PnlWznmQryMNTable::DpchAppDo();
			((PnlWznmQryMNTable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYQRY1NQUERYCOLDATA) {
			req->dpchapp = new PnlWznmQryQry1NQuerycol::DpchAppData();
			((PnlWznmQryQry1NQuerycol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYQRY1NQUERYCOLDO) {
			req->dpchapp = new PnlWznmQryQry1NQuerycol::DpchAppDo();
			((PnlWznmQryQry1NQuerycol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYRECDO) {
			req->dpchapp = new PnlWznmQryRec::DpchAppDo();
			((PnlWznmQryRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYSUP1NQUERYDATA) {
			req->dpchapp = new PnlWznmQrySup1NQuery::DpchAppData();
			((PnlWznmQrySup1NQuery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMQRYSUP1NQUERYDO) {
			req->dpchapp = new PnlWznmQrySup1NQuery::DpchAppDo();
			((PnlWznmQrySup1NQuery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMREL1NTABLECOLDATA) {
			req->dpchapp = new PnlWznmRel1NTablecol::DpchAppData();
			((PnlWznmRel1NTablecol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMREL1NTABLECOLDO) {
			req->dpchapp = new PnlWznmRel1NTablecol::DpchAppDo();
			((PnlWznmRel1NTablecol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELATITLEDATA) {
			req->dpchapp = new PnlWznmRelATitle::DpchAppData();
			((PnlWznmRelATitle::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELATITLEDO) {
			req->dpchapp = new PnlWznmRelATitle::DpchAppDo();
			((PnlWznmRelATitle::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELDETAILDATA) {
			req->dpchapp = new PnlWznmRelDetail::DpchAppData();
			((PnlWznmRelDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELDETAILDO) {
			req->dpchapp = new PnlWznmRelDetail::DpchAppDo();
			((PnlWznmRelDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELDO) {
			req->dpchapp = new CrdWznmRel::DpchAppDo();
			((CrdWznmRel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELLISTDATA) {
			req->dpchapp = new PnlWznmRelList::DpchAppData();
			((PnlWznmRelList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELLISTDO) {
			req->dpchapp = new PnlWznmRelList::DpchAppDo();
			((PnlWznmRelList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELRECDO) {
			req->dpchapp = new PnlWznmRelRec::DpchAppDo();
			((PnlWznmRelRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NCONTROLDATA) {
			req->dpchapp = new PnlWznmRelRef1NControl::DpchAppData();
			((PnlWznmRelRef1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NCONTROLDO) {
			req->dpchapp = new PnlWznmRelRef1NControl::DpchAppDo();
			((PnlWznmRelRef1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NDIALOGDATA) {
			req->dpchapp = new PnlWznmRelRef1NDialog::DpchAppData();
			((PnlWznmRelRef1NDialog::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NDIALOGDO) {
			req->dpchapp = new PnlWznmRelRef1NDialog::DpchAppDo();
			((PnlWznmRelRef1NDialog::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NPANELDATA) {
			req->dpchapp = new PnlWznmRelRef1NPanel::DpchAppData();
			((PnlWznmRelRef1NPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELREF1NPANELDO) {
			req->dpchapp = new PnlWznmRelRef1NPanel::DpchAppDo();
			((PnlWznmRelRef1NPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELSUP1NRELATIONDATA) {
			req->dpchapp = new PnlWznmRelSup1NRelation::DpchAppData();
			((PnlWznmRelSup1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRELSUP1NRELATIONDO) {
			req->dpchapp = new PnlWznmRelSup1NRelation::DpchAppDo();
			((PnlWznmRelSup1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRESUME) {
			req->dpchapp = new DpchAppWznmResume();
			((DpchAppWznmResume*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDETAILDATA) {
			req->dpchapp = new PnlWznmRlsDetail::DpchAppData();
			((PnlWznmRlsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDETAILDO) {
			req->dpchapp = new PnlWznmRlsDetail::DpchAppDo();
			((PnlWznmRlsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSDO) {
			req->dpchapp = new CrdWznmRls::DpchAppDo();
			((CrdWznmRls::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSLISTDATA) {
			req->dpchapp = new PnlWznmRlsList::DpchAppData();
			((PnlWznmRlsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSLISTDO) {
			req->dpchapp = new PnlWznmRlsList::DpchAppDo();
			((PnlWznmRlsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRLSRECDO) {
			req->dpchapp = new PnlWznmRlsRec::DpchAppDo();
			((PnlWznmRlsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJ1NRTBLOCKDATA) {
			req->dpchapp = new PnlWznmRtj1NRtblock::DpchAppData();
			((PnlWznmRtj1NRtblock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJ1NRTBLOCKDO) {
			req->dpchapp = new PnlWznmRtj1NRtblock::DpchAppDo();
			((PnlWznmRtj1NRtblock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJ1NRTDPCHDATA) {
			req->dpchapp = new PnlWznmRtj1NRtdpch::DpchAppData();
			((PnlWznmRtj1NRtdpch::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJ1NRTDPCHDO) {
			req->dpchapp = new PnlWznmRtj1NRtdpch::DpchAppDo();
			((PnlWznmRtj1NRtdpch::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJDETAILDATA) {
			req->dpchapp = new PnlWznmRtjDetail::DpchAppData();
			((PnlWznmRtjDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJDETAILDO) {
			req->dpchapp = new PnlWznmRtjDetail::DpchAppDo();
			((PnlWznmRtjDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJDO) {
			req->dpchapp = new CrdWznmRtj::DpchAppDo();
			((CrdWznmRtj::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJLISTDATA) {
			req->dpchapp = new PnlWznmRtjList::DpchAppData();
			((PnlWznmRtjList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJLISTDO) {
			req->dpchapp = new PnlWznmRtjList::DpchAppDo();
			((PnlWznmRtjList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJRECDO) {
			req->dpchapp = new PnlWznmRtjRec::DpchAppDo();
			((PnlWznmRtjRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJSUP1NRTJOBDATA) {
			req->dpchapp = new PnlWznmRtjSup1NRtjob::DpchAppData();
			((PnlWznmRtjSup1NRtjob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMRTJSUP1NRTJOBDO) {
			req->dpchapp = new PnlWznmRtjSup1NRtjob::DpchAppDo();
			((PnlWznmRtjSup1NRtjob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBS1NSTUBDATA) {
			req->dpchapp = new PnlWznmSbs1NStub::DpchAppData();
			((PnlWznmSbs1NStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBS1NSTUBDO) {
			req->dpchapp = new PnlWznmSbs1NStub::DpchAppDo();
			((PnlWznmSbs1NStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBS1NTABLECOLDATA) {
			req->dpchapp = new PnlWznmSbs1NTablecol::DpchAppData();
			((PnlWznmSbs1NTablecol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBS1NTABLECOLDO) {
			req->dpchapp = new PnlWznmSbs1NTablecol::DpchAppDo();
			((PnlWznmSbs1NTablecol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSASBMNSUBSETDATA) {
			req->dpchapp = new PnlWznmSbsAsbMNSubset::DpchAppData();
			((PnlWznmSbsAsbMNSubset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSASBMNSUBSETDO) {
			req->dpchapp = new PnlWznmSbsAsbMNSubset::DpchAppDo();
			((PnlWznmSbsAsbMNSubset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSATITLEDATA) {
			req->dpchapp = new PnlWznmSbsATitle::DpchAppData();
			((PnlWznmSbsATitle::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSATITLEDO) {
			req->dpchapp = new PnlWznmSbsATitle::DpchAppDo();
			((PnlWznmSbsATitle::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSBSBMNSUBSETDATA) {
			req->dpchapp = new PnlWznmSbsBsbMNSubset::DpchAppData();
			((PnlWznmSbsBsbMNSubset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSBSBMNSUBSETDO) {
			req->dpchapp = new PnlWznmSbsBsbMNSubset::DpchAppDo();
			((PnlWznmSbsBsbMNSubset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSDETAILDATA) {
			req->dpchapp = new PnlWznmSbsDetail::DpchAppData();
			((PnlWznmSbsDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSDETAILDO) {
			req->dpchapp = new PnlWznmSbsDetail::DpchAppDo();
			((PnlWznmSbsDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSDO) {
			req->dpchapp = new CrdWznmSbs::DpchAppDo();
			((CrdWznmSbs::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSFRS1NRELATIONDATA) {
			req->dpchapp = new PnlWznmSbsFrs1NRelation::DpchAppData();
			((PnlWznmSbsFrs1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSFRS1NRELATIONDO) {
			req->dpchapp = new PnlWznmSbsFrs1NRelation::DpchAppDo();
			((PnlWznmSbsFrs1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSLISTDATA) {
			req->dpchapp = new PnlWznmSbsList::DpchAppData();
			((PnlWznmSbsList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSLISTDO) {
			req->dpchapp = new PnlWznmSbsList::DpchAppDo();
			((PnlWznmSbsList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSPST1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmSbsPst1NQuerymod::DpchAppData();
			((PnlWznmSbsPst1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSPST1NQUERYMODDO) {
			req->dpchapp = new PnlWznmSbsPst1NQuerymod::DpchAppDo();
			((PnlWznmSbsPst1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSRECDO) {
			req->dpchapp = new PnlWznmSbsRec::DpchAppDo();
			((PnlWznmSbsRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSTOS1NRELATIONDATA) {
			req->dpchapp = new PnlWznmSbsTos1NRelation::DpchAppData();
			((PnlWznmSbsTos1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSBSTOS1NRELATIONDO) {
			req->dpchapp = new PnlWznmSbsTos1NRelation::DpchAppDo();
			((PnlWznmSbsTos1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQDETAILDATA) {
			req->dpchapp = new PnlWznmSeqDetail::DpchAppData();
			((PnlWznmSeqDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQDETAILDO) {
			req->dpchapp = new PnlWznmSeqDetail::DpchAppDo();
			((PnlWznmSeqDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQDO) {
			req->dpchapp = new CrdWznmSeq::DpchAppDo();
			((CrdWznmSeq::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQLISTDATA) {
			req->dpchapp = new PnlWznmSeqList::DpchAppData();
			((PnlWznmSeqList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQLISTDO) {
			req->dpchapp = new PnlWznmSeqList::DpchAppDo();
			((PnlWznmSeqList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQRECDO) {
			req->dpchapp = new PnlWznmSeqRec::DpchAppDo();
			((PnlWznmSeqRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQSEQ1NSTATEDATA) {
			req->dpchapp = new PnlWznmSeqSeq1NState::DpchAppData();
			((PnlWznmSeqSeq1NState::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSEQSEQ1NSTATEDO) {
			req->dpchapp = new PnlWznmSeqSeq1NState::DpchAppDo();
			((PnlWznmSeqSeq1NState::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGE1NSENSITIVITYDATA) {
			req->dpchapp = new PnlWznmSge1NSensitivity::DpchAppData();
			((PnlWznmSge1NSensitivity::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGE1NSENSITIVITYDO) {
			req->dpchapp = new PnlWznmSge1NSensitivity::DpchAppDo();
			((PnlWznmSge1NSensitivity::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGEDETAILDATA) {
			req->dpchapp = new PnlWznmSgeDetail::DpchAppData();
			((PnlWznmSgeDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGEDETAILDO) {
			req->dpchapp = new PnlWznmSgeDetail::DpchAppDo();
			((PnlWznmSgeDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGEDO) {
			req->dpchapp = new CrdWznmSge::DpchAppDo();
			((CrdWznmSge::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGELISTDATA) {
			req->dpchapp = new PnlWznmSgeList::DpchAppData();
			((PnlWznmSgeList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGELISTDO) {
			req->dpchapp = new PnlWznmSgeList::DpchAppDo();
			((PnlWznmSgeList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGERECDO) {
			req->dpchapp = new PnlWznmSgeRec::DpchAppDo();
			((PnlWznmSgeRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGESQKMNSTUBDATA) {
			req->dpchapp = new PnlWznmSgeSqkMNStub::DpchAppData();
			((PnlWznmSgeSqkMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSGESQKMNSTUBDO) {
			req->dpchapp = new PnlWznmSgeSqkMNStub::DpchAppDo();
			((PnlWznmSgeSqkMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBDETAILDATA) {
			req->dpchapp = new PnlWznmStbDetail::DpchAppData();
			((PnlWznmStbDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBDETAILDO) {
			req->dpchapp = new PnlWznmStbDetail::DpchAppDo();
			((PnlWznmStbDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBDO) {
			req->dpchapp = new CrdWznmStb::DpchAppDo();
			((CrdWznmStb::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBLISTDATA) {
			req->dpchapp = new PnlWznmStbList::DpchAppData();
			((PnlWznmStbList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBLISTDO) {
			req->dpchapp = new PnlWznmStbList::DpchAppDo();
			((PnlWznmStbList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBMNCALLDATA) {
			req->dpchapp = new PnlWznmStbMNCall::DpchAppData();
			((PnlWznmStbMNCall::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBMNCALLDO) {
			req->dpchapp = new PnlWznmStbMNCall::DpchAppDo();
			((PnlWznmStbMNCall::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBMNSQUAWKDATA) {
			req->dpchapp = new PnlWznmStbMNSquawk::DpchAppData();
			((PnlWznmStbMNSquawk::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBMNSQUAWKDO) {
			req->dpchapp = new PnlWznmStbMNSquawk::DpchAppDo();
			((PnlWznmStbMNSquawk::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBRECDO) {
			req->dpchapp = new PnlWznmStbRec::DpchAppDo();
			((PnlWznmStbRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBSUBMNSTUBDATA) {
			req->dpchapp = new PnlWznmStbSubMNStub::DpchAppData();
			((PnlWznmStbSubMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBSUBMNSTUBDO) {
			req->dpchapp = new PnlWznmStbSubMNStub::DpchAppDo();
			((PnlWznmStbSubMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBSUPMNSTUBDATA) {
			req->dpchapp = new PnlWznmStbSupMNStub::DpchAppData();
			((PnlWznmStbSupMNStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTBSUPMNSTUBDO) {
			req->dpchapp = new PnlWznmStbSupMNStub::DpchAppDo();
			((PnlWznmStbSupMNStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEASTEPDATA) {
			req->dpchapp = new PnlWznmSteAStep::DpchAppData();
			((PnlWznmSteAStep::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEASTEPDO) {
			req->dpchapp = new PnlWznmSteAStep::DpchAppDo();
			((PnlWznmSteAStep::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEDETAILDATA) {
			req->dpchapp = new PnlWznmSteDetail::DpchAppData();
			((PnlWznmSteDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEDETAILDO) {
			req->dpchapp = new PnlWznmSteDetail::DpchAppDo();
			((PnlWznmSteDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTEDO) {
			req->dpchapp = new CrdWznmSte::DpchAppDo();
			((CrdWznmSte::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTELISTDATA) {
			req->dpchapp = new PnlWznmSteList::DpchAppData();
			((PnlWznmSteList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTELISTDO) {
			req->dpchapp = new PnlWznmSteList::DpchAppDo();
			((PnlWznmSteList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMSTERECDO) {
			req->dpchapp = new PnlWznmSteRec::DpchAppDo();
			((PnlWznmSteRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGDETAILDATA) {
			req->dpchapp = new PnlWznmTagDetail::DpchAppData();
			((PnlWznmTagDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGDETAILDO) {
			req->dpchapp = new PnlWznmTagDetail::DpchAppDo();
			((PnlWznmTagDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGDO) {
			req->dpchapp = new CrdWznmTag::DpchAppDo();
			((CrdWznmTag::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGLISTDATA) {
			req->dpchapp = new PnlWznmTagList::DpchAppData();
			((PnlWznmTagList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGLISTDO) {
			req->dpchapp = new PnlWznmTagList::DpchAppDo();
			((PnlWznmTagList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTAGRECDO) {
			req->dpchapp = new PnlWznmTagRec::DpchAppDo();
			((PnlWznmTagRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NCHECKDATA) {
			req->dpchapp = new PnlWznmTbl1NCheck::DpchAppData();
			((PnlWznmTbl1NCheck::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NCHECKDO) {
			req->dpchapp = new PnlWznmTbl1NCheck::DpchAppDo();
			((PnlWznmTbl1NCheck::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NIMPEXPDATA) {
			req->dpchapp = new PnlWznmTbl1NImpexp::DpchAppData();
			((PnlWznmTbl1NImpexp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NIMPEXPDO) {
			req->dpchapp = new PnlWznmTbl1NImpexp::DpchAppDo();
			((PnlWznmTbl1NImpexp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NSTUBDATA) {
			req->dpchapp = new PnlWznmTbl1NStub::DpchAppData();
			((PnlWznmTbl1NStub::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NSTUBDO) {
			req->dpchapp = new PnlWznmTbl1NStub::DpchAppDo();
			((PnlWznmTbl1NStub::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NSUBSETDATA) {
			req->dpchapp = new PnlWznmTbl1NSubset::DpchAppData();
			((PnlWznmTbl1NSubset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBL1NSUBSETDO) {
			req->dpchapp = new PnlWznmTbl1NSubset::DpchAppDo();
			((PnlWznmTbl1NSubset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLALOADFCTDATA) {
			req->dpchapp = new PnlWznmTblALoadfct::DpchAppData();
			((PnlWznmTblALoadfct::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLALOADFCTDO) {
			req->dpchapp = new PnlWznmTblALoadfct::DpchAppDo();
			((PnlWznmTblALoadfct::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLATITLEDATA) {
			req->dpchapp = new PnlWznmTblATitle::DpchAppData();
			((PnlWznmTblATitle::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLATITLEDO) {
			req->dpchapp = new PnlWznmTblATitle::DpchAppDo();
			((PnlWznmTblATitle::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLDETAILDATA) {
			req->dpchapp = new PnlWznmTblDetail::DpchAppData();
			((PnlWznmTblDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLDETAILDO) {
			req->dpchapp = new PnlWznmTblDetail::DpchAppDo();
			((PnlWznmTblDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLDO) {
			req->dpchapp = new CrdWznmTbl::DpchAppDo();
			((CrdWznmTbl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLFCT1NTABLECOLDATA) {
			req->dpchapp = new PnlWznmTblFct1NTablecol::DpchAppData();
			((PnlWznmTblFct1NTablecol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLFCT1NTABLECOLDO) {
			req->dpchapp = new PnlWznmTblFct1NTablecol::DpchAppDo();
			((PnlWznmTblFct1NTablecol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLFR1NRELATIONDATA) {
			req->dpchapp = new PnlWznmTblFr1NRelation::DpchAppData();
			((PnlWznmTblFr1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLFR1NRELATIONDO) {
			req->dpchapp = new PnlWznmTblFr1NRelation::DpchAppDo();
			((PnlWznmTblFr1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLHK1NVECTORDATA) {
			req->dpchapp = new PnlWznmTblHk1NVector::DpchAppData();
			((PnlWznmTblHk1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLHK1NVECTORDO) {
			req->dpchapp = new PnlWznmTblHk1NVector::DpchAppDo();
			((PnlWznmTblHk1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLLISTDATA) {
			req->dpchapp = new PnlWznmTblList::DpchAppData();
			((PnlWznmTblList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLLISTDO) {
			req->dpchapp = new PnlWznmTblList::DpchAppDo();
			((PnlWznmTblList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLMNQUERYDATA) {
			req->dpchapp = new PnlWznmTblMNQuery::DpchAppData();
			((PnlWznmTblMNQuery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLMNQUERYDO) {
			req->dpchapp = new PnlWznmTblMNQuery::DpchAppDo();
			((PnlWznmTblMNQuery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLMNVECTORDATA) {
			req->dpchapp = new PnlWznmTblMNVector::DpchAppData();
			((PnlWznmTblMNVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLMNVECTORDO) {
			req->dpchapp = new PnlWznmTblMNVector::DpchAppDo();
			((PnlWznmTblMNVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLPST1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmTblPst1NQuerymod::DpchAppData();
			((PnlWznmTblPst1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLPST1NQUERYMODDO) {
			req->dpchapp = new PnlWznmTblPst1NQuerymod::DpchAppDo();
			((PnlWznmTblPst1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLRECDO) {
			req->dpchapp = new PnlWznmTblRec::DpchAppDo();
			((PnlWznmTblRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NCALLDATA) {
			req->dpchapp = new PnlWznmTblRef1NCall::DpchAppData();
			((PnlWznmTblRef1NCall::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NCALLDO) {
			req->dpchapp = new PnlWznmTblRef1NCall::DpchAppDo();
			((PnlWznmTblRef1NCall::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NDIALOGDATA) {
			req->dpchapp = new PnlWznmTblRef1NDialog::DpchAppData();
			((PnlWznmTblRef1NDialog::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NDIALOGDO) {
			req->dpchapp = new PnlWznmTblRef1NDialog::DpchAppDo();
			((PnlWznmTblRef1NDialog::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NPANELDATA) {
			req->dpchapp = new PnlWznmTblRef1NPanel::DpchAppData();
			((PnlWznmTblRef1NPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NPANELDO) {
			req->dpchapp = new PnlWznmTblRef1NPanel::DpchAppDo();
			((PnlWznmTblRef1NPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmTblRef1NQuerymod::DpchAppData();
			((PnlWznmTblRef1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NQUERYMODDO) {
			req->dpchapp = new PnlWznmTblRef1NQuerymod::DpchAppDo();
			((PnlWznmTblRef1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NRTBLOCKDATA) {
			req->dpchapp = new PnlWznmTblRef1NRtblock::DpchAppData();
			((PnlWznmTblRef1NRtblock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLREF1NRTBLOCKDO) {
			req->dpchapp = new PnlWznmTblRef1NRtblock::DpchAppDo();
			((PnlWznmTblRef1NRtblock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLSRC1NFEEDDATA) {
			req->dpchapp = new PnlWznmTblSrc1NFeed::DpchAppData();
			((PnlWznmTblSrc1NFeed::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLSRC1NFEEDDO) {
			req->dpchapp = new PnlWznmTblSrc1NFeed::DpchAppDo();
			((PnlWznmTblSrc1NFeed::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLTBL1NTABLECOLDATA) {
			req->dpchapp = new PnlWznmTblTbl1NTablecol::DpchAppData();
			((PnlWznmTblTbl1NTablecol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLTBL1NTABLECOLDO) {
			req->dpchapp = new PnlWznmTblTbl1NTablecol::DpchAppDo();
			((PnlWznmTblTbl1NTablecol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLTO1NRELATIONDATA) {
			req->dpchapp = new PnlWznmTblTo1NRelation::DpchAppData();
			((PnlWznmTblTo1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTBLTO1NRELATIONDO) {
			req->dpchapp = new PnlWznmTblTo1NRelation::DpchAppDo();
			((PnlWznmTblTo1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NCHECKDATA) {
			req->dpchapp = new PnlWznmTco1NCheck::DpchAppData();
			((PnlWznmTco1NCheck::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NCHECKDO) {
			req->dpchapp = new PnlWznmTco1NCheck::DpchAppDo();
			((PnlWznmTco1NCheck::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NIMPEXPCOLDATA) {
			req->dpchapp = new PnlWznmTco1NImpexpcol::DpchAppData();
			((PnlWznmTco1NImpexpcol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NIMPEXPCOLDO) {
			req->dpchapp = new PnlWznmTco1NImpexpcol::DpchAppDo();
			((PnlWznmTco1NImpexpcol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NQUERYCOLDATA) {
			req->dpchapp = new PnlWznmTco1NQuerycol::DpchAppData();
			((PnlWznmTco1NQuerycol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCO1NQUERYCOLDO) {
			req->dpchapp = new PnlWznmTco1NQuerycol::DpchAppDo();
			((PnlWznmTco1NQuerycol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOATITLEDATA) {
			req->dpchapp = new PnlWznmTcoATitle::DpchAppData();
			((PnlWznmTcoATitle::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOATITLEDO) {
			req->dpchapp = new PnlWznmTcoATitle::DpchAppDo();
			((PnlWznmTcoATitle::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCODETAILDATA) {
			req->dpchapp = new PnlWznmTcoDetail::DpchAppData();
			((PnlWznmTcoDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCODETAILDO) {
			req->dpchapp = new PnlWznmTcoDetail::DpchAppDo();
			((PnlWznmTcoDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCODO) {
			req->dpchapp = new CrdWznmTco::DpchAppDo();
			((CrdWznmTco::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOLISTDATA) {
			req->dpchapp = new PnlWznmTcoList::DpchAppData();
			((PnlWznmTcoList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOLISTDO) {
			req->dpchapp = new PnlWznmTcoList::DpchAppDo();
			((PnlWznmTcoList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCORECDO) {
			req->dpchapp = new PnlWznmTcoRec::DpchAppDo();
			((PnlWznmTcoRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOREF1NCONTROLDATA) {
			req->dpchapp = new PnlWznmTcoRef1NControl::DpchAppData();
			((PnlWznmTcoRef1NControl::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOREF1NCONTROLDO) {
			req->dpchapp = new PnlWznmTcoRef1NControl::DpchAppDo();
			((PnlWznmTcoRef1NControl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOREF1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmTcoRef1NQuerymod::DpchAppData();
			((PnlWznmTcoRef1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMTCOREF1NQUERYMODDO) {
			req->dpchapp = new PnlWznmTcoRef1NQuerymod::DpchAppDo();
			((PnlWznmTcoRef1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGAACCESSDATA) {
			req->dpchapp = new PnlWznmUsgAAccess::DpchAppData();
			((PnlWznmUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGAACCESSDO) {
			req->dpchapp = new PnlWznmUsgAAccess::DpchAppDo();
			((PnlWznmUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGDETAILDATA) {
			req->dpchapp = new PnlWznmUsgDetail::DpchAppData();
			((PnlWznmUsgDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGDETAILDO) {
			req->dpchapp = new PnlWznmUsgDetail::DpchAppDo();
			((PnlWznmUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGDO) {
			req->dpchapp = new CrdWznmUsg::DpchAppDo();
			((CrdWznmUsg::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGLISTDATA) {
			req->dpchapp = new PnlWznmUsgList::DpchAppData();
			((PnlWznmUsgList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGLISTDO) {
			req->dpchapp = new PnlWznmUsgList::DpchAppDo();
			((PnlWznmUsgList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGMNUSERDATA) {
			req->dpchapp = new PnlWznmUsgMNUser::DpchAppData();
			((PnlWznmUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGMNUSERDO) {
			req->dpchapp = new PnlWznmUsgMNUser::DpchAppDo();
			((PnlWznmUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSGRECDO) {
			req->dpchapp = new PnlWznmUsgRec::DpchAppDo();
			((PnlWznmUsgRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSR1NSESSIONDATA) {
			req->dpchapp = new PnlWznmUsr1NSession::DpchAppData();
			((PnlWznmUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSR1NSESSIONDO) {
			req->dpchapp = new PnlWznmUsr1NSession::DpchAppDo();
			((PnlWznmUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRAACCESSDATA) {
			req->dpchapp = new PnlWznmUsrAAccess::DpchAppData();
			((PnlWznmUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRAACCESSDO) {
			req->dpchapp = new PnlWznmUsrAAccess::DpchAppDo();
			((PnlWznmUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRDETAILDATA) {
			req->dpchapp = new PnlWznmUsrDetail::DpchAppData();
			((PnlWznmUsrDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRDETAILDO) {
			req->dpchapp = new PnlWznmUsrDetail::DpchAppDo();
			((PnlWznmUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRDO) {
			req->dpchapp = new CrdWznmUsr::DpchAppDo();
			((CrdWznmUsr::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRLISTDATA) {
			req->dpchapp = new PnlWznmUsrList::DpchAppData();
			((PnlWznmUsrList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRLISTDO) {
			req->dpchapp = new PnlWznmUsrList::DpchAppDo();
			((PnlWznmUsrList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRMNUSERGROUPDATA) {
			req->dpchapp = new PnlWznmUsrMNUsergroup::DpchAppData();
			((PnlWznmUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRMNUSERGROUPDO) {
			req->dpchapp = new PnlWznmUsrMNUsergroup::DpchAppDo();
			((PnlWznmUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUSRRECDO) {
			req->dpchapp = new PnlWznmUsrRec::DpchAppDo();
			((PnlWznmUsrRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMUTLDO) {
			req->dpchapp = new CrdWznmUtl::DpchAppDo();
			((CrdWznmUtl::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECATITLEDATA) {
			req->dpchapp = new PnlWznmVecATitle::DpchAppData();
			((PnlWznmVecATitle::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECATITLEDO) {
			req->dpchapp = new PnlWznmVecATitle::DpchAppDo();
			((PnlWznmVecATitle::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECDETAILDATA) {
			req->dpchapp = new PnlWznmVecDetail::DpchAppData();
			((PnlWznmVecDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECDETAILDO) {
			req->dpchapp = new PnlWznmVecDetail::DpchAppDo();
			((PnlWznmVecDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECDO) {
			req->dpchapp = new CrdWznmVec::DpchAppDo();
			((CrdWznmVec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECFCT1NTABLECOLDATA) {
			req->dpchapp = new PnlWznmVecFct1NTablecol::DpchAppData();
			((PnlWznmVecFct1NTablecol::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECFCT1NTABLECOLDO) {
			req->dpchapp = new PnlWznmVecFct1NTablecol::DpchAppDo();
			((PnlWznmVecFct1NTablecol::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECLISTDATA) {
			req->dpchapp = new PnlWznmVecList::DpchAppData();
			((PnlWznmVecList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECLISTDO) {
			req->dpchapp = new PnlWznmVecList::DpchAppDo();
			((PnlWznmVecList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECMNTABLEDATA) {
			req->dpchapp = new PnlWznmVecMNTable::DpchAppData();
			((PnlWznmVecMNTable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECMNTABLEDO) {
			req->dpchapp = new PnlWznmVecMNTable::DpchAppDo();
			((PnlWznmVecMNTable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECPST1NQUERYMODDATA) {
			req->dpchapp = new PnlWznmVecPst1NQuerymod::DpchAppData();
			((PnlWznmVecPst1NQuerymod::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECPST1NQUERYMODDO) {
			req->dpchapp = new PnlWznmVecPst1NQuerymod::DpchAppDo();
			((PnlWznmVecPst1NQuerymod::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECRECDO) {
			req->dpchapp = new PnlWznmVecRec::DpchAppDo();
			((PnlWznmVecRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECREF1NPANELDATA) {
			req->dpchapp = new PnlWznmVecRef1NPanel::DpchAppData();
			((PnlWznmVecRef1NPanel::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECREF1NPANELDO) {
			req->dpchapp = new PnlWznmVecRef1NPanel::DpchAppDo();
			((PnlWznmVecRef1NPanel::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECSRC1NFEEDDATA) {
			req->dpchapp = new PnlWznmVecSrc1NFeed::DpchAppData();
			((PnlWznmVecSrc1NFeed::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECSRC1NFEEDDO) {
			req->dpchapp = new PnlWznmVecSrc1NFeed::DpchAppDo();
			((PnlWznmVecSrc1NFeed::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECVEC1NVECTORITEMDATA) {
			req->dpchapp = new PnlWznmVecVec1NVectoritem::DpchAppData();
			((PnlWznmVecVec1NVectoritem::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVECVEC1NVECTORITEMDO) {
			req->dpchapp = new PnlWznmVecVec1NVectoritem::DpchAppDo();
			((PnlWznmVecVec1NVectoritem::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NBLOCKDATA) {
			req->dpchapp = new PnlWznmVer1NBlock::DpchAppData();
			((PnlWznmVer1NBlock::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NBLOCKDO) {
			req->dpchapp = new PnlWznmVer1NBlock::DpchAppDo();
			((PnlWznmVer1NBlock::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCALLDATA) {
			req->dpchapp = new PnlWznmVer1NCall::DpchAppData();
			((PnlWznmVer1NCall::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCALLDO) {
			req->dpchapp = new PnlWznmVer1NCall::DpchAppDo();
			((PnlWznmVer1NCall::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCAPABILITYDATA) {
			req->dpchapp = new PnlWznmVer1NCapability::DpchAppData();
			((PnlWznmVer1NCapability::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCAPABILITYDO) {
			req->dpchapp = new PnlWznmVer1NCapability::DpchAppDo();
			((PnlWznmVer1NCapability::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCOMPONENTDATA) {
			req->dpchapp = new PnlWznmVer1NComponent::DpchAppData();
			((PnlWznmVer1NComponent::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NCOMPONENTDO) {
			req->dpchapp = new PnlWznmVer1NComponent::DpchAppDo();
			((PnlWznmVer1NComponent::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NIMPEXPCPLXDATA) {
			req->dpchapp = new PnlWznmVer1NImpexpcplx::DpchAppData();
			((PnlWznmVer1NImpexpcplx::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NIMPEXPCPLXDO) {
			req->dpchapp = new PnlWznmVer1NImpexpcplx::DpchAppDo();
			((PnlWznmVer1NImpexpcplx::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NJOBDATA) {
			req->dpchapp = new PnlWznmVer1NJob::DpchAppData();
			((PnlWznmVer1NJob::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NJOBDO) {
			req->dpchapp = new PnlWznmVer1NJob::DpchAppDo();
			((PnlWznmVer1NJob::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NOPPACKDATA) {
			req->dpchapp = new PnlWznmVer1NOppack::DpchAppData();
			((PnlWznmVer1NOppack::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NOPPACKDO) {
			req->dpchapp = new PnlWznmVer1NOppack::DpchAppDo();
			((PnlWznmVer1NOppack::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NPRESETDATA) {
			req->dpchapp = new PnlWznmVer1NPreset::DpchAppData();
			((PnlWznmVer1NPreset::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NPRESETDO) {
			req->dpchapp = new PnlWznmVer1NPreset::DpchAppDo();
			((PnlWznmVer1NPreset::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NQUERYDATA) {
			req->dpchapp = new PnlWznmVer1NQuery::DpchAppData();
			((PnlWznmVer1NQuery::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NQUERYDO) {
			req->dpchapp = new PnlWznmVer1NQuery::DpchAppDo();
			((PnlWznmVer1NQuery::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NRELATIONDATA) {
			req->dpchapp = new PnlWznmVer1NRelation::DpchAppData();
			((PnlWznmVer1NRelation::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NRELATIONDO) {
			req->dpchapp = new PnlWznmVer1NRelation::DpchAppDo();
			((PnlWznmVer1NRelation::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NTABLEDATA) {
			req->dpchapp = new PnlWznmVer1NTable::DpchAppData();
			((PnlWznmVer1NTable::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NTABLEDO) {
			req->dpchapp = new PnlWznmVer1NTable::DpchAppDo();
			((PnlWznmVer1NTable::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NVECTORDATA) {
			req->dpchapp = new PnlWznmVer1NVector::DpchAppData();
			((PnlWznmVer1NVector::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVER1NVECTORDO) {
			req->dpchapp = new PnlWznmVer1NVector::DpchAppDo();
			((PnlWznmVer1NVector::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERBVR1NVERSIONDATA) {
			req->dpchapp = new PnlWznmVerBvr1NVersion::DpchAppData();
			((PnlWznmVerBvr1NVersion::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERBVR1NVERSIONDO) {
			req->dpchapp = new PnlWznmVerBvr1NVersion::DpchAppDo();
			((PnlWznmVerBvr1NVersion::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDETAILDATA) {
			req->dpchapp = new PnlWznmVerDetail::DpchAppData();
			((PnlWznmVerDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDETAILDO) {
			req->dpchapp = new PnlWznmVerDetail::DpchAppDo();
			((PnlWznmVerDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERDO) {
			req->dpchapp = new CrdWznmVer::DpchAppDo();
			((CrdWznmVer::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERLISTDATA) {
			req->dpchapp = new PnlWznmVerList::DpchAppData();
			((PnlWznmVerList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERLISTDO) {
			req->dpchapp = new PnlWznmVerList::DpchAppDo();
			((PnlWznmVerList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERMNLOCALEDATA) {
			req->dpchapp = new PnlWznmVerMNLocale::DpchAppData();
			((PnlWznmVerMNLocale::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERMNLOCALEDO) {
			req->dpchapp = new PnlWznmVerMNLocale::DpchAppDo();
			((PnlWznmVerMNLocale::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERRECDO) {
			req->dpchapp = new PnlWznmVerRec::DpchAppDo();
			((PnlWznmVerRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERREF1NFILEDATA) {
			req->dpchapp = new PnlWznmVerRef1NFile::DpchAppData();
			((PnlWznmVerRef1NFile::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERREF1NFILEDO) {
			req->dpchapp = new PnlWznmVerRef1NFile::DpchAppDo();
			((PnlWznmVerRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NAPPDATA) {
			req->dpchapp = new PnlWznmVerVer1NApp::DpchAppData();
			((PnlWznmVerVer1NApp::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NAPPDO) {
			req->dpchapp = new PnlWznmVerVer1NApp::DpchAppDo();
			((PnlWznmVerVer1NApp::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NERRORDATA) {
			req->dpchapp = new PnlWznmVerVer1NError::DpchAppData();
			((PnlWznmVerVer1NError::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NERRORDO) {
			req->dpchapp = new PnlWznmVerVer1NError::DpchAppDo();
			((PnlWznmVerVer1NError::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NMODULEDATA) {
			req->dpchapp = new PnlWznmVerVer1NModule::DpchAppData();
			((PnlWznmVerVer1NModule::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVERVER1NMODULEDO) {
			req->dpchapp = new PnlWznmVerVer1NModule::DpchAppDo();
			((PnlWznmVerVer1NModule::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITDETAILDATA) {
			req->dpchapp = new PnlWznmVitDetail::DpchAppData();
			((PnlWznmVitDetail::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITDETAILDO) {
			req->dpchapp = new PnlWznmVitDetail::DpchAppDo();
			((PnlWznmVitDetail::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITDO) {
			req->dpchapp = new CrdWznmVit::DpchAppDo();
			((CrdWznmVit::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITLISTDATA) {
			req->dpchapp = new PnlWznmVitList::DpchAppData();
			((PnlWznmVitList::DpchAppData*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITLISTDO) {
			req->dpchapp = new PnlWznmVitList::DpchAppDo();
			((PnlWznmVitList::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		} else if (ixWznmVDpch == VecWznmVDpch::DPCHAPPWZNMVITRECDO) {
			req->dpchapp = new PnlWznmVitRec::DpchAppDo();
			((PnlWznmVitRec::DpchAppDo*) (req->dpchapp))->readXML(docctx, "/", true);
		};
	} catch (SbeException& e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWznmVDpch;
};

void WznmdAppsrv::writeDpchEng(
			XchgWznmd* xchg
			, ReqWznm* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixWznmVLocale, wr);
	} else {
		DpchEngWznmConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixWznmVLocale, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};

