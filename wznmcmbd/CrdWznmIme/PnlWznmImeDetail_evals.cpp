/**
	* \file PnlWznmImeDetail_evals.cpp
	* job handler for job PnlWznmImeDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmImeDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalTxtIexActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalButIexViewAvail(
			DbsWznm* dbswznm
		) {
	// ime.iexEq(0)|(pre.ixCrdaccIex()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recIme.refWznmMImpexpcplx == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmImeDetail::evalButIexViewActive(
			DbsWznm* dbswznm
		) {
	// !ime.iexEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recIme.refWznmMImpexpcplx == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmImeDetail::evalTxtSupActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalButSupViewAvail(
			DbsWznm* dbswznm
		) {
	// ime.supEq(0)|((pre.ixCrdaccIme()&pre.refIex())|(pre.ixCrdaccIme()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recIme.supRefWznmMImpexp == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmImeDetail::evalButSupViewActive(
			DbsWznm* dbswznm
		) {
	// !ime.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recIme.supRefWznmMImpexp == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmImeDetail::evalTxtTblActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalLstIopActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalLstRtrActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalButRtrViewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalButRtrViewActive(
			DbsWznm* dbswznm
		) {
	// LstRtr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRtr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmImeDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccImeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

