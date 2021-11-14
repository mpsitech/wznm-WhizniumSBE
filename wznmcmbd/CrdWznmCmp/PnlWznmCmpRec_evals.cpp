/**
	* \file PnlWznmCmpRec_evals.cpp
	* job handler for job PnlWznmCmpRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCmpRec::evalPnlmnlibraryAvail(
			DbsWznm* dbswznm
		) {
	// cmp.inSbs(ccp)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetCmp & VecWznmWMComponentSubset::SBSWZNMBMCOMPONENTCCP) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCmpRec::evalPnlmnoppackAvail(
			DbsWznm* dbswznm
		) {
	// cmp.inSbs(oen)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetCmp & VecWznmWMComponentSubset::SBSWZNMBMCOMPONENTOEN) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCmpRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};
