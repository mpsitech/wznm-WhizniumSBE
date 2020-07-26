/**
	* \file PnlWznmNavDbstr_evals.cpp
	* job handler for job PnlWznmNavDbstr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavDbstr::evalLstTblAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTbl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButTblViewActive(
			DbsWznm* dbswznm
		) {
	// LstTbl.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTbl != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButTblNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstTcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButTcoViewActive(
			DbsWznm* dbswznm
		) {
	// LstTco.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTco != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButTcoNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstSbsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButSbsViewActive(
			DbsWznm* dbswznm
		) {
	// LstSbs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSbs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButSbsNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstRelAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButRelViewActive(
			DbsWznm* dbswznm
		) {
	// LstRel.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRel != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButRelNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstVecAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButVecViewActive(
			DbsWznm* dbswznm
		) {
	// LstVec.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVec != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButVecNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstVitAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButVitViewActive(
			DbsWznm* dbswznm
		) {
	// LstVit.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVit != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButVitNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstChkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccChk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCHK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButChkViewActive(
			DbsWznm* dbswznm
		) {
	// LstChk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstChk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButChkNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstStbAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStb()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButStbViewActive(
			DbsWznm* dbswznm
		) {
	// LstStb.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstStb != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButStbNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstIexAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIex()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButIexViewActive(
			DbsWznm* dbswznm
		) {
	// LstIex.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstIex != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButIexNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstImeAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIme()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButImeViewActive(
			DbsWznm* dbswznm
		) {
	// LstIme.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstIme != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButImeNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalLstIelAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDbstr::evalButIelViewActive(
			DbsWznm* dbswznm
		) {
	// LstIel.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstIel != 0);
	args.push_back(a);

	return(args.back());
};

