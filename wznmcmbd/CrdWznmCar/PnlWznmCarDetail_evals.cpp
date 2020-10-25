/**
	* \file PnlWznmCarDetail_evals.cpp
	* job handler for job PnlWznmCarDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCarDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalPupJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalButJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxtTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxtMdlActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalButMdlViewAvail(
			DbsWznm* dbswznm
		) {
	// car.mdlEq(0)|(pre.ixCrdaccMdl()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCar.mdlRefWznmMModule == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
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

bool PnlWznmCarDetail::evalButMdlViewActive(
			DbsWznm* dbswznm
		) {
	// !car.mdlEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCar.mdlRefWznmMModule == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxtReuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalButReuViewAvail(
			DbsWznm* dbswznm
		) {
	// car.reuEq(0)|(pre.ixCrdaccSbs()&car.retEq(sbs)&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCar.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);
	a = false; a = (recCar.refIxVTbl == VecWznmVMCardRefTbl::SBS);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmCarDetail::evalButReuViewActive(
			DbsWznm* dbswznm
		) {
	// !car.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCar.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxtJobActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalButJobViewAvail(
			DbsWznm* dbswznm
		) {
	// car.jobEq(0)|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCar.refWznmMJob == 0);
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

bool PnlWznmCarDetail::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// !car.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCar.refWznmMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxfAvlActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCarDetail::evalTxfActActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCarIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

