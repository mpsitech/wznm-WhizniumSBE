/**
	* \file PnlWznmPrsRec_evals.cpp
	* job handler for job PnlWznmPrsRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmPrsRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

