/**
	* \file PnlWznmQcoRec_evals.cpp
	* job handler for job PnlWznmQcoRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmQcoRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refQco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFQCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

