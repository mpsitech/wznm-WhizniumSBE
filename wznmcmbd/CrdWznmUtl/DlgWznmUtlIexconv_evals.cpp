/**
	* \file DlgWznmUtlIexconv_evals.cpp
	* job handler for job DlgWznmUtlIexconv (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWznmUtlIexconv::evalButDneActive(
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

bool DlgWznmUtlIexconv::evalResDldActive(
			DbsWznm* dbswznm
		) {
	// sge(done)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUtlIexconv::evalCnvButRunActive(
			DbsWznm* dbswznm
		) {
	// sge(ulddone|upkdone)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::ULDDONE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::UPKDONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool DlgWznmUtlIexconv::evalCnvButStoActive(
			DbsWznm* dbswznm
		) {
	// sge(conv)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CONV);
	args.push_back(a);

	return(args.back());
};

bool DlgWznmUtlIexconv::evalSrcUldActive(
			DbsWznm* dbswznm
		) {
	// sge(idle)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);

	return(args.back());
};

