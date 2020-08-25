/**
	* \file WznmWrappBase.cpp
	* Wznm operation processor - write code for accessor app (implementation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrappBase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

/******************************************************************************
 namespace WznmWrappBase
 ******************************************************************************/

DpchRetWznm* WznmWrappBase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappBase* dpchinv
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

		dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(app->verRefWznmMVersion), Prjshort);
		Prjshort = StrMod::cap(Prjshort);

		// AppXxxx.h
		s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeAppHcxx(dbswznm, outfile, app, Prjshort, rtjs, evts, stes, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
		outfile.close();

		// AppXxxx.cpp/.mm
		if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".mm.ip";
		else s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeAppCxx(dbswznm, outfile, app, Prjshort, rtjs, evts, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
		outfile.close();

		// VecXxxxVEvent.h
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.h.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecEvtH(dbswznm, outfile, evts);
		outfile.close();

		// VecXxxxVEvent.cpp
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecEvtCpp(dbswznm, outfile, evts);
		outfile.close();

		// VecXxxxVState.h
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.h.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecSteH(dbswznm, outfile, seqs, stes, icsSeqs);
		outfile.close();

		// VecXxxxVState.cpp
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecSteCpp(dbswznm, outfile, seqs, stes);
		outfile.close();

		delete app;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrappBase::writeAppHcxx(
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

	if (app->ixWznmVApptarget != VecWznmVApptarget::COCOA_OBJC) {
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
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (unsigned int)enter" << s << ";" << endl;
			else outfile << "\tunsigned int enter" << s << "();" << endl;
		};

		if (ipAllNotSpec || cntsReent[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (unsigned int)renter" << s << ":(unsigned int)ixVEvent withDpcheng:(DpchEng" << Prjshort << "*)_dpcheng;" << endl;
			else outfile << "\tunsigned int reenter" << s << "(const unsigned int ixVEvent, DpchEng" << Prjshort << "* _dpcheng);" << endl;
		};

		if (ipAllNotSpec || cntsLve[i]) {
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (void)leave" << s << ";" << endl;
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
						if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (bool)merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*)dpcheng;" << endl;
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

void WznmWrappBase::writeAppCxx(
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

	if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) {
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
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (unsigned int)enter" << s << " {" << endl;
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
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (unsigned int)renter" << s << ":(unsigned int)ixVEvent withDpcheng:(DpchEng" << Prjshort << "*)_dpcheng {" << endl;
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
			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (unsigned int)leave" << s << " {" << endl;
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

						if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "- (bool)merge" << blk->sref << ":(" << dpchsref << "*)dpcheng {" << endl;
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

void WznmWrappBase::writeVecEvtH(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMEvent& evts
		) {
	WznmMEvent* evt = NULL;

	unsigned int num;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;

	num = 1;

	for (unsigned int i = 0; i < evts.nodes.size(); i++) {
		evt = evts.nodes[i];

		outfile << "\tconst unsigned int " << StrMod::uc(StrMod::dotToUsc(evt->sref)) << " = " << num << ";" << endl;
		num++;
	};

	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrappBase::writeVecEvtCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMEvent& evts
		) {
	WznmMEvent* evt = NULL;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;

	for (unsigned int i = 0; i < evts.nodes.size(); i++) {
		evt = evts.nodes[i];
		outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(evt->sref)) << ") return(\"" << evt->sref << "\");" << endl;
	};

	outfile << "// IP getSref --- IEND" << endl;
};

void WznmWrappBase::writeVecSteH(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, vector<unsigned int>& icsSeqs
		) {
	WznmMSequence* seq = NULL;
	WznmMState* ste = NULL;

	unsigned int ixSeqsLast;

	unsigned int num;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;

	ixSeqsLast = 0;
	ixSeqsLast--;

	num = 1;

	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		if (icsSeqs[i] != ixSeqsLast) {
			ixSeqsLast = icsSeqs[i];
			seq = seqs.nodes[ixSeqsLast];

			if (i != 0) outfile << endl;
			outfile << "\t// " << seq->Title << endl;
		};

		outfile << "\tconst unsigned int " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << " = " << num++ << ";" << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-states for entering a sub-sequence" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		outfile << "\tconst unsigned int SUBSEQ_" << StrMod::uc(StrMod::dotToUsc(seq->sref)) << " = " << num++ << ";" << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-state for returning from a sub-sequence" << endl;
	outfile << "\tconst unsigned int RETSEQ = " << num++ << ";" << endl;
	outfile << endl;

	outfile << "\t// alibi-state for interrupting the state update loop" << endl;
	outfile << "\tconst unsigned int BREAK = " << num++ << ";" << endl;
	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrappBase::writeVecSteCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
		) {
	WznmMSequence* seq = NULL;
	WznmMState* ste = NULL;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;

	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];
		outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ") return(\"" << ste->sref << "\");" << endl;
	};

	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];
		outfile << "\tif (ix == SUBSEQ_" << StrMod::uc(StrMod::dotToUsc(seq->sref)) << ") return(\"subseq." << seq->sref << "\");" << endl;
	};

	outfile << "\tif (ix == RETSEQ) return(\"retseq\");" << endl;
	outfile << "\tif (ix == BREAK) return(\"break\");" << endl;

	outfile << "// IP getSref --- IEND" << endl;
};
// IP cust --- IEND


