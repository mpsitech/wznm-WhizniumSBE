/**
	* \file PnlWznmConRec_evals.cpp
	* job handler for job PnlWznmConRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmConRec::evalPnlfedref1nrtblockAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refCon()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCON, jref) != 0);
	args.push_back(a);

	return(args.back());
};
