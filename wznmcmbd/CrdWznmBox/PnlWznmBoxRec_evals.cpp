/**
	* \file PnlWznmBoxRec_evals.cpp
	* job handler for job PnlWznmBoxRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmBoxRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refBox()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFBOX, jref) != 0);
	args.push_back(a);

	return(args.back());
};
