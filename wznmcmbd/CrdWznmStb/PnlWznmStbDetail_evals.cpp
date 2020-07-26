/**
	* \file PnlWznmStbDetail_evals.cpp
	* job handler for job PnlWznmStbDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmStbDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalTxtTblActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalTxtSbsActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalButSbsViewAvail(
			DbsWznm* dbswznm
		) {
	// stb.sbsEq(0)|(pre.ixCrdaccSbs()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recStb.refWznmMSubset == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
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

bool PnlWznmStbDetail::evalButSbsViewActive(
			DbsWznm* dbswznm
		) {
	// !stb.sbsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recStb.refWznmMSubset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmStbDetail::evalChkHrcActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalTxtTcoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalButTcoViewAvail(
			DbsWznm* dbswznm
		) {
	// stb.tcoEq(0)|(pre.ixCrdaccTco()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recStb.refWznmMTablecol == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
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

bool PnlWznmStbDetail::evalButTcoViewActive(
			DbsWznm* dbswznm
		) {
	// !stb.tcoEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recStb.refWznmMTablecol == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmStbDetail::evalChkLclActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbDetail::evalTxfExaActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

