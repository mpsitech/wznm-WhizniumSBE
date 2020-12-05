/**
	* \file PnlWznmCapRec_evals.cpp
	* job handler for job PnlWznmCapRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCapRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refCap()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAP, jref) != 0);
	args.push_back(a);

	return(args.back());
};



