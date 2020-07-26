/**
	* \file WznmWrappBase.cpp
	* Wznm operation processor - write code for accessor app (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
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

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMApp* app = NULL;

	ListWznmMRtjob rtjs;
	ListWznmMSequence seqs;

	string Appshort;
	string Prjshort;

	fstream outfile;

	string s;

	if (dbswznm->tblwznmmapp->loadRecByRef(refWznmMApp, &app)) {
		loadRtjtree(dbswznm, refWznmMApp, rtjs);
		dbswznm->tblwznmmsequence->loadRstBySQL("SELECT * FROM TblWznmMSequence WHERE appRefWznmMApp = " + to_string(app->ref) + " ORDER BY appNum ASC", false, seqs);

		Appshort = StrMod::cap(app->Short);

		dbswznm->loadStringBySQL("SELECT TblWznmMProject.Short FROM TblWznmMProject, TblWznmMVersion WHERE TblWznmMProject.ref = TblWznmMVersion.prjRefWznmMProject AND TblWznmMVersion.ref = " + to_string(app->verRefWznmMVersion), Prjshort);
		Prjshort = StrMod::cap(Prjshort);

		// AppXxxx.h
		s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".h.ip";
		outfile.open(s.c_str(), ios::out);
		writeAppHcxx(dbswznm, outfile, app, Prjshort, rtjs, seqs);
		outfile.close();

		// AppXxxx.cpp/.mm
		if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".mm.ip";
		else s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeAppCxx(dbswznm, outfile, app, Prjshort, rtjs, seqs);
		outfile.close();

		// VecXxxxVSte.h
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VSte.h.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecSteH(dbswznm, outfile, seqs);
		outfile.close();

		// VecXxxxVSte.cpp
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VSte.cpp.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecSteCpp(dbswznm, outfile, seqs);
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
			, ListWznmMSequence& seqs
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	WznmMBlock* blk = NULL;

	WznmMSequence* seq = NULL;

	ListWznmMState stes;
	WznmMState* ste = NULL;

	string s;

	if (app->ixVTarget != VecWznmVMAppTarget::COCOA_OBJC) {
		// --- DOM.summary
		outfile << "// IP DOM.summary --- IBEGIN" << endl;
		writeRtjtree(dbswznm, outfile, app->ixVTarget, rtjs);
		outfile << "// IP DOM.summary --- IEND" << endl;

		// --- DOM.vars
		outfile << "// IP DOM.vars --- IBEGIN" << endl;
		writeRtobjs(dbswznm, outfile, app->ixVTarget, rtjs);
		outfile << "// IP DOM.vars --- IEND" << endl;
	};

	// --- enterLeaveStes
	outfile << "// IP enterLeaveStes --- IBEGIN" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			s = StrMod::cap(StrMod::dotToUsc(ste->sref));

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) {
				outfile << "- (unsigned int) enterSte" << s << ";" << endl;
				outfile << "- (void) leaveSte" << s << ";" << endl;
			} else {
				outfile << "\tunsigned int enterSte" << s << "();" << endl;
				outfile << "\tvoid leaveSte" << s << "();" << endl;
			};
		};

		outfile << endl;
	};
	outfile << "// IP enterLeaveStes --- IEND" << endl;

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
						if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (bool)merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*)dpcheng;" << endl;
						else outfile << "\tbool merge" << blk->sref << "(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "* dpcheng);" << endl;

						delete blk;
					};
				};

				delete job;
			};
		};
	};
	outfile << "// IP mergeDpchEngs --- IEND" << endl;

	// --- handleDpchEngs
	outfile << "// IP handleDpchEngs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (bool)handleDpchEng" << StrMod::cap(seq->sref) << ":(DpchEng" << Prjshort << "*)_dpcheng;" << endl;
		else outfile << "\tbool handleDpchEng" << StrMod::cap(seq->sref) << "(DpchEng" << Prjshort << "* _dpcheng);" << endl;
	};
	outfile << "// IP handleDpchEngs --- IEND" << endl;
};

void WznmWrappBase::writeAppCxx(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, const string& Prjshort
			, ListWznmMRtjob& rtjs
			, ListWznmMSequence& seqs
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	ListWznmMRtblock rtbs;

	WznmMBlock* blk = NULL;

	WznmMSequence* seq = NULL;

	ListWznmMState stes;
	WznmMState* ste = NULL;

	string dpchsref;

	string s;

	string prjshort = StrMod::lc(Prjshort);

	string Appshort = StrMod::cap(app->Short);

	if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) {
		// --- DOM.summary
		outfile << "// IP DOM.summary --- IBEGIN" << endl;
		writeRtjtree(dbswznm, outfile, app->ixVTarget, rtjs);
		outfile << "// IP DOM.summary --- IEND" << endl;

		// --- DOM.vars
		outfile << "// IP DOM.vars --- IBEGIN" << endl;
		writeRtobjs(dbswznm, outfile, app->ixVTarget, rtjs);
		outfile << "// IP DOM.vars --- IEND" << endl;
	};

	// --- changeState
	outfile << "// IP changeState --- IBEGIN" << endl;
	writeChangeState(dbswznm, outfile, app, seqs);
	outfile << "// IP changeState --- IEND" << endl;

	// --- enterLeaveStes
	outfile << "// IP enterLeaveStes --- IBEGIN" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			s = StrMod::cap(StrMod::dotToUsc(ste->sref));

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (unsigned int)enterSte" << s << " {" << endl;
			else outfile << "unsigned int App" << Appshort << "::enterSte" << s << "() {" << endl;

			outfile << "\tunsigned int retval = 0;" << endl;

			writeEnterSte(dbswznm, outfile, Prjshort, app, ste);

			outfile << "\treturn retval;" << endl;
			outfile << "};" << endl;
			outfile << endl;

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (void)leaveSte" << s << " {" << endl;
			else outfile << "void App" << Appshort << "::leaveSte" << s << "() {" << endl;

			writeLeaveSte(outfile, app->ixVTarget, ste);

			outfile << "};" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP enterLeaveStes --- IEND" << endl;

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

						if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (bool)merge" << blk->sref << ":(" << dpchsref << "*)dpcheng {" << endl;
						else {
							outfile << "bool App" << Appshort << "::merge" << blk->sref << "(" << endl;
							outfile << "\t\t\t" << dpchsref << "* dpcheng" << endl;
							outfile << "\t\t) {" << endl;
						};

						writeMerge(dbswznm, outfile, app, blk, dpchsref, rtbs);

						outfile << "};" << endl;
						outfile << endl;
					};
				};

				delete job;
			};
		};
	};
	outfile << "// IP mergeDpchEngs --- IEND" << endl;

	// --- handleDpchEngs
	outfile << "// IP handleDpchEngs --- IBEGIN" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "- (bool)handleDpchEng" << StrMod::cap(seq->sref) << ":(DpchEng" << Prjshort << "*)_dpcheng {" << endl;
		else {
			outfile << "bool App" << Appshort << "::handleDpchEng" << StrMod::cap(seq->sref) << "(" << endl;
			outfile << "\t\t\tDpchEng" << Prjshort << "* _dpcheng" << endl;
			outfile << "\t\t) {" << endl;
		};

		outfile << "\tbool skipRefresh = false;" << endl;
		outfile << "\tuint oldIxVSte = ixVSte;" << endl;

		writeHandleDpchEng(dbswznm, outfile, app->ixVTarget, Appshort, Prjshort, seq, stes);

		outfile << endl;
		outfile << "\tif (!skipRefresh && (ixVSte != oldIxVSte)) skipRefresh = true;" << endl;
		outfile << "\treturn skipRefresh;" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};
	outfile << "// IP handleDpchEngs --- IEND" << endl;

	// --- handleDpchEng.merge
	outfile << "// IP handleDpchEng.merge --- IBEGIN" << endl;
	writeDpchEngMerge(dbswznm, outfile, app->ixVTarget, Prjshort, rtjs);
	outfile << "// IP handleDpchEng.merge --- IEND" << endl;

	// --- handleDpchEng.handle
	outfile << "// IP handleDpchEng.handle --- IBEGIN" << endl;
	writeDpchEngHandle(dbswznm, outfile, app->ixVTarget, Appshort, seqs);
	outfile << "// IP handleDpchEng.handle --- IEND" << endl;
};

void WznmWrappBase::writeVecSteH(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
		) {
	WznmMSequence* seq = NULL;

	ListWznmMState stes;
	WznmMState* ste = NULL;

	unsigned int num;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;
	num = 1;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		outfile << "\t// " << seq->Title << endl;

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			outfile << "\tconst unsigned int " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << " = " << num << ";" << endl;
			num++;
		};

		outfile << endl;
	};
	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrappBase::writeVecSteCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
		) {
	WznmMSequence* seq = NULL;

	ListWznmMState stes;
	WznmMState* ste = NULL;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);
		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			outfile << "\tif (ix == " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ") return(\"" << ste->sref << "\");" << endl;
		};

		outfile << endl;
	};
	outfile << "// IP getSref --- IEND" << endl;
};


// IP cust --- IEND


