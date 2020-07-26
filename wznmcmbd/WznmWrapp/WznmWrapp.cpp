/**
	* \file WznmWrapp.cpp
	* Wznm operation pack global code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmopd.h>
#endif

#include "WznmWrapp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WznmWrapp
 ******************************************************************************/

// IP cust --- IBEGIN
void WznmWrapp::loadRtjtree(
			DbsWznm* dbswznm
			, const ubigint refWznmMApp
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	dbswznm->tblwznmmrtjob->loadRstBySQL("SELECT * FROM TblWznmMRtjob WHERE refWznmMApp = " + to_string(refWznmMApp) + " ORDER BY supLvl ASC, sref ASC", false, rtjs);

	// initial order by supLvl ; i.e. the insertion of sub-jobs is strictly in the order of supLvl=0, then supLvl=1, then supLvl=2, ...

	for (unsigned int i = 0; i < rtjs.nodes.size(); i++) {
		rtj = rtjs.nodes[i];

		for (unsigned int j = 0; j < i; j++) {
			if (rtjs.nodes[j]->ref == rtj->supRefWznmMRtjob) {
				// super job found, insert sub-job as last sub-job to this super job (alphabetical order is ensured by initial order)

				for (unsigned int k=j+1;k<i;k++) if (rtjs.nodes[k]->supRefWznmMRtjob == rtj->supRefWznmMRtjob) j++; else break;

				// move sub-job up to position j+1, push down all jobs between j+1 and i-1
				if ((j+1) != i) {
					for (unsigned int k = i; k > (j+1); k--) rtjs.nodes[k] = rtjs.nodes[k-1];
					rtjs.nodes[j+1] = rtj;
				};

				break;
			};
		};
	};
};

void WznmWrapp::writeRtjtree(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixVTarget
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	ListWznmMRtblock rtbs;
	WznmMRtblock* rtb = NULL;

	string indent;

	if (ixVTarget != VecWznmVMAppTarget::COCOA_OBJC) indent = "\t";

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

void WznmWrapp::writeRtobjs(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixVTarget
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

	if (ixVTarget == VecWznmVMAppTarget::JAVA) {
		pre = "public ";
		str = "String";
		subdlm = ".";
	} else {
		str = "string";
		subdlm = "::";
	};

	if (ixVTarget != VecWznmVMAppTarget::COCOA_OBJC) indent = "\t";

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

void WznmWrapp::writeChangeState(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, ListWznmMSequence& seqs
		) {
	WznmMSequence* seq = NULL;

	ListWznmMState stes;
	WznmMState* ste = NULL;

	string indent, dlm;

	string Appshort = StrMod::cap(app->Short);

	if (app->ixVTarget == VecWznmVMAppTarget::JAVA) indent = "\t\t\t";
	else indent = "\t\t";

	if (app->ixVTarget == VecWznmVMAppTarget::JAVA) dlm = ".";
	else dlm = "::";

	outfile << indent << "switch (ixVSte) {" << endl;

	// leaveSte...
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			outfile << indent << "\tcase Vec" << Appshort << "VSte" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ": ";

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "[self leaveSte" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
			else outfile <<  "leaveSte" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(); break;" << endl;
		};
	};

	outfile << indent << "};" << endl;
	outfile << endl;

	outfile << indent << "ixVSte = _ixVSte;" << endl;

	if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "[self refresh];" << endl;
	else outfile << indent << "refresh();" << endl;

	outfile << endl;

	outfile << indent << "switch (_ixVSte) {" << endl;

	// enterSte...
	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		for (unsigned int j = 0; j < stes.nodes.size(); j++) {
			ste = stes.nodes[j];

			outfile << indent << "\tcase Vec" << Appshort << "VSte" << dlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ": _ixVSte = ";

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "[self enterSte" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
			else outfile <<  "enterSte" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(); break;" << endl;
		};
	};

	outfile << indent << "};" << endl;
};

void WznmWrapp::writeEnterSte(
			DbsWznm* dbswznm
			, fstream& outfile
			, const string& Prjshort
			, WznmMApp* app
			, WznmMState* ste
		) {
	ubigint ref;

	WznmMRtjob* erj = NULL;
	WznmMJob* job = NULL;

	WznmMVector* eve = NULL;
	WznmMVectoritem* evi = NULL;

	WznmMState* esn = NULL;

	ListWznmAMBlockItem blkAitms;
	WznmAMBlockItem* blkAitm = NULL;

	string s2;

	string indent, subdlm, dom;

	string prjshort = StrMod::lc(Prjshort);

	string Appshort = StrMod::cap(app->Short);

	string s = StrMod::cap(StrMod::dotToUsc(ste->sref));

	if (app->ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
	} else {
		indent = "\t";
		subdlm = "::";
	};

	if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) dom = "";
	else if (app->ixVTarget == VecWznmVMAppTarget::JAVA) dom = "DOM.";
	else dom = "DOM->";

	if ((ste->eacIxVAction == VecWznmVMStateAction::VOID) || (ste->eacIxVAction == VecWznmVMStateAction::CUST)) {
		outfile << indent << "// IP enterSte" << s << " --- INSERT" << endl;

	} else {
		outfile << indent << "// IP enterSte" << s << " --- BEGIN" << endl;

		if (ste->eacIxVAction == VecWznmVMStateAction::LOGIN) {
			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "[self sendDpchApp:";
			else outfile << indent << "sendDpchApp(";

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "new Root" << Prjshort << "::DpchAppLogin(\"\", stg" << prjshort << "api.username, stg" << prjshort << "api.password, false, false, {Root" << Prjshort << "::DpchAppLogin::ALL})";
			else if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << "(new Root" << Prjshort << "()).new DpchAppLogin(\"\", stg" << prjshort << "api.username, stg" << prjshort << "api.password, false, false, new Integer[]{Root" << Prjshort << ".DpchAppLogin.ALL})";
			else outfile << "new Root" << Prjshort << "::DpchAppLogin(\"\", stg" << prjshort << "api->username, stg" << prjshort << "api->password, false, false, {Root" << Prjshort << "::DpchAppLogin::ALL})";

			if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "];" << endl;
			else outfile << ");" << endl;

		} else if ((ste->eacIxVAction == VecWznmVMStateAction::INIT) || (ste->eacIxVAction == VecWznmVMStateAction::DO)) {
			if (dbswznm->tblwznmmrtjob->loadRecByRef(ste->erjRefWznmMRtjob, &erj)) {
				if (dbswznm->tblwznmmjob->loadRecByRef(erj->refWznmMJob, &job)) {
					if (ste->eacIxVAction == VecWznmVMStateAction::INIT) {
						if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "[self sendDpchApp:";
						else outfile << indent << "sendDpchApp(";

						if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << "new DpchApp" << Prjshort << "Init(" << dom << getScrJrefVar(dbswznm, erj, job) << ")";
						else outfile << "new DpchApp" << Prjshort << "Init(" << dom << getScrJrefVar(dbswznm, erj, job) << ")";

						if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "];" << endl;
						else outfile << ");" << endl;

					} else if (ste->eacIxVAction == VecWznmVMStateAction::DO) {
						if (dbswznm->tblwznmmvector->loadRecByRef(ste->eveRefWznmMVector, &eve)) {
							if (dbswznm->tblwznmmvectoritem->loadRecByRef(ste->eviRefWznmMVectoritem, &evi)) {
								if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
											+ " AND sref LIKE 'DpchApp%Do'", ref)) {

									if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "[self sendDpchApp:";
									else outfile << indent << "sendDpchApp(";

									if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << "(new " << job->sref << "()).new DpchAppDo(";
									else outfile << "new " << job->sref << "::DpchAppDo(";

									outfile << dom << getScrJrefVar(dbswznm, erj, job);

									s2 = "";

									dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, blkAitms);

									for (unsigned int k = 0; k < blkAitms.nodes.size(); k++) {
										blkAitm = blkAitms.nodes[k];

										if (blkAitm->refWznmMVector != 0) {
											if (blkAitm->refWznmMVector == eve->ref) {
												s2 = blkAitm->sref;
												outfile << ", " << job->sref << subdlm << "Vec" << blkAitm->sref.substr(2) << subdlm << StrMod::uc(evi->sref);
											} else outfile << ", 0";
										};
									};

									if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << ", new Integer[]{";
									else outfile << ", {";

									if (blkAitms.nodes.size() == 2) outfile << job->sref << subdlm << "DpchAppDo" << subdlm << "ALL";
									else outfile << job->sref << subdlm << "DpchAppDo" << subdlm << "SCRJREF, " << job->sref << subdlm << "DpchAppDo" << subdlm << StrMod::uc(s2);
									outfile << "}";

									if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << ")];" << endl;
									else outfile << "));" << endl;
								};

								delete evi;
							};

							delete eve;
						};
					};

					delete job;
				};

				delete erj;
			};

		} else if (ste->eacIxVAction == VecWznmVMStateAction::STEP) {
			if (dbswznm->tblwznmmstate->loadRecByRef(ste->esnRefWznmMState, &esn)) {
				outfile << indent << "retval = Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(esn->sref)) << ";" << endl;
				delete esn;
			};
		};

		outfile << indent << "// IP enterSte" << s << " --- END" << endl;
	};
};

void WznmWrapp::writeLeaveSte(
			fstream& outfile
			, const uint ixVTarget
			, WznmMState* ste
		) {
	string indent;

	string s = StrMod::cap(StrMod::dotToUsc(ste->sref));

	if (ixVTarget == VecWznmVMAppTarget::JAVA) indent = "\t\t";
	else indent = "\t";

	if ((ste->lacIxVAction == VecWznmVMStateAction::VOID) || (ste->lacIxVAction == VecWznmVMStateAction::CUST)) {
		outfile << indent << "// IP leaveSte" << s << " --- INSERT" << endl;

	} else {
		outfile << indent << "// IP leaveSte" << s << " --- BEGIN" << endl;
		// other actions not foreseen
		outfile << indent << "// IP leaveSte" << s << " --- END" << endl;
	};
};

void WznmWrapp::writeMerge(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMApp* app
			, WznmMBlock* blk
			, const string& dpchsref
			, ListWznmMRtblock& rtbs
		) {
	WznmMRtblock* rtb = NULL;

	vector<string> maskitems;

	string indent, subdlm, dom;

	vector<string> ss;
	string s;

	if (app->ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
	} else {
		indent = "\t";
		subdlm = "::";
	};

	if (app->ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) dom = "";
	else if (app->ixVTarget == VecWznmVMAppTarget::JAVA) dom = "DOM.";
	else dom = "DOM->";

	// dispatch block items that serve as source for run-time data block are found in rtb->srcSrefsWznmAMBlockItem
	for (unsigned int i = 0; i < rtbs.nodes.size(); i++) {
		rtb = rtbs.nodes[i];

		StrMod::stringToVector(rtb->srcSrefsWznmAMBlockItem, ss);
		for (unsigned int j = 0; j < ss.size(); j++) {
			s = ss[j];

			if (s.find(blk->sref) == 0) {
				s = s.substr(blk->sref.length() + 1);
				maskitems.push_back(s);

				if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << indent << "if (dpcheng.has(";
				else outfile << indent << "if (dpcheng->has(";

				outfile << dpchsref << subdlm << StrMod::uc(s) << ")) ";

				if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << dom << rtb->sref << " = dpcheng." << s << ";" << endl;
				else outfile << dom << rtb->sref << " = dpcheng->" << s << ";" << endl;
			};
		};
	};

	if (maskitems.size() > 0) {
		outfile << endl;

		outfile << indent << "return(dpcheng";

		if (app->ixVTarget == VecWznmVMAppTarget::JAVA) outfile << ".hasAny(new Integer[]";
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

void WznmWrapp::writeHandleDpchEng(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixVTarget
			, const string& Appshort
			, const string& Prjshort
			, WznmMSequence* seq
			, ListWznmMState& stes
		) {
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;

	WznmMRtdpch* rtd = NULL;

	WznmMBlock* blk = NULL;

	WznmMState* ste = NULL;

	ListWznmAMStateStep steAstps;
	WznmAMStateStep* steAstp = NULL;

	WznmMState* snx = NULL;
	WznmMVectoritem* vit = NULL;

	string indent, subdlm;

	string s;
	size_t ptr;

	bool first, first2;

	if (ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
	} else {
		indent = "\t";
		subdlm = "::";
	};

	first = true;

	for (unsigned int j = 0; j < stes.nodes.size(); j++) {
		ste = stes.nodes[j];

		dbswznm->tblwznmamstatestep->loadRstBySQL("SELECT * FROM TblWznmAMStateStep WHERE refWznmMState = " + to_string(ste->ref), false, steAstps);

		if (ste->Custstep || (steAstps.nodes.size() > 0)) {
			outfile << endl;

			outfile << indent;
			if (first) first = false;
			else outfile << "} else ";
			outfile << "if (ixVSte == Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(ste->sref)) << ") {" << endl;

			if (ste->Custstep) {
				outfile << indent << "\t// IP handleDpchEng" << StrMod::cap(seq->sref) << "." << ste->sref << " --- INSERT" << endl;
			} else {
				first2 = true;
				
				for (unsigned int k = 0; k < steAstps.nodes.size(); k++) {
					steAstp = steAstps.nodes[k];

					if (dbswznm->tblwznmmstate->loadRecByRef(steAstp->snxRefWznmMState, &snx)) {
						rtj = NULL; job = NULL;
						if (steAstp->refWznmMRtjob != 0) {
							dbswznm->tblwznmmrtjob->loadRecByRef(steAstp->refWznmMRtjob, &rtj);
							if (rtj) dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job);
						};
						vit = NULL; if (steAstp->refWznmMVectoritem != 0) dbswznm->tblwznmmvectoritem->loadRecByRef(steAstp->refWznmMVectoritem, &vit);
						rtd = NULL; blk = NULL;
						if (steAstp->refWznmMRtdpch != 0) {
							dbswznm->tblwznmmrtdpch->loadRecByRef(steAstp->refWznmMRtdpch, &rtd);
							if (rtd) dbswznm->tblwznmmblock->loadRecByRef(rtd->refWznmMBlock, &blk);
						};

						s = writeHandleDpchEng_genSteastpif(dbswznm, ixVTarget, Prjshort, steAstp, rtj, job, vit, rtd, blk);

						if (s != "") {
							outfile << indent << "\t";
							if (first2) first2 = false;
							else outfile << "} else ";

							if (steAstp->Custcode) {
								ptr = s.rfind('\n');

								if (ptr == (s.length()-1)) {
									outfile << s;
									outfile << indent << "\t\t// IP handleDpchEng" << StrMod::cap(seq->sref) << "." << ste->sref << (k+1) << " --- INSERT" << endl;

									if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "\t\t[self changeState:Vec" << Appshort << "VSte::" << StrMod::uc(StrMod::dotToUsc(snx->sref)) << "];" << endl;
									else outfile << indent << "\t\tchangeState(Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(snx->sref)) << ");" << endl;

								} else {
									outfile << s.substr(0, ptr) << " {" << endl;
									outfile << indent << "\t\t// IP handleDpchEng" << StrMod::cap(seq->sref) << "." << ste->sref << (k+1) << " --- INSERT" << endl;
									for (size_t l=ptr+1;l<s.length();l++) outfile << "\t";

									if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "\t[self changeState:Vec" << Appshort << "VSte::" << StrMod::uc(StrMod::dotToUsc(snx->sref)) << "];" << endl;
									else outfile << indent << "\tchangeState(Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(snx->sref)) << ");" << endl;

									for (size_t l=ptr+1;l<s.length();l++) outfile << "\t";
									outfile << indent << "};" << endl;
								};

							} else {
								if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << s << indent <<  "\t\t[self changeState:Vec" << Appshort << "VSte::" << StrMod::uc(StrMod::dotToUsc(snx->sref)) << "];" << endl;
								else outfile << s << indent << "\t\tchangeState(Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(snx->sref)) << ");" << endl;
							};
						};

						if (rtj) delete rtj;
						if (job) delete job;
						if (vit) delete vit;
						if (rtd) delete rtd;
						if (blk) delete blk;

						delete snx;
					};
				};

				if (!first2) outfile << indent << "\t};" << endl;
			};
		};
	};

	if (!first) outfile << indent << "};" << endl;
};

string WznmWrapp::writeHandleDpchEng_genSteastpif(
			DbsWznm* dbswznm
			, const uint ixVTarget
			, const string& Prjshort
			, WznmAMStateStep* steAstp
			, WznmMRtjob* rtj
			, WznmMJob* job
			, WznmMVectoritem* vit
			, WznmMRtdpch* rtd
			, WznmMBlock* blk
		) {
	string retval;

	WznmMRtblock* rtb = NULL;
	WznmMRtblock* rtb2 = NULL;

	string dpchsref;

	string indent, subdlm, dom, dpchjref;

	vector<string> ss;

	if (ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t\t";
		subdlm = ".";
		dpchjref = "_dpcheng.scrJref";
	} else {
		indent = "\t\t";
		subdlm = "::";
		dpchjref = "_dpcheng->scrJref";
	};

	if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) dom = "";
	else if (ixVTarget == VecWznmVMAppTarget::JAVA) dom = "DOM.";
	else dom = "DOM->";

	if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::SGEEQ) && rtj && vit) {
		// find feed and continf run-time data block
		if (dbswznm->tblwznmmrtblock->loadRecBySQL("SELECT TblWznmMRtblock.* FROM TblWznmMRtblock, TblWznmMFeed WHERE TblWznmMRtblock.refWznmMRtjob = " + to_string(rtj->ref)
					+ " AND TblWznmMRtblock.refIxVTbl = " + to_string(VecWznmVMRtblockRefTbl::FED) + " AND TblWznmMRtblock.refUref = TblWznmMFeed.ref AND TblWznmMFeed.sref LIKE '%Sge'", &rtb))

			if (dbswznm->tblwznmmrtblock->loadRecBySQL("SELECT TblWznmMRtblock.* FROM TblWznmMRtblock, TblWznmMBlock WHERE TblWznmMRtblock.refWznmMRtjob = " + to_string(rtj->ref)
						+ " AND TblWznmMRtblock.refIxVTbl = " + to_string(VecWznmVMRtblockRefTbl::BLK) + " AND TblWznmMRtblock.refUref = TblWznmMBlock.ref AND TblWznmMBlock.sref LIKE 'ContInf%' ORDER BY TblWznmMBlock.sref ASC LIMIT 1", &rtb2)) {

				if (ixVTarget == VecWznmVMAppTarget::JAVA) retval = "if (" + dom + rtb->sref + ".getSrefByNum(" + dom + rtb2->sref + ".numFSge).equals(\"" + vit->sref + "\")) {\n";
				else retval = "if (" + dom + rtb->sref + ".getSrefByNum(" + dom + rtb2->sref + ".numFSge) == \"" + vit->sref + "\") {\n";
			};

	} else if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::JOBEX) && rtj && job) {
		if (ixVTarget == VecWznmVMAppTarget::JAVA) retval = "if (!" + dom + getScrJrefVar(dbswznm, rtj, job) + ".equals(\"\")) {\n";
		else retval = "if (" + dom + getScrJrefVar(dbswznm, rtj, job) + " != \"\") {\n";

	} else if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::JOBNEX) && rtj && job) {
		if (ixVTarget == VecWznmVMAppTarget::JAVA) retval = "if (" + dom + getScrJrefVar(dbswznm, rtj, job) + ".equals(\"\")) {\n";
		else retval = "if (" + dom + getScrJrefVar(dbswznm, rtj, job) + " == \"\") {\n";

	} else if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::CONFACC) && rtj && job) {
		if (job->ixVBasetype == VecWznmVMJobBasetype::SESS) {
			if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) retval = "if ([self dpchEngConfirmAccepted:_dpcheng]) {\n";
			else retval = "if (dpchEngConfirmAccepted(_dpcheng, \"\", \"\")) {\n";

			retval += indent + "\t" + dom + getScrJrefVar(dbswznm, rtj, job) + " = " + dpchjref + ";\n";

		} else if (steAstp->xsref != "") {
			if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) retval = "if ([self dpchEngConfirmAccepted:_dpcheng withScrJref:\"\" withSref:\"" + steAstp->xsref + "\"]) {\n";
			else retval = "if (dpchEngConfirmAccepted(_dpcheng, \"\", \"" + steAstp->xsref + "\")) {\n";

			retval += indent + "\t" + dom + getScrJrefVar(dbswznm, rtj, job) + " = " + dpchjref + ";\n";

		} else {
			if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) retval = "if ([self dpchEngConfirmAccepted:_dpcheng withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]) {\n";
			else retval = "if (dpchEngConfirmAccepted(_dpcheng, " + dom + getScrJrefVar(dbswznm, rtj, job) + ", \"\")) {\n";
		};

	} else if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::CONFDNY) && rtj && job) {
		if (job->ixVBasetype == VecWznmVMJobBasetype::SESS) {
			if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) retval = "if ([self dpchEngConfirmDenied:_dpcheng]) {\n";
			else if (ixVTarget == VecWznmVMAppTarget::JAVA)  retval = "if (dpchEngConfirmDenied(_dpcheng, \"\")) {\n";
			else retval = "if (dpchEngConfirmDenied(_dpcheng)) {\n";
		};

	} else if ((steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::DPCHRCV) && rtj && job && rtd && blk) {
		if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) retval = "if ([self dpchEng:_dpcheng isOfType:Vec" + Prjshort + "VDpch::" + StrMod::uc(blk->sref) + " withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]) {\n";
		else retval = "if (dpchEngIsOfType(_dpcheng, Vec" + Prjshort + "VDpch" + subdlm + StrMod::uc(blk->sref) + ", " + dom + getScrJrefVar(dbswznm, rtj, job) + ")) {\n";

		if (steAstp->srefsMask != "") {
			dpchsref = job->sref + subdlm + Wznm::getSubsref(job, blk->sref);
			StrMod::stringToVector(steAstp->srefsMask, ss);

			if (ixVTarget == VecWznmVMAppTarget::JAVA) retval += indent + "\tif (_dpcheng.hasAll(new Integer[]";
			else retval += indent + "\tif (_dpcheng->hasAll(";

			retval += "{";
			for (unsigned int i = 0; i < ss.size(); i++) {
				if (i != 0) retval += ",";
				retval += dpchsref + subdlm + StrMod::uc(ss[i]);
			};
			retval += "}))\n" + indent;
		};

	} else if (steAstp->ixVTrigger == VecWznmVAMStateStepTrigger::CUST) {
		retval = "if (" + steAstp->Cond + ") {\n";
	};

	return retval;
};

void WznmWrapp::writeDpchEngMerge(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixVTarget
			, const string& Prjshort
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	ListWznmMRtdpch rtds;
	WznmMRtdpch* rtd = NULL;

	WznmMJob* job = NULL;

	WznmMBlock* blk = NULL;

	string indent, subdlm, dom;

	vector<string> ss;
	string s;

	bool first;

	if (ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
	} else {
		indent = "\t";
		subdlm = "::";
	};

	if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) dom = "";
	else if (ixVTarget == VecWznmVMAppTarget::JAVA) dom = "DOM.";
	else dom = "DOM->";

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
						
						if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << "if ([self dpchEng:_dpcheng isOfType:Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << " withScrJref:" << dom << getScrJrefVar(dbswznm, rtj, job) << "]) {" << endl;
						else outfile << "if (dpchEngIsOfType(_dpcheng, Vec" << Prjshort << "VDpch" << subdlm << StrMod::uc(blk->sref) << ", " << dom << getScrJrefVar(dbswznm, rtj, job) << ")) {" << endl;

						if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "\t[self merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*) _dpcheng];" << endl;
						else if (ixVTarget == VecWznmVMAppTarget::JAVA) outfile << indent << "\tmerge" << blk->sref << "((" << job->sref << subdlm << Wznm::getSubsref(job, blk->sref) << ") _dpcheng);" << endl;
						else  outfile << indent << "\tmerge" << blk->sref << "((" << job->sref << subdlm << Wznm::getSubsref(job, blk->sref) << "*) _dpcheng);" << endl;
					};
				};

				delete job;
			};
		};
	};

	if (!first) outfile << "\t};" << endl;
};

void WznmWrapp::writeDpchEngHandle(
			DbsWznm* dbswznm
			, fstream& outfile
			, const uint ixVTarget
			, const string& Appshort
			, ListWznmMSequence seqs
		) {
	WznmMSequence* seq = NULL;

	ListWznmMState stes;

	string indent, subdlm;

	bool first;

	if (ixVTarget == VecWznmVMAppTarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
	} else {
		indent = "\t";
		subdlm = "::";
	};

	first = true;

	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		dbswznm->tblwznmmstate->loadRstBySQL("SELECT * FROM TblWznmMState WHERE seqRefWznmMSequence = " + to_string(seq->ref) + " ORDER BY seqNum ASC", false, stes);

		if (stes.nodes.size() > 1) {
			outfile << indent;
			if (first) first = false;
			else outfile << "} else ";

			outfile << "if ((ixVSte >= Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(stes.nodes[0]->sref)) << ") && (ixVSte <= Vec" << Appshort << "VSte" << subdlm << StrMod::uc(StrMod::dotToUsc(stes.nodes[stes.nodes.size()-1]->sref)) << ")) {" << endl;

			if (ixVTarget == VecWznmVMAppTarget::COCOA_OBJC) outfile << indent << "\tif ([self handleDpchEng" << StrMod::cap(seq->sref) << ":_dpcheng]) _refresh = false;" << endl;
			else outfile << indent << "\tif (handleDpchEng" << StrMod::cap(seq->sref) << "(_dpcheng)) _refresh = false;" << endl;
		};
	};

	if (!first) outfile << indent << "};" << endl;
};

string WznmWrapp::getScrJrefVar(
			DbsWznm* dbswznm
			, WznmMRtjob* rtj
			, WznmMJob* job
		) {
	string retval;

	WznmMRtblock* rtb = NULL;

	// locate scrJref
	if ((job->ixVBasetype == VecWznmVMJobBasetype::SESS) || (job->ixVBasetype == VecWznmVMJobBasetype::CRD)) {
		retval = "scrJref" + StrMod::cap(rtj->sref);

	} else if ((job->ixVBasetype == VecWznmVMJobBasetype::PNL) || (job->ixVBasetype == VecWznmVMJobBasetype::DLG)) {
		// look in statshr of superior job (either a card or a panel)
		if (dbswznm->tblwznmmrtblock->loadRecBySQL("SELECT TblWznmMRtblock.* FROM TblWznmMRtblock, TblWznmMBlock WHERE TblWznmMRtblock.refWznmMRtjob = "
					+ to_string(rtj->supRefWznmMRtjob) + " AND TblWznmMRtblock.refIxVTbl = " + to_string(VecWznmVMRtblockRefTbl::BLK)
					+ " AND TblWznmMBlock.ref = TblWznmMRtblock.refUref AND TblWznmMBlock.sref LIKE 'StatShr%'", &rtb)) {

			retval = rtb->sref + ".scrJref";

			if (job->ixVBasetype == VecWznmVMJobBasetype::PNL) retval += StrMod::cap(job->sref.substr(3+4+3));
			else retval += "Dlg" + StrMod::lc(job->sref.substr(3+4+3));

			delete rtb;
		};
	};

	return retval;
};
// IP cust --- IEND


