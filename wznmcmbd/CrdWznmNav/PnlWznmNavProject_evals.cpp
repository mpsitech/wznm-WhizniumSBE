/**
	* \file PnlWznmNavProject_evals.cpp
	* job handler for job PnlWznmNavProject (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavProject::evalLstPrjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButPrjViewActive(
			DbsWznm* dbswznm
		) {
	// LstPrj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalLstVerAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButVerViewActive(
			DbsWznm* dbswznm
		) {
	// LstVer.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstVer != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalLstCapAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCap()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButCapViewActive(
			DbsWznm* dbswznm
		) {
	// LstCap.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCap != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButCapNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalLstErrAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccErr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCERR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButErrViewActive(
			DbsWznm* dbswznm
		) {
	// LstErr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstErr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavProject::evalButErrNewcrdActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};
