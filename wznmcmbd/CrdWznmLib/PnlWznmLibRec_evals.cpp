/**
	* \file PnlWznmLibRec_evals.cpp
	* job handler for job PnlWznmLibRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmLibRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};
