/**
	* \file PnlWznmConRec_evals.cpp
	* job handler for job PnlWznmConRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

