/**
	* \file PnlWznmSgeRec_evals.cpp
	* job handler for job PnlWznmSgeRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmSgeRec::evalPnlsqkmnstubAvail(
			DbsWznm* dbswznm
		) {
	// !sge.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSge.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSgeRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refSge()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSGE, jref) != 0);
	args.push_back(a);

	return(args.back());
};
