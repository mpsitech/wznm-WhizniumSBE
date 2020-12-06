/**
	* \file DlgWznmRlsStareptr_evals.cpp
	* job handler for job DlgWznmRlsStareptr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmRlsStareptr::evalDetButStaActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniUldAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptypeEq(uld)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::ULD);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniUldActive(
			DbsWznm* dbswznm
		) {
	// sge(stadone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::STADONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniTxtPrgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniSep1Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniButClgAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalIniButClgActive(
			DbsWznm* dbswznm
		) {
	// sge(stadone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::STADONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalExtButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(upkdone|clgdone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::CLGDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalExtButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(extract)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::EXTRACT);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalLfiDldActive(
			DbsWznm* dbswznm
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsStareptr::evalButDneActive(
			DbsWznm* dbswznm
		) {
	// sge(idle|fail|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};
