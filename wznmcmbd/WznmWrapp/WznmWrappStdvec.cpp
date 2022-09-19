/**
	* \file WznmWrappStdvec.cpp
	* Wznm operation processor - write standard vector code for accessor app (implementation)
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

#include "WznmWrappStdvec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrappStdvec
 ******************************************************************************/

DpchRetWznm* WznmWrappStdvec::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappStdvec* dpchinv
		) {
	ubigint refWznmMApp = dpchinv->refWznmMApp;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	WznmMApp* app = NULL;

	ListWznmMEvent evts;

	ListWznmMSequence seqs;
	ListWznmMState stes;
	vector<unsigned int> icsSeqs;
	vector<uint> cntsEnt;
	vector<uint> cntsReent;
	vector<uint> cntsLve;

	string Appshort;

	fstream outfile;

	string s;

	if (dbswznm->tblwznmmapp->loadRecByRef(refWznmMApp, &app)) {
		dbswznm->tblwznmmevent->loadRstByApp(refWznmMApp, false, evts);

		analyzeStes(dbswznm, app->ref, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve);

		Appshort = StrMod::cap(app->Short);

		// VecXxxxVEvent.swift, .java, .h/.cpp
		if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.swift.ip";
		else if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.java.ip";
		else if (app->ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.h.ip";
		outfile.open(s.c_str(), ios::out);

		writeVecEvtIpVec(dbswznm, outfile, evts, app->ixWznmVApptarget);

		if (app->ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) {
			outfile.close();
			s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.cpp.ip";
			outfile.open(s.c_str(), ios::out);
		};

		writeVecEvtIpGetSref(dbswznm, outfile, evts, app->ixWznmVApptarget);

		outfile.close();

		// VecXxxxVState.swift, .java, .h/.cpp
		if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.swift.ip";
		else if (app->ixWznmVApptarget == VecWznmVApptarget::JAVA) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.java.ip";
		else if (app->ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.h.ip";
		outfile.open(s.c_str(), ios::out);

		writeVecSteIpVec(dbswznm, outfile, seqs, stes, icsSeqs, app->ixWznmVApptarget);

		if (app->ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) {
			outfile.close();
			s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.cpp.ip";
			outfile.open(s.c_str(), ios::out);
		};

		writeVecSteIpGetSref(dbswznm, outfile, seqs, stes, app->ixWznmVApptarget);

		outfile.close();

		delete app;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrappStdvec::writeVecEvtIpVec(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMEvent& evts
			, const uint ixWznmVApptarget
		) {
	WznmMEvent* evt = NULL;

	unsigned int num;

	// --- vec
	outfile << "// IP vec --- IBEGIN" << endl;

	num = 1;

	for (unsigned int i = 0; i < evts.nodes.size(); i++) {
		evt = evts.nodes[i];
		outfile << wrConst(num++, evt->sref, ixWznmVApptarget) << endl;
	};

	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrappStdvec::writeVecEvtIpGetSref(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMEvent& evts
			, const uint ixWznmVApptarget
		) {
	WznmMEvent* evt = NULL;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;

	for (unsigned int i = 0; i < evts.nodes.size(); i++) {
		evt = evts.nodes[i];
		outfile << wrGetSref(evt->sref, ixWznmVApptarget) << endl;
	};

	outfile << "// IP getSref --- IEND" << endl;
};

void WznmWrappStdvec::writeVecSteIpVec(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, vector<unsigned int>& icsSeqs
			, const uint ixWznmVApptarget
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

		outfile << wrConst(num++, ste->sref, ixWznmVApptarget) << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-states for entering a sub-sequence" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		outfile << wrConst(num++, "subseq." + seq->sref, ixWznmVApptarget) << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-state for returning from a sub-sequence" << endl;
	outfile << wrConst(num++, "retseq", ixWznmVApptarget) << endl;
	outfile << endl;

	outfile << "\t// alibi-state for interrupting the state update loop" << endl;
	outfile << wrConst(num++, "break", ixWznmVApptarget) << endl;

	outfile << "// IP vec --- IEND" << endl;
};

void WznmWrappStdvec::writeVecSteIpGetSref(
			DbsWznm* dbswznm
			, fstream& outfile
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, const uint ixWznmVApptarget
		) {
	WznmMSequence* seq = NULL;
	WznmMState* ste = NULL;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;
	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];
		outfile << wrGetSref(ste->sref, ixWznmVApptarget) << endl;
	};

	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];
		outfile << wrGetSref("subseq." + seq->sref, ixWznmVApptarget) << endl;
	};

	outfile << wrGetSref("retseq", ixWznmVApptarget) << endl;
	outfile << wrGetSref("break", ixWznmVApptarget) << endl;

	outfile << "// IP getSref --- IEND" << endl;
};

string WznmWrappStdvec::wrConst(
			const unsigned int num
			, const string& sref
			, const uint ixWznmVApptarget
		) {
	if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) return("\tpublic static let " + StrMod::uc(StrMod::dotToUsc(sref)) + ": Int = " + to_string(num));
	if (ixWznmVApptarget == VecWznmVApptarget::JAVA) return("\tpublic static final int " + StrMod::uc(StrMod::dotToUsc(sref)) + " = " + to_string(num) + ";");
	if (ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) return("\tconst unsigned int " + StrMod::uc(StrMod::dotToUsc(sref)) + " = " + to_string(num) + ";");
};

string WznmWrappStdvec::wrGetSref(
			const string& sref
			, const uint ixWznmVApptarget
		) {
	if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) return("\tif (ix == " + StrMod::uc(StrMod::dotToUsc(sref)) + ") {return \"" + sref + "\"}");
	if (ixWznmVApptarget == VecWznmVApptarget::JAVA) return("\tif (ix == " + StrMod::uc(StrMod::dotToUsc(sref)) + ") return(\"" + sref + "\");");
	if (ixWznmVApptarget == VecWznmVApptarget::POSIX_CPP) return("if (ix == " + StrMod::uc(StrMod::dotToUsc(sref)) + ") return(\"" + sref + "\");");
};
// IP cust --- IEND
