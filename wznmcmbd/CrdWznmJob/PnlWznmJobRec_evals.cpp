/**
	* \file PnlWznmJobRec_evals.cpp
	* job handler for job PnlWznmJobRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmJobRec::evalPnlsupmnjobAvail(
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

