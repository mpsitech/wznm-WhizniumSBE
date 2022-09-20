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

	// IP run --- IBEGIN
	WznmMApp* app = NULL;

	ListWznmMRtjob rtjs;
	ListWznmMEvent evts;

	ListWznmMSequence seqs;
	ListWznmMState stes;
	vector<unsigned int> icsSeqs;
	vector<uint> cntsEnt;
	vector<uint> cntsReent;
	vector<uint> cntsLve;

	string Appshort;
	string Prjshort;

	fstream outfile;

	string s;

	if (dbswznm->tblwznmmapp->loadRecByRef(refWznmMApp, &app)) {
		loadRtjtree(dbswznm, refWznmMApp, rtjs);
		dbswznm->tblwznmmevent->loadRstByApp(refWznmMApp, false, evts);

		analyzeStes(dbswznm, app->ref, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve);

		Appshort = StrMod::cap(app->Short);

		Prjshort = Wznm::getPrjshort(dbswznm, app->verRefWznmMVersion);

		if (app->ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) {
			// AppXxxx.h
			s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".h.ip";
			outfile.open(s.c_str(), ios::out);
			writeAppHcxx(dbswznm, outfile, app, Prjshort, rtjs, evts, stes, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
			outfile.close();

			// AppXxxx.cpp/.mm
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".mm.ip";
			else s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".cpp.ip";
			outfile.open(s.c_str(), ios::out);
			writeAppCxx(dbswznm, outfile, app, Prjshort, rtjs, evts, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
			outfile.close();

		} else if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) {
			// AppXxxx.java
			s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".java.ip";
			outfile.open(s.c_str(), ios::out);
			writeAppJ(dbswznm, outfile, app, Prjshort, rtjs, evts, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
			outfile.close();
		};

		delete app;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrappMain::writeAppHcxx(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, const string& Prjshort
			, ListWznmMRtjob& rtjs
			, ListWznmMEvent& evts
			, ListWznmMState& stes
			, vector<uint>& cntsEnt
			, vector<uint>& cntsReent
			, vector<uint>& cntsLve
			, const bool ipAllNotSpec
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	WznmMBlock* blk = NULL;

	WznmMState* ste = NULL;

	string s;

	if (app->ixWznmVApptarget != VecWznmVApptarget::COCOA_SWIFT) {
		// --- DOM.summary
		outfile << "// IP DOM.summary --- IBEGIN" << endl;
		writeRtjtree(dbswznm, outfile, app->ixWznmVApptarget, rtjs);
		outfile << "// IP DOM.summary --- IEND" << endl;

		// --- DOM.vars
		outfile << "// IP DOM.vars --- IBEGIN" << endl;
		writeRtobjs(dbswznm, outfile, app->ixWznmVApptarget, rtjs);
		outfile << "// IP DOM.vars --- IEND" << endl;
	};

	// --- states
	outfile << "// IP states --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		s = StrMod::cap(StrMod::dotToUsc(ste->sref));

		if (ipAllNotSpec || cntsEnt[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (unsigned int)enter" << s << ";" << endl;
			else outfile << "\tunsigned int enter" << s << "();" << endl;
		};

		if (ipAllNotSpec || cntsReent[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (unsigned int)renter" << s << ":(unsigned int)ixVEvent withDpcheng:(DpchEng" << Prjshort << "*)_dpcheng;" << endl;
			else outfile << "\tunsigned int reenter" << s << "(const unsigned int ixVEvent, DpchEng" << Prjshort << "* _dpcheng);" << endl;
		};

		if (ipAllNotSpec || cntsLve[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (void)leave" << s << ";" << endl;
			else outfile << "\tvoid leave" << s << "();" << endl;
		};

		if (ipAllNotSpec || (cntsEnt[i] + cntsReent[i] + cntsLve[i])) outfile << endl;
	};
	outfile << "// IP states --- IEND" << endl;

	// --- mergeDpchEngs
	outfile << "// IP mergeDpchEngs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		dbswznm->tblwznmmrtdpch->loadRstBySQL("SELECT * FROM TblWznmMRtdpch WHERE refWznmMRtjob = " + to_string(rtj->ref) + " AND Merge = 1 ORDER BY sref ASC", false, rtds);

		if (rtds.nodes.size() > 0) {
			if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {

				for (unsigned int j = 0; j < rtds.nodes.size(); j++) {
					rtd = rtds.nodes[j];

					if (dbswznm->tblwznmmblock->loadRecByRef(rtd->refWznmMBlock, &blk)) {
						if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (bool)merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*)dpcheng;" << endl;
						else outfile << "\tbool merge" << blk->sref << "(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "* dpcheng);" << endl;

						delete blk;
					};
				};

				delete job;
			};
		};
	};
	outfile << "// IP mergeDpchEngs --- IEND" << endl;
};

void WznmWrappMain::writeAppCxx(
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

	string prjshort = StrMod::lc(Prjshort);

	string Appshort = StrMod::cap(app->Short);

	getTargetStrs(app->ixWznmVApptarget, dom, indent, subdlm, dpchjref);

	if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) {
		// --- DOM.summary
		outfile << "// IP DOM.summary --- IBEGIN" << endl;
		writeRtjtree(dbswznm, outfile, app->ixWznmVApptarget, rtjs);
		outfile << "// IP DOM.summary --- IEND" << endl;

		// --- DOM.vars
		outfile << "// IP DOM.vars --- IBEGIN" << endl;
		writeRtobjs(dbswznm, outfile, app->ixWznmVApptarget, rtjs);
		outfile << "// IP DOM.vars --- IEND" << endl;
	};

	writeHandleTrigger(dbswznm, outfile, app, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);

	// --- states
	outfile << "// IP states --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		s = StrMod::cap(StrMod::dotToUsc(ste->sref));

		getSteTrigs(dbswznm, Prjshort, Appshort, app->ixWznmVApptarget, ste->ref, dom, subdlm, trigs);

		if (ipAllNotSpec || cntsEnt[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (unsigned int)enter" << s << " {" << endl;
			else outfile << "unsigned int App" << Appshort << "::enter" << s << "() {" << endl;

			outfile << "\tunsigned int retval = Vec" << Appshort << "VState::" << StrMod::uc(s) << ";" << endl;

			outfile << endl;
			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::ENT);
			outfile << endl;

			outfile << "\treturn retval;" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		if (ipAllNotSpec || cntsReent[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (unsigned int)renter" << s << ":(unsigned int)ixVEvent withDpcheng:(DpchEng" << Prjshort << "*)_dpcheng {" << endl;
			else {
				outfile << "unsigned int App" << Appshort << "::reenter" << s << "(" << endl;
				outfile << "\t\t\tconst unsigned int ixVEvent" << endl;
				outfile << "\t\t\t, DpchEng" << Prjshort << "* _dpcheng" << endl;
				outfile << "\t\t) {" << endl;
			};
	
			outfile << "\tunsigned int retval = Vec" << Appshort << "VState::" << StrMod::uc(s) << ";" << endl;
	
			outfile << endl;
			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::REENT);
			outfile << endl;

			outfile << "\treturn retval;" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};

		if (ipAllNotSpec || cntsLve[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (unsigned int)leave" << s << " {" << endl;
			else outfile << "unsigned int App" << Appshort << "::leave" << s << "() {" << endl;

			writeState(dbswznm, outfile, Prjshort, Appshort, app->ixWznmVApptarget, dom, indent, subdlm, dpchjref, ste, trigs, VecWznmVAMStateActionSection::LVE);

			outfile << "};" << endl;
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
						dpchsref = job->sref + "::" + Wznm::getSubsref(job, blk->sref);

						if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "- (bool)merge" << blk->sref << ":(" << dpchsref << "*)dpcheng {" << endl;
						else {
							outfile << "bool App" << Appshort << "::merge" << blk->sref << "(" << endl;
							outfile << "\t\t\t" << dpchsref << "* dpcheng" << endl;
							outfile << "\t\t) {" << endl;
						};

						writeMerge(dbswznm, outfile, app->ixWznmVApptarget, blk, dpchsref, rtbs);

						outfile << "};" << endl;
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
	writeDpchEngMerge(dbswznm, outfile, Prjshort, app->ixWznmVApptarget, rtjs);
	outfile << "// IP handleDpchEng.merge --- IEND" << endl;
};

void WznmWrappMain::writeAppJ(
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

void WznmWrappMain::writeRtjtree(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixWznmVApptarget
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	ListWznmMRtblock rtbs;
	WznmMRtblock* rtb = NULL;

	string indent;

	if (ixWznmVApptarget != VecWznmVApptarget::COCOA_SWIFT) indent = "\t";

	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		outfile << indent;
		for (unsigned int j = 0; j < rtj->supLvl; j++) outfile << "\t";
		outfile << "- " << rtj->sref;

		dbswznm->tblwznmmrtblock->loadRstBySQL("SELECT * FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(rtj->ref) + " ORDER BY sref ASC", false, rtbs);

		if (rtbs.nodes.size() > 0) {
			outfile << " (";

			for (unsigned int j = 0; j < rtbs.nodes.size(); j++) {
				rtb = rtbs.nodes[j];

				if (j != 0) outfile << ", ";
				outfile << rtb->sref;
			};

			outfile << ")";
		};

		outfile << endl;
	};
};

void WznmWrappMain::writeRtobjs(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixWznmVApptarget
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtblock rtbs;
	WznmMRtblock* rtb = NULL;

	WznmMBlock* blk = NULL;
	WznmMJob* hostjob = NULL;

	WznmMTable* tbl = NULL;

	string indent, pre, str, subdlm;

	if (ixWznmVApptarget == VecWznmVApptarget::JAVA) {
		pre = "public ";
		str = "String";
		subdlm = ".";
	} else {
		str = "string";
		subdlm = "::";
	};

	if (ixWznmVApptarget != VecWznmVApptarget::COCOA_SWIFT) indent = "\t";

	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
			dbswznm->tblwznmmrtblock->loadRstBySQL("SELECT * FROM TblWznmMRtblock WHERE refWznmMRtjob = " + to_string(rtj->ref) + " ORDER BY sref ASC", false, rtbs);

			if ((rtbs.nodes.size() > 0) || (job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD)) {
				outfile << indent << "// " << rtj->sref << endl;
				
				// session and card jref's not part of any statshr block
				if ((job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD)) outfile << indent << pre << str << " scrJref" << StrMod::cap(rtj->sref) << ";" << endl;

				for (unsigned int j = 0; j < rtbs.nodes.size(); j++) {
					rtb = rtbs.nodes[j];

					if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::BLK) {
						if (dbswznm->tblwznmmblock->loadRecByRef(rtb->refUref, &blk)) {
							if (blk->refIxVTbl == VecWznmVMBlockRefTbl::JOB) {
								if (dbswznm->tblwznmmjob->loadRecByRef(blk->refUref, &hostjob)) { // hostjob is not necessarily equal to job
									outfile << indent << pre << hostjob->sref << subdlm << Wznm::getSubsref(hostjob, blk->sref) << " " << rtb->sref << ";" << endl;
									delete hostjob;
								};
							};

							delete blk;
						};

					} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::FED) {
						outfile << indent << pre << "Feed " << rtb->sref << ";" << endl;

					} else if (rtb->refIxVTbl == VecWznmVMRtblockRefTbl::TBL) {
						if (dbswznm->tblwznmmtable->loadRecByRef(rtb->refUref, &tbl)) {
							outfile << indent << pre << "List" << tbl->sref.substr(3) << " " << rtb->sref << ";" << endl;
							delete tbl;
						};
					};
				};

				outfile << endl;
			};

			delete job;
		};
	};
};

void WznmWrappMain::writeHandleTrigger(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, vector<unsigned int>& icsSeqs
			, vector<uint>& cntsEnt
			, vector<uint>& cntsReent
			, vector<uint>& cntsLve
			, const bool ipAllNotSpec
		) {
	WznmMSequence* seq = NULL;
	WznmMState* ste = NULL;

	string indent, dlm;

	string Appshort = StrMod::cap(app->Short);

	unsigned int ixSeqsLast;

	if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) indent = "\t\t\t";
	else indent = "\t\t";

	if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) dlm = ".";
	else dlm = "::";

	// --- handleTrigger.reenter
	outfile << "// IP handleTrigger.reenter --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		if (ipAllNotSpec || (cntsReent[i] > 0)) {
			outfile << indent << "case Vec" << Appshort << "VState" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ": _ixVState = ";

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "[self reenter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << ":ixVEvent withDpcheng:dpcheng]; break;" << endl;
			else outfile <<  "reenter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(ixVEvent, dpcheng); break;" << endl;
		};
	};
	outfile << "// IP handleTrigger.reenter --- IEND" << endl;

	// --- handleTrigger.leave
	outfile << "// IP handleTrigger.leave --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		if (ipAllNotSpec || (cntsLve[i] > 0)) {
			outfile << indent << "\t\tcase Vec" << Appshort << "VState" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ": ";

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "[self leave" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
			else outfile <<  "leave" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(); break;" << endl;
		};
	};
	outfile << "// IP handleTrigger.leave --- IEND" << endl;

	// --- handleTrigger.subseq
	outfile << "// IP handleTrigger.subseq --- IBEGIN" << endl;

	ixSeqsLast = 0;
	ixSeqsLast--;

	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		if (icsSeqs[i] != ixSeqsLast) {
			ixSeqsLast = icsSeqs[i];
			seq = seqs.nodes[ixSeqsLast];

			outfile << indent << "\t\tcase Vec" << Appshort << "VState" << dlm << "SUBSEQ_" << StrMod::uc(StrMod::dotToUsc(seq->sref)) << ": ";

			if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) outfile << "stkIcsVState.push";
			else outfile << "stkIcsVState.push_back";

			outfile << "(ixVState); ixVState = Vec" << Appshort << "VState" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << "; break;" << endl;
		};
	};

	outfile << "// IP handleTrigger.subseq --- IEND" << endl;

	// --- handleTrigger.enter
	outfile << "// IP handleTrigger.enter --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		if (ipAllNotSpec || (cntsEnt[i] > 0)) {
			outfile << indent << "\t\tcase Vec" << Appshort << "VState" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ": _ixVState = ";

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "[self enter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
			else outfile <<  "enter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(); break;" << endl;
		};
	};
	outfile << "// IP handleTrigger.enter --- IEND" << endl;
};

void WznmWrappMain::writeState(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const string& Appshort
			, const uint ixWznmVApptarget
			, const string& dom
			, const string& indent
			, const string& subdlm
			, const string& dpchjref
			, WznmMState* ste
			, map<string,string>& trigs
			, const uint ixVSection
		) {
	ListWznmAMStateAction steAacts;
	WznmAMStateAction* steAact = NULL;

	string ipbase;

	vector<string> conds, lastconds;
	vector<string> ips, lastips;

	bool rootip;

	unsigned int lvl, lastlvl, matchlvl;

	unsigned int il;

	vector<string> ss;
	string s;

	bool found;

	if (ixVSection == VecWznmVAMStateActionSection::ENT) ipbase = "enter";
	else if (ixVSection == VecWznmVAMStateActionSection::REENT) ipbase = "reenter";
	else if (ixVSection == VecWznmVAMStateActionSection::LVE) ipbase = "leave";
	ipbase += StrMod::cap(StrMod::dotToUsc(ste->sref));

	dbswznm->tblwznmamstateaction->loadRstBySQL("SELECT * FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(ste->ref) + " AND ixVSection = " + to_string(ixVSection) + " ORDER BY steNum ASC", false, steAacts);

	if (steAacts.nodes.size() == 0) {
		outfile << indent << "// IP " << ipbase << " --- INSERT" << endl;

	} else {
		conds.resize(4);
		lastconds = conds;

		ips.resize(4);
		lastips = ips;

		lvl = 0;
		lastlvl = 0;

		// check for non-conditional IP common to all actions
		rootip = !steAacts.nodes.empty();

		for (unsigned int k = 0; k < steAacts.nodes.size(); k++) {
			steAact = steAacts.nodes[k];

			if (k == 0) {
				conds[0] = steAact->tr1SrefATrig;
				ips[0] = steAact->Ip1;

				rootip = (conds[0] == "") && (ips[0] != "");

			} else {
				rootip = (conds[0] == steAact->tr1SrefATrig) && (ips[0] == steAact->Ip1);
			};

			if (!rootip) break;
		};

		if (rootip) outfile << indent << "// IP " << ipbase << "." << ips[0] << " --- INSERT" << endl;

		// write out decision tree
		for (unsigned int k = 0; k < steAacts.nodes.size(); k++) {
			steAact = steAacts.nodes[k];

			conds[0] = steAact->tr1SrefATrig; ips[0] = steAact->Ip1;
			conds[1] = steAact->tr2SrefATrig; ips[1] = steAact->Ip2;
			conds[2] = steAact->tr3SrefATrig; ips[2] = steAact->Ip3;
			conds[3] = steAact->tr4SrefATrig; ips[3] = steAact->Ip4;

			if (rootip) {
				for (unsigned int l = 0; l < 3; l++) {
					conds[l] = conds[l+1];
					ips[l] = ips[l+1];
				};

				conds[3] = ""; ips[3] = "";
			};

			lvl = 0;
			for (unsigned int l = 0; l < 4; l++) {
				if (conds[l] != "") lvl++;
				else break;
			};

			for (matchlvl = 0; matchlvl < lvl; matchlvl++) if ((lastconds[matchlvl] != conds[matchlvl]) || (lastips[matchlvl] != lastips[matchlvl])) break;

			// end if's
			if (lastlvl > 0) for (unsigned int l = lastlvl - 1; l > matchlvl; l--) outfile << indent << string(l, '\t') << "};" << endl;

			for (unsigned int l = matchlvl; l <= lvl; l++) {
				// if's / else if's / else's
				if (l < 4) if (conds[l] != "") {
					outfile << indent << string(l, '\t');
					if (conds[l] == "else") {
						outfile << "} else {" << endl;

					} else {
						if ((k > 0) && (l == matchlvl)) outfile << "} else if";
						else outfile << "if";

						outfile << " (";

						s = conds[l];

						found = (s[0] == '!');

						if (found) {
							outfile << "!(";
							s = s.substr(1);
						};

						auto it = trigs.find(s);
						if (it != trigs.end()) outfile << it->second;
						else outfile <<  "false";

						if (found) outfile << ")";

						outfile << ") {" << endl;
					};
				};

				if (l < 4) if (ips[l] != "") {
					if (lvl > 0) il = l + 1;
					else il = 0;

					outfile << indent << string(il, '\t') << "// IP " << ipbase << "." << ips[l] << " --- INSERT" << endl;
				};

				if (l == lvl) {
					s = writeState_action(dbswznm, Prjshort, Appshort, ixWznmVApptarget, dom, subdlm, dpchjref, steAact);
					
					if (s != "") {
						StrMod::stringToVector(s, ss, '\n');
						for (unsigned int m = 0; m < ss.size(); m++) outfile << indent << string(l, '\t') << ss[m] << endl;
					};
				};
			};

			lastconds = conds;
			lastips = ips;

			lastlvl = lvl;
		};

		// remaining end if's
		for (unsigned int l = lvl; l > 0; l--) outfile << indent << string(l-1, '\t') << "};" << endl;
	};
};

string WznmWrappMain::writeState_action(
			DbsWznm* dbswznm
			, const string& Prjshort
			, const string& Appshort
			, const uint ixWznmVApptarget
			, const string& dom
			, const string& subdlm
			, const string& dpchjref
			, WznmAMStateAction* steAact
		) {
	string retval;

	ubigint ref;

	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	WznmMVector* vec = NULL;
	WznmMVectoritem* vit = NULL;

	WznmMSequence* seq = NULL;
	WznmMState* snx = NULL;

	ListWznmAMBlockItem blkAitms;
	WznmAMBlockItem* blkAitm = NULL;

	string s2;

	string prjshort = StrMod::lc(Prjshort);

	if (steAact->ixVType == VecWznmVAMStateActionType::LOGIN) {
		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self sendDpchApp:";
		else retval = "sendDpchApp(";

		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval += "new Root" + Prjshort + "::DpchAppLogin(\"\", stg" + prjshort + "api.username, stg" + prjshort + "api.password, false, false, {Root" + Prjshort + "::DpchAppLogin::ALL})";
		else if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += "(new Root" + Prjshort + "()).new DpchAppLogin(\"\", stg" + prjshort + "api.username, stg" + prjshort + "api.password, false, false, new Integer[]{Root" + Prjshort + ".DpchAppLogin.ALL})";
		else retval += "new Root" + Prjshort + "::DpchAppLogin(\"\", stg" + prjshort + "api->username, stg" + prjshort + "api->password, false, false, {Root" + Prjshort + "::DpchAppLogin::ALL})";

		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval += "];";
		else retval += ");";

	} else if ((steAact->ixVType == VecWznmVAMStateActionType::INIT) || (steAact->ixVType == VecWznmVAMStateActionType::DO)) {
		if (dbswznm->tblwznmmrtjob->loadRecByRef(steAact->refWznmMRtjob, &rtj)) {
			if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
				if (steAact->ixVType == VecWznmVAMStateActionType::INIT) {
					if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self sendDpchApp:";
					else retval = "sendDpchApp(";

					if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += "new DpchApp" + Prjshort + "Init(" + dom + getScrJrefVar(dbswznm, rtj, job) + ")";
					else retval += "new DpchApp" + Prjshort + "Init(" + dom + getScrJrefVar(dbswznm, rtj, job) + ")";

					if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval += "];";
					else retval += ");";

				} else if (steAact->ixVType == VecWznmVAMStateActionType::DO) {
					if (dbswznm->tblwznmmvector->loadRecByRef(steAact->refWznmMVector, &vec)) {
						if (dbswznm->tblwznmmvectoritem->loadRecByRef(steAact->refWznmMVectoritem, &vit)) {
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
										+ " AND sref LIKE 'DpchApp%Do'", ref)) {

								if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self sendDpchApp:";
								else retval = "sendDpchApp(";

								if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += "(new " + job->sref + "()).new DpchAppDo(";
								else retval += "new " + job->sref + "::DpchAppDo(";

								retval += dom + getScrJrefVar(dbswznm, rtj, job);

								s2 = "";

								dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, blkAitms);

								for (unsigned int k = 0; k < blkAitms.nodes.size(); k++) {
									blkAitm = blkAitms.nodes[k];

									if (blkAitm->refWznmMVector != 0) {
										if (blkAitm->refWznmMVector == vec->ref) {
											s2 = blkAitm->sref;
											retval += ", " + job->sref + subdlm + "Vec" + blkAitm->sref.substr(2) + subdlm + StrMod::uc(vit->sref);
										} else retval += ", 0";
									};
								};

								if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += ", new Integer[]{";
								else retval += ", {";

								if (blkAitms.nodes.size() == 2) retval += job->sref + subdlm + "DpchAppDo" + subdlm + "ALL";
								else retval += job->sref + subdlm + "DpchAppDo" + subdlm + "SCRJREF, " + job->sref + subdlm + "DpchAppDo" + subdlm + StrMod::uc(s2);
								retval += "}";

								if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval += ")];";
								else retval += "));";
							};

							delete vit;
						};

						delete vec;
					};
				};

				delete job;
			};

			delete rtj;
		};

	} else if ((steAact->ixVType == VecWznmVAMStateActionType::CSJSTEP) || (steAact->ixVType == VecWznmVAMStateActionType::CSJNTFSTEP) || (steAact->ixVType == VecWznmVAMStateActionType::STEP)) {
		if ((steAact->ixVType == VecWznmVAMStateActionType::CSJSTEP) || (steAact->ixVType == VecWznmVAMStateActionType::CSJNTFSTEP)) {
			if (dbswznm->tblwznmmrtjob->loadRecByRef(steAact->refWznmMRtjob, &rtj)) {
				if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
					retval = dom + getScrJrefVar(dbswznm, rtj, job) + " = " + dpchjref + ";\n";
					delete job;
				};
				delete rtj;
			};
			if (steAact->ixVType == VecWznmVAMStateActionType::CSJNTFSTEP) {
				if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval += "[self startNotify];\n";
				else retval += "startNotify();\n";
			};
		};

		if (dbswznm->tblwznmmstate->loadRecByRef(steAact->snxRefWznmMState, &snx)) {
			retval += "retval = Vec" + Appshort + "VState" + subdlm + StrMod::uc(StrMod::dotToUsc(snx->sref)) + ";";
			delete snx;
		};

	} else if (steAact->ixVType == VecWznmVAMStateActionType::STEPSEQ) {
		if (dbswznm->tblwznmmstate->loadRecBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(steAact->refWznmMSequence) + " AND seqNum = 1", &snx)) {
			retval = "retval = Vec" + Appshort + "VState" + subdlm + StrMod::uc(StrMod::dotToUsc(snx->sref)) + ";";
			delete snx;
		};

	} else if (steAact->ixVType == VecWznmVAMStateActionType::SUBSEQ) {
		if (dbswznm->tblwznmmsequence->loadRecByRef(steAact->refWznmMSequence, &seq)) {
			retval = "retval = Vec" + Appshort + "VState" + subdlm + "SUBSEQ_" + StrMod::uc(StrMod::dotToUsc(seq->sref)) + ";";
			delete seq;
		};

	} else if (steAact->ixVType == VecWznmVAMStateActionType::RETSEQ) {
		retval = "retval = Vec" + Appshort + "VState" + subdlm + "RETSEQ;";

	} else if (steAact->ixVType == VecWznmVAMStateActionType::BREAK) {
		retval = "retval = Vec" + Appshort + "VState" + subdlm + "BREAK;";
	};

	return retval;
};

void WznmWrappMain::writeMerge(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixWznmVApptarget
			, WznmMBlock* blk
			, const string& dpchsref
			, ListWznmMRtblock& rtbs
		) {
	WznmMRtblock* rtb = NULL;

	vector<string> maskitems;

	string dom, indent, subdlm, dpchjref;

	vector<string> ss;
	string s;

	getTargetStrs(ixWznmVApptarget, dom, indent, subdlm, dpchjref);

	// dispatch block items that serve as source for run-time data block are found in rtb->srcSrefsWznmAMBlockItem
	for (unsigned int i = 0; i < rtbs.nodes.size(); i++) {
		rtb = rtbs.nodes[i];

		StrMod::srefsToVector(rtb->srcSrefsWznmAMBlockItem, ss);
		for (unsigned int j = 0; j < ss.size(); j++) {
			s = ss[j];

			if (s.find(blk->sref) == 0) {
				s = s.substr(blk->sref.length() + 1);
				maskitems.push_back(s);

				if (ixWznmVApptarget == VecWznmVApptarget::JAVA) outfile << indent << "if (dpcheng.has(";
				else outfile << indent << "if (dpcheng->has(";

				outfile << dpchsref << subdlm << StrMod::uc(s) << ")) ";

				if (ixWznmVApptarget == VecWznmVApptarget::JAVA) outfile << dom << rtb->sref << " = dpcheng." << s << ";" << endl;
				else outfile << dom << rtb->sref << " = dpcheng->" << s << ";" << endl;
			};
		};
	};

	if (maskitems.size() > 0) {
		outfile << endl;

		outfile << indent << "return(dpcheng";

		if (ixWznmVApptarget == VecWznmVApptarget::JAVA) outfile << ".hasAny(new Integer[]";
		else outfile << "->hasAny(";
		
		outfile << "{";
		for (unsigned int i = 0; i < maskitems.size(); i++) {
			if (i != 0) outfile << ",";
			outfile << dpchsref << subdlm << StrMod::uc(maskitems[i]);
		};
		outfile << "}));" << endl;

	} else {
		outfile << indent << "return false;" << endl;
	};
};

void WznmWrappMain::writeDpchEngMerge(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, const uint ixWznmVApptarget
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	WznmMJob* job = NULL;

	WznmMBlock* blk = NULL;

	string dom, indent, subdlm, dpchjref;

	vector<string> ss;
	string s;

	bool first;

	getTargetStrs(ixWznmVApptarget, dom, indent, subdlm, dpchjref);

	first = true;

	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		dbswznm->tblwznmmrtdpch->loadRstBySQL("SELECT * FROM TblWznmMRtdpch WHERE refWznmMRtjob = " + to_string(rtj->ref) + " AND Merge = 1 ORDER BY sref ASC", false, rtds);

		if (rtds.nodes.size() > 0) {
			if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
				for (unsigned int j = 0; j < rtds.nodes.size(); j++) {
					rtd = rtds.nodes[j];

					if (dbswznm->tblwznmmblock->loadRecByRef(rtd->refWznmMBlock, &blk)) {
						outfile << indent;
						if (first) first = false;
						else outfile << "} else ";
						
						if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << "if ([self dpchEng:_dpcheng isOfType:Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << " withScrJref:" << dom << getScrJrefVar(dbswznm, rtj, job) << "]) {" << endl;
						else outfile << "if (dpchEngIsOfType(_dpcheng, Vec" << Prjshort << "VDpch" << subdlm << StrMod::uc(blk->sref) << ", " << dom << getScrJrefVar(dbswznm, rtj, job) << ")) {" << endl;

						if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) outfile << indent << "\t[self merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*) _dpcheng];" << endl;
						else if (ixWznmVApptarget == VecWznmVApptarget::JAVA) outfile << indent << "\tmerge" << blk->sref << "((" << job->sref << subdlm << Wznm::getSubsref(job, blk->sref) << ") _dpcheng);" << endl;
						else  outfile << indent << "\tmerge" << blk->sref << "((" << job->sref << subdlm << Wznm::getSubsref(job, blk->sref) << "*) _dpcheng);" << endl;
					};
				};

				delete job;
			};
		};
	};

	if (!first) outfile << indent << "};" << endl;
};
// IP cust --- IEND
