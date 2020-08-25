/**
	* \file PnlWznmEvtRec_evals.cpp
	* job handler for job PnlWznmEvtRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmEvtRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refEvt()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFEVT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

