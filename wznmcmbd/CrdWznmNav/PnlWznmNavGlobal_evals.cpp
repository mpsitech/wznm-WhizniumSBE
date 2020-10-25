/**
	* \file PnlWznmNavGlobal_evals.cpp
	* job handler for job PnlWznmNavGlobal (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmNavGlobal::evalLstLocAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLoc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLOC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButLocViewActive(
			DbsWznm* dbswznm
		) {
	// LstLoc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLoc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalLstTagAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTag()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButTagViewActive(
			DbsWznm* dbswznm
		) {
	// LstTag.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTag != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalLstCtpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButCtpViewActive(
			DbsWznm* dbswznm
		) {
	// LstCtp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCtp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalLstMtyAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMty()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMTY, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButMtyViewActive(
			DbsWznm* dbswznm
		) {
	// LstMty.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMty != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalLstMchAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButMchViewActive(
			DbsWznm* dbswznm
		) {
	// LstMch.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMch != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalLstLibAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccLib()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmNavGlobal::evalButLibViewActive(
			DbsWznm* dbswznm
		) {
	// LstLib.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLib != 0);
	args.push_back(a);

	return(args.back());
};

