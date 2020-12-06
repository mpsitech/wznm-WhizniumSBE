/**
	* \file PnlWznmRtjDetail_evals.cpp
	* job handler for job PnlWznmRtjDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmRtjDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalTxtAppActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButAppViewAvail(
			DbsWznm* dbswznm
		) {
	// rtj.appEq(0)|(pre.ixCrdaccApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRtj.refWznmMApp == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButAppViewActive(
			DbsWznm* dbswznm
		) {
	// !rtj.appEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRtj.refWznmMApp == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalTxtSupActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButSupViewAvail(
			DbsWznm* dbswznm
		) {
	// rtj.supEq(0)|(pre.ixCrdaccRtj()&pre.refApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRtj.supRefWznmMRtjob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButSupViewActive(
			DbsWznm* dbswznm
		) {
	// !rtj.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRtj.supRefWznmMRtjob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalTxtJobActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalButJobViewAvail(
			DbsWznm* dbswznm
		) {
	// rtj.jobEq(0)|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRtj.refWznmMJob == 0);
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

bool PnlWznmRtjDetail::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// !rtj.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRtj.refWznmMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRtjDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRtjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
