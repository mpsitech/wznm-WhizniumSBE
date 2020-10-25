/**
	* \file PnlWznmSbsDetail_evals.cpp
	* job handler for job PnlWznmSbsDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmSbsDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxfShoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtTblActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtCarActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButCarViewAvail(
			DbsWznm* dbswznm
		) {
	// sbs.carEq(0)|(pre.ixCrdaccCar()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSbs.refWznmMCard == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
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

bool PnlWznmSbsDetail::evalButCarViewActive(
			DbsWznm* dbswznm
		) {
	// !sbs.carEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMCard == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxfCndActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButPstNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)&sbs.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButPstDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)&!sbs.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstSrfAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstJtiAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButPstJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstTitAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstVerAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalTxtPstVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButPstVerViewAvail(
			DbsWznm* dbswznm
		) {
	// pst.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recPst.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmSbsDetail::evalButPstVerViewActive(
			DbsWznm* dbswznm
		) {
	// !pst.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPst.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstScoAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstScoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstAtyAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsDetail::evalPupPstAtyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSbsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

