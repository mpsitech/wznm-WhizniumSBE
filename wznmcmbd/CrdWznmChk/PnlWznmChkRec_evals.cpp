/**
	* \file PnlWznmChkRec_evals.cpp
	* job handler for job PnlWznmChkRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmChkRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refChk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCHK, jref) != 0);
	args.push_back(a);

	return(args.back());
};
