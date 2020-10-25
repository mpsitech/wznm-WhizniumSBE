/**
	* \file PnlWznmOpxRec_evals.cpp
	* job handler for job PnlWznmOpxRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmOpxRec::evalPnlsqkmnstubAvail(
			DbsWznm* dbswznm
		) {
	// !opx.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOpx.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmOpxRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

