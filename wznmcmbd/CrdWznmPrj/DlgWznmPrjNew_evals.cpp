/**
	* \file DlgWznmPrjNew_evals.cpp
	* job handler for job DlgWznmPrjNew (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmPrjNew::evalDetButAutActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)&valid()

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = valid;
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool DlgWznmPrjNew::evalButCncActive(
			DbsWznm* dbswznm
		) {
	// !sge(create)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREATE);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgWznmPrjNew::evalButCreActive(
			DbsWznm* dbswznm
		) {
	// sge(autdone)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::AUTDONE);
	args.push_back(a);

	return(args.back());
};

