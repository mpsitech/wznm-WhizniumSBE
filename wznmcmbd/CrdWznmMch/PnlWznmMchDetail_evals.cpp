/**
	* \file PnlWznmMchDetail_evals.cpp
	* job handler for job PnlWznmMchDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmMchDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalTxtSupActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalButSupViewAvail(
			DbsWznm* dbswznm
		) {
	// mch.supEq(0)|(pre.ixCrdaccMch())

	vector<bool> args;
	bool a, b;

	a = false; a = (recMch.supRefWznmMMachine == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmMchDetail::evalButSupViewActive(
			DbsWznm* dbswznm
		) {
	// !mch.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMch.supRefWznmMMachine == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmMchDetail::evalTxtCchActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalButCchViewAvail(
			DbsWznm* dbswznm
		) {
	// mch.cchEq(0)|(pre.ixCrdaccMch())

	vector<bool> args;
	bool a, b;

	a = false; a = (recMch.cchRefWznmMMachine == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmMchDetail::evalButCchViewActive(
			DbsWznm* dbswznm
		) {
	// !mch.cchEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recMch.cchRefWznmMMachine == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmMchDetail::evalPupPkmActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalButPkmEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmMchDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
