/**
	* \file DlgWznmVerDbstr_evals.cpp
	* job handler for job DlgWznmVerDbstr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmVerDbstr::evalButDneActive(
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

bool DlgWznmVerDbstr::evalLfiDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerDbstr::evalPprButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(impdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IMPDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerDbstr::evalPprButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(postprc)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::POSTPRC);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerDbstr::evalImpButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(prsdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::PRSDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerDbstr::evalImpButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(impidle|import)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IMPIDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::IMPORT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmVerDbstr::evalIfiUldActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};



