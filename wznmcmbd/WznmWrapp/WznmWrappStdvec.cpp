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

	// IP run --- INSERT

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
/*
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

void WznmWrappJbase::writeVecEvtJ(
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

		outfile << "\tpublic static final int " << StrMod::uc(StrMod::dotToUsc(evt->sref)) << " = " << num << ";" << endl;
		num++;
	};

	outfile << "// IP vec --- IEND" << endl;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;

	for (unsigned int i = 0; i < evts.nodes.size(); i++) {
		evt = evts.nodes[i];
		outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(evt->sref)) << ") return(\"" << evt->sref << "\");" << endl;
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

void WznmWrappJbase::writeVecSteJ(
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

		outfile << "\tpublic static final int " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << " = " << num++ << ";" << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-states for entering a sub-sequence" << endl;
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		outfile << "\tpublic static final int SUBSEQ_" << StrMod::uc(StrMod::dotToUsc(seq->sref)) << " = " << num++ << ";" << endl;
	};
	outfile << endl;

	outfile << "\t// alibi-state for returning from a sub-sequence" << endl;
	outfile << "\tpublic static final int RETSEQ = " << num++ << ";" << endl;
	outfile << endl;

	outfile << "\t// alibi-state for interrupting the state update loop" << endl;
	outfile << "\tpublic static final int BREAK = " << num++ << ";" << endl;

	outfile << "// IP vec --- IEND" << endl;

	// --- getSref
	outfile << "// IP getSref --- IBEGIN" << endl;

	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];
		outfile << "\t\tif (ix == " << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ") return(\"" << ste->sref << "\");" << endl;
	};

	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];
		outfile << "\t\tif (ix == SUBSEQ_" << StrMod::uc(StrMod::dotToUsc(seq->sref)) << ") return(\"subseq." << seq->sref << "\");" << endl;
	};

	outfile << "\t\tif (ix == RETSEQ) return(\"retseq\");" << endl;
	outfile << "\t\tif (ix == BREAK) return(\"break\");" << endl;

	outfile << "// IP getSref --- IEND" << endl;
};
*/
// IP cust --- IEND
