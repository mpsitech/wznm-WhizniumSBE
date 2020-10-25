/**
	* \file PnlWznmUsgDetail_evals.cpp
	* job handler for job PnlWznmUsgDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmUsgDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmUsgDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmUsgDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmUsgDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSG, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

