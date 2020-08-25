/**
	* \file PnlWznmCarRec_evals.cpp
	* job handler for job PnlWznmCarRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCarRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refCar()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

