/**
	* \file PnlWznmJobRec_evals.cpp
	* job handler for job PnlWznmJobRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmJobRec::evalPnlsubmnjobAvail(
			DbsWznm* dbswznm
		) {
	// job.typEq(!root)

	vector<bool> args;
	bool a;

	a = false; a = (recJob.ixVBasetype == VecWznmVMJobBasetype::ROOT);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmJobRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refJob()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFJOB, jref) != 0);
	args.push_back(a);

	return(args.back());
};
