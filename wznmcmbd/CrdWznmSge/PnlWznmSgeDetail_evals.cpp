/**
	* \file PnlWznmSgeDetail_evals.cpp
	* job handler for job PnlWznmSgeDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmSgeDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtJobActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButJobViewAvail(
			DbsWznm* dbswznm
		) {
	// sge.jobEq(0)|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSge.jobRefWznmMJob == 0);
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

bool PnlWznmSgeDetail::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// !sge.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.jobRefWznmMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxfMonActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtSnxActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButSnxViewAvail(
			DbsWznm* dbswznm
		) {
	// sge.snxEq(0)|((pre.ixCrdaccSge()&pre.refJob())|(pre.ixCrdaccSge()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSge.snxRefWznmMStage == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
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

bool PnlWznmSgeDetail::evalButSnxViewActive(
			DbsWznm* dbswznm
		) {
	// !sge.snxEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.snxRefWznmMStage == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtFnxActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButFnxViewAvail(
			DbsWznm* dbswznm
		) {
	// sge.fnxEq(0)|((pre.ixCrdaccSge()&pre.refJob())|(pre.ixCrdaccSge()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recSge.fnxRefWznmMStage == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) != 0);
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

bool PnlWznmSgeDetail::evalButFnxViewActive(
			DbsWznm* dbswznm
		) {
	// !sge.fnxEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.fnxRefWznmMStage == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButSqkNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)&sge.sqkEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButSqkDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)&!sge.sqkEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmSgeDetail::evalPupSqkJtiAvail(
			DbsWznm* dbswznm
		) {
	// !sge.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalPupSqkJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalButSqkJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtSqkTitAvail(
			DbsWznm* dbswznm
		) {
	// !sge.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxtSqkTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxfSqkExaAvail(
			DbsWznm* dbswznm
		) {
	// !sge.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeDetail::evalTxfSqkExaActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSgeIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSGE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};



