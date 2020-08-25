/**
	* \file PnlWznmIexRec_evals.cpp
	* job handler for job PnlWznmIexRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmIexRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refIex()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIEX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

