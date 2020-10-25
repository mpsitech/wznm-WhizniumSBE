/**
	* \file PnlWznmLibRec_evals.cpp
	* job handler for job PnlWznmLibRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmLibRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

