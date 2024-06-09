/**
	* \file WznmWrappDom.cpp
	* Wznm operation processor - write DOM code for accessor app (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 11 Sep 2022
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrappDom.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrappDom
 ******************************************************************************/

DpchRetWznm* WznmWrappDom::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappDom* dpchinv
		) {
	ubigint refWznmMApp = dpchinv->refWznmMApp;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMApp* app = NULL;

	ListWznmMRtjob rtjs;

	string Appshort;

	fstream outfile;

	string s;

	if (dbswznm->tblwznmmapp->loadRecByRef(refWznmMApp, &app)) {
		loadRtjtree(dbswznm, refWznmMApp, rtjs);

		Appshort = StrMod::cap(app->Short);

		// DOMXxxx.java
		s = xchg->tmppath + "/" + folder + "/DOM" + Appshort + ".java.ip";
		outfile.open(s.c_str(), ios::out);
		writeDOMJ(dbswznm, outfile, rtjs);
		outfile.close();

		delete app;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrappDom::writeDOMJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtblock rtbs;
	WznmMRtblock* rtb = NULL;

	WznmMBlock* blk = NULL;
	WznmMJob* hostjob = NULL;

	WznmMTable* tbl = NULL;

	// --- summary
	outfile << "// IP summary --- IBEGIN" << endl;
	writeRtjtree(dbswznm, outfile, VecWznmVApptarget::JAVA, rtjs);
	outfile << "// IP summary --- IEND" << endl;

	// --- constructor
	outfile << "// IP constructor --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
			dbswznm->tblwznmmrtblock->loadRstBySQL("SELECT * FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(rtj->ref) + " ORDER BY sref ASC", false, rtbs);

			if ((rtbs.nodes.size() > 0) || (job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD)) {
				// session and card jref's not part of any statshr block
				if ((job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD)) outfile << "\t\tscrJref" << StrMod::cap(rtj->sref) << " = \"\";" << endl;

				for (unsigned int j = 0; j < rtbs.nodes.size(); j++) {
					rtb = rtbs.nodes[j];

					if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::BLK) {
						if (dbswznm->tblwznmmblock->loadRecByRef(rtb->refUref, &blk)) {
							if (blk->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
								if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &hostjob)) { // hostjob is not necessarily equal to job
									//outfile << "\t\t" << rtb->sref << " = " << getBlknew(dbswznm, hostjob, blk) << ";" << endl;
									delete hostjob;
								};
							};

							delete blk;
						};

					} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::FED) {
						outfile << "\t\t" << rtb->sref << " = new Feed(\"" << rtb->sref << "\");" << endl;

					} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::TBL) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rtb->refUref, &tbl)) {
							outfile << "\t\t" << rtb->sref << " = new List" << tbl->sref.substr(3) << "();" << endl;
							delete tbl;
						};
					};
				};

				outfile << endl;
			};

			delete job;
		};
	};
	outfile << "// IP constructor --- IEND" << endl;

	// --- vars
	outfile << "// IP vars --- IBEGIN" << endl;
	writeRtobjs(dbswznm, outfile, VecWznmVApptarget::JAVA, rtjs);
	outfile << "// IP vars --- IEND" << endl;
};
// IP cust --- IEND