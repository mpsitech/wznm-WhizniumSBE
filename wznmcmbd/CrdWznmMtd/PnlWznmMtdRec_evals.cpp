/**
	* \file PnlWznmMtdRec_evals.cpp
	* job handler for job PnlWznmMtdRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmMtdRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refMtd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMTD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

