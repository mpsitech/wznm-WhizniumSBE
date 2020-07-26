/**
	* \file PnlWznmUsgRec_evals.cpp
	* job handler for job PnlWznmUsgRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmUsgRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

