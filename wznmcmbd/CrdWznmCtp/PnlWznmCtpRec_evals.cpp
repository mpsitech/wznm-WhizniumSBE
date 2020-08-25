/**
	* \file PnlWznmCtpRec_evals.cpp
	* job handler for job PnlWznmCtpRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCtpRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

