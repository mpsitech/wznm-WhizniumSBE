/**
	* \file DlgWznmUsrMngkeypair_evals.cpp
	* job handler for job DlgWznmUsrMngkeypair (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmUsrMngkeypair::evalDetButDelAvail(
			DbsWznm* dbswznm
		) {
	// sge(found)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FOUND);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUsrMngkeypair::evalDetButGenAvail(
			DbsWznm* dbswznm
		) {
	// sge(nf)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::NF);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUsrMngkeypair::evalDetDldActive(
			DbsWznm* dbswznm
		) {
	// sge(found)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FOUND);
	args.push_back(a);

	return(args.back());
};

