/**
	* \file DlgWznmVerGenjtr_evals.cpp
	* job handler for job DlgWznmVerGenjtr (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmVerGenjtr::evalLfiDldActive(
			DbsWznm* dbswznm
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerGenjtr::evalGjtButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmVerGenjtr::evalGjtButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(genqtb|genjob|gencall|genctp)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::GENQTB);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::GENJOB);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::GENCALL);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::GENCTP);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmVerGenjtr::evalButDneActive(
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
