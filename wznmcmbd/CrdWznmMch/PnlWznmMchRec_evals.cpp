/**
	* \file PnlWznmMchRec_evals.cpp
	* job handler for job PnlWznmMchRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmMchRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

