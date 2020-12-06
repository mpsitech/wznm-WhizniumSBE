/**
	* \file PnlWznmCtpRec_evals.cpp
	* job handler for job PnlWznmCtpRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
