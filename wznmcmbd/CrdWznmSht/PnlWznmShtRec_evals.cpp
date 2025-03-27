/**
	* \file PnlWznmShtRec_evals.cpp
	* job handler for job PnlWznmShtRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmShtRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};
