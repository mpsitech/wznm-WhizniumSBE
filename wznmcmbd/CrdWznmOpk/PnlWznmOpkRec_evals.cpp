/**
	* \file PnlWznmOpkRec_evals.cpp
	* job handler for job PnlWznmOpkRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmOpkRec::evalPnlsqkmnstubAvail(
			DbsWznm* dbswznm
		) {
	// !opk.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOpk.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmOpkRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refOpk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

