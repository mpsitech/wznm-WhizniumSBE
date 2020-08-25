/**
	* \file PnlWznmCmpRec_evals.cpp
	* job handler for job PnlWznmCmpRec (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

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

