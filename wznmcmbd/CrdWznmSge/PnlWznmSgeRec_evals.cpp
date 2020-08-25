/**
	* \file PnlWznmSgeRec_evals.cpp
	* job handler for job PnlWznmSgeRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

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

