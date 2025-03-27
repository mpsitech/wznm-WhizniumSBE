/**
	* \file PnlWznmBoxDetail_evals.cpp
	* job handler for job PnlWznmBoxDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmBoxDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBoxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalTxtShtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBoxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalButShtViewAvail(
			DbsWznm* dbswznm
		) {
	// box.shtEq(0)|(pre.ixCrdaccSht()&pre.refVis())

	vector<bool> args;
	bool a, b;

	a = false; a = (recBox.refWznmMSheet == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSHT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmBoxDetail::evalButShtViewActive(
			DbsWznm* dbswznm
		) {
	// !box.shtEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recBox.refWznmMSheet == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalTxtUnvActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBoxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalTxfXActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBoxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmBoxDetail::evalTxfYActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccBoxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCBOX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
