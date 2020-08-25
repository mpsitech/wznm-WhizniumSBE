/**
	* \file WznmcmbdOpprc.cpp
	* operation processor for Wznm combined daemon (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#include "Wznmcmbd.h"

#include "WznmcmbdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmcmbdOpprc
 ******************************************************************************/

void* WznmcmbdOpprc::run(
			void* arg
		) {
	XchgWznmcmbd* xchg = (XchgWznmcmbd*) arg;

	ReqWznm* req = NULL;
	DpchInvWznm* inv = NULL;

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
				e.vals["object"] = "WznmcmbdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WznmcmbdOpprc", "run");

	try {
		// main loop: wait for operation invocations
		while (true) {
			xchg->cOpprcs.lockMutex("WznmcmbdOpprc", "run");
			inv = xchg->pullFirstInv();

			while (!inv) {
				xchg->cOpprcs.wait("WznmcmbdOpprc", "run");
				inv = xchg->pullFirstInv();
			};

			xchg->cOpprcs.unlockMutex("WznmcmbdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WznmcmbdOpprc", "run");

			// prepare request
			req = new ReqWznm(ReqWznm::VecVBasetype::DPCHRET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI) {
				req->dpchret = WznmComplBscui::run(xchg, &dbswznm, (DpchInvWznmComplBscui*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDBS) {
				req->dpchret = WznmComplDbs::run(xchg, &dbswznm, (DpchInvWznmComplDbs*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLIEX) {
				req->dpchret = WznmComplIex::run(xchg, &dbswznm, (DpchInvWznmComplIex*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLJTR) {
				req->dpchret = WznmComplJtr::run(xchg, &dbswznm, (DpchInvWznmComplJtr*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENJTR) {
				if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrAcv") req->dpchret = WznmCtpGenjtrAcv::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrDlgimp") req->dpchret = WznmCtpGenjtrDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
				else if (((DpchInvWznmCtpGenjtr*) req->dpchinv)->srefKCustop == "WznmCtpGenjtrDlgloaini") req->dpchret = WznmCtpGenjtrDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpGenjtr*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPGENUI) {
				if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiAcv") req->dpchret = WznmCtpGenuiAcv::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiDlgimp") req->dpchret = WznmCtpGenuiDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
				else if (((DpchInvWznmCtpGenui*) req->dpchinv)->srefKCustop == "WznmCtpGenuiDlgloaini") req->dpchret = WznmCtpGenuiDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpGenui*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSRV) {
				if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvAcv") req->dpchret = WznmCtpWrsrvAcv::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvDlgimp") req->dpchret = WznmCtpWrsrvDlgimp::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
				else if (((DpchInvWznmCtpWrsrv*) req->dpchinv)->srefKCustop == "WznmCtpWrsrvDlgloaini") req->dpchret = WznmCtpWrsrvDlgloaini::run(xchg, &dbswznm, (DpchInvWznmCtpWrsrv*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRSTKIT) {
				if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitAcv") req->dpchret = WznmCtpWrstkitAcv::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
				else if (((DpchInvWznmCtpWrstkit*) req->dpchinv)->srefKCustop == "WznmCtpWrstkitArm") req->dpchret = WznmCtpWrstkitArm::run(xchg, &dbswznm, (DpchInvWznmCtpWrstkit*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCTPWRWEB) {
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENBASE) {
				req->dpchret = WznmGenBase::run(xchg, &dbswznm, (DpchInvWznmGenBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCAL) {
				req->dpchret = WznmGenCal::run(xchg, &dbswznm, (DpchInvWznmGenCal*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENCHK) {
				req->dpchret = WznmGenChk::run(xchg, &dbswznm, (DpchInvWznmGenChk*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENDETUI) {
				req->dpchret = WznmGenDetui::run(xchg, &dbswznm, (DpchInvWznmGenDetui*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENJOB) {
				req->dpchret = WznmGenJob::run(xchg, &dbswznm, (DpchInvWznmGenJob*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENQTB) {
				req->dpchret = WznmGenQtb::run(xchg, &dbswznm, (DpchInvWznmGenQtb*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMGENSYSVEC) {
				req->dpchret = WznmGenSysvec::run(xchg, &dbswznm, (DpchInvWznmGenSysvec*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT) {
				req->dpchret = WznmPrcfileConcat::run(xchg, &dbswznm, (DpchInvWznmPrcfileConcat*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILEIEXCONV) {
				req->dpchret = WznmPrcfileIexconv::run(xchg, &dbswznm, (DpchInvWznmPrcfileIexconv*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL) {
				req->dpchret = WznmPrcfilePlhrpl::run(xchg, &dbswznm, (DpchInvWznmPrcfilePlhrpl*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT) {
				req->dpchret = WznmPrctreeExtract::run(xchg, &dbswznm, (DpchInvWznmPrctreeExtract*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE) {
				req->dpchret = WznmPrctreeMerge::run(xchg, &dbswznm, (DpchInvWznmPrctreeMerge*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE) {
				req->dpchret = WznmPrctreeValidate::run(xchg, &dbswznm, (DpchInvWznmPrctreeValidate*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIBASE) {
				req->dpchret = WznmWrapiBase::run(xchg, &dbswznm, (DpchInvWznmWrapiBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIDEPLOY) {
				req->dpchret = WznmWrapiDeploy::run(xchg, &dbswznm, (DpchInvWznmWrapiDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIJOB) {
				req->dpchret = WznmWrapiJob::run(xchg, &dbswznm, (DpchInvWznmWrapiJob*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPIQTB) {
				req->dpchret = WznmWrapiQtb::run(xchg, &dbswznm, (DpchInvWznmWrapiQtb*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPBASE) {
				req->dpchret = WznmWrappBase::run(xchg, &dbswznm, (DpchInvWznmWrappBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPJBASE) {
				req->dpchret = WznmWrappJbase::run(xchg, &dbswznm, (DpchInvWznmWrappJbase*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDBS) {
				req->dpchret = WznmWrdbsDbs::run(xchg, &dbswznm, (DpchInvWznmWrdbsDbs*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDEPLOY) {
				req->dpchret = WznmWrdbsDeploy::run(xchg, &dbswznm, (DpchInvWznmWrdbsDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSDIFFSQL) {
				req->dpchret = WznmWrdbsDiffsql::run(xchg, &dbswznm, (DpchInvWznmWrdbsDiffsql*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSSQL) {
				req->dpchret = WznmWrdbsSql::run(xchg, &dbswznm, (DpchInvWznmWrdbsSql*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRDBSTBL) {
				req->dpchret = WznmWrdbsTbl::run(xchg, &dbswznm, (DpchInvWznmWrdbsTbl*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIBASE) {
				req->dpchret = WznmWrjapiBase::run(xchg, &dbswznm, (DpchInvWznmWrjapiBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIJOB) {
				req->dpchret = WznmWrjapiJob::run(xchg, &dbswznm, (DpchInvWznmWrjapiJob*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIQTB) {
				req->dpchret = WznmWrjapiQtb::run(xchg, &dbswznm, (DpchInvWznmWrjapiQtb*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIVEC) {
				req->dpchret = WznmWrjapiVec::run(xchg, &dbswznm, (DpchInvWznmWrjapiVec*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVBASE) {
				req->dpchret = WznmWrsrvBase::run(xchg, &dbswznm, (DpchInvWznmWrsrvBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCMBENGBASE) {
				req->dpchret = WznmWrsrvCmbengbase::run(xchg, &dbswznm, (DpchInvWznmWrsrvCmbengbase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVCRD) {
				req->dpchret = WznmWrsrvCrd::run(xchg, &dbswznm, (DpchInvWznmWrsrvCrd*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDDS) {
				req->dpchret = WznmWrsrvDds::run(xchg, &dbswznm, (DpchInvWznmWrsrvDds*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDEPLOY) {
				req->dpchret = WznmWrsrvDeploy::run(xchg, &dbswznm, (DpchInvWznmWrsrvDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVDLG) {
				req->dpchret = WznmWrsrvDlg::run(xchg, &dbswznm, (DpchInvWznmWrsrvDlg*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVENGBASE) {
				req->dpchret = WznmWrsrvEngbase::run(xchg, &dbswznm, (DpchInvWznmWrsrvEngbase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVIEX) {
				req->dpchret = WznmWrsrvIex::run(xchg, &dbswznm, (DpchInvWznmWrsrvIex*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVINIXML) {
				req->dpchret = WznmWrsrvInixml::run(xchg, &dbswznm, (DpchInvWznmWrsrvInixml*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVJOB) {
				req->dpchret = WznmWrsrvJob::run(xchg, &dbswznm, (DpchInvWznmWrsrvJob*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOP) {
				req->dpchret = WznmWrsrvOp::run(xchg, &dbswznm, (DpchInvWznmWrsrvOp*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPENGBASE) {
				req->dpchret = WznmWrsrvOpengbase::run(xchg, &dbswznm, (DpchInvWznmWrsrvOpengbase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVOPK) {
				req->dpchret = WznmWrsrvOpk::run(xchg, &dbswznm, (DpchInvWznmWrsrvOpk*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPNL) {
				req->dpchret = WznmWrsrvPnl::run(xchg, &dbswznm, (DpchInvWznmWrsrvPnl*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVPREF) {
				req->dpchret = WznmWrsrvPref::run(xchg, &dbswznm, (DpchInvWznmWrsrvPref*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVQRY) {
				req->dpchret = WznmWrsrvQry::run(xchg, &dbswznm, (DpchInvWznmWrsrvQry*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVROOTSESS) {
				req->dpchret = WznmWrsrvRootsess::run(xchg, &dbswznm, (DpchInvWznmWrsrvRootsess*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVUA) {
				req->dpchret = WznmWrsrvUa::run(xchg, &dbswznm, (DpchInvWznmWrsrvUa*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRSRVVEC) {
				req->dpchret = WznmWrsrvVec::run(xchg, &dbswznm, (DpchInvWznmWrsrvVec*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBBASE) {
				req->dpchret = WznmWrwebBase::run(xchg, &dbswznm, (DpchInvWznmWrwebBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBCRD) {
				req->dpchret = WznmWrwebCrd::run(xchg, &dbswznm, (DpchInvWznmWrwebCrd*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDEPLOY) {
				req->dpchret = WznmWrwebDeploy::run(xchg, &dbswznm, (DpchInvWznmWrwebDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBDLG) {
				req->dpchret = WznmWrwebDlg::run(xchg, &dbswznm, (DpchInvWznmWrwebDlg*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRWEBPNL) {
				req->dpchret = WznmWrwebPnl::run(xchg, &dbswznm, (DpchInvWznmWrwebPnl*) req->dpchinv);
			};

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
			};
		};

	} catch (WznmException& e) {
		cout << e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, VecWznmVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWznmVError::getIx, VecWznmVError::getTitle, VecWznmVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void WznmcmbdOpprc::cleanup(
			void* arg
		) {
	XchgWznmcmbd* xchg = (XchgWznmcmbd*) arg;

	xchg->cOpprcs.unlockMutex("WznmcmbdOpprc", "cleanup");
};

