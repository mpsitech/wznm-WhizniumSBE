/**
	* \file DlgWznmRlsFinreptr_evals.cpp
	* job handler for job DlgWznmRlsFinreptr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmRlsFinreptr::evalButDneActive(
			DbsWznm* dbswznm
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsFinreptr::evalFinButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsFinreptr::evalFinButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(finidle|pack|commit)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::FINIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::PACK);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::COMMIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmRlsFinreptr::evalResDldAvail(
			DbsWznm* dbswznm
		) {
	// !pre.ixBasereptypeEq(prjgit|custgit)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::PRJGIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) == VecWznmVBasereptype::CUSTGIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgWznmRlsFinreptr::evalResDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmRlsFinreptr::evalResTxtPrgAvail(
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

bool DlgWznmRlsFinreptr::evalResSep1Avail(
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

bool DlgWznmRlsFinreptr::evalResButPsgAvail(
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

bool DlgWznmRlsFinreptr::evalResButPsgActive(
			DbsWznm* dbswznm
		) {
	// sge(findone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FINDONE);
	args.push_back(a);

	return(args.back());
};

