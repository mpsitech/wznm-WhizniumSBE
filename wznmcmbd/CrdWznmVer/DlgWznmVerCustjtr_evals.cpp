/**
	* \file DlgWznmVerCustjtr_evals.cpp
	* job handler for job DlgWznmVerCustjtr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmVerCustjtr::evalButDneActive(
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

bool DlgWznmVerCustjtr::evalLfiDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerCustjtr::evalImpButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(prsdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::PRSDONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerCustjtr::evalImpButStoActive(
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

bool DlgWznmVerCustjtr::evalIfiUldActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};
