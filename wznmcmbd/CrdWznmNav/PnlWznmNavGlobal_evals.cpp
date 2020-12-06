/**
	* \file PnlWznmNavGlobal_evals.cpp
	* job handler for job PnlWznmNavGlobal (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

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
