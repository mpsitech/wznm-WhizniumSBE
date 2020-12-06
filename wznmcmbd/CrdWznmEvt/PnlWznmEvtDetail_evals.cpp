/**
	* \file PnlWznmEvtDetail_evals.cpp
	* job handler for job PnlWznmEvtDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmEvtDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmEvtDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmEvtDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmEvtDetail::evalTxtAppActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmEvtDetail::evalButAppViewAvail(
			DbsWznm* dbswznm
		) {
	// evt.appEq(0)|(pre.ixCrdaccApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recEvt.refWznmMApp == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmEvtDetail::evalButAppViewActive(
			DbsWznm* dbswznm
		) {
	// !evt.appEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recEvt.refWznmMApp == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmEvtDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccEvtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCEVT, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
