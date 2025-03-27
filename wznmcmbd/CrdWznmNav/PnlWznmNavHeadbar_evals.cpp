/**
	* \file PnlWznmNavHeadbar_evals.cpp
	* job handler for job PnlWznmNavHeadbar (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavHeadbar::evalMenCrdAvail(
			DbsWznm* dbswznm
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()|MspCrd4Avail()|MspCrd5Avail()|MspCrd6Avail()|MspCrd7Avail()|MspCrd8Avail()|MspCrd9Avail()|MspCrd10Avail()|MspCrd11Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd4Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd5Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd6Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd7Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd8Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd9Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd10Avail(dbswznm);
	args.push_back(a);
	a = false; a = evalMspCrd11Avail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdUsgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdUsrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdPrsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdFilAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd2Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdLocAvail()|MitCrdTagAvail()|MitCrdCtpAvail()|MitCrdMchAvail()|MitCrdLibAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdLocAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdTagAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCtpAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdMchAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdLibAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdLocAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdTagAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTag()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdCtpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdMchAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdLibAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd3Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdPrjAvail()|MitCrdVerAvail()|MitCrdCapAvail()|MitCrdErrAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPrjAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdVerAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCapAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdErrAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdPrjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdVerAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdCapAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCap()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdErrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd4Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdTblAvail()|MitCrdTcoAvail()|MitCrdSbsAvail()|MitCrdRelAvail()|MitCrdVecAvail()|MitCrdVitAvail()|MitCrdChkAvail()|MitCrdStbAvail()|MitCrdIexAvail()|MitCrdImeAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdTblAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdTcoAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdSbsAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdRelAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdVecAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdVitAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdChkAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdStbAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdIexAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdImeAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdTblAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTbl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdTcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdSbsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdRelAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdVecAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdVitAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdChkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccChk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdStbAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdIexAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIex()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdImeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIme()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd5Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdPstAvail()|MitCrdMdlAvail()|MitCrdCarAvail()|MitCrdDlgAvail()|MitCrdPnlAvail()|MitCrdQryAvail()|MitCrdQcoAvail()|MitCrdQmdAvail()|MitCrdConAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdPstAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdMdlAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCarAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdDlgAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdPnlAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdQryAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdQcoAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdQmdAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdConAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdPstAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdMdlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMdl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdCarAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdDlgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccDlg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdPnlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdQryAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQry()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdQcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdQmdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdConAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd6Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdOpkAvail()|MitCrdOpxAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdOpkAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdOpxAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdOpkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdOpxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd7Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdJobAvail()|MitCrdSgeAvail()|MitCrdMtdAvail()|MitCrdBlkAvail()|MitCrdCalAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdJobAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdSgeAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdMtdAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdBlkAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCalAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdJobAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdSgeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSge()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdMtdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMtd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdBlkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBlk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdCalAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd8Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdCmpAvail()|MitCrdRlsAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdCmpAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdRlsAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdCmpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdRlsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd9Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdVisAvail()|MitCrdShtAvail()|MitCrdBoxAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdVisAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdShtAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdBoxAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdVisAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdShtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdBoxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBox()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd10Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdAppAvail()|MitCrdRtjAvail()|MitCrdEvtAvail()|MitCrdSeqAvail()|MitCrdSteAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdAppAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdRtjAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdEvtAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdSeqAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdSteAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdAppAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdRtjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdEvtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdSeqAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSeq()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdSteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSte()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMspCrd11Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdUtlAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUtlAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavHeadbar::evalMitCrdUtlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
