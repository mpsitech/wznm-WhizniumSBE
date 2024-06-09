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

// IP ns.cust --- INSERT

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
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self dpchEngConfirmAccepted:_dpcheng]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, \"\", \"\")";

		} else if (steAtrg->xsref != "") {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self dpchEngConfirmAccepted:_dpcheng withScrJref:\"\" withSref:\"" + steAtrg->xsref + "\"]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, \"\", \"" + steAtrg->xsref + "\")";

		} else {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self dpchEngConfirmAccepted:_dpcheng withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]";
			else retval = "dpchEngConfirmAccepted(_dpcheng, " + dom + getScrJrefVar(dbswznm, rtj, job) + ", \"\")";
		};

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::CONFDNY) && rtj && job) {
		if (job->ixVBasetype == VecWznmVMJobBasetype::SESS) {
			if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self dpchEngConfirmDenied:_dpcheng]";
			else if (ixWznmVApptarget == VecWznmVApptarget::JAVA)  retval = "dpchEngConfirmDenied(_dpcheng, \"\")";
			else retval = "dpchEngConfirmDenied(_dpcheng)";
		};

	} else if ((steAtrg->ixVType == VecWznmVAMStateTrigType::DPCHRCV) && rtj && job && rtd && blk) {
		if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) retval = "[self dpchEng:_dpcheng isOfType:Vec" + Prjshort + "VDpch::" + StrMod::uc(blk->sref) + " withScrJref:" + dom + getScrJrefVar(dbswznm, rtj, job) + "]";
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

void WznmWrapp::getTargetStrs(
			const uint ixWznmVApptarget
			, string& dom
			, string& indent
			, string& subdlm
			, string& dpchjref
		) {
	if (ixWznmVApptarget == VecWznmVApptarget::COCOA_SWIFT) dom = "";
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
