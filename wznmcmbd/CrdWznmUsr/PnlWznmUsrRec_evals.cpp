/**
	* \file PnlWznmUsrRec_evals.cpp
	* job handler for job PnlWznmUsrRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmUsrRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

