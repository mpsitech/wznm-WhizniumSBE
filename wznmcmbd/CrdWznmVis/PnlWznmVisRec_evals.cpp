/**
	* \file PnlWznmVisRec_evals.cpp
	* job handler for job PnlWznmVisRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmVisRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
