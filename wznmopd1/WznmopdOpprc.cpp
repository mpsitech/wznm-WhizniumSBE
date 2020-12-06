/**
	* \file WznmopdOpprc.cpp
	* operation processor for Wznm operation daemon wznmopd1 (implementation)
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
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIBASE) {
				req->dpchret = WznmWrjapiBase::run(xchg, &dbswznm, (DpchInvWznmWrjapiBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIJOB) {
				req->dpchret = WznmWrjapiJob::run(xchg, &dbswznm, (DpchInvWznmWrjapiJob*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIQTB) {
				req->dpchret = WznmWrjapiQtb::run(xchg, &dbswznm, (DpchInvWznmWrjapiQtb*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRJAPIVEC) {
				req->dpchret = WznmWrjapiVec::run(xchg, &dbswznm, (DpchInvWznmWrjapiVec*) req->dpchinv);
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
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPBASE) {
				req->dpchret = WznmWrappBase::run(xchg, &dbswznm, (DpchInvWznmWrappBase*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMWRAPPJBASE) {
				req->dpchret = WznmWrappJbase::run(xchg, &dbswznm, (DpchInvWznmWrappJbase*) req->dpchinv);
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
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEEXTRACT) {
				req->dpchret = WznmPrctreeExtract::run(xchg, &dbswznm, (DpchInvWznmPrctreeExtract*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEMERGE) {
				req->dpchret = WznmPrctreeMerge::run(xchg, &dbswznm, (DpchInvWznmPrctreeMerge*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCTREEVALIDATE) {
				req->dpchret = WznmPrctreeValidate::run(xchg, &dbswznm, (DpchInvWznmPrctreeValidate*) req->dpchinv);
			};
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILECONCAT) {
				req->dpchret = WznmPrcfileConcat::run(xchg, &dbswznm, (DpchInvWznmPrcfileConcat*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMPRCFILEPLHRPL) {
				req->dpchret = WznmPrcfilePlhrpl::run(xchg, &dbswznm, (DpchInvWznmPrcfilePlhrpl*) req->dpchinv);
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
			if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLBSCUI) {
				req->dpchret = WznmComplBscui::run(xchg, &dbswznm, (DpchInvWznmComplBscui*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDBS) {
				req->dpchret = WznmComplDbs::run(xchg, &dbswznm, (DpchInvWznmComplDbs*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLDEPLOY) {
				req->dpchret = WznmComplDeploy::run(xchg, &dbswznm, (DpchInvWznmComplDeploy*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLIEX) {
				req->dpchret = WznmComplIex::run(xchg, &dbswznm, (DpchInvWznmComplIex*) req->dpchinv);
			} else if (req->dpchinv->ixWznmVDpch == VecWznmVDpch::DPCHINVWZNMCOMPLJTR) {
				req->dpchret = WznmComplJtr::run(xchg, &dbswznm, (DpchInvWznmComplJtr*) req->dpchinv);
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

	pthread_cleanup_pop(0);

	return(NULL);
};

void WznmopdOpprc::cleanup(
			void* arg
		) {
	XchgWznmopd* xchg = (XchgWznmopd*) arg;

	xchg->cOpprcs.unlockMutex("WznmopdOpprc", "cleanup");
};
