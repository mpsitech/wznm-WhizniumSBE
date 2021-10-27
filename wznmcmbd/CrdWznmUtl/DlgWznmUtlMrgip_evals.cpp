/**
	* \file DlgWznmUtlMrgip_evals.cpp
	* job handler for job DlgWznmUtlMrgip (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmUtlMrgip::evalButDneActive(
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

bool DlgWznmUtlMrgip::evalResDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUtlMrgip::evalLfiDldActive(
			DbsWznm* dbswznm
		) {
	// sge(fail)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::FAIL);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUtlMrgip::evalMrgButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(tupdone|tuldone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::TUPDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::TULDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmUtlMrgip::evalMrgButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(merge|pack)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::MERGE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::PACK);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmUtlMrgip::evalTrgUldActive(
			DbsWznm* dbswznm
		) {
	// sge(supdone|suldone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::SUPDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::SULDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmUtlMrgip::evalSrcUldActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};
