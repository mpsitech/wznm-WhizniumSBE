/**
	* \file CrdWznmNav_evals.cpp
	* job handler for job CrdWznmNav (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmNav::evalPnlpreAvail(
			DbsWznm* dbswznm
		) {
	// pre.refApp()|pre.refVer()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmNav::evalPnladminAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) != 0);
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

bool CrdWznmNav::evalPnlglobalAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLoc()|pre.ixCrdaccTag()|pre.ixCrdaccCtp()|pre.ixCrdaccMty()|pre.ixCrdaccMch()|pre.ixCrdaccLib()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTY, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref) != 0);
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

	return(args.back());
};

bool CrdWznmNav::evalPnlprojectAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrj()|pre.ixCrdaccVer()|pre.ixCrdaccCap()|pre.ixCrdaccErr()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref) != 0);
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

bool CrdWznmNav::evalPnldbstrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTbl()|pre.ixCrdaccTco()|pre.ixCrdaccSbs()|pre.ixCrdaccRel()|pre.ixCrdaccVec()|pre.ixCrdaccVit()|pre.ixCrdaccChk()|pre.ixCrdaccStb()|pre.ixCrdaccIex()|pre.ixCrdaccIme()|pre.ixCrdaccIel()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEL, jref) != 0);
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

bool CrdWznmNav::evalPnluixAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPst()|pre.ixCrdaccMdl()|pre.ixCrdaccCar()|pre.ixCrdaccDlg()|pre.ixCrdaccPnl()|pre.ixCrdaccQry()|pre.ixCrdaccQco()|pre.ixCrdaccQmd()|pre.ixCrdaccCon()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
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

bool CrdWznmNav::evalPnlcompAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpk()|pre.ixCrdaccOpx()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmNav::evalPnljobAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccJob()|pre.ixCrdaccSge()|pre.ixCrdaccMtd()|pre.ixCrdaccBlk()|pre.ixCrdaccCal()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref) != 0);
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

bool CrdWznmNav::evalPnldeployAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmp()|pre.ixCrdaccRls()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmNav::evalPnlappdevAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccApp()|pre.ixCrdaccRtj()|pre.ixCrdaccEvt()|pre.ixCrdaccSeq()|pre.ixCrdaccSte()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) != 0);
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

bool CrdWznmNav::evalPnlauxfctAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitSesSpsAvail(
			DbsWznm* dbswznm
		) {
	// stgwznmappearance.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwznmappearance.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd1Avail(
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

bool CrdWznmNav::evalMitCrdUsgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdUsrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdPrsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdFilAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd2Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdLocAvail()|MitCrdTagAvail()|MitCrdCtpAvail()|MitCrdMtyAvail()|MitCrdMchAvail()|MitCrdLibAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdLocAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdTagAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCtpAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdMtyAvail(dbswznm);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdLocAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdTagAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTag()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCtpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMtyAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMchAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdLibAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd3Avail(
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

bool CrdWznmNav::evalMitCrdPrjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdVerAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCapAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCap()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCapActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdErrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdErrActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd4Avail(
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

bool CrdWznmNav::evalMitCrdTblAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTbl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdTblActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdTcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdTcoActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSbsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSbsActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRelAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRelActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdVecAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdVecActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdVitAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdVitActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdChkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccChk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdChkActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdStbAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdStbActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdIexAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIex()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdIexActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdImeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIme()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdImeActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd5Avail(
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

bool CrdWznmNav::evalMitCrdPstAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPst()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdPstActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMdlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMdl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMdlActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCarAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCarActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdDlgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccDlg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdDlgActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdPnlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdPnlActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQryAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQry()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQryActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQcoActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQmdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQmd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQMD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdQmdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdConAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdConActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd6Avail(
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

bool CrdWznmNav::evalMitCrdOpkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdOpkActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdOpxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdOpxActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd7Avail(
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

bool CrdWznmNav::evalMitCrdJobAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdJobActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSgeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSge()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSgeActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMtdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMtd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdMtdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdBlkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBlk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBLK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdBlkActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCalAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCal()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdCalActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd8Avail(
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

bool CrdWznmNav::evalMitCrdCmpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRlsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRlsActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd9Avail(
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

bool CrdWznmNav::evalMitCrdAppAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRtjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdRtjActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdEvtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdEvtActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSeqAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSeq()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSeqActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSte()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdSteActive(
			DbsWznm* dbswznm
		) {
	// pre.refApp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspCrd10Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdUtlAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdUtlAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitCrdUtlAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMspApp2Avail(
			DbsWznm* dbswznm
		) {
	// MitAppMlcAvail()|MitAppLoiAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitAppMlcAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitAppLoiAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmNav::evalMitAppMlcAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool CrdWznmNav::evalMitAppLoiAvail(
			DbsWznm* dbswznm
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {uint cnt = 0; dbswznm->loadUintBySQL("SELECT COUNT(ref) FROM TblWznmMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};

