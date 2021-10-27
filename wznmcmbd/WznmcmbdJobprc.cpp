/**
	* \file WznmcmbdJobprc.cpp
	* job processor for Wznm combined daemon (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wznmcmbd.h"

#include "WznmcmbdJobprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmcmbdJobprc
 ******************************************************************************/

void* WznmcmbdJobprc::run(
			void* arg
		) {
	XchgWznmcmbd* xchg = (XchgWznmcmbd*) arg;

	ReqWznm* req = NULL;
	JobWznm* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWznm dbswznm;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswznm.init(xchg->stgwznmdatabase.ixDbsVDbstype, xchg->stgwznmdatabase.dbspath, xchg->stgwznmdatabase.dbsname, xchg->stgwznmdatabase.ip,
						xchg->stgwznmdatabase.port, xchg->stgwznmdatabase.username, xchg->stgwznmdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WznmcmbdJobprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WznmcmbdJobprc", "run");

	try {
		// main loop: wait for requests
		while (true) {
			xchg->cJobprcs.lockMutex("WznmcmbdJobprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cJobprcs.wait("WznmcmbdJobprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cJobprcs.unlockMutex("WznmcmbdJobprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cJobprcs.signal("WznmcmbdJobprc", "run");

			// --- handle request
			if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
				xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

				// pass on to job
				accessJob(xchg, &dbswznm, req);

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
				if (req->dpchapp) {
					//cout << "WznmcmbdJobprc::run() DPCHAPP request:'" << VecWznmVDpch::getSref(req->dpchapp->ixWznmVDpch) << "'" << endl;
					eref = xchg->mon.eventHandleReqDpchapp(req->jref, VecWznmVDpch::getSref(req->dpchapp->ixWznmVDpch), req->dpchapp->getSrefsMask(), "");

					// pass on to job
					accessJob(xchg, &dbswznm, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngWznmAck(req->jref);
				xchg->mon.eventReplyReqDpchapp(eref, req->jref, VecWznmVDpch::getSref(req->dpcheng->ixWznmVDpch), req->dpcheng->getSrefsMask(), "");

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) {
				//cout << "WznmcmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
				xchg->mon.eventHandleReqUpload(req->jref, req->filename);

				// pass on to job
				accessJob(xchg, &dbswznm, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD) {
				eref = xchg->mon.eventHandleReqDownload(req->jref);

				// pass on to job
				accessJob(xchg, &dbswznm, req);

				xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) {
				if (req->dpchret) {
					//cout << "WznmcmbdJobprc::run() DPCHRET request: '" << VecWznmVDpch::getSref(req->dpchret->ixWznmVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					xchg->mon.eventHandleReqDpchret(req->jref, VecWznmVDpch::getSref(req->dpchret->ixWznmVDpch), "", req->dpchret->oref);

					accessJob(xchg, &dbswznm, req);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::METHOD) {
				if (req->method) {
					//cout << "WznmcmbdJobprc::run() METHOD request: '" << VecWznmVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
					xchg->mon.eventHandleReqMethod(req->jref, VecWznmVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

					// pass on to job
					accessJob(xchg, &dbswznm, req);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);

				if (job) if (req->wref >= job->wrefMin) {
					xchg->mon.eventHandleReqTimer(req->jref, req->sref);
					accessJob(xchg, &dbswznm, req);
				};

			} else if (req->ixVBasetype == ReqWznm::VecVBasetype::EXTCALL) {
				xchg->triggerCall(&dbswznm, req->call);
			};

			if ((req->ixVBasetype == ReqWznm::VecVBasetype::DPCHRET) || (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) || (req->ixVBasetype == ReqWznm::VecVBasetype::EXTCALL)) {
				// ret, timer and extcall requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};

	} catch (WznmException& e) {
		cout << e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, VecWznmVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, VecWznmVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(1);

	return(NULL);
};

void WznmcmbdJobprc::cleanup(
			void* arg
		) {
	XchgWznmcmbd* xchg = (XchgWznmcmbd*) arg;

	xchg->cJobprcs.unlockMutex("WznmcmbdJobprc", "cleanup");
};

void WznmcmbdJobprc::accessJob(
			XchgWznmcmbd* xchg
			, DbsWznm* dbswznm
			, ReqWznm* req
		) {
	time_t rawtime;

	JobWznm* job = NULL;

	if ((req->ixVBasetype == ReqWznm::VecVBasetype::CMD) || (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) || (req->ixVBasetype == ReqWznm::VecVBasetype::UPLOAD) || (req->ixVBasetype == ReqWznm::VecVBasetype::DOWNLOAD)) {
		if ((xchg->stgwznmappearance.roottterm != 0) || (xchg->stgwznmappearance.sesstterm != 0)) {
			time(&rawtime);
			xchg->triggerIxRefCall(dbswznm, VecWznmVCall::CALLWZNMREFPRESET, req->jref, VecWznmVPreset::PREWZNMTLAST, rawtime);
		};
	};

	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("WznmcmbdJobprc", "accessJob");

		req->ixWznmVLocale = job->ixWznmVLocale;
		job->handleRequest(dbswznm, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("WznmcmbdJobprc", "accessJob");
	};
};
