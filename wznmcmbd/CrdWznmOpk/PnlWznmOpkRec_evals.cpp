/**
	* \file PnlWznmOpkRec_evals.cpp
	* job handler for job PnlWznmOpkRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmOpkRec::evalPnlsqkmnstubAvail(
			DbsWznm* dbswznm
		) {
	// !opk.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOpk.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmOpkRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refOpk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPK, jref) != 0);
	args.push_back(a);

	return(args.back());
};



