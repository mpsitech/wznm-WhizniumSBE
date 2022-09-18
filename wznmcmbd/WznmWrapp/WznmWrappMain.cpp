/**
	* \file WznmWrappMain.cpp
	* Wznm operation processor - write main state machine code for accessor app (implementation)
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

#include "WznmWrappMain.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrappMain
 ******************************************************************************/

DpchRetWznm* WznmWrappMain::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappMain* dpchinv
		) {
	ubigint refWznmMApp = dpchinv->refWznmMApp;
	string folder = dpchinv->folder;
	bool ipAllNotSpec = dpchinv->ipAllNotSpec;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
/*
void WznmWrappJbase::writeAppJ(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, const string& Prjshort
			, ListWznmMRtjob& rtjs
			, ListWznmMEvent& evts
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, vector<unsigned int>& icsSeqs
			, vector<uint>& cntsEnt
			, vector<uint>& cntsReent
			, vector<uint>& cntsLve
			, const bool ipAllNotSpec
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	ListWznmMRtblock rtbs;

	WznmMBlock* blk = NULL;

	WznmMState* ste = NULL;

	map<string,string> trigs;

	string dom, indent, subdlm, dpchjref;

	string dpchsref;

	string s;

	string Appshort = StrMod::cap(app->Short);

	getTargetStrs(app->ixWznmVApptarget, dom, indent, subdlm, dpchjref);

	writeHandleTrigger(dbswznm, outfile, app, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);

	// --- states
	outfile << "// IP states --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		s = StrMod::cap(StrMod::dotToUsc(ste->sref));

		getSteTrigs(dbswznm, Prjshort, Appshort, app->ixWznmVApptarget, ste->ref, dom, subdlm, trigs);

		if (ipAllNotSpec || cntsEnt[i]) {
			outfile << "\tpublic int enter" << s << "() {" << endl;

			outfile << "\t\tint retval = Vec" << Appshort << "VState." << StrMod::uc(s) << ";" << endl;

			outfile << endl;
			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::ENT);
			outfile << endl;

			outfile << "\t\treturn retval;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;
		};

		if (ipAllNotSpec || cntsReent[i]) {
			outfile << "\tpublic int reenter" << s << "(" << endl;
			outfile << "\t\t\t\tint ixVEvent" << endl;
			outfile << "\t\t\t\t, DpchEng" << Prjshort << " _dpcheng" << endl;
			outfile << "\t\t\t) {" << endl;
	
			outfile << "\t\tint retval = Vec" << Appshort << "VState." << StrMod::uc(s) << ";" << endl;

			outfile << endl;
			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::REENT);
			outfile << endl;

			outfile << "\t\treturn retval;" << endl;
			outfile << "\t};" << endl;
			outfile << endl;
		};

		if (ipAllNotSpec || cntsLve[i]) {
			outfile << "\tpublic void leave" << s << "() {" << endl;

			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::LVE);

			outfile << "\t};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP states --- IEND" << endl;

	// --- mergeDpchEngs
	outfile << "// IP mergeDpchEngs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		dbswznm->tblwznmmrtdpch->loadRstBySQL("SELECT * FROM TblWznmMRtdpch WHERE refWznmMRtjob = " + to_string(rtj->ref) + " AND Merge = 1 ORDER BY sref ASC", false, rtds);

		if (rtds.nodes.size() > 0) {
			if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
				dbswznm->tblwznmmrtblock->loadRstBySQL("SELECT * FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(rtj->ref) + " ORDER BY sref ASC", false, rtbs);

				for (unsigned int j = 0; j < rtds.nodes.size(); j++) {
					rtd = rtds.nodes[j];

					if (dbswznm->tblwznmmblock->loadRecByRef(rtd->refWznmMBlock, &blk)) {
						dpchsref = job->sref + "." + Wznm::getSubsref(job, blk->sref);

						outfile << "\tpublic boolean merge" << blk->sref << "(" << endl;
						outfile << "\t\t\t\t" << dpchsref << " dpcheng" << endl;
						outfile << "\t\t\t) {" << endl;

						writeMerge(dbswznm, outfile, VecWznmVApptarget::JAVA, blk, dpchsref, rtbs);

						outfile << "\t};" << endl;
						outfile << endl;
					};
				};

				delete job;
			};
		};
	};
	outfile << "// IP mergeDpchEngs --- IEND" << endl;

	// --- handleDpchEng.merge
	outfile << "// IP handleDpchEng.merge --- IBEGIN" << endl;
	writeDpchEngMerge(dbswznm, outfile, Prjshort, VecWznmVApptarget::JAVA, rtjs);
	outfile << "// IP handleDpchEng.merge --- IEND" << endl;
};
*/
// IP cust --- IEND
