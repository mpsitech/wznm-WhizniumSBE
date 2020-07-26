/**
	* \file PnlWznmRelRec_evals.cpp
	* job handler for job PnlWznmRelRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmRelRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refRel()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFREL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

