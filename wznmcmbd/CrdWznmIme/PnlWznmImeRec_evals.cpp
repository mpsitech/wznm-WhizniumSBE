/**
	* \file PnlWznmImeRec_evals.cpp
	* job handler for job PnlWznmImeRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmImeRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refIme()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFIME, jref) != 0);
	args.push_back(a);

	return(args.back());
};

