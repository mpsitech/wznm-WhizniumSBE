/**
	* \file WznmWrapp.cpp
	* Wznm operation pack global code (implementation)
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

				for (unsigned int k = j + 1; k < i; k++) if (rtjs.nodes[k]->supRefWznmMRtjob == rtj->supRefWznmMRtjob) j++; else break;

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
			, const uint ixWznmVApptarget
			, ListWznmMRtjob& rtjs
		) {
	WznmMRtjob* rtj = NULL;

	ListWznmMRtblock rtbs;
	WznmMRtblock* rtb = NULL;

	string indent;

	if (ixWznmVApptarget != VecWznmVApptarget::COCOA_OBJC) indent = "\t";

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

	if (ixWznmVApptarget != VecWznmVApptarget::COCOA_OBJC) indent = "\t";

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

void WznmWrapp::analyzeStes(
			DbsWznm* dbswznm
			, const ubigint refWznmMApp
			, ListWznmMSequence& seqs
			, ListWznmMState& stes
			, vector<unsigned int>& icsSeqs
			, vector<uint>& cntsEnt
			, vector<uint>& cntsReent
			, vector<uint>& cntsLve
		) {
	WznmMSequence* seq = NULL;
	WznmMState* ste = NULL;

	unsigned int ix0;

	uint cnt;

	dbswznm->tblwznmmsequence->loadRstByApp(refWznmMApp, false, seqs);

	stes.clear();
	cntsEnt.clear();
	cntsReent.clear();
	cntsLve.clear();

	for (unsigned int i = 0; i < seqs.nodes.size(); i++) {
		seq = seqs.nodes[i];

		ix0 = stes.nodes.size();

		dbswznm->tblwznmmstate->loadRstBySeq(seq->ref, true, stes);
		for (unsigned int j = ix0; j < stes.nodes.size(); j++) icsSeqs.push_back(i);
	};

	for (unsigned int i = 0; i < stes.nodes.size(); i++) {
		ste = stes.nodes[i];

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(ste->ref) + " AND ixVSection = " + to_string(VecWznmVAMStateActionSection::ENT), cnt);
		cntsEnt.push_back(cnt);

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(ste->ref) + " AND ixVSection = " + to_string(VecWznmVAMStateActionSection::REENT), cnt);
		cntsReent.push_back(cnt);

		dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmAMStateAction WHERE steRefWznmMState = " + to_string(ste->ref) + " AND ixVSection = " + to_string(VecWznmVAMStateActionSection::LVE), cnt);
		cntsLve.push_back(cnt);
	};
};

void WznmWrapp::writeHandleTrigger(
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

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "[self reenter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << ":ixVEvent withDpcheng:dpcheng]; break;" << endl;
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

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "[self leave" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
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

			if (app->ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "[self enter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "]; break;" << endl;
			else outfile <<  "enter" << StrMod::cap(StrMod::dotToUsc(ste->sref)) << "(); break;" << endl;
		};
	};
	outfile << "// IP handleTrigger.enter --- IEND" << endl;
};

void WznmWrapp::getSteTrigs(
			DbsWznm* dbswznm
			, const string& Prjshort
			, const string& Appshort
			, const uint ixWznmVApptarget
			, const ubigint refWznmMState
			, const string& dom
			, const string& subdlm
			, map<string,string>& trigs
		) {
	ListWznmAMStateTrig steAtrgs;
	WznmAMStateTrig* steAtrg = NULL;

	trigs.clear();

	dbswznm->tblwznmamstatetrig->loadRstBySte(refWznmMState, false, steAtrgs);

	for (unsigned int i = 0; i < steAtrgs.nodes.size(); i++) {
		steAtrg = steAtrgs.nodes[i];
		trigs[steAtrg->sref] = getSteTrigs_string(dbswznm, Prjshort, Appshort, ixWznmVApptarget, steAtrg, dom, subdlm);
	};
};

string WznmWrapp::getSteTrigs_string(
			DbsWznm* dbswznm
			, const string& Prjshort
			, const string& Appshort
			, const uint ixWznmVApptarget
			, WznmAMStateTrig* steAtrg
			, const string& dom
			, const string& subdlm
		) {
	string retval;

	WznmMEvent* evt = NULL;
	WznmMRtjob* rtj = NULL;
	WznmMJob* job = NULL;
	WznmMVectoritem* vit = NULL;
	WznmMRtdpch* rtd = NULL;
	WznmMBlock* blk = NULL;

	WznmMRtblock* rtb = NULL;
	WznmMRtblock* rtb2 = NULL;

	string dpchsref;

	vector<string> ss;

	if (steAtrg->refWznmMEvent != 0) dbswznm->tblwznmmevent->loadRecByRef(steAtrg->refWznmMEvent, &evt);
	if (steAtrg->refWznmMRtjob != 0) {
		dbswznm->tblwznmmrtjob->loadRecByRef(steAtrg->refWznmMRtjob, &rtj);
		if (rtj) dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job);
	};
	if (steAtrg->refWznmMVectoritem != 0) dbswznm->tblwznmmvectoritem->loadRecByRef(steAtrg->refWznmMVectoritem, &vit);
	if (steAtrg->refWznmMRtdpch != 0) {
		dbswznm->tblwznmmrtdpch->loadRecByRef(steAtrg->refWznmMRtdpch, &rtd);
		if (rtd) dbswznm->tblwznmmblock->loadRecByRef(rtd->refWznmMBlock, &blk);
	};
	if (steAtrg->Cond != "") dbswznm->tblwznmjamstatetrigcond->loadCndByStrTrg(steAtrg->ref, ixWznmVApptarget, steAtrg->Cond);

	if ((steAtrg->ixVType == VecWznmVAMStateTrigType::EVT) && evt) {
		retval = "ixVEvent == Vec" + Appshort + "VEvent" + subdlm + StrMod::uc(StrMod::dotToUsc(evt->sref));

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::SGEEQ) && rtj && vit) {
		// find feed and continf run-time data block
		if (dbswznm->tblwznmmrtblock->loadRecBySQL("SELECT TblWznmMRtblock.* FROM TblWznmMRtblock, TblWznmMFeed WHERE TblWznmMRtblock.refWznmMRtjob = " + to_string(rtj->ref)
					+ " AND TblWznmMRtblock.refIxVTbl = " + to_string(VecWznmVMRtblockRefTbl::FED) + " AND TblWznmMRtblock.refUref = TblWznmMFeed.ref AND TblWznmMFeed.sref LIKE '%Sge'", &rtb)) {

			if (dbswznm->tblwznmmrtblock->loadRecBySQL("SELECT TblWznmMRtblock.* FROM TblWznmMRtblock, TblWznmMBlock WHERE TblWznmMRtblock.refWznmMRtjob = " + to_string(rtj->ref)
						+ " AND TblWznmMRtblock.refIxVTbl = " + to_string(VecWznmVMRtblockRefTbl::BLK) + " AND TblWznmMRtblock.refUref = TblWznmMBlock.ref AND TblWznmMBlock.sref LIKE 'ContInf%' ORDER BY TblWznmMBlock.sref ASC LIMIT 1", &rtb2)) {

				if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval = dom + rtb->sref + ".getSrefByNum(" + dom + rtb2->sref + ".numFSge).equals(\"" + vit->sref + "\")";
				else retval = dom + rtb->sref + ".getSrefByNum(" + dom + rtb2->sref + ".numFSge) == \"" + vit->sref + "\"";

				delete rtb2;
			};

			delete rtb;
		};

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::JOBEX) && rtj && job) {
		if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval = "!" + dom + getScrJrefVar(dbswznm, rtj, job) + ".equals(\"\")";
		else retval = dom + getScrJrefVar(dbswznm, rtj, job) + " != \"\"";

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::JOBNEX) && rtj && job) {
		if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval = dom + getScrJrefVar(dbswznm, rtj, job) + ".equals(\"\")";
		else retval = dom + getScrJrefVar(dbswznm, rtj, job) + " == \"\"";

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::CONFACC) && rtj && job) {
		if (job->ixVBasetype == VecWznmVMJobBasetype::SESS) {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self dpchEngConfirmAccepted:_dpcheng]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, \"\", \"\")";

		} else if (steAtrg->xsref != "") {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self dpchEngConfirmAccepted:_dpcheng withScrJref:\"\" withSref:\"" + steAtrg->xsref + "\"]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, \"\", \"" + steAtrg->xsref + "\")";

		} else {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self dpchEngConfirmAccepted:_dpcheng withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, " + dom + getScrJrefVar(dbswznm, rtj, job) + ", \"\")";
		};

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::CONFDNY) && rtj && job) {
		if (job->ixVBasetype == VecWznmVMJobBasetype::SESS) {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self dpchEngConfirmDenied:_dpcheng]";
			else if (ixWznmVApptarget == VecWznmVApptarget::JAVA)  retval = "dpchEngConfirmDenied(_dpcheng, \"\")";
			else retval = "dpchEngConfirmDenied(_dpcheng)";
		};

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::DPCHRCV) && rtj && job && rtd && blk) {
		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self dpchEng:_dpcheng isOfType:Vec" + Prjshort + "VDpch::" + StrMod::uc(blk->sref) + " withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]";
		else retval = "dpchEngIsOfType(_dpcheng, Vec" + Prjshort + "VDpch" + subdlm + StrMod::uc(blk->sref) + ", " + dom + getScrJrefVar(dbswznm, rtj, job) + ")";

		if (steAtrg->srefsMask != "") {
			dpchsref = job->sref + subdlm + Wznm::getSubsref(job, blk->sref);
			StrMod::srefsToVector(steAtrg->srefsMask, ss);

			if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += " && _dpcheng.hasAll(new Integer[]";
			else retval += " && _dpcheng->hasAll(";

			retval += "{";
			for (unsigned int i = 0; i < ss.size(); i++) {
				if (i != 0) retval += ",";
				retval += dpchsref + subdlm + StrMod::uc(ss[i]);
			};
			retval += "})";
		};

	} else if (steAtrg->ixVType == VecWznmVAMStateTrigType::CUST) {
		retval = steAtrg->Cond;
	};

	if (evt) delete evt;
	if (rtj) delete rtj;
	if (job) delete job;
	if (vit) delete vit;
	if (rtd) delete rtd;
	if (blk) delete blk;

	return retval;
};

void WznmWrapp::writeState(
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

string WznmWrapp::writeState_action(
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
		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self sendDpchApp:";
		else retval = "sendDpchApp(";

		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval += "new Root" + Prjshort + "::DpchAppLogin(\"\", stg" + prjshort + "api.username, stg" + prjshort + "api.password, false, false, {Root" + Prjshort + "::DpchAppLogin::ALL})";
		else if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += "(new Root" + Prjshort + "()).new DpchAppLogin(\"\", stg" + prjshort + "api.username, stg" + prjshort + "api.password, false, false, new Integer[]{Root" + Prjshort + ".DpchAppLogin.ALL})";
		else retval += "new Root" + Prjshort + "::DpchAppLogin(\"\", stg" + prjshort + "api->username, stg" + prjshort + "api->password, false, false, {Root" + Prjshort + "::DpchAppLogin::ALL})";

		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval += "];";
		else retval += ");";

	} else if ((steAact->ixVType == VecWznmVAMStateActionType::INIT) || (steAact->ixVType == VecWznmVAMStateActionType::DO)) {
		if (dbswznm->tblwznmmrtjob->loadRecByRef(steAact->refWznmMRtjob, &rtj)) {
			if (dbswznm->tblwznmmjob->loadRecByRef(rtj->refWznmMJob, &job)) {
				if (steAact->ixVType == VecWznmVAMStateActionType::INIT) {
					if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self sendDpchApp:";
					else retval = "sendDpchApp(";

					if (ixWznmVApptarget == VecWznmVApptarget::JAVA) retval += "new DpchApp" + Prjshort + "Init(" + dom + getScrJrefVar(dbswznm, rtj, job) + ")";
					else retval += "new DpchApp" + Prjshort + "Init(" + dom + getScrJrefVar(dbswznm, rtj, job) + ")";

					if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval += "];";
					else retval += ");";

				} else if (steAact->ixVType == VecWznmVAMStateActionType::DO) {
					if (dbswznm->tblwznmmvector->loadRecByRef(steAact->refWznmMVector, &vec)) {
						if (dbswznm->tblwznmmvectoritem->loadRecByRef(steAact->refWznmMVectoritem, &vit)) {
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
										+ " AND sref LIKE 'DpchApp%Do'", ref)) {

								if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval = "[self sendDpchApp:";
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

								if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval += ")];";
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
				if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) retval += "[self startNotify];\n";
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

void WznmWrapp::writeMerge(
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

void WznmWrapp::writeDpchEngMerge(
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
						
						if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << "if ([self dpchEng:_dpcheng isOfType:Vec" << Prjshort << "VDpch::" << StrMod::uc(blk->sref) << " withScrJref:" << dom << getScrJrefVar(dbswznm, rtj, job) << "]) {" << endl;
						else outfile << "if (dpchEngIsOfType(_dpcheng, Vec" << Prjshort << "VDpch" << subdlm << StrMod::uc(blk->sref) << ", " << dom << getScrJrefVar(dbswznm, rtj, job) << ")) {" << endl;

						if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) outfile << indent << "\t[self merge" << blk->sref << ":(" << job->sref << "::" << Wznm::getSubsref(job, blk->sref) << "*) _dpcheng];" << endl;
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

void WznmWrapp::getTargetStrs(
			const uint ixWznmVApptarget
			, string& dom
			, string& indent
			, string& subdlm
			, string& dpchjref
		) {
	if (ixWznmVApptarget == VecWznmVApptarget::COCOA_OBJC) dom = "";
	else if (ixWznmVApptarget == VecWznmVApptarget::JAVA) dom = "DOM.";
	else dom = "DOM->";

	if (ixWznmVApptarget == VecWznmVApptarget::JAVA) {
		indent = "\t\t";
		subdlm = ".";
		dpchjref = "_dpcheng.scrJref";
	} else {
		indent = "\t";
		subdlm = "::";
		dpchjref = "_dpcheng->scrJref";
	};
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
