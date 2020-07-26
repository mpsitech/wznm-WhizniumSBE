/**
	* \file PnlWznmNavAuxfct_evals.cpp
	* job handler for job PnlWznmNavAuxfct (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavAuxfct::evalButUtlNewcrdAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUtl()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUTL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

