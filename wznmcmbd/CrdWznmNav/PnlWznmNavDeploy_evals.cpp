/**
	* \file PnlWznmNavDeploy_evals.cpp
	* job handler for job PnlWznmNavDeploy (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

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

bool PnlWznmNavDeploy::evalButCmpNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
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

