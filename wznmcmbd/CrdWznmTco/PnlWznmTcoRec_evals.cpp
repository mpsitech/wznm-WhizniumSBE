/**
	* \file PnlWznmTcoRec_evals.cpp
	* job handler for job PnlWznmTcoRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmTcoRec::evalPnlatitleAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoRec::evalPnl1nimpexpcolAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoRec::evalPnl1nquerycolAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoRec::evalPnlref1ncontrolAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoRec::evalPnlref1nquerymodAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refTco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};
