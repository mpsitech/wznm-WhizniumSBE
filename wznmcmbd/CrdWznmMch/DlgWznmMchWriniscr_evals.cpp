/**
	* \file DlgWznmMchWriniscr_evals.cpp
	* job handler for job DlgWznmMchWriniscr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmMchWriniscr::evalButDneActive(
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

bool DlgWznmMchWriniscr::evalFiaDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmMchWriniscr::evalWriButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmMchWriniscr::evalWriButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(write)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::WRITE);
	args.push_back(a);

	return(args.back());
};
