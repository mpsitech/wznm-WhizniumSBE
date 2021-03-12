/**
	* \file WznmWrappJbase.cpp
	* Wznm operation processor - write code for Java accessor app (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrappJbase.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrapp;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WznmWrappJbase
 ******************************************************************************/

DpchRetWznm* WznmWrappJbase::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrappJbase* dpchinv
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

		// AppXxxx.java
		s = xchg->tmppath + "/" + folder + "/App" + Appshort + ".java.ip";
		outfile.open(s.c_str(), ios::out);
		writeAppJ(dbswznm, outfile, app, Prjshort, rtjs, evts, seqs, stes, icsSeqs, cntsEnt, cntsReent, cntsLve, ipAllNotSpec);
		outfile.close();

		// DOMXxxx.java
		s = xchg->tmppath + "/" + folder + "/DOM" + Appshort + ".java.ip";
		outfile.open(s.c_str(), ios::out);
		writeDOMJ(dbswznm, outfile, rtjs);
		outfile.close();

		// VecXxxxVEvent.java
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VEvent.java.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecEvtJ(dbswznm, outfile, evts);
		outfile.close();

		// VecXxxxVState.java
		s = xchg->tmppath + "/" + folder + "/Vec" + Appshort + "VState.java.ip";
		outfile.open(s.c_str(), ios::out);
		writeVecSteJ(dbswznm, outfile, seqs, stes, icsSeqs);
		outfile.close();

		delete app;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
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

void WznmWrappJbase::writeDOMJ(
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
									outfile << "\t\t" << rtb->sref << " = " << getBlknew(dbswznm, hostjob, blk) << ";" << endl;
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

// stripped down copy from WznmWrjapiJob
string WznmWrappJbase::getBlknew(
			DbsWznm* dbswznm
			, WznmMJob* hostjob
			, WznmMBlock* blk
		) {
	// ex. "(new QryWznmPrjList()).new StgIac(0, 0, 0)"
	string retval = blk->sref;

	ListWznmAMBlockItem bits;
	WznmAMBlockItem* bit = NULL;

	dbswznm->tblwznmamblockitem->loadRstByBlk(blk->ref, false, bits);

	retval = "(new " + hostjob->sref + "()).new " + Wznm::getSubsref(hostjob, blk->sref);

	retval += "(";
	for (unsigned int i = 0; i < bits.nodes.size(); i++) {
		bit = bits.nodes[i];

		if (i != 0) retval += ", ";
		retval += getJDefault(getBitJType(bit));
	};
	retval += ")";

	return retval;
};

// exact copy from WznmWrjapiJob
string WznmWrappJbase::getBitJType(
			WznmAMBlockItem* bit
		) {
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEAN) return("boolean");
	if (bit->ixWznmVVartype == VecWznmVVartype::TINYINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SMALLINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::INT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINT) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::BIGINT) return("long");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINT) return("long");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOAT) return("float");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLE) return("double");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRING) return("String");
	if (bit->ixWznmVVartype == VecWznmVVartype::BOOLEANVEC) return("ArrayList<Boolean>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UTINYINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::USMALLINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::INTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UINTVEC) return("ArrayList<Integer>");
	if (bit->ixWznmVVartype == VecWznmVVartype::UBIGINTVEC) return("ArrayList<Long>");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATVEC) return("ArrayList<Float>");
	if (bit->ixWznmVVartype == VecWznmVVartype::FLOATMAT) return("Floatmat");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEVEC) return("ArrayList<Double>");
	if (bit->ixWznmVVartype == VecWznmVVartype::DOUBLEMAT) return("Doublemat");
	if (bit->ixWznmVVartype == VecWznmVVartype::STRINGVEC) return("ArrayList<String>");
	if (bit->ixWznmVVartype == VecWznmVVartype::VECSREF) return("int");
	if (bit->ixWznmVVartype == VecWznmVVartype::SCRREF) return("String");

	return("");
};

// exact copy from WznmWrjapi
string WznmWrappJbase::getJDefault(
			const string& jtype
		) {
	if (jtype == "boolean") return("false");
	if (jtype == "int") return("0");
	if (jtype == "long") return("0l");
	if (jtype == "float") return("0.0f");
	if (jtype == "double") return("0.0");
	if (jtype == "String") return("\"\"");

	return("new " + jtype + "()");
};
// IP cust --- IEND
