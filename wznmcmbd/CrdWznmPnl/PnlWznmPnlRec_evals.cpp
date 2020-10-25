/**
	* \file PnlWznmPnlRec_evals.cpp
	* job handler for job PnlWznmPnlRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmPnlRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refPnl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPNL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

