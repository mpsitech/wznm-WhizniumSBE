/**
	* \file PnlWznmNavComp_evals.cpp
	* job handler for job PnlWznmNavComp (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavComp::evalLstOpkAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavComp::evalButOpkViewActive(
			DbsWznm* dbswznm
		) {
	// LstOpk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOpk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavComp::evalButOpkNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavComp::evalLstOpxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpx()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavComp::evalButOpxViewActive(
			DbsWznm* dbswznm
		) {
	// LstOpx.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOpx != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavComp::evalButOpxNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};
