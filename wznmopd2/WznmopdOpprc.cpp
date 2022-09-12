/**
	* \file WznmopdOpprc.cpp
	* operation processor for Wznm operation daemon wznmopd2 (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wznmopd.h"

#include "WznmopdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmopdOpprc
 ******************************************************************************/

void* WznmopdOpprc::run(
			void* arg
		) {
	XchgWznmopd* xchg = (XchgWznmopd*) arg;

	ReqopWznm* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWznm dbswznm;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswznm.init(xchg->stgwznmdatabase.ixDbsVDbstype, xchg->stgwznmdatabase.dbspath, xchg->stgwznmdatabase.dbsname, xchg->stgwznmdatabase.ip
						, xchg->stgwznmdatabase.port, xchg->stgwznmdatabase.username, xchg->stgwznmdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WznmopdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WznmopdOpprc", "run");

	try {
		// main loop: wait for ops in execution list
		while (true) {
			xchg->cOpprcs.lockMutex("WznmopdOpprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cOpprcs.wait("WznmopdOpprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cOpprcs.unlockMutex("WznmopdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WznmopdOpprc", "run");

			// perform op corresponding to req's invoc
			if (req->dpchinv) {
				// perform op
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRWEB) {
				if (((DpchInvWznmCtpWrweb*) req->dpchinv)->srefKCustop == "WznmCtpWrwebDbeterm") req->dpchret = WznmCtpWrwebDbeterm::run(xchg, &dbswznm, (DpchInvWznmCtpWrweb*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSTKIT) {
				if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitAcv") req->dpchret = WznmCtpWrstkitAcv::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
				else if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitArm") req->dpchret = WznmCtpWrstkitArm::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
				else if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitClustmgr") req->dpchret = WznmCtpWrstkitClustmgr::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
				else if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitPrefs") req->dpchret = WznmCtpWrstkitPrefs::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSRV) {
				if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvAcv") req->dpchret = WznmCtpWrsrvAcv::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvClustmgr") req->dpchret = WznmCtpWrsrvClustmgr::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvDbeterm") req->dpchret = WznmCtpWrsrvDbeterm::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvDlgimp") req->dpchret = WznmCtpWrsrvDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvDlgloaini") req->dpchret = WznmCtpWrsrvDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvPrefs") req->dpchret = WznmCtpWrsrvPrefs::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENUI) {
				if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiAcv") req->dpchret = WznmCtpGenuiAcv::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiClustmgr") req->dpchret = WznmCtpGenuiClustmgr::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiDbeterm") req->dpchret = WznmCtpGenuiDbeterm::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiDlgimp") req->dpchret = WznmCtpGenuiDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiDlgloaini") req->dpchret = WznmCtpGenuiDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiPrefs") req->dpchret = WznmCtpGenuiPrefs::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENJTR) {
				if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrAcv") req->dpchret = WznmCtpGenjtrAcv::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrClustmgr") req->dpchret = WznmCtpGenjtrClustmgr::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrDbeterm") req->dpchret = WznmCtpGenjtrDbeterm::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrDlgimp") req->dpchret = WznmCtpGenjtrDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrDlgloaini") req->dpchret = WznmCtpGenjtrDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrPrefs") req->dpchret = WznmCtpGenjtrPrefs::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
			};
			};

			req->setStateReply();
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

void WznmopdOpprc::cleanup(
			void* arg
		) {
	XchgWznmopd* xchg = (XchgWznmopd*) arg;

	xchg->cOpprcs.unlockMutex("WznmopdOpprc", "cleanup");
};
