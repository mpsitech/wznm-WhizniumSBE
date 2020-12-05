/**
	* \file PnlWznmNavDeploy_evals.cpp
	* job handler for job PnlWznmNavDeploy (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavDeploy::evalLstCmpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDeploy::evalButCmpViewActive(
			DbsWznm* dbswznm
		) {
	// LstCmp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCmp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDeploy::evalLstRlsAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDeploy::evalButRlsViewActive(
			DbsWznm* dbswznm
		) {
	// LstRls.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRls != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavDeploy::evalButRlsNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};



