/**
	* \file PnlWznmIexDetail_evals.cpp
	* job handler for job PnlWznmIexDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmIexDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxfShoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalPupJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalButJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxtTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxtVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalButVerViewAvail(
			DbsWznm* dbswznm
		) {
	// iex.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recIex.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmIexDetail::evalButVerViewActive(
			DbsWznm* dbswznm
		) {
	// !iex.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recIex.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxtJobActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalButJobViewAvail(
			DbsWznm* dbswznm
		) {
	// iex.jobEq(0)|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recIex.refWznmMJob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
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

bool PnlWznmIexDetail::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// !iex.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recIex.refWznmMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxfMivActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmIexDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccIexIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

