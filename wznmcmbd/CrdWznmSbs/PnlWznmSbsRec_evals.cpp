/**
	* \file PnlWznmSbsRec_evals.cpp
	* job handler for job PnlWznmSbsRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

