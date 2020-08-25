/**
	* \file PnlWznmMtyRec_evals.cpp
	* job handler for job PnlWznmMtyRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmMtyRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refMty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

