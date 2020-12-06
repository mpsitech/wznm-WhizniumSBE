/**
	* \file WznmWrsrvPnl.cpp
	* Wznm operation processor - write specific job C++ code for panel (implementation)
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

#include "WznmWrsrvPnl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WznmWrsrv;

/******************************************************************************
 namespace WznmWrsrvPnl
 ******************************************************************************/

DpchRetWznm* WznmWrsrvPnl::run(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, DpchInvWznmWrsrvPnl* dpchinv
		) {
	ubigint refWznmMJob = dpchinv->refWznmMJob;
	string Prjshort = dpchinv->Prjshort;
	string folder = dpchinv->folder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	fstream hfile;
	fstream cppfile;

	WznmMJob* job = NULL;
	WznmMPanel* pnl = NULL;
	WznmMCard* car = NULL;

	vector<string> sesspsts;

	vector<string> carrecpsts;
	vector<string> carsesspsts;
	vector<string> carpsts;
	bool always, never;

	ListWznmMTable rectbls;

	ListWznmMControl cons;
	vector<unsigned int> icsBasecons;

	vector<string> bitsEval;
	vector<string> rulesEval;
	vector<string> exprsEval;

	string s;

	if (dbswznm->tblwznmmjob->loadRecByRef(refWznmMJob, &job)) {
		Wznm::getSesspsts(dbswznm, job->refWznmMVersion, sesspsts);

		if (dbswznm->tblwznmmpanel->loadRecByRef(job->refUref, &pnl)) {
			if (dbswznm->tblwznmmcard->loadRecByRef(pnl->carRefWznmMCard, &car)) {
				// include jump tables for detail panels only
				Wznm::getPnlrecs(dbswznm, job->refWznmMVersion, Prjshort, car, pnl, rectbls, ((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length())));

				Wznm::getCarrecpsts(dbswznm, car, carrecpsts);
				Wznm::getCarpsts(sesspsts, car, carsesspsts, carpsts, always, never);

				dbswznm->tblwznmmcontrol->loadRstByHktHku(VecWznmVMControlHkTbl::PNL, pnl->ref, false, cons);
				Wznm::getBasecons(dbswznm, cons, {VecWznmVMControlHkSection::CONT, VecWznmVMControlHkSection::CONTDETD, VecWznmVMControlHkSection::CONTREGD}, 0, icsBasecons);

				Wznm::getJobevals(dbswznm, job, bitsEval, rulesEval, exprsEval);

				// PnlXxxxYyyZzzzz.h, PnlXxxxYyyZzzzz.cpp
				s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".h.ip";
				hfile.open(s.c_str(), ios::out);
				s = xchg->tmppath + "/" + folder + "/" + pnl->sref + ".cpp.ip";
				cppfile.open(s.c_str(), ios::out);

				writePnlH(dbswznm, hfile, job, car, pnl, rectbls, cons, icsBasecons, Prjshort);
				writePnlCpp(dbswznm, cppfile, sesspsts, job, car, carrecpsts, carsesspsts, carpsts, pnl, rectbls, cons, icsBasecons, bitsEval, rulesEval, exprsEval, Prjshort);

				hfile.close();
				cppfile.close();

				delete car;
			};
			delete pnl;
		};
		delete job;
	};
	// IP run --- IEND

	return(new DpchRetWznm(VecWznmVDpch::DPCHRETWZNM, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WznmWrsrvPnl::writePnlH(
			DbsWznm* dbswznm
			, fstream& outfile
			, WznmMJob* job
			, WznmMCard* car
			, WznmMPanel* pnl
			, ListWznmMTable& rectbls
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, const string& Prjshort
		) {
	WznmMTable* rectbl = NULL;

	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	WznmMTablecol* tco = NULL;

	string prjshort = StrMod::lc(Prjshort);

	// --- specVar
	outfile << "// IP vars.spec --- IBEGIN" << endl;
	if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];

			outfile << "\t" << rectbl->sref.substr(3) << " rec" << StrMod::cap(rectbl->Short) << ";" << endl;
			if (Wznm::hasSubset(dbswznm, rectbl->ref)) outfile << "\tSbecore::uint ixWSubset" << StrMod::cap(rectbl->Short) << ";" << endl;

			outfile << endl;
		};

		if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
			outfile << "\tbool dirty;" << endl;
			outfile << endl;
		};
	};
	outfile << "// IP vars.spec --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;
	outfile << "\tDpchEng" << Prjshort << "* getNewDpchEng(std::set<Sbecore::uint> items);" << endl;
	outfile << endl;

	// -- refresh
	if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) {
				// ex.: refreshLstRly, refreshRly
				outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
				outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
			};
		};

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
					if (cplxtype == Concplxtype::LST_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) {
							// ex.: refreshLstOpt, refreshTxfOpt, refreshOpt (klref/klrefmult)
							outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							con = cons.nodes[ixTxf];
							outfile << "\tvoid refresh" << con->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) {
							// ex.: refreshLstEsg, refreshEsg (tblsref/tsrefmult)
							outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
						};

					} else if (cplxtype == Concplxtype::LST_TXTALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
							// ex.: refreshTxtInv (vecref/vrefand)
							con = cons.nodes[ixTxt];
							outfile << "\tvoid refresh" << con->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) {
							// ex.: refreshLstClu, refreshClu (tblref/trefclu)
							outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) {
							// ex.: refreshPupMim, refreshTxfMim, refreshMim (klref/klrefsng or klrefopt)
							outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							con = cons.nodes[ixTxf];
							outfile << "\tvoid refresh" << con->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
							outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_VBAR) {
						if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
							// ex.: refreshJ (tblref/trefmin of J)
							outfile << "\tvoid refresh" << baseconshort << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
						};

					} else if (cplxtype == Concplxtype::TXT_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) {
							// ex.: refreshTxtFlr (tblsref/tsrefsng)
							outfile << "\tvoid refresh" << basecon->sref << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
						};
					};

					delete tco;
				};
			};
		};
		outfile << endl;

		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];
			outfile << "\tvoid refreshRec" << StrMod::cap(rectbl->Short) << "(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems);" << endl;
		};
		outfile << endl;
	};

	outfile << "\tvoid refresh(Dbs" << Prjshort << "* dbs" << prjshort << ", std::set<Sbecore::uint>& moditems, const bool unmute = false);" << endl;
	outfile << endl;

	// updatePreset
	if ( ( (car->sref.find("Nav") == (3+4)) && ((pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM)) )
				|| (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM)
				|| (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) ) {
		outfile << "\tvoid updatePreset(Dbs" << Prjshort << "* dbs" << prjshort << ", const Sbecore::uint ix" << Prjshort << "VPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);" << endl;
	};

	// expand state management
	if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
		outfile << "\tvoid minimize(Dbs" << Prjshort << "* dbs" << prjshort << ", const bool notif = false, DpchEng" << Prjshort << "** dpcheng = NULL);" << endl;
		outfile << "\tvoid regularize(Dbs" << Prjshort << "* dbs" << prjshort << ", const bool notif = false, DpchEng" << Prjshort << "** dpcheng = NULL);" << endl;
	};

	outfile << "// IP spec --- IEND" << endl;
};

void WznmWrsrvPnl::writePnlCpp(
			DbsWznm* dbswznm
			, fstream& outfile
			, const vector<string>& sesspsts
			, WznmMJob* job
			, WznmMCard* car
			, const vector<string>& carrecpsts
			, const vector<string>& carsesspsts
			, const vector<string>& carpsts
			, WznmMPanel* pnl
			, ListWznmMTable& rectbls
			, ListWznmMControl& cons
			, vector<unsigned int>& icsBasecons
			, vector<string>& bitsEval
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, const string& Prjshort
		) {
	set<ubigint> unqrefs;
	ubigint ref;

	vector<bool> oksEval;

	ListWznmAMBlockItem dpchengdatabits;

	ListWznmMBlock jobblks;
	WznmMBlock* jobblk = NULL;

	ubigint refContiac, refContinf, refStatshr;

	ListWznmRMJobMJob jrjs;

	ListWznmMPanel crdpnls;
	WznmMPanel* crdpnl = NULL;

	WznmAMQueryOrder* qao = NULL;

	WznmMTable* rectbl = NULL;

	WznmMRelation* rel = NULL;

	WznmMTable* tbl = NULL;
	WznmMTable* tbl2 = NULL;

	bool hassbs;

	WznmMTablecol* tco = NULL;
	WznmMTablecol* tco2 = NULL;
	WznmMTablecol* tco21 = NULL;
	WznmMTablecol* tco22 = NULL;

	unsigned int cplxtype;
	string baseconsref, baseconshort;
	bool ldyn, dyn, rdyn, vbar;
	unsigned int ix0, ix1;
	unsigned int ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView;
	vector<unsigned int> icsButs;
	unsigned int ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt;
	vector<unsigned int> icsVbarcons;

	WznmMControl* basecon = NULL;
	WznmMControl* con = NULL;

	ListWznmJMControl conJs;
	WznmJMControl* conJ = NULL;

	unsigned int ixButNew;

	WznmMPreset* pst = NULL;
	WznmMStub* stb = NULL;
	WznmMVector* vec = NULL;
	
	ListWznmMVectoritem vits;
	WznmMVectoritem* vit = NULL;

	multimap<ubigint,string> vecrefsBaseconshorts;

	string ixCarpst;

	list<Trg*> trgs;

	string PRJSHORT = StrMod::uc(Prjshort);
	string prjshort = StrMod::lc(Prjshort);

	vector<string> ss;
	string s, s2;

	string indent;

	bool toNotFr;

	bool first, found, special;

	oksEval.resize(bitsEval.size(), false);

	if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref)
				+ " AND sref = 'DpchEng" + pnl->sref.substr(3) + "Data'", ref)) dbswznm->tblwznmamblockitem->loadRstByBlk(ref, false, dpchengdatabits);

	dbswznm->tblwznmmblock->loadRstBySQL("SELECT * FROM TblWznmMBlock WHERE refIxVTbl = " + to_string(VecWznmVMBlockRefTbl::JOB) + " AND refUref = " + to_string(job->ref), false, jobblks);

	refContiac = 0;
	refContinf = 0;
	refStatshr = 0;

	for (unsigned int i = 0; i < jobblks.nodes.size(); i++) {
		jobblk = jobblks.nodes[i];

		if (jobblk->sref.find("ContIac") == 0) refContiac = jobblk->ref;
		else if (jobblk->sref.find("ContInf") == 0) refContinf = jobblk->ref;
		else if (jobblk->sref.find("StatShr") == 0) refStatshr = jobblk->ref;
	};

	dbswznm->tblwznmrmjobmjob->loadRstBySup(job->ref, false, jrjs);

	ixCarpst = "Vec" + Prjshort + "VPreset::PRE" + PRJSHORT + "REF" + StrMod::uc(pnl->sref.substr(3+4, 3));

	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) dbswznm->tblwznmmpanel->loadRstByCar(pnl->carRefWznmMCard, false, crdpnls);

	// --- ns.spec
	outfile << "// IP ns.spec --- IBEGIN" << endl;
	outfile << "// IP ns.spec --- IEND" << endl;

	// --- constructor.spec1
	outfile << "// IP constructor.spec1 --- IBEGIN" << endl;
	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref, xchg->getRefPreset(" << ixCarpst << ", jref));" << endl;

		if (dbswznm->tblwznmamqueryorder->loadRecBySQL("SELECT TblWznmAMQueryOrder.* FROM TblWznmAMQueryOrder, TblWznmMQuery WHERE TblWznmAMQueryOrder.ref = TblWznmMQuery.inoRefAOrder AND TblWznmMQuery.sref = 'Qry"
					+ pnl->sref.substr(3) + "' AND TblWznmMQuery.refWznmMVersion = " + to_string(job->refWznmMVersion), &qao)) {
			outfile << "\txchg->addIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXORD, jref, Qry" << pnl->sref.substr(3) << "::VecVOrd::" << StrMod::uc(qao->Short) << ");" << endl;

			delete qao;
		};

		outfile << endl;

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		outfile << "\tdirty = false;" << endl;
		outfile << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		outfile << "\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref, 0);" << endl;
		outfile << endl;
	};
	outfile << "// IP constructor.spec1 --- IEND" << endl;

	// --- constructor.spec2
	outfile << "// IP constructor.spec2 --- IBEGIN" << endl;
	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	} else if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) ) {
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	} else if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		outfile << "\tset<uint> moditems;" << endl;
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
		};
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
		outfile << "\tset<uint> moditems;" << endl;
		// future: IP for custom initialization here
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\tstatshr.ix" << Prjshort << "VExpstate = ((xchg->getRefPreset(" << ixCarpst << ", jref)) ? Vec" << Prjshort << "VExpstate::MIND : Vec" << Prjshort << "VExpstate::REGD);" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		outfile << "\tset<uint> moditems;" << endl;
		outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
	};
	outfile << "// IP constructor.spec2 --- IEND" << endl;

	// --- constructor.spec3
	outfile << "// IP constructor.spec3 --- IBEGIN" << endl;
	if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) {
				outfile << "\txchg->addIxRefClstn(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "HUSRRUNVMOD_CRDUSREQ, jref, Clstn::VecVJobmask::ALL, 0, false, Vec" << Prjshort << "VCard::CRD" << PRJSHORT << StrMod::uc(baseconshort) << ", xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, jref));" << endl;
			};
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
		outfile << "\tupdatePreset(dbs" << prjshort << ", " << ixCarpst << ", jref);" << endl;

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		// keylist key mod events (so far, do not distinguish record-specific vs. not record-specific ; record-specific can not be handled in constructor but rather in refresh())
		unqrefs.clear();

		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
					if (cplxtype == Concplxtype::LST_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) unqrefs.insert(tco->fctUref);
					} else if (cplxtype == Concplxtype::PUP_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) unqrefs.insert(tco->fctUref);
					};
					delete tco;
				};
			};
		};

		for (auto it = unqrefs.begin(); it != unqrefs.end(); it++) {
			if (dbswznm->tblwznmmvector->loadRecByRef(*it, &vec)) {
				outfile << "\txchg->addIxClstn(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "KLSAKEYMOD_KLSEQ, jref, Clstn::VecVJobmask::ALL, 0, false, Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ");" << endl;
				delete vec;
			};
		};
		outfile << endl;

		outfile << "\tupdatePreset(dbs" << prjshort << ", " << ixCarpst << ", jref);" << endl;
	};
	outfile << "// IP constructor.spec3 --- IEND" << endl;

	// --- spec
	outfile << "// IP spec --- IBEGIN" << endl;

	outfile << "DpchEng" << Prjshort << "* " << pnl->sref << "::getNewDpchEng(" << endl;
	outfile << "\t\t\tset<uint> items" << endl;
	outfile << "\t\t) {" << endl;
	wrGetnewdpchengCpp(dbswznm, Prjshort, outfile, dpchengdatabits, job, jobblks, jrjs);
	outfile << "};" << endl;
	outfile << endl;

	// -- refresh
	if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) {
				// ex.: refreshLstRly
				outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				outfile << "\t\t\t, set<uint>& moditems" << endl;
				outfile << "\t\t) {" << endl;

				outfile << "\tStatShr oldStatshr(statshr);" << endl;
				outfile << endl;

				writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
				outfile << endl;

				outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
				outfile << "};" << endl;
				outfile << endl;

				// ex.: refreshRly
				outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
				outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
				outfile << "\t\t\t, set<uint>& moditems" << endl;
				outfile << "\t\t) {" << endl;

				outfile << "\tContIac oldContiac(contiac);" << endl;
				outfile << endl;

				outfile << "\tList" << Prjshort << "HistRMUserUniversal rst;" << endl;
				outfile << "\t" << Prjshort << "HistRMUserUniversal* rec = NULL;" << endl;
				outfile << endl;

				outfile << "\t// contiac" << endl;
				outfile << "\tcontiac.numF" << basecon->sref << " = 0;" << endl;
				outfile << endl;

				outfile << "\t// feedF" << basecon->sref << endl;
				outfile << "\tfeedF" << basecon->sref << ".clear();" << endl;
				outfile << endl;

				outfile << "\tdbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->loadRstByUsrCrd(xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "OWNER, jref), Vec" << Prjshort << "VCard::CRD" << PRJSHORT << StrMod::uc(baseconshort) << ", false, rst);" << endl;
				outfile << endl;

				outfile << "\tfor (unsigned int i = 0; i < rst.nodes.size(); i++) {" << endl;
				outfile << "\t\trec = rst.nodes[i];" << endl;
				if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
					outfile << "\t\tfeedF" << basecon->sref << ".appendRefTitles(rec->ref, Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec->unvUref, ix" << Prjshort << "VLocale));" << endl;
					delete stb;
				};
				outfile << "\t};" << endl;
				outfile << endl;

				outfile << "\tinsert(moditems, DpchEngData::FEEDF" << StrMod::uc(basecon->sref) << ");" << endl;
				outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
				outfile << endl;

				outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
				outfile << "};" << endl;
				outfile << endl;
			};
		};

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
					if (cplxtype == Concplxtype::LST_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) {
							// ex.: refreshLstOpt
							outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\tset<uint> nums;" << endl;
							outfile << endl;

							outfile << "\tvector<string> ss;" << endl;
							outfile << "\tstring s;" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac.numsF" << basecon->sref << ".clear();" << endl;
							outfile << endl;

							con = cons.nodes[ixTxf];
							outfile << "\tStrMod::stringToVector(contiac." << con->sref << ", ss);" << endl;
							outfile << endl;

							outfile << "\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
							outfile << "\t\ts = ss[i];" << endl;
							outfile << endl;

							outfile << "\t\tfor (unsigned int j = 0; j < feedF" << basecon->sref << ".size(); j++) {" << endl;
							outfile << "\t\t\tif (feedF" << basecon->sref << ".getSrefByNum(j+1) == s) {" << endl;
							outfile << "\t\t\t\tnums.insert(j+1);" << endl;
							outfile << "\t\t\t\tbreak;" << endl;
							outfile << "\t\t\t};" << endl;
							outfile << "\t\t};" << endl;
							outfile << "\t};" << endl;
							outfile << endl;

							outfile << "\tfor (auto it = nums.begin(); it != nums.end(); it++) contiac.numsF" << basecon->sref << ".push_back(*it);" << endl;
							outfile << endl;

							outfile << "\t// statshr" << endl;
							outfile << "\tstatshr." << con->sref << "Valid = ( (ss.size() == nums.size()) && (nums.size() == contiac.numsF" << basecon->sref << ".size()) );" << endl;
							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
							outfile << endl;

							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshTxfOpt
							con = cons.nodes[ixTxf];

							outfile << "void " << pnl->sref << "::refresh" << con->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac." << con->sref << " = \"\";" << endl;
							outfile << endl;

							outfile << "\tfor (unsigned int i = 0; i < contiac.numsF" << basecon->sref << ".size(); i++) {" << endl;
							outfile << "\t\tif (i != 0) contiac." << con->sref << " += \";\";" << endl;
							outfile << "\t\tcontiac." << con->sref << " += feedF" << basecon->sref << ".getSrefByNum(contiac.numsF" << basecon->sref << "[i]);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;

							outfile << "\t// statshr" << endl;
							outfile << "\tstatshr." << con->sref << "Valid = true;" << endl;
							outfile << endl;

							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshOpt
							outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\t// feedF" << basecon->sref << endl;
							if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
								outfile << "\tdbs" << prjshort << "->fillFeedFromKlst(Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ", ix" << Prjshort << "VLocale, feedF" << basecon->sref << ");" << endl;
								delete vec;
							};
							outfile << endl;

							outfile << "\tinsert(moditems, DpchEngData::FEEDF" << StrMod::uc(basecon->sref) << ");" << endl;
							outfile << endl;

							outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "};" << endl;
							outfile << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) {
							// ex.: refreshLstEsg
							outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
							outfile << endl;

							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshEsg
							outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\tvector<string> ss;" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac.numF" << basecon->sref << " = 0;" << endl;
							outfile << endl;

							outfile << "\t// feedF" << basecon->sref << endl;
							outfile << "\tfeedF" << basecon->sref << ".clear();" << endl;
							outfile << endl;

							con = cons.nodes[ixTxf];
							outfile << "\tStrMod::stringToVector(contiac." << con->sref << ", ss);" << endl;
							outfile << endl;

							outfile << "\t// IP refresh" << baseconshort << ".validate --- INSERT" << endl;
							outfile << endl;

							outfile << "\t// statshr" << endl;
							outfile << "\tstatshr." << con->sref << "Valid = (ss.size() == feedF" << basecon->sref << ".size());" << endl;
							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
							outfile << endl;

							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::LST_TXTALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
							// ex.: refreshTxtInv
							con = cons.nodes[ixTxt];

							outfile << "void " << pnl->sref << "::refresh" << con->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContInf oldContinf(continf);" << endl;
							outfile << endl;

							outfile << "\tuint ix = 0;" << endl;
							outfile << "\tfor (unsigned int i = 0; i < contiac.numsF" << basecon->sref << ".size(); i++) ix |= feedF" << basecon->sref << ".getIxByNum(contiac.numsF" << basecon->sref << "[i]);" << endl;
							con = cons.nodes[ixTxt];
							if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
								outfile << "\tcontinf." << con->sref << " = " << vec->sref << "::getSrefs(ix);" << endl;
								delete vec;
							};
							outfile << endl;

							outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
							outfile << "};" << endl;
							outfile << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) {
							// ex.: refreshLstClu
							outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
							outfile << endl;

							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshClu
							outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tContInf oldContinf(continf);" << endl;
							outfile << endl;

							outfile << "\tvector<ubigint> refs;" << endl;
							outfile << endl;

							outfile << "\tbool first;" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac.numF" << basecon->sref << " = 0;" << endl;
							outfile << endl;

							outfile << "\t// feedF" << basecon->sref << ", continf" << endl;
							outfile << "\tfeedF" << basecon->sref << ".clear();" << endl;
							con = cons.nodes[ixTxt];
							outfile << "\tcontinf." << con->sref << " = \"\";" << endl;
							outfile << endl;

							if (dbswznm->tblwznmmtable->loadRecByRef(tco->tblRefWznmMTable, &tbl)) {
								outfile << "\tif (rec" << StrMod::cap(tbl->Short) << "." << tco->sref << " != 0) dbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRefsBy" << StrMod::cap(tco->Short) << "(rec" << StrMod::cap(tbl->Short) << "." << tco->sref << ", false, refs);" << endl;
								outfile << endl;

								outfile << "\tfirst = true;" << endl;
								outfile << "\tfor (unsigned int i = 0; i < refs.size(); i++) {" << endl;

								outfile << "\t\tif (refs[i] != rec" << StrMod::cap(tbl->Short) << ".ref) {" << endl;

								if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
									outfile << "\t\t\tfeedF" << basecon->sref << ".appendRefTitles(refs[i], Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", refs[i], ix" << Prjshort << "VLocale));" << endl;
									outfile << endl;

									outfile << "\t\t\tif (first) first = false;" << endl;
									outfile << "\t\t\telse continf." << con->sref << " += \";\";" << endl;
									outfile << endl;

									outfile << "\t\t\tcontinf." << con->sref << " += Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", refs[i], ix" << Prjshort << "VLocale);" << endl;

									delete stb;
								};

								outfile << "\t\t};" << endl;
								outfile << "\t};" << endl;
								outfile << "\tif (first) continf." << con->sref << " = \"-\";" << endl;
								outfile << endl;

								delete tbl;
							};

							outfile << "\tinsert(moditems, DpchEngData::FEEDF" << StrMod::uc(basecon->sref) << ");" << endl;
							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
							outfile << endl;

							outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) {
							// ex.: refreshPupMim
							outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac.numF" << basecon->sref << " = 0;" << endl;
							outfile << endl;

							con = cons.nodes[ixTxf];
							outfile << "\tfor (unsigned int i = 0; i < feedF" << basecon->sref << ".size(); i++) {" << endl;
							outfile << "\t\tif (feedF" << basecon->sref << ".getSrefByNum(i+1) == contiac." << con->sref << ") {" << endl;
							outfile << "\t\t\tcontiac.numF" << baseconsref << " = i+1;" << endl;
							outfile << "\t\t\tbreak;" << endl;
							outfile << "\t\t};" << endl;
							outfile << "\t};" << endl;
							outfile << endl;

							outfile << "\t// statshr" << endl;
							outfile << "\tstatshr." << con->sref << "Valid = (contiac.numF" << baseconsref << " != 0);" << endl;
							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
							outfile << endl;

							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshTxfMim
							con = cons.nodes[ixTxf];

							outfile << "void " << pnl->sref << "::refresh" << con->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContIac oldContiac(contiac);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\t// contiac" << endl;
							outfile << "\tcontiac." << con->sref << " = feedF" << basecon->sref << ".getSrefByNum(contiac.numF" << basecon->sref << ");" << endl;
							outfile << endl;

							outfile << "\t// statshr" << endl;
							outfile << "\tstatshr." << con->sref << "Valid = true;" << endl;
							outfile << endl;

							outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;

							// ex.: refreshMim
							outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\t// feedF" << basecon->sref << endl;
							if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
								outfile << "\tdbs" << prjshort << "->fillFeedFromKlst(Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ", ix" << Prjshort << "VLocale, feedF" << basecon->sref << ");" << endl;
								delete vec;
							};
							outfile << endl;

							outfile << "\tinsert(moditems, DpchEngData::FEEDF" << StrMod::uc(basecon->sref) << ");" << endl;
							outfile << endl;

							outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_VBAR) {
						if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
							// ex.: refreshJ
							outfile << "void " << pnl->sref << "::refresh" << baseconshort << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							if (dbswznm->tblwznmmtable->loadRecByRef(tco->tblRefWznmMTable, &tbl)) {
								outfile << "\tList" << tbl->sref.substr(3) << " " << tbl->Short << "s;" << endl;
								outfile << "\t" << tbl->sref.substr(3) << "* " << tbl->Short << " = NULL;" << endl;
								outfile << endl;

								outfile << "\tstring s;" << endl;
								outfile << endl;

								outfile << "\t// feedF" << basecon->sref << endl;
								outfile << "\tfeedF" << basecon->sref << ".clear();" << endl;
								outfile << endl;

								if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable AND TblWznmMRelation.toRefWznmMTable = "
											+ to_string(tbl->ref) + " AND TblWznmMRelation.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), &tbl2)) {
									outfile << "\tdbs" << prjshort << "->" << StrMod::lc(tbl->sref) << "->loadRstBy" << StrMod::cap(tbl2->Short) << "(rec" << StrMod::cap(tbl2->Short) << ".ref, false, " << tbl->Short << "s);" << endl;
									delete tbl2;
								};
								outfile << endl;

								outfile << "\tfor (unsigned int i = 0; i < " << tbl->Short << "s.nodes.size(); i++) {" << endl;
								outfile << "\t\t" << tbl->Short << " = " << tbl->Short << "s.nodes[i];" << endl;
								outfile << endl;

								outfile << "\t\ts = \"\";" << endl;

								tco21 = NULL;
								tco22 = NULL;

								if (!dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND sref LIKE 'x1%' AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::PT), &tco21))
											dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND sref LIKE 'x1%' AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::SPT), &tco21);
								dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(tbl->ref) + " AND sref LIKE 'x1%' AND ixVAxisfct = " + to_string(VecWznmVMTablecolAxisfct::EPT), &tco22);

								if (tco21) tco21->sref = tbl->Short + "->" + tco21->sref;
								if (tco22) tco22->sref = tbl->Short + "->" + tco22->sref;

								if (tco21 && !tco22) {
									if (tco21->ixVAxisfct == VecWznmVMTablecolAxisfct::PT) {
										if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco21->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG)) {
											if (dbswznm->tblwznmmvector->loadRecByRef(tco21->fctUref, &vec)) {
												outfile << "\t\ts = dbs" << prjshort << "->getKlstTitleBySref(Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ", " << tco21->sref << ", ix" << Prjshort << "VLocale);" << endl;
												outfile << "\t\tif (s.length() == 0) s = " << tco21->sref << ";" << endl;

												delete vec;
											};

										} else if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC)) {
											if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
												outfile << "\t\ts = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", " << tco21->sref << ", ix" << Prjshort << "VLocale);" << endl;
												outfile << "\t\tif (s == \"-\") s = \"(\" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::GENERAL, ix" << Prjshort << "VLocale) + \")\";" << endl;

												delete stb;
											};

										} else if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco21->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN)) {
											if (dbswznm->tblwznmmvector->loadRecByRef(tco21->fctUref, &vec)) {
												outfile << "\t\ts = " << vec->sref << "::getTitle(" << tco21->sref << ", ix" << Prjshort << "VLocale);" << endl;
												outfile << "\t\tif (s.length() == 0) s = \"(\" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::GENERAL, ix" << Prjshort << "VLocale) + \")\";" << endl;

												delete vec;
											};

										} else if (tco21->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
											outfile << "\t\ts = to_string(" << tco21->sref << ");" << endl;

										} else if (tco21->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
											outfile << "\t\ts = to_string(" << tco21->sref << ");" << endl;

										} else if (tco21->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) {
											if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) outfile << "\t\ts = Ftm::date(" << tco21->sref << ");" << endl;
											else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) outfile << "\t\ts = Ftm::time(" << tco21->sref << ");" << endl;
											else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) outfile << "\t\ts = Ftm::stamp(" << tco21->sref << ");" << endl;
											else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) outfile << "\t\ts = Ftm::usecstamp(" << tco21->sref << ");" << endl;

											outfile << "\t\tif (s.length() == 0) s = \"(\" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::ALWAYS, ix" << Prjshort << "VLocale) + \")\";" << endl;
										};

									} else if (tco21->ixVAxisfct == VecWznmVMTablecolAxisfct::SPT) {
										if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco21->ixVSubtype != VecWznmVMTablecolSubtype::TMTIME)) {
											if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) s = "date";
											else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) s = "stamp";
											else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) s = "ustamp";

											outfile << "\t\tif (" << tco21->sref << " != 0) {" << endl;
											outfile << "\t\t\ts = Ftm::" << s << "(" << tco21->sref << ") + \" -\";" << endl;
											outfile << "\t\t\tif ((i+2) < " << tbl->Short << "s.nodes.size()) if (" << tbl->Short << "s.nodes[i+1]->" << tco21->sref.substr(tco21->sref.find("->")+2) << " != 0) s += \" \" + Ftm::" << s << "(" << tbl->Short << "s.nodes[i+1]->" << tco21->sref.substr(tco21->sref.find("->")+2) << ");" << endl;
											outfile << "\t\t} else s = \"(\" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::ALWAYS, ix" << Prjshort << "VLocale) + \")\";" << endl;
										};

									};
								} else if (tco21 && tco22) {
									if (tco21->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
										outfile << "\t\tif (" << tco21->sref << " < " << tco22->sref << ") s = to_string(" << tco21->sref << ") + \" - \" + to_string(" << tco22->sref << ");" << endl;
										outfile << "\t\telse if (" << tco21->sref << " == " << tco22->sref << ") s = \" - \" + to_string(" << tco21->sref << ");" << endl;
										outfile << "\t\telse s = to_string(" << tco21->sref << ") + \" - \";" << endl;

									} else if (tco21->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) {
										outfile << "\t\tif (" << tco21->sref << " < " << tco22->sref << ") s = to_string(" << tco21->sref << ") + \" - \" + to_string(" << tco22->sref << ");" << endl;
										outfile << "\t\telse if (" << tco21->sref << " == " << tco22->sref << ") s = \" - \" + to_string(" << tco21->sref << ");" << endl;
										outfile << "\t\telse s = to_string(" << tco21->sref << ") + \" - \";" << endl;

									} else if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco21->ixVSubtype != VecWznmVMTablecolSubtype::TMTIME)) {
										if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) s = "date";
										else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) s = "stamp";
										else if (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) s = "ustamp";

										outfile << "\t\tif (" << tco21->sref << " != 0) s = Ftm::" << s << "(" << tco21->sref << ") + \" \";" << endl;
										outfile << "\t\tif ((" << tco21->sref << " != 0) || (" << tco22->sref << " != 0)) s += \"-\";" << endl;
										outfile << "\t\tif (" << tco22->sref << " != 0) s += \" \" + Ftm::" << s << "(" << tco22->sref << ");" << endl;
										outfile << "\t\tif (s.length() == 0) s = \"(\" + Vec" << Prjshort << "VTag::getTitle(Vec" << Prjshort << "VTag::ALWAYS, ix" << Prjshort << "VLocale) + \")\";" << endl;

									} else if ((tco21->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco21->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME)) {
										outfile << "\t\tif (" << tco21->sref << " < " << tco22->sref << ") s = Ftm::time(" << tco21->sref << ") + \" - \" + Ftm::time(" << tco22->sref << ");" << endl;
										outfile << "\t\telse if (" << tco21->sref << " == " << tco22->sref << ") s = \" - \" + Ftm::time(" << tco21->sref << ");" << endl;
										outfile << "\t\telse s = Ftm::time(" << tco21->sref << ") + \" - \";" << endl;
									};
								};

								if (tco21) delete tco21;
								if (tco22) delete tco22;

								outfile << "\t\tfeedF" << basecon->sref << ".appendRefTitles(" << tbl->Short << "->ref, s);" << endl;
								outfile << "\t};" << endl;
								outfile << endl;

								outfile << "\tinsert(moditems, DpchEngData::FEEDF" << StrMod::uc(basecon->sref) << ");" << endl;
								outfile << endl;

								outfile << "\trefreshRec" << StrMod::cap(tbl->Short) << "(dbs" << prjshort << ", moditems);" << endl;
								outfile << endl;

								delete tbl;
							};

							outfile << "};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::TXT_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) {
							// ex.: refreshTxtFlr
							outfile << "void " << pnl->sref << "::refresh" << basecon->sref << "(" << endl;
							outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
							outfile << "\t\t\t, set<uint>& moditems" << endl;
							outfile << "\t\t) {" << endl;

							outfile << "\tContInf oldContinf(continf);" << endl;
							outfile << "\tStatShr oldStatshr(statshr);" << endl;
							outfile << endl;

							outfile << "\t// IP refresh" << basecon->sref << " --- BEGIN" << endl;
							if (dbswznm->tblwznmmtable->loadRecByRef(tco->fctUref, &tbl)) {
								outfile << "\tubigint ref" << StrMod::cap(tbl->Short) << " = 0;" << endl;
								outfile << endl;

								con = cons.nodes[ixTxf];
								outfile << "\tdbs" << prjshort << "->loadRefBySQL(\"SELECT ref FROM " << tbl->sref << " WHERE sref = '\" + contiac." << con->sref << " + \"'\", ref" << StrMod::cap(tbl->Short) << ");" << endl;
								outfile << endl;

								if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
									outfile << "\tcontinf." << basecon->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", ref" << StrMod::cap(tbl->Short) << ", ix" << Prjshort << "VLocale);" << endl;
									outfile << endl;

									delete stb;
								};

								outfile << "\tstatshr." << con->sref << "Valid = (ref" << StrMod::cap(tbl->Short) << " != 0);" << endl;

								delete tbl;
							};

							writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);

							outfile << "\t// IP refresh" << basecon->sref << " --- END" << endl;
							outfile << endl;

							outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
							outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
							outfile << "};" << endl;
							outfile << endl;
						};
					};

					delete tco;
				};
			};
		};

		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];

			hassbs = Wznm::hasSubset(dbswznm, rectbl->ref);

			outfile << "void " << pnl->sref << "::refreshRec" << StrMod::cap(rectbl->Short) << "(" << endl;
			outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
			outfile << "\t\t\t, set<uint>& moditems" << endl;
			outfile << "\t\t) {" << endl;

			// - block declarations
			if (refContiac != 0) outfile << "\tContIac oldContiac(contiac);" << endl;
			if (refContinf != 0) outfile << "\tContInf oldContinf(continf);" << endl;
			if (refStatshr != 0) outfile << "\tStatShr oldStatshr(statshr);" << endl;
			outfile << endl;

			// - ics
			found = false;
			for (unsigned int j = 0; j < icsBasecons.size(); j++) {
				basecon = cons.nodes[icsBasecons[j]];

				Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, j, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
							icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
					if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
						if (cplxtype == Concplxtype::LST_TXTALT) if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
							found = true;
							break;
						};

						delete tco;
					};
				};
			};

			if (found) {
				outfile << "\tset<uint> ics;" << endl;
				outfile << endl;
			};

			// - record variable declaration and load
			outfile << "\t" << rectbl->sref.substr(3) << "* _rec" << StrMod::cap(rectbl->Short) << " = NULL;" << endl;
			outfile << endl;

			outfile << "\tif (dbs" << prjshort << "->" << StrMod::lc(rectbl->sref) << "->loadRecByRef(rec" << StrMod::cap(rectbl->Short) << ".ref, &_rec" << StrMod::cap(rectbl->Short) << ")) {" << endl;
			outfile << "\t\trec" << StrMod::cap(rectbl->Short) << " = *_rec" << StrMod::cap(rectbl->Short) << ";" << endl;
			if (hassbs) outfile << "\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = dbs" << prjshort << "->getIxWSubsetBy" << rectbl->sref.substr(3) << "(_rec" << StrMod::cap(rectbl->Short) << ");" << endl;
			outfile << "\t\tdelete _rec" << StrMod::cap(rectbl->Short) << ";" << endl;

			if (hassbs) {
				outfile << "\t} else {" << endl;
				outfile << "\t\trec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
				outfile << "\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = 0;" << endl;
				outfile << "\t};" << endl;
			} else {
				outfile << "\t} else rec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
			};
			outfile << endl;

			if (i == 0) {
				outfile << "\tdirty = false;" << endl;
				outfile << endl;
			};

			// - sub-record load
			if (rectbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) {
				for (unsigned int j=i+1;j<rectbls.nodes.size(); j++) {
					tbl2 = rectbls.nodes[j];

					if ( (i == 0) && (tbl2->ixVBasetype == VecWznmVMTableBasetype::MAIN) ) {
						// inc/u1nsubinc
						if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rectbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND fctUref = " + to_string(tbl2->ref), &tco)) {
							outfile << "\trec" << StrMod::cap(tbl2->Short) << ".ref = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
							outfile << endl;

							delete tco;
						};

					} else if (tbl2->ixVBasetype == VecWznmVMTableBasetype::JUMP) {
						// check if jump of rectbl
						if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMRelation WHERE frRefWznmMTable = " + to_string(rectbl->ref) + " AND toRefWznmMTable = "
									+ to_string(tbl2->ref) + " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), ref)) {

							if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rectbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND fctUref = " + to_string(tbl2->ref), &tco)) {
								outfile << "\trec" << StrMod::cap(tbl2->Short) << ".ref = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;

								outfile << "\tif (rec" << StrMod::cap(rectbl->Short) << ".ref == 0) xchg->removeClstns(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << StrMod::uc(tbl2->Short) << "MOD_" << StrMod::uc(rectbl->Short) << "EQ, jref);" << endl;
								outfile << "\telse xchg->addRefClstn(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << StrMod::uc(tbl2->Short) << "MOD_" << StrMod::uc(rectbl->Short) << "EQ, jref, Clstn::VecVJobmask::ALL, 0, true, rec" << StrMod::cap(rectbl->Short) << ".ref);" << endl;

								outfile << endl;

								delete tco;
							};
						};
					};
				};
			};

			// - call listener update for clustered table
			if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rectbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF) + " AND ixVSubtype = " + to_string(VecWznmVMTablecolSubtype::TREFCLU), &tco)) {
				outfile << "\tif (rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << " == 0) xchg->removeClstns(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << StrMod::uc(rectbl->Short) << "MOD_" << StrMod::uc(tco->Short) << "EQ, jref);" << endl;
				outfile << "\telse xchg->addRefClstn(Vec" << Prjshort << "VCall::CALL" << PRJSHORT << StrMod::uc(rectbl->Short) << "MOD_" << StrMod::uc(tco->Short) << "EQ, jref, Clstn::VecVJobmask::ALL, 0, true, rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
				outfile << endl;

				delete tco;
			};

			// - record to content
			for (unsigned int j = 0; j < icsBasecons.size(); j++) {
				basecon = cons.nodes[icsBasecons[j]];

				Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, j, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
							icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
					if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
						if (tco->tblRefWznmMTable == rectbl->ref) {
							if (cplxtype == Concplxtype::CHK) {
								if (tco->ixVBasetype == VecWznmVMTablecolBasetype::BOOLVAL) {
									outfile << "\tcontiac." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};

							} else if (cplxtype == Concplxtype::LST_TXFALT) {
								if ( ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) )
											|| ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) ) {
									con = cons.nodes[ixTxf];
									outfile << "\tcontiac." << con->sref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};

							} else if (cplxtype == Concplxtype::LST_TXTALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
									if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
										outfile << "\tcontiac.numsF" << baseconsref << ".clear();" << endl;
										outfile << "\t" << vec->sref << "::getIcs(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ", ics);" << endl;
										outfile << "\tfor (auto it = ics.begin(); it != ics.end(); it++) contiac.numsF" << baseconsref << ".push_back(feedF" << basecon->sref << ".getNumByIx(*it));" << endl;

										delete vec;
									};
								};

							} else if (cplxtype == Concplxtype::PUP) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFLIN) ) {
									outfile << "\tcontiac.numF" << baseconsref << " = feedF" << basecon->sref << ".getNumByIx(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								};

							} else if (cplxtype == Concplxtype::PUP_PUP) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) ) {
									// ...
								};

							} else if (cplxtype == Concplxtype::PUP_TXFALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ( (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) ) ) {
									con = cons.nodes[ixTxf];
									outfile << "\tcontiac." << con->sref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};

							} else if (cplxtype == Concplxtype::PUP_VBAR) {
								if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
									outfile << "\tcontiac.numF" << baseconsref << " = feedF" << basecon->sref << ".getNumByRef(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								};

							} else if (cplxtype == Concplxtype::SLD) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL)
											|| (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) ) {
									outfile << "\tcontiac." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};

							} else if (cplxtype == Concplxtype::TXF) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) ) {
									outfile << "\tcontiac." << baseconsref << " = to_string(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::UVSREF) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) ){
									outfile << "\tcontiac." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) ) {
									outfile << "\tcontiac." << baseconsref << " = Ftm::date(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) ) {
									outfile << "\tcontiac." << baseconsref << " = Ftm::time(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) ) {
									outfile << "\tcontiac." << baseconsref << " = Ftm::stamp(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) ) {
									outfile << "\tcontiac." << baseconsref << " = Ftm::usecstamp(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								};

							} else if (cplxtype == Concplxtype::TXT) {
								if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDSREF) {
									outfile << "\tcontinf." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;

								} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) {
									outfile << "\tcontinf." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;

								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFSPEC) ) {
									if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
										outfile << "\tcontinf." << baseconsref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;
										delete stb;
									};

								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFMIN) ) {
									if (dbswznm->tblwznmmstub->loadRecByRef(basecon->stdRefWznmMStub, &stb)) {
										outfile << "\tcontinf." << baseconsref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;
										delete stb;
									};

								} else if (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) {
									outfile << "\tcontinf." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;

								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
									if (dbswznm->tblwznmmvector->loadRecByRef(tco->fctUref, &vec)) {
										outfile << "\tcontinf." << baseconsref << " = " << vec->sref << "::getSrefs(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
										delete vec;
									};

								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::DBLVAL) ) {
									outfile << "\tcontinf." << baseconsref << " = to_string(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TXTVAL) || (tco->ixVBasetype == VecWznmVMTablecolBasetype::EXPR) ){
									outfile << "\tcontinf." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMDATE) ) {
									outfile << "\tcontinf." << baseconsref << " = Ftm::date(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMTIME) ) {
									outfile << "\tcontinf." << baseconsref << " = Ftm::time(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMSTAMP) ) {
									outfile << "\tcontinf." << baseconsref << " = Ftm::stamp(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TIMEVAL) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TMUSTAMP) ) {
									outfile << "\tcontinf." << baseconsref << " = Ftm::usecstamp(rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ");" << endl;
								};

							} else if (cplxtype == Concplxtype::TXT_PUP) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFUNIV) ) {
									con = cons.nodes[ixPup];
									if (dbswznm->tblwznmmtablecol->loadRecByRef(con->refUref, &tco2)) {
										outfile << "\tcontiac.numF" << con->sref << " = feedF" << con->sref << ".getNumByIx(rec" << StrMod::cap(rectbl->Short) << "." << tco2->sref << ");" << endl;

										if (dbswznm->tblwznmmvector->loadRecByRef(tco2->fctUref, &vec)) {
											dbswznm->tblwznmjmcontrol->loadRstByCon(basecon->ref, false, conJs);

											first = true;

											for (unsigned int j = 0; j < conJs.nodes.size(); j++) {
												conJ = conJs.nodes[j];

												if (dbswznm->tblwznmmvectoritem->loadRecByRef(conJ->x1RefWznmMVectoritem, &vit)) {
													if (dbswznm->tblwznmmstub->loadRecByRef(conJ->stdRefWznmMStub, &stb)) {

														outfile << "\t";

														if (first) first = false;
														else outfile << "else ";

														outfile << "if (rec" << StrMod::cap(rectbl->Short) << "." << tco2->sref << " == " << vec->sref << "::" << StrMod::uc(vit->sref) << ") continf." << baseconsref
																	<< " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ", ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;

														delete stb;
													};

													delete vit;
												};
											};

											if (!first) outfile << "\telse continf." << baseconsref << " = \"-\";" << endl;

											delete vec;
										};

										delete tco2;
									};
								};

							} else if (cplxtype == Concplxtype::TXT_TXFALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) {
									con = cons.nodes[ixTxf];
									outfile << "\tcontiac." << con->sref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};

							} else if (cplxtype == Concplxtype::UPD) {
								if (tco->ixVBasetype == VecWznmVMTablecolBasetype::INTVAL) {
									outfile << "\tcontiac." << baseconsref << " = rec" << StrMod::cap(rectbl->Short) << "." << tco->sref << ";" << endl;
								};
							};
						};
					};

					delete tco;
				};
			};
			outfile << endl;

			// - Active/Avail
			for (unsigned int j = 0; j < icsBasecons.size(); j++) {
				basecon = cons.nodes[icsBasecons[j]];

				Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, j, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
							icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
					if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
						if (tco->tblRefWznmMTable == rectbl->ref) writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
						delete tco;
					};
				} else if ((basecon->refIxVTbl == VecWznmVMControlRefTbl::TBL) && (basecon->refUref == rectbl->ref)) {
					// separator and heading for included tables
					writePnlCpp_evals(outfile, cons, ix0, ix1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);
				};
			};

			// - diff
			if (refContiac != 0) outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;
			if (refContinf != 0) outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
			if (refStatshr != 0) outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
			outfile << endl;

			// - inc/u1nsubinc refresh invocations
			if (i == 0) {
				for (unsigned int j=1;j<rectbls.nodes.size(); j++) {
					tbl2 = rectbls.nodes[j];
					if (tbl2->ixVBasetype == VecWznmVMTableBasetype::MAIN) outfile << "\trefreshRec" << StrMod::cap(tbl2->Short) << "(dbs" << prjshort << ", moditems);" << endl;
				};

				outfile << endl;
			};

			// - special base control refresh invocations
			for (unsigned int j = 0; j < icsBasecons.size(); j++) {
				basecon = cons.nodes[icsBasecons[j]];

				Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, j, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
							icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
					if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
						if (tco->tblRefWznmMTable == rectbl->ref) {
							if (cplxtype == Concplxtype::LST_TXFALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
								else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
							} else if (cplxtype == Concplxtype::LST_TXTALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
									con = cons.nodes[ixTxt];
									outfile << "\trefresh" << con->sref << "(dbs" << prjshort << ", moditems);" << endl;
								} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
							} else if (cplxtype == Concplxtype::PUP_TXFALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) )
											outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
							} else if (cplxtype == Concplxtype::TXT_TXFALT) {
								if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) outfile << "\trefresh" << basecon->sref << "(dbs" << prjshort << ", moditems);" << endl;
							};

						} else if ((cplxtype == Concplxtype::PUP_VBAR) && (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF)) {
							if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMRelation WHERE frRefWznmMTable = " + to_string(rectbl->ref) + " AND toRefWznmMTable = " + to_string(tco->tblRefWznmMTable)
										+ " AND ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), ref)) {
								outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
							};
						};

						delete tco;
					};
				};
			};
			outfile << endl;

			outfile << "};" << endl;
			outfile << endl;
		};
	};

	outfile << "void " << pnl->sref << "::refresh(" << endl;
	outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
	outfile << "\t\t\t, set<uint>& moditems" << endl;
	outfile << "\t\t\t, const bool unmute" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tif (muteRefresh && !unmute) return;" << endl;
	outfile << "\tmuteRefresh = true;" << endl;
	outfile << endl;

	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADBAR) {
		if (bitsEval.size() > 0) {
			outfile << "\tStatShr oldStatshr(statshr);" << endl;
			outfile << endl;

			outfile << "\t// IP refresh --- BEGIN" << endl;

			outfile << "\t// statshr" << endl;
			for (unsigned int i = 0; i < bitsEval.size(); i++) writeEvalstatshr(outfile, bitsEval[i], rulesEval[i], exprsEval[i], prjshort);

			outfile << "\t// IP refresh --- END" << endl;
			outfile << endl;

			outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
		};

	} else if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) ) {
		outfile << "\tContInf oldContinf(continf);" << endl;
		if (bitsEval.size() > 0) outfile << "\tStatShr oldStatshr(statshr);" << endl;
		outfile << endl;

		outfile << "\t// IP refresh --- BEGIN" << endl;

		outfile << "\t// continf" << endl;
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::TXT) {
				if (dbswznm->tblwznmmstub->loadRecByRef(con->stdRefWznmMStub, &stb)) {
					outfile << "\tcontinf." << con->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE"
								<< PRJSHORT << "REF" << StrMod::uc(con->sref.substr(3)) << ", jref), ix" << Prjshort << "VLocale);" << endl;

					delete stb;
				};
			};
		};
		outfile << endl;

		if (bitsEval.size() > 0) {
			outfile << "\t// statshr" << endl;
			for (unsigned int i = 0; i < bitsEval.size(); i++) writeEvalstatshr(outfile, bitsEval[i], rulesEval[i], exprsEval[i], prjshort);
			outfile << endl;
		};

		outfile << "\t// IP refresh --- END" << endl;

		outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
		if (bitsEval.size() > 0) outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) ) {
		found = false;

		for (unsigned int i = 0; i < oksEval.size(); i++) {
			if (!oksEval[i]) {
				found = true;
				break;
			};
		};
		
		if (found) {
			outfile << "\tStatShr oldStatshr(statshr);" << endl;
			outfile << endl;

			outfile << "\t// IP refresh --- BEGIN" << endl;

			outfile << "\t// statshr" << endl;
			if (cons.nodes.size() > 0) writePnlCpp_evals(outfile, cons, 0, cons.nodes.size()-1, bitsEval, rulesEval, exprsEval, oksEval, prjshort);

			outfile << "\t// IP refresh --- END" << endl;
			outfile << endl;

			outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;

		} else {
			outfile << "\t// IP refresh --- INSERT" << endl;
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		outfile << "\tContInf oldContinf(continf);" << endl;
		outfile << "\tContIac oldContiac(contiac);" << endl;
		outfile << endl;

		outfile << "\t// IP refresh --- BEGIN" << endl;

		outfile << "\t// continf" << endl;
		outfile << "\tcontinf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ix" << Prjshort << "VQrystate);" << endl;
		outfile << endl;

		if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref) + " AND sref = 'TxtPre'", &con)) {
			outfile << "\tuint ixPre = xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXPRE, jref);" << endl;
			outfile << "\tif ((ixPre != 0) && (ixPre != Vec" << Prjshort << "VPreset::VOID)) {" << endl;
			outfile << "\t\tcontinf.TxtFor = Vec" << Prjshort << "VPreset::getTitle(ixPre, ix" << Prjshort << "VLocale);" << endl;
			outfile << endl;

			dbswznm->tblwznmjmcontrol->loadRstByCon(con->ref, false, conJs);

			first = true;
			for (unsigned int i = 0; i < conJs.nodes.size(); i++) {
				conJ = conJs.nodes[i];

				if (dbswznm->tblwznmmpreset->loadRecByRef(conJ->x2RefWznmMPreset, &pst)) {
					if (dbswznm->tblwznmmstub->loadRecByRef(conJ->stdRefWznmMStub, &stb)) {
						outfile << "\t\t";
						if (first) first = false; else outfile << "else ";

						outfile << "if (ixPre == Vec" << Prjshort << "VPreset::" << StrMod::uc(pst->sref) << ") continf.TxtPre = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4)
									<< "(dbs" << prjshort << ", xchg->getRefPreset(ixPre, jref), ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;

						delete stb;
					};
					delete pst;
				};
			};
			if (!first) outfile << endl;

			outfile << "\t} else {" << endl;
			outfile << "\t\tcontinf.TxtFor = \"\";" << endl;
			outfile << "\t};" << endl;
			outfile << endl;

			delete con;
		};

		outfile << "\t// contiac" << endl;
		outfile << "\tcontiac.numFTos = xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXORD, jref);" << endl;
		outfile << endl;

		outfile << "\t// IP refresh --- END" << endl;

		outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
		outfile << "\tif (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);" << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
		outfile << "\tContInf oldContinf(continf);" << endl;
		outfile << "\tStatShr oldStatshr(statshr);" << endl;
		outfile << endl;

		outfile << "\t// IP refresh --- BEGIN" << endl;

		outfile << "\t// continf" << endl;
		if (dbswznm->tblwznmmcontrol->loadRecBySQL("SELECT * FROM TblWznmMControl WHERE hkIxVTbl = " + to_string(VecWznmVMControlHkTbl::PNL) + " AND hkUref = " + to_string(pnl->ref)
					+ " AND sref = 'TxtRef'", &con)) {
			if (dbswznm->tblwznmmstub->loadRecByRef(con->stdRefWznmMStub, &stb)) {
				outfile << "\tcontinf." << con->sref << " = Stub" << Prjshort << "::getStub" << stb->sref.substr(4+4) << "(dbs" << prjshort << ", rec" << StrMod::cap(rectbls.nodes[0]->Short) << ".ref, ix" << Prjshort << "VLocale, Stub::VecVNonetype::FULL);" << endl;
				delete stb;
			};
			delete con;
		};
		outfile << endl;

		outfile << "\t// statshr" << endl;
		outfile << "\tif (rec" << StrMod::cap(rectbls.nodes[0]->Short) << ".ref == 0) statshr.ix" << Prjshort << "VExpstate = Vec" << Prjshort << "VExpstate::MIND;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < bitsEval.size(); i++) writeEvalstatshr(outfile, bitsEval[i], rulesEval[i], exprsEval[i], prjshort);
		outfile << endl;

		outfile << "\tif (statshr.ix" << Prjshort << "VExpstate == Vec" << Prjshort << "VExpstate::MIND) {" << endl;

		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];

			if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
				outfile << "\t\tif (pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << ") {delete pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3))
							<< "; pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << " = NULL;};" << endl;
			};
		};

		outfile << "\t} else {" << endl;

		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];

			if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
				outfile << "\t\tif (!pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << ") pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << " = new " << crdpnl->sref
							<< "(xchg, dbs" << prjshort << ", jref, ix" << Prjshort << "VLocale);" << endl;
			};
		};

		outfile << "\t};" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
			crdpnl = crdpnls.nodes[i];

			if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST))
						outfile << "\tstatshr.jref" << crdpnl->sref.substr(3+4+3) << " = ((pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << ") ? pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "->jref : 0);" << endl;
		};
		outfile << endl;

		outfile << "\t// IP refresh --- END" << endl;

		outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
		outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
		outfile << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		outfile << "\tContInf oldContinf(continf);" << endl;
		if (bitsEval.size() > 0) outfile << "\tStatShr oldStatshr(statshr);" << endl;
		outfile << endl;

		outfile << "\t// IP refresh --- BEGIN" << endl;

		outfile << "\t// continf" << endl;
		outfile << "\tcontinf.numFCsiQst = feedFCsiQst.getNumByIx(qry->ix" << Prjshort << "VQrystate);" << endl;
		outfile << endl;

		if (bitsEval.size() > 0) {
			outfile << "\t// statshr" << endl;
			for (unsigned int i = 0; i < bitsEval.size(); i++) writeEvalstatshr(outfile, bitsEval[i], rulesEval[i], exprsEval[i], prjshort);
			outfile << endl;
		};

		outfile << "\t// IP refresh --- END" << endl;

		outfile << "\tif (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);" << endl;
		if (bitsEval.size() > 0) outfile << "\tif (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);" << endl;
	};

	outfile << endl;
	outfile << "\tmuteRefresh = false;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// -- updatePreset
	if ( ((car->sref.find("Nav") == (3+4)) && ((pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM)))
				|| (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM)
				|| (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) ) {

		outfile << "void " << pnl->sref << "::updatePreset(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const uint ix" << Prjshort << "VPreset" << endl;
		outfile << "\t\t\t, const ubigint jrefTrig" << endl;
		outfile << "\t\t\t, const bool notif" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\t// IP updatePreset --- BEGIN" << endl;

		if (car->sref.find("Nav") == (3+4)) {
			outfile << "\tset<uint> moditems;" << endl;
			outfile << endl;

			// TBD: check for pst's with SESS scope

			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) {
				outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
				outfile << endl;

				outfile << "\tif (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

			} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) {
				outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
				outfile << endl;

				for (unsigned int i = 0; i < icsBasecons.size(); i++) {
					basecon = cons.nodes[icsBasecons[i]];

					Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
								icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
					
					if (cplxtype == Concplxtype::LST_NOALT) outfile << "\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
				};

				outfile << "\tif (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
			};

		} else {
			// - non-crdnav, non-headbar panels
			if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) || ((pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()))
						|| (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) ) {
				outfile << "\tset<uint> moditems;" << endl;
				outfile << endl;
			};

			outfile << "\tif (ix" << Prjshort << "VPreset == " << ixCarpst << ") {" << endl;

			if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
				outfile << "\t\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref, xchg->getRefPreset(" << ixCarpst << ", jref));" << endl;
				outfile << "\t\tqry->refreshJnum();" << endl;
				outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
				outfile << endl;

				outfile << "\t\tinsert(moditems, DpchEngData::STGIACQRY);" << endl;
				outfile << endl;

				outfile << "\t\tif ((jrefTrig != jref) && notif) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

			} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
				for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
					rectbl = rectbls.nodes[i];
					if (rectbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) outfile << "\t\t" << rectbl->sref.substr(3) << "* _rec" << StrMod::cap(rectbl->Short) << " = NULL;" << endl;
				};
				outfile << endl;

				for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
					rectbl = rectbls.nodes[i];

					hassbs = Wznm::hasSubset(dbswznm, rectbl->ref);

					if (rectbl->ixVBasetype == VecWznmVMTableBasetype::MAIN) {
						outfile << "\t\tif (dbs" << prjshort << "->" << StrMod::lc(rectbl->sref) << "->loadRecByRef(";
						
						if (i == 0) {
							outfile << "xchg->getRefPreset(" << ixCarpst << ", jref)";

						} else if (dbswznm->tblwznmmtablecol->loadRecBySQL("SELECT * FROM TblWznmMTablecol WHERE tblRefWznmMTable = " + to_string(rectbls.nodes[0]->ref) + " AND fctIxVTbl = " + to_string(VecWznmVMTablecolFctTbl::TBL)
									+ " AND fctUref = " + to_string(rectbl->ref) + " AND ixVBasetype = " + to_string(VecWznmVMTablecolBasetype::TBLREF), &tco)) {

							outfile << "rec" << StrMod::cap(rectbls.nodes[0]->Short) << "." << tco->sref;
							delete tco;
						};

						outfile << ", &_rec" << StrMod::cap(rectbl->Short) << ")) {" << endl;
						outfile << "\t\t\trec" << StrMod::cap(rectbl->Short) << " = *_rec" << StrMod::cap(rectbl->Short) << ";" << endl;
						if (hassbs) outfile << "\t\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = dbs" << prjshort << "->getIxWSubsetBy" << rectbl->sref.substr(3) << "(_rec" << StrMod::cap(rectbl->Short) << ");" << endl;
						outfile << "\t\t\tdelete _rec" << StrMod::cap(rectbl->Short) << ";" << endl;

						if (hassbs) {
							outfile << "\t\t} else {" << endl;
							outfile << "\t\t\trec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
							outfile << "\t\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = 0;" << endl;
							outfile << "\t\t};" << endl;
						} else {
							outfile << "\t\t} else rec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
						};
						outfile << endl;
					};
				};

				outfile << "\t\tif (rec" << StrMod::cap(rectbls.nodes[0]->Short) << ".ref != 0) {" << endl;
				for (unsigned int i = 0; i < crdpnls.nodes.size(); i++) {
					crdpnl = crdpnls.nodes[i];

					if ((crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (crdpnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
						outfile << "\t\t\tif (pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << ") pnl" << StrMod::lc(crdpnl->sref.substr(3+4+3)) << "->updatePreset(dbs" << prjshort << ", ix" << Prjshort << "VPreset, jrefTrig, notif);" << endl;
					};
				};
				outfile << "\t\t};" << endl;
				outfile << endl;

				outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
				outfile << "\t\tif (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

			} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
				rectbl = rectbls.nodes[0];

				outfile << "\t\trec" << StrMod::cap(rectbl->Short) << ".ref = xchg->getRefPreset(" << ixCarpst << ", jref);" << endl;
				outfile << "\t\trefreshRec" << StrMod::cap(rectbl->Short) << "(dbs" << prjshort << ", moditems);" << endl;
				outfile << endl;

				outfile << "\t\tif (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;

			} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
				for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
					rectbl = rectbls.nodes[i];

					outfile << "\t\trec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
					if (Wznm::hasSubset(dbswznm, rectbl->ref)) outfile << "\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = 0;" << endl;
					outfile << endl;
				};

				outfile << "\t\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref, 0);" << endl;
				outfile << endl;

				outfile << "\t\tqry->stgiac.jnumFirstload = 1;" << endl;
				outfile << endl;

				outfile << "\t\tqry->rerun(dbs" << prjshort << ");" << endl;
				outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
				outfile << endl;

				outfile << "\t\tif (notif) {" << endl;
				outfile << "\t\t\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
				outfile << "\t\t\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
				outfile << "\t\t};" << endl;
			};

			outfile << "\t};" << endl;
		};

		outfile << "\t// IP updatePreset --- END" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	// -- expand state management
	if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
		outfile << "void " << pnl->sref << "::minimize(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const bool notif" << endl;
		outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tif (statshr.ix" << Prjshort << "VExpstate != Vec" << Prjshort << "VExpstate::MIND) {" << endl;
		outfile << "\t\tstatshr.ix" << Prjshort << "VExpstate = Vec" << Prjshort << "VExpstate::MIND;" << endl;
		outfile << "\t\tinsert(moditems, DpchEngData::STATSHR);" << endl;

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
			outfile << endl;
			outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tif (notif) {" << endl;
		outfile << "\t\tif (dpcheng) *dpcheng = getNewDpchEng(moditems);" << endl;
		outfile << "\t\telse if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
		outfile << "\t};" << endl;

		outfile << "};" << endl;
		outfile << endl;

		outfile << "void " << pnl->sref << "::regularize(" << endl;
		outfile << "\t\t\tDbs" << Prjshort << "* dbs" << prjshort << endl;
		outfile << "\t\t\t, const bool notif" << endl;
		outfile << "\t\t\t, DpchEng" << Prjshort << "** dpcheng" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tif (statshr.ix" << Prjshort << "VExpstate != Vec" << Prjshort << "VExpstate::REGD) {" << endl;
		outfile << "\t\tstatshr.ix" << Prjshort << "VExpstate = Vec" << Prjshort << "VExpstate::REGD;" << endl;
		outfile << "\t\tinsert(moditems, DpchEngData::STATSHR);" << endl;

		if (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC) {
			outfile << endl;
			outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tif (notif) {" << endl;
		outfile << "\t\tif (dpcheng) *dpcheng = getNewDpchEng(moditems);" << endl;
		outfile << "\t\telse if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
		outfile << "\t};" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	outfile << "// IP spec --- IEND" << endl;

	// --- handleDpchAppXxxxInit
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IBEGIN" << endl;
	outfile << "\t*dpcheng = getNewDpchEng({DpchEngData::ALL});" << endl;
	outfile << "// IP handleDpchApp" << Prjshort << "Init --- IEND" << endl;

	// --- handleDpchAppData
	if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		ss.resize(0);

		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) ss.push_back(baseconsref);
		};

		if (ss.size() > 0) {
			outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
			outfile << endl;

			found = false;
			for (unsigned int i = 0; i < ss.size(); i++) {
				if (StrMod::has(sesspsts, "ref" + ss[i].substr(3))) {
					found = true;
					break;
				};
			};

			if (found) {
				outfile << "\tubigint ref;" << endl;
				outfile << endl;
			};

			for (unsigned int i = 0; i < ss.size(); i++) {
				outfile << "\tif (has(diffitems, ContIac::NUMF" << StrMod::uc(ss[i]) << ")) {" << endl;
				outfile << "\t\tcontiac.numF" << ss[i] << " = _contiac->numF" << ss[i] << ";" << endl;

				if (StrMod::has(sesspsts, "ref" + ss[i].substr(3))) {
					outfile << "\t\tif (dbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->loadUnuByRef(feedF" << ss[i] << ".getRefByNum(contiac.numF" << ss[i] << "), ref)) xchg->triggerIxRefCall(dbs" << prjshort
								<< ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "REFPRESET, jref, Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(ss[i].substr(3)) << ", ref);" << endl;
				};

				outfile << "\t\trefresh" << ss[i] << "(dbs" << prjshort << ", moditems);" << endl;
				outfile << "\t};" << endl;
				outfile << endl;
			};

			outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmMVector WHERE refWznmMVersion = " + to_string(job->refWznmMVersion) + " AND sref = 'VecVQry" + pnl->sref.substr(3) + "Ord'", ref)) {
			dbswznm->tblwznmmvectoritem->loadRstByVec(ref, false, vits);

			if (vits.nodes.size() > 0) {
				outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
				outfile << endl;

				outfile << "\tif (has(diffitems, ContIac::NUMFTOS)) {" << endl;
				outfile << "\t\tif ((_contiac->numFTos >= Qry" << pnl->sref.substr(3) << "::VecVOrd::" << StrMod::uc(vits.nodes[0]->sref) << ") && (_contiac->numFTos <= Qry"
							<< pnl->sref.substr(3) << "::VecVOrd::" << StrMod::uc(vits.nodes[vits.nodes.size()-1]->sref) << ")) {" << endl;

				outfile << "\t\t\tmuteRefresh = true;" << endl;
				outfile << endl;

				outfile << "\t\t\txchg->addIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXORD, jref, _contiac->numFTos);" << endl;
				outfile << endl;

				outfile << "\t\t\tqry->rerun(dbs" << prjshort << ");" << endl;
				outfile << endl;

				outfile << "\t\t\trefresh(dbs" << prjshort << ", moditems, true);" << endl;
				outfile << "\t\t\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
				outfile << "\t\t};" << endl;
				outfile << "\t};" << endl;
				outfile << endl;

				outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;
			};
		};

		outfile << "// IP handleDpchAppDataStgiacqry --- IBEGIN" << endl;
		outfile << endl;

		outfile << "\tubigint refSelNew = 0;" << endl;
		outfile << endl;

		outfile << "\tif (!diffitems.empty()) {" << endl;
		outfile << "\t\tqry->stgiac = *_stgiacqry;" << endl;
		outfile << endl;

		outfile << "\t\tif (has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM)) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);" << endl;
		outfile << endl;

		outfile << "\t\tif (!has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM) || (diffitems.size() > 1)) {" << endl;
		outfile << "\t\t\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t\t\tqry->rerun(dbs" << prjshort << ");" << endl;
		outfile << endl;

		outfile << "\t\t\trefresh(dbs" << prjshort << ", moditems, true);" << endl;
		outfile << "\t\t\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\tif (has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM)) {" << endl;
		outfile << "\t\t\tif (refSelNew == 0) refSelNew = qry->getRefByJnum(_stgiacqry->jnum);" << endl;
		outfile << "\t\t\txchg->triggerIxRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "REFPRESET, jref, Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(pnl->sref.substr(3+4, 3)) << ", refSelNew);" << endl;
		outfile << "\t\t};" << endl;
		outfile << "\t};" << endl;
		outfile << endl;
		outfile << "// IP handleDpchAppDataStgiacqry --- IEND" << endl;

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		outfile << "// IP handleDpchAppDataContiac --- IBEGIN" << endl;
		outfile << endl;

		// interactive controls without special functionality
		ss.resize(0);

		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			s = ""; s2 = "";
			
			if ((cplxtype == Concplxtype::CHK) || (cplxtype == Concplxtype::SLD) || (cplxtype == Concplxtype::TXF) || (cplxtype == Concplxtype::UPD)) {
				s = baseconsref;
			} else if ((cplxtype == Concplxtype::LST) || (cplxtype == Concplxtype::LST_NOALT) || (cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::LST_TXTALT)) {
				if (StrMod::srefInSrefs(basecon->srefsKOption, "multsel")) s = "numsF" + baseconsref;
				else s = "numF" + baseconsref;
			} else if ((cplxtype == Concplxtype::PUP) || (cplxtype == Concplxtype::PUP_PUP) || (cplxtype == Concplxtype::PUP_TXFALT) || (cplxtype == Concplxtype::PUP_VBAR)) {
				s = "numF" + baseconsref;
			};
			if ((cplxtype == Concplxtype::LST_TXFALT) || (cplxtype == Concplxtype::PUP_TXFALT) || (cplxtype == Concplxtype::TXT_TXFALT)) {
				con = cons.nodes[ixTxf];
				if (s.length() == 0) s = con->sref;
				else s2 = con->sref;
			};

			if (s.length() > 0) {
				special = false;

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
					if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
						if (cplxtype == Concplxtype::LST_TXFALT) {
							if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) special = true;
							else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) special = true;
						} else if (cplxtype == Concplxtype::LST_TXTALT) {
							if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) special = true;
							else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) special = true;
						} else if (cplxtype == Concplxtype::PUP_TXFALT) {
							if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) special = true;
						} else if (cplxtype == Concplxtype::PUP_VBAR) {
							if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) special = true;
						} else if (cplxtype == Concplxtype::TXT_TXFALT) {
							if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) special = true;
						};

						delete tco;
					};
				};

				if (!special) {
					ss.push_back(s);
					if (s2.length() > 0) ss.push_back(s2);
				};
			};
		};

		if (ss.size() > 0) {
			outfile << "\tif (hasAny(diffitems, {";
			for (unsigned int i = 0; i < ss.size(); i++) {
				if (i != 0) outfile << ", ";
				outfile << "ContIac::" << StrMod::uc(ss[i]);
			};
			outfile << "})) {" << endl;
			for (unsigned int i = 0; i < ss.size(); i++) outfile << "\t\tif (has(diffitems, ContIac::" << StrMod::uc(ss[i]) << ")) contiac." << ss[i] << " = _contiac->" << ss[i] << ";" << endl;
			outfile << "\t};" << endl;
			outfile << endl;
		};

		// interactive controls with special functionality
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if ((ixTxf+1) != 0) con = cons.nodes[ixTxf];

			if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
					if (cplxtype == Concplxtype::LST_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) {
							// ex.: numsFLstOpt, TxfOpt
							outfile << "\tif (has(diffitems, ContIac::" << StrMod::uc(con->sref) << ")) {" << endl;
							outfile << "\t\tcontiac." << con->sref << " = _contiac->" << con->sref << ";" << endl;
							outfile << "\t\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t} else if (has(diffitems, ContIac::NUMSF" << StrMod::uc(baseconsref) << ")) {" << endl;
							outfile << "\t\tcontiac.numsF" << baseconsref << " = _contiac->numsF" << baseconsref << ";" << endl;
							outfile << "\t\trefresh" << con->sref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFMULT) ) {
							// ex.: numFLstEsg, TxfEsg
							outfile << "\tif (has(diffitems, ContIac::" << StrMod::uc(con->sref) << ")) {" << endl;
							outfile << "\t\tcontiac." << con->sref << " = _contiac->" << con->sref << ";" << endl;
							outfile << "\t\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t} else if (has(diffitems, ContIac::NUMF" << StrMod::uc(baseconsref) << ")) {" << endl;
							outfile << "\t\tcontiac.numF" << baseconsref << " = _contiac->numF" << baseconsref << ";" << endl;
							outfile << "\t\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::LST_TXTALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::VECREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::VREFAND) ) {
							// ex.: numsFLstInv
							outfile << "\tif (has(diffitems, ContIac::NUMSF" << StrMod::uc(baseconsref) << ")) {" << endl;
							outfile << "\t\tcontiac.numsF" << baseconsref << " = _contiac->numsF" << baseconsref << ";" << endl;
							outfile << "\t\trefreshTxt" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;

						} else if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) {
							// ex.: numFLstClu
							outfile << "\tif (has(diffitems, ContIac::NUMF" << StrMod::uc(baseconsref) << ")) {" << endl;
							outfile << "\t\tcontiac.numF" << baseconsref << " = _contiac->numF" << baseconsref << ";" << endl;
							outfile << "\t\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) {
							// ex.: numFPupMim, TxfMim
							outfile << "\tif (has(diffitems, ContIac::" << StrMod::uc(con->sref) << ")) {" << endl;
							outfile << "\t\tcontiac." << con->sref << " = _contiac->" << con->sref << ";" << endl;
							outfile << "\t\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t} else if (has(diffitems, ContIac::NUMF" << StrMod::uc(baseconsref) << ")) {" << endl;
							outfile << "\t\tcontiac.numF" << baseconsref << " = _contiac->numF" << baseconsref << ";" << endl;
							outfile << "\t\trefresh" << con->sref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;
						};

					} else if (cplxtype == Concplxtype::PUP_VBAR) {
						if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
							// ex.: numFPupJ
							if (dbswznm->tblwznmmtable->loadRecByRef(tco->tblRefWznmMTable, &tbl)) {
								outfile << "\tif (has(diffitems, ContIac::NUMF" << StrMod::uc(baseconsref) << ")) {" << endl;
								outfile << "\t\trec" << StrMod::cap(tbl->Short) << ".ref = feedF" << baseconsref << ".getRefByNum(_contiac->numF" << baseconsref << ");" << endl;
								outfile << "\t\trefreshRec" << StrMod::cap(tbl->Short) << "(dbs" << prjshort << ", moditems);" << endl;
								outfile << "\t};" << endl;
								outfile << endl;

								delete tbl;
							};
						};

					} else if (cplxtype == Concplxtype::TXT_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLSREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TSREFSNG) ) {
							// ex.: TxfFlr
							outfile << "\tif (has(diffitems, ContIac::" << StrMod::uc(con->sref) << ")) {" << endl;
							outfile << "\t\tcontiac." << con->sref << " = _contiac->" << con->sref << ";" << endl;
							outfile << "\t\trefresh" << baseconsref << "(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
							outfile << "\t};" << endl;
							outfile << endl;
						};
					};

					delete tco;
				};
			};
		};

		outfile << "// IP handleDpchAppDataContiac --- IEND" << endl;

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		outfile << "// IP handleDpchAppDataStgiacqry --- IBEGIN" << endl;
		outfile << endl;

		outfile << "\t" << Prjshort << "Q" << pnl->sref.substr(3+4) << "* recSelNew = NULL;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];
			outfile << "\t" << rectbl->sref.substr(3) << "* _rec" << StrMod::cap(rectbl->Short) << " = NULL;" << endl;
		};
		outfile << endl;

		outfile << "\tif (!diffitems.empty()) {" << endl;
		outfile << "\t\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\t\tqry->stgiac = *_stgiacqry;" << endl;
		outfile << endl;

		outfile << "\t\tif (has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM)) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);" << endl;
		outfile << endl;

		outfile << "\t\tif (!has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM) || (diffitems.size() > 1)) {" << endl;
		outfile << "\t\t\tqry->rerun(dbs" << prjshort << ");" << endl;
		outfile << "\t\t\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::RST});" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\tif (has(diffitems, Qry" << pnl->sref.substr(3) << "::StgIac::JNUM)) {" << endl;
		outfile << "\t\t\tif (!recSelNew) recSelNew = qry->getRecByJnum(_stgiacqry->jnum);" << endl;
		outfile << endl;

		outfile << "\t\t\trec" << StrMod::cap(rectbls.nodes[0]->Short) << " = " << rectbls.nodes[0]->sref.substr(3) << "();" << endl;
		outfile << endl;

		for (unsigned int i = 1; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];

			outfile << "\t\t\trec" << StrMod::cap(rectbl->Short) << " = " << rectbl->sref.substr(3) << "();" << endl;
			if (Wznm::hasSubset(dbswznm, rectbl->ref)) outfile << "\t\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = 0;" << endl;
			outfile << endl;
		};

		outfile << "\t\t\tif (recSelNew) {" << endl;
		for (unsigned int i = 0; i < rectbls.nodes.size(); i++) {
			rectbl = rectbls.nodes[i];

			outfile << "\t\t\t\tif (dbs" << prjshort << "->" << StrMod::lc(rectbl->sref) << "->loadRecByRef(";
			if (i == 0) outfile << "recSelNew->ref";
			else if (i == 1) outfile << "recSelNew->mref";
			else outfile << "0";
			outfile << ", &_rec" << StrMod::cap(rectbl->Short) << ")) {" << endl;

			outfile << "\t\t\t\t\trec" << StrMod::cap(rectbl->Short) << " = *_rec" << StrMod::cap(rectbl->Short) << ";" << endl;
			if (Wznm::hasSubset(dbswznm, rectbl->ref)) outfile << "\t\t\t\t\tixWSubset" << StrMod::cap(rectbl->Short) << " = dbs" << prjshort << "->getIxWSubsetBy" << rectbl->sref.substr(3) << "(_rec" << StrMod::cap(rectbl->Short) << ");" << endl;

			outfile << "\t\t\t\t\tdelete _rec" << StrMod::cap(rectbl->Short) << ";" << endl;
			outfile << "\t\t\t\t};" << endl;
		};
		outfile << "\t\t\t};" << endl;
		outfile << endl;

		outfile << "\t\t\txchg->addRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REFSEL, jref, ((recSelNew) ? recSelNew->ref : 0));" << endl;
		outfile << "\t\t\tqry->refreshJnum();" << endl;
		outfile << "\t\t};" << endl;
		outfile << endl;

		outfile << "\t\trefresh(dbs" << prjshort << ", moditems, true);" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "// IP handleDpchAppDataStgiacqry --- IEND" << endl;
	};

	// --- handleDpchAppDoButMinimizeClick / handleDpchAppDoButRegularizeClick
	found = false;
	for (unsigned int i = 0; i < cons.nodes.size(); i++) {
		con = cons.nodes[i];

		if ((con->ixVScope == VecWznmVMControlScope::SHR) && (con->sref == "ButRegularize")) {
			found = true;
			break;
		};
	};

	if (found) {
		if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST)) {
			// -- handleDpchAppDoButMinimizeClick
			outfile << "// IP handleDpchAppDoButMinimizeClick --- IBEGIN" << endl;
			outfile << "\t// IP handleDpchAppDoButMinimizeClick --- BEGIN" << endl;
			outfile << "\tstatshr.ix" << Prjshort << "VExpstate = Vec" << Prjshort << "VExpstate::MIND;" << endl;
			outfile << "\t*dpcheng = getNewDpchEng({DpchEngData::STATSHR});" << endl;
			outfile << "\t// IP handleDpchAppDoButMinimizeClick --- END" << endl;
			outfile << "// IP handleDpchAppDoButMinimizeClick --- IEND" << endl;

			// -- handleDpchAppDoButRegularizeClick
			outfile << "// IP handleDpchAppDoButRegularizeClick --- IBEGIN" << endl;
			outfile << "\t// IP handleDpchAppDoButRegularizeClick --- BEGIN" << endl;
			outfile << "\tstatshr.ix" << Prjshort << "VExpstate = Vec" << Prjshort << "VExpstate::REGD;" << endl;
			outfile << "\t*dpcheng = getNewDpchEng({DpchEngData::STATSHR});" << endl;
			outfile << "\t// IP handleDpchAppDoButRegularizeClick --- END" << endl;
			outfile << "// IP handleDpchAppDoButRegularizeClick --- IEND" << endl;

		} else if ((pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) || (pnl->ixVBasetype == VecWznmVMPanelBasetype::REC)) {
			// -- handleDpchAppDoButMinimizeClick
			outfile << "// IP handleDpchAppDoButMinimizeClick --- IBEGIN" << endl;
			outfile << "\tminimize(dbs" << prjshort << ", true, dpcheng);" << endl;
			outfile << "// IP handleDpchAppDoButMinimizeClick --- IEND" << endl;

			// -- handleDpchAppDoButRegularizeClick
			outfile << "// IP handleDpchAppDoButRegularizeClick --- IBEGIN" << endl;
			outfile << "\tregularize(dbs" << prjshort << ", true, dpcheng);" << endl;
			outfile << "// IP handleDpchAppDoButRegularizeClick --- IEND" << endl;
		};
	};

	// --- handleDpchAppDo
	if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::HEADLINE) ) {
		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if (con->ixVBasetype == VecWznmVMControlBasetype::BUT) {
				if (con->sref.rfind("Remove") == (con->sref.length()-6)) {
					// -- handleDpchAppDoButXxxRemoveClick
					outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IBEGIN" << endl;
					outfile << "\tset<uint> moditems;" << endl;
					outfile << endl;

					outfile << "\txchg->triggerIxRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "REFPRESET, jref, Vec" << Prjshort << "VPreset::PRE" << PRJSHORT
								<< "REF" << StrMod::uc(con->sref.substr(3, 3)) << ", 0);" << endl;
					outfile << endl;

					outfile << "\trefresh(dbs" << prjshort << ", moditems);" << endl;
					outfile << endl;

					outfile << "\t*dpcheng = getNewDpchEng(moditems);" << endl;
					outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IEND" << endl;
				};
			};
		};

	} else if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) {
				if ((ixButView+1) != 0) {
					con = cons.nodes[ixButView];

					// -- handleDpchAppDoButXxxViewClick
					outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IBEGIN" << endl;
					outfile << "\t" << Prjshort << "HistRMUserUniversal* husrRunv = NULL;" << endl;
					outfile << "\tubigint jrefNew = 0;" << endl;
					outfile << endl;

					outfile << "\tif (statshr." << baseconsref << "Avail && statshr." << con->sref << "Active) {" << endl;
					outfile << "\t\tif (dbs" << prjshort << "->tbl" << prjshort << "histrmuseruniversal->loadRecByRef(feedF" << baseconsref << ".getRefByNum(contiac.numF" << baseconsref << "), &husrRunv)) {" << endl;
					outfile << "\t\t\txchg->triggerIxRefSrefIntvalToRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "CRDOPEN, jref, husrRunv->ix" << Prjshort << "VPreset, husrRunv->preUref, \"Crd"
								<< Prjshort << baseconshort << "\", husrRunv->unvUref, jrefNew);" << endl;
					outfile << "\t\t\tdelete husrRunv;" << endl;
					outfile << "\t\t};" << endl;
					outfile << endl;

					outfile << "\t\tif (jrefNew == 0) *dpcheng = new DpchEng" << Prjshort << "Confirm(false, 0, \"\");" << endl;
					outfile << "\t\telse *dpcheng = new DpchEng" << Prjshort << "Confirm(true, jrefNew, \"Crd" << Prjshort << baseconshort << "\");" << endl;
					outfile << "\t};" << endl;
					outfile << "// IP handleDpchAppDo" << con->sref << "Click --- IEND" << endl;
				};
			};

			if ((cplxtype == Concplxtype::BUT_CLUST) || (cplxtype == Concplxtype::LST_NOALT)) {
				found = false;
				
				for (unsigned int j = 0; j < icsButs.size(); j++) {
					con = cons.nodes[icsButs[j]];

					if ((con->sref.rfind("Newcrd")+6) == con->sref.length()) {
						found = true;
						break;
					};
				};

				if (found) {
					// -- handleDpchAppDoButXxxNewcrdClick
					outfile << "// IP handleDpchAppDoBut" << baseconshort << "NewcrdClick --- IBEGIN" << endl;
					outfile << "\tubigint jrefNew = 0;" << endl;
					outfile << endl;

					if (con->Active.length() > 0) {
						outfile << "\tif (statshr.But" << baseconshort << "NewcrdActive) {" << endl;
						indent = "\t\t";
					} else indent = "\t";

					outfile << indent << "xchg->triggerIxRefSrefIntvalToRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "CRDOPEN, jref, 0, 0, \"Crd" << Prjshort << baseconshort << "\", 0, jrefNew);" << endl;
					outfile << endl;

					outfile << indent << "if (jrefNew == 0) *dpcheng = new DpchEng" << Prjshort << "Confirm(false, 0, \"\");" << endl;
					outfile << indent << "else *dpcheng = new DpchEng" << Prjshort << "Confirm(true, jrefNew, \"Crd" << Prjshort << baseconshort << "\");" << endl;

					if (con->Active.length() > 0) outfile << "\t};" << endl;

					outfile << "// IP handleDpchAppDoBut" << baseconshort << "NewcrdClick --- IEND" << endl;
				};
			};
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		// -- handleDpchAppDoButRefreshClick
		outfile << "// IP handleDpchAppDoButRefreshClick --- IBEGIN" << endl;
		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\tqry->rerun(dbs" << prjshort << ", false);" << endl;
		outfile << endl;

		outfile << "\trefresh(dbs" << prjshort << ", moditems, true);" << endl;
		outfile << endl;

		outfile << "\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
		outfile << "\t*dpcheng = getNewDpchEng(moditems);" << endl;
		outfile << "// IP handleDpchAppDoButRefreshClick --- IEND" << endl;

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if ((ixButView+1) != 0) {

				if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {
					found = false;
					for (unsigned int j = 0; j < rectbls.nodes.size(); j++) {
						rectbl = rectbls.nodes[j];

						if (rectbl->ref == tco->tblRefWznmMTable) {
							found = true;
							break;
						};
					};

					if (found) {
						if (dbswznm->tblwznmmrelation->loadRecByRef(tco->refWznmMRelation, &rel)) {
							if ((rel->ixVBasetype != VecWznmVMRelationBasetype::AS1N) && (rel->ixVBasetype != VecWznmVMRelationBasetype::ASMN)) {
								toNotFr = ( ((rel->ixVBasetype == VecWznmVMRelationBasetype::_11) && (tco->tblRefWznmMTable == rel->frRefWznmMTable)) || (rel->ixVBasetype == VecWznmVMRelationBasetype::U1NSUB11) );

								Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, rectbl, tco, rel, toNotFr, trgs);

								if (!trgs.empty()) {
									con = cons.nodes[ixButView];

									// -- handleDpchAppDoButXxxView
									outfile << "// IP handleDpchAppDoBut" << baseconshort << "ViewClick --- IBEGIN" << endl;
									writePnlCpp_butnewview(dbswznm, outfile, job->refWznmMVersion, Prjshort, rectbls, con, con->sref, trgs, rectbl, tco, false);
									outfile << "// IP handleDpchAppDoBut" << baseconshort << "ViewClick --- IEND" << endl;
								};
							};

							delete rel;
						};
					};
					delete tco;
				};
			};
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		ixButNew = 0; ixButNew--;
		ixButView = 0; ixButView--;

		for (unsigned int i = 0; i < cons.nodes.size(); i++) {
			con = cons.nodes[i];

			if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->supRefWznmMControl == 0) && (con->sref == "ButNew")) ixButNew = i;
			else if ((con->ixVBasetype == VecWznmVMControlBasetype::BUT) && (con->supRefWznmMControl == 0) && (con->sref == "ButView")) ixButView = i;

			if (((ixButNew+1) != 0) && ((ixButView+1) != 0)) break;
		};

		if (((ixButNew+1) != 0) || ((ixButView+1) != 0)) {
			if ((rectbls.nodes.size() > 0) && (pnl->refIxVTbl == VecWznmVMPanelRefTbl::REL)) {
				if (dbswznm->tblwznmmrelation->loadRecByRef(pnl->refUref, &rel)) {
					Wznm::collectTrgs(dbswznm, sesspsts, car, carrecpsts, carpsts, rectbls.nodes[rectbls.nodes.size()-1], NULL, rel, true, trgs); // by convention 1n has single rectbl and mn has main as last rectbl

					if (!trgs.empty()) {
						if ((ixButNew+1) != 0) {
							con = cons.nodes[ixButNew];

							// -- handleDpchAppDoButNewClick
							outfile << "// IP handleDpchAppDoButNewClick --- IBEGIN" << endl;
							writePnlCpp_butnewview(dbswznm, outfile, job->refWznmMVersion, Prjshort, rectbls, con, con->sref, trgs, rectbls.nodes[rectbls.nodes.size()-1], NULL, true);
							outfile << "// IP handleDpchAppDoButNewClick --- IEND" << endl;
						};
						if ((ixButView+1) != 0) {
							con = cons.nodes[ixButView];

							// -- handleDpchAppDoButViewClick
							outfile << "// IP handleDpchAppDoButViewClick --- IBEGIN" << endl;
							writePnlCpp_butnewview(dbswznm, outfile, job->refWznmMVersion, Prjshort, rectbls, con, con->sref, trgs, rectbls.nodes[rectbls.nodes.size()-1], NULL, false);
							outfile << "// IP handleDpchAppDoButViewClick --- IEND" << endl;
						};
					};

					delete rel;
				};
			};
		};

		// -- handleDpchAppDoButRefreshClick
		outfile << "// IP handleDpchAppDoButRefreshClick --- IBEGIN" << endl;
		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tmuteRefresh = true;" << endl;
		outfile << endl;

		outfile << "\tqry->rerun(dbs" << prjshort << ", false);" << endl;
		outfile << endl;

		outfile << "\trefresh(dbs" << prjshort << ", moditems, true);" << endl;
		outfile << endl;

		outfile << "\tinsert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
		outfile << "\t*dpcheng = getNewDpchEng(moditems);" << endl;
		outfile << "// IP handleDpchAppDoButRefreshClick --- IEND" << endl;
	};

	// --- handleCall

	if (pnl->ixVBasetype == VecWznmVMPanelBasetype::LIST) {
		// -- handleCallXxxxStatChg
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IBEGIN" << endl;
		outfile << "\t// IP handleCall" << Prjshort << "StatChg --- BEGIN" << endl;
		outfile << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tif (jrefTrig == qry->jref) {" << endl;
		outfile << "\t\tif (!muteRefresh) {" << endl;
		outfile << "\t\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "\t\t\tif (qry->ix" << Prjshort << "VQrystate == Vec" << Prjshort << "VQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
		outfile << "\t\t\tif (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
		outfile << "\t\t};" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\t// IP handleCall" << Prjshort << "StatChg --- END" << endl;
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IEND" << endl;

	} else if ( (car->sref.find("Nav") == (3+4)) && (pnl->ixVBasetype == VecWznmVMPanelBasetype::FORM) ) {
		// -- handleCallXxxxHusrRunvMod_crdUsrEq ; requires at least one card with tbl/sbs source
		ss.resize(0);

		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);
			
			if (cplxtype == Concplxtype::LST_NOALT) ss.push_back(baseconshort);
		};

		if (ss.size() > 0) {
			outfile << "// IP handleCall" << Prjshort << "HusrRunvMod_crdUsrEq --- IBEGIN" << endl;
			outfile << "\tset<uint> moditems;" << endl;
			outfile << endl;

			for (unsigned int i = 0; i < ss.size(); i++) {
				outfile << "\t";
				if (i != 0) outfile << "} else ";
				outfile << "if (ixInv == Vec" << Prjshort << "VCard::CRD" << PRJSHORT << StrMod::uc(ss[i]) << ") {" << endl;
				outfile << "\t\trefresh" << ss[i] << "(dbs" << prjshort << ", moditems);" << endl;
			};

			outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
			outfile << "// IP handleCall" << Prjshort << "HusrRunvMod_crdUsrEq --- IEND" << endl;
		};

	} else if ( (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECFORM) && ((pnl->sref.rfind("Detail")+6) == pnl->sref.length()) ) {
		// -- handleCallXxxxKlsAkeyMod_klsEq ; requires at least one klst
		vecrefsBaseconshorts.clear();

		for (unsigned int i = 0; i < icsBasecons.size(); i++) {
			basecon = cons.nodes[icsBasecons[i]];

			Wznm::analyzeBasecon(dbswznm, cons, icsBasecons, i, "", cplxtype, baseconsref, baseconshort, ldyn, dyn, rdyn, vbar, ix0, ix1, ixBut, ixButCollapse, ixButEdit, ixButExpand, ixButToggle, ixButView,
						icsButs, ixChk, ixCpt, ixHdg, ixLsb, ixPup, ixTxf, ixTxt, icsVbarcons);

			if (basecon->refIxVTbl == VecWznmVMControlRefTbl::TCO) {
				if (dbswznm->tblwznmmtablecol->loadRecByRef(basecon->refUref, &tco)) {

					if (cplxtype == Concplxtype::LST_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFMULT) ) vecrefsBaseconshorts.insert(pair<ubigint,string>(tco->fctUref, baseconshort));

					} else if (cplxtype == Concplxtype::LST_TXTALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::TBLREF) && (tco->ixVSubtype == VecWznmVMTablecolSubtype::TREFCLU) ) {
							if (dbswznm->tblwznmmtable->loadRecByRef(tco->tblRefWznmMTable, &tbl)) {
								// --- handleCallXxxxYyyMod_zzzEq
								outfile << "// IP handleCall" << Prjshort << StrMod::cap(tbl->Short) << "Mod_" << tco->Short << "Eq --- IBEGIN" << endl;
								outfile << "\tset<uint> moditems;" << endl;
								outfile << endl;

								outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
								outfile << endl;

								outfile << "\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
								outfile << "// IP handleCall" << Prjshort << StrMod::cap(tbl->Short) << "Mod_" << tco->Short << "Eq --- IEND" << endl;

								delete tbl;
							};
						};

					} else if (cplxtype == Concplxtype::PUP_TXFALT) {
						if ( (tco->ixVBasetype == VecWznmVMTablecolBasetype::KLREF) && ((tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFSNG) || (tco->ixVSubtype == VecWznmVMTablecolSubtype::KLREFOPT)) ) vecrefsBaseconshorts.insert(pair<ubigint,string>(tco->fctUref, baseconshort));

					} else if (cplxtype == Concplxtype::PUP_VBAR) {
						if (tco->ixVBasetype == VecWznmVMTablecolBasetype::IDREF) {
							if (dbswznm->tblwznmmtable->loadRecByRef(tco->tblRefWznmMTable, &tbl)) {
								if (dbswznm->tblwznmmtable->loadRecBySQL("SELECT TblWznmMTable.* FROM TblWznmMTable, TblWznmMRelation WHERE TblWznmMTable.ref = TblWznmMRelation.frRefWznmMTable AND TblWznmMRelation.toRefWznmMTable = "
											+ to_string(tbl->ref) + " AND TblWznmMRelation.ixVBasetype = " + to_string(VecWznmVMRelationBasetype::J), &tbl2)) {
									// --- handleCallXxxxYyyJzzzMod_aaaEq
									outfile << "// IP handleCall" << Prjshort << StrMod::cap(tbl->Short) << "Mod_" << tbl2->Short << "Eq --- IBEGIN" << endl;
									outfile << "\tset<uint> moditems;" << endl;
									outfile << endl;

									outfile << "\trefresh" << baseconshort << "(dbs" << prjshort << ", moditems);" << endl;
									outfile << endl;

									outfile << "\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
									outfile << "// IP handleCall" << Prjshort << StrMod::cap(tbl->Short) << "Mod_" << tbl2->Short << "Eq --- IEND" << endl;

									delete tbl2;
								};

								delete tbl;
							};
						};
					};

					delete tco;
				};
			};
		};

		if (vecrefsBaseconshorts.size() > 0) {
			outfile << "// IP handleCall" << Prjshort << "KlsAkeyMod_klsEq --- IBEGIN" << endl;
			outfile << "\tset<uint> moditems;" << endl;
			outfile << endl;

			first = true;
			ref = 0;

			for (auto it = vecrefsBaseconshorts.begin(); it != vecrefsBaseconshorts.end(); it++) {
				if ((*it).first != ref) {
					ref = (*it).first;

					if (dbswznm->tblwznmmvector->loadRecByRef(ref, &vec)) {
						outfile << "\t";
						if (first) first = false;
						else outfile << "} else ";
						outfile << "if (ixInv == Vec" << Prjshort << "VKeylist::" << StrMod::uc(vec->sref) << ") {" << endl;

						delete vec;

					} else ref = 0;
				};

				if (ref != 0) outfile << "\t\trefresh" << (*it).second << "(dbs" << prjshort << ", moditems);" << endl;
			};

			if (!first) outfile << "\t};" << endl;
			outfile << endl;

			outfile << "\txchg->submitDpch(getNewDpchEng(moditems));" << endl;
			outfile << "// IP handleCall" << Prjshort << "KlsAkeyMod_klsEq --- IEND" << endl;
		};

	} else if (pnl->ixVBasetype == VecWznmVMPanelBasetype::RECLIST) {
		// -- handleCallXxxxStatChg
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IBEGIN" << endl;
		outfile << "\t// IP handleCall" << Prjshort << "StatChg --- BEGIN" << endl;
		outfile << endl;

		outfile << "\tset<uint> moditems;" << endl;
		outfile << endl;

		outfile << "\tif (jrefTrig == qry->jref) {" << endl;
		outfile << "\t\tif (!muteRefresh) {" << endl;
		outfile << "\t\t\trefresh(dbs" << prjshort << ", moditems);" << endl;
		outfile << "\t\t\tif (qry->ix" << Prjshort << "VQrystate == Vec" << Prjshort << "VQrystate::UTD) insert(moditems, {DpchEngData::STATSHRQRY, DpchEngData::STGIACQRY, DpchEngData::RST});" << endl;
		outfile << "\t\t\tif (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));" << endl;
		outfile << "\t\t};" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\t// IP handleCall" << Prjshort << "StatChg --- END" << endl;
		outfile << "// IP handleCall" << Prjshort << "StatChg --- IEND" << endl;
	};
};

void WznmWrsrvPnl::writePnlCpp_butnewview(
			DbsWznm* dbswznm
			, fstream& outfile
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMTable& rectbls
			, WznmMControl* con
			, const string& baseconsref
			, list<Trg*>& trgs
			, WznmMTable* reftbl
			, WznmMTablecol* reftco
			, const bool newNotView
		) {
	WznmMTable* trgcartbl = NULL;
	WznmMTablecol* inctco = NULL;

	Trg* trg;

	Expr expr;

	string indent;

	set<string> unqss;
	string s, s2;

	bool first;

	string prjshort = StrMod::lc(Prjshort);
	string PRJSHORT = StrMod::uc(Prjshort);

	outfile << "\tubigint jrefNew = 0;" << endl;
	outfile << "\tstring sref;" << endl;
	outfile << endl;

	// card preset if required for at least one target
	for (auto it = trgs.begin(); it != trgs.end(); it++) {
		trg = *it;

		if (trg->carpstcond != "") {
			if (!(newNotView && ((trg->cond1 != "") || (trg->cond2 != "")))) { // for now, no new with cond1/cond2
				outfile << "\tuint ixPre = xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXPRE, jref);" << endl;
				outfile << "\tubigint refPre = ((ixPre) ? xchg->getRefPreset(ixPre, jref) : 0);" << endl;
				outfile << endl;

				break;
			};
		};
	};

	// other presets once each
	unqss.clear();
	for (auto it = trgs.begin(); it != trgs.end(); it++) {
		trg = *it;

		if (!(newNotView && ((trg->cond1 != "") || (trg->cond2 != "")))) { // for now, no new with cond1/cond2
			if (trg->carrecpstcond != "") unqss.insert(trg->carrecpstcond);
			else if (trg->sesspstcond != "") unqss.insert(trg->sesspstcond);
		};
	};

	if (!unqss.empty()) {
		for (auto it = unqss.begin(); it != unqss.end(); it++) {
			s = pstcondToShort(*it);
			outfile << "\tubigint ref" + StrMod::cap(s) + " = xchg->getRefPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(s) << ", jref);" << endl;
		};
		outfile << endl;
	};

	outfile << "\tif (statshr." << baseconsref << "Avail";
	if (con->Active != "") outfile << " && statshr." << con->sref << "Active";
	outfile << ") {" << endl;

	// traverse all possible targets: cond1 "xyz.hktEq(loc)" pnldetail & view only ; cond2 "xyz.inSbs(abc)", ... - view only ; max. one out of *pstcond
	first = true;
	for (auto it = trgs.begin(); it != trgs.end(); it++) {
		trg = *it;

		if (!(newNotView && ((trg->cond1 != "") || (trg->cond2 != "")))) { // for now, no new with cond1/cond2
			if (trg->carrecpstcond != "") s = pstcondToShort(trg->carrecpstcond);
			else if (trg->carpstcond != "") s = pstcondToShort(trg->carpstcond);
			else if (trg->sesspstcond != "") s = pstcondToShort(trg->sesspstcond);

			if (!first) outfile << "\t\tif (jrefNew == 0) {" << endl;

			if (first) indent = "\t\t";
			else indent = "\t\t\t";

			if (newNotView) outfile << indent << "if ((xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXCRDACC" << StrMod::uc(trg->srefWznmMCard.substr(3+4)) << ", jref) & Vec" << Prjshort << "WAccess::EDIT) != 0)";
			else outfile << indent << "if (xchg->getIxPreset(Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "IXCRDACC" << StrMod::uc(trg->srefWznmMCard.substr(3+4)) << ", jref))";

			if (trg->cond1 != "") if (expr.tokenize(trg->cond1)) if (expr.parse()) if (expr.root) {
				s2 = getCaleval(dbswznm, refWznmMVersion, Prjshort, rectbls, expr.root, false);
				if (s2 != "") outfile << " if " << s2;
			};

			if (trg->cond2 != "") if (expr.tokenize(trg->cond2)) if (expr.parse()) if (expr.root) {
				s2 = getCaleval(dbswznm, refWznmMVersion, Prjshort, rectbls, expr.root, false);
				if (s2 != "") outfile << " if " << s2;
			};

			if (trg->carrecpstcond != "") outfile << " if (ref" << StrMod::cap(s) << " != 0)";
			else if (trg->carpstcond != "") outfile << " if (ixPre == Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(s) << ")";
			else if (trg->sesspstcond != "") outfile << " if (ref" << StrMod::cap(s) << " != 0)";

			outfile << " {" << endl;
			outfile << indent << "\tsref = \"" << trg->srefWznmMCard << "\";" << endl;

			outfile << indent << "\txchg->triggerIxRefSrefIntvalToRefCall(dbs" << prjshort << ", Vec" << Prjshort << "VCall::CALL" << PRJSHORT << "CRDOPEN, jref";

			if (trg->carrecpstcond != "") outfile << ", Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(s) << ", ref" << StrMod::cap(s);
			else if (trg->carpstcond != "") outfile << ", ixPre, refPre";
			else if (trg->sesspstcond != "") outfile << ", Vec" << Prjshort << "VPreset::PRE" << PRJSHORT << "REF" << StrMod::uc(s) << ", ref" << StrMod::cap(s);
			else outfile << ", 0, 0";

			outfile << ", sref";

			if (newNotView) {
				outfile << ", -1";

			} else {
				if (trg->incRefWznmMTablecol != 0) {
					if (dbswznm->tblwznmmtable->loadRecByRef(trg->refWznmMTable, &trgcartbl)) {
						if (dbswznm->tblwznmmtablecol->loadRecByRef(trg->incRefWznmMTablecol, &inctco)) {
							outfile << ", [&](){ubigint ref = 0; dbs" << prjshort << "->loadRefBySQL(\"SELECT ref FROM " << trgcartbl->sref << " WHERE " << inctco->sref << " = \" + to_string(rec" << StrMod::cap(reftbl->Short) << ".";
							if (reftco) outfile << reftco->sref;
							else outfile << "ref";
							outfile << "), ref); return ref;}()";

							delete inctco;
						};
						delete trgcartbl;
					};

				} else {
					outfile << ", rec" << StrMod::cap(reftbl->Short) << ".";
					if (reftco) outfile << reftco->sref;
					else outfile << "ref";
				};
			};

			outfile << ", jrefNew);" << endl;

			outfile << indent << "};" << endl;

			indent = indent.substr(1);
			if (!first) outfile << indent << "};" << endl;
			else first = false;
		};
	};

	outfile << endl;
	outfile << "\t\tif (jrefNew == 0) *dpcheng = new DpchEng" << Prjshort << "Confirm(false, 0, \"\");" << endl;
	outfile << "\t\telse *dpcheng = new DpchEng" << Prjshort << "Confirm(true, jrefNew, sref);" << endl;

	outfile << "\t};" << endl;
};

void WznmWrsrvPnl::writePnlCpp_evals(
			fstream& outfile
			, ListWznmMControl& cons
			, const unsigned int ix0
			, const unsigned int ix1
			, vector<string>& bitsEval
			, vector<string>& rulesEval
			, vector<string>& exprsEval
			, vector<bool>& oksEval
			, const string& prjshort
		) {
	WznmMControl* con = NULL;

	string s, s2;

	for (unsigned int i=ix0;i<=ix1; i++) {
		con = cons.nodes[i];

		s = con->sref + "Avail";
		s2 = con->sref + "Active";

		for (unsigned int j = 0; j < rulesEval.size(); j++) {
			if (!oksEval[j]) {
				if ((rulesEval[j] == s) || (rulesEval[j] == s2)) {
					writeEvalstatshr(outfile, bitsEval[j], rulesEval[j], exprsEval[j], prjshort);
					oksEval[j] = true;
				};
			};
		};
	};
};

string WznmWrsrvPnl::getCondeval(
			DbsWznm* dbswznm
			, const ubigint refWznmMVersion
			, const string& Prjshort
			, ListWznmMTable& rectbls
			, const string& cond
		) {
	string retval;

	Expr expr;

	if (expr.tokenize(cond)) if (expr.parse()) if (expr.root) if (expr.root->ixVNodetype == Expr::VecVNodetype::FCT) retval = getCaleval(dbswznm, refWznmMVersion, Prjshort, rectbls, expr.root, false);

	return retval;
};

string WznmWrsrvPnl::pstcondToShort(
			const string& pstcond
		) {
	// pre.refXyz() -> xyz
	string retval;

	Expr expr;
	Expr::Node* node = NULL;

	if (expr.tokenize(pstcond)) if (expr.parse()) if (expr.root) {
		node = expr.root;

		if (node->ixVNodetype == Expr::VecVNodetype::FCT) {
			if ((node->key.find("pre.") == 0) && (node->key.length() > 4)) {
				if (node->key.substr(4).find("ref") == 0) {
					retval = StrMod::uncap(node->key.substr(4+3));
				};
			};
		};
	};

	return retval;
};
// IP cust --- IEND
