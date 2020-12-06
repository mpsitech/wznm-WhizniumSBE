/**
	* \file PnlWznmSbsRec_evals.cpp
	* job handler for job PnlWznmSbsRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmSbsRec::evalPnlpst1nquerymodAvail(
			DbsWznm* dbswznm
		) {
	// !sbs.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSbs.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSbsRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refSbs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFSBS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
