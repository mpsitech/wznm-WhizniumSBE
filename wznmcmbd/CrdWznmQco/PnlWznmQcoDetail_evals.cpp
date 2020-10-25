/**
	* \file PnlWznmQcoDetail_evals.cpp
	* job handler for job PnlWznmQcoDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmQcoDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalTxfShoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalLstOccActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalTxtQryActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalButQryViewAvail(
			DbsWznm* dbswznm
		) {
	// qco.qryEq(0)|(pre.ixCrdaccQry()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recQco.qryRefWznmMQuery == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
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

bool PnlWznmQcoDetail::evalButQryViewActive(
			DbsWznm* dbswznm
		) {
	// !qco.qryEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recQco.qryRefWznmMQuery == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalTxtTcoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalTxtStbActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQcoDetail::evalButStbViewAvail(
			DbsWznm* dbswznm
		) {
	// qco.stbEq(0)|(pre.ixCrdaccStb()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recQco.refWznmMStub == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
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

bool PnlWznmQcoDetail::evalButStbViewActive(
			DbsWznm* dbswznm
		) {
	// !qco.stbEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recQco.refWznmMStub == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

