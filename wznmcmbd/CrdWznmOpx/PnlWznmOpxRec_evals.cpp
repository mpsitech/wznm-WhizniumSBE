/**
	* \file PnlWznmOpxRec_evals.cpp
	* job handler for job PnlWznmOpxRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmOpxRec::evalPnlsqkmnstubAvail(
			DbsWznm* dbswznm
		) {
	// !opx.sqkEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOpx.refWznmMSquawk == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmOpxRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};



