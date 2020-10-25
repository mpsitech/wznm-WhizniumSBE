/**
	* \file PnlWznmCmpMNLibrary_evals.cpp
	* job handler for job PnlWznmCmpMNLibrary (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmCmpMNLibrary::evalButViewAvail(
			DbsWznm* dbswznm
		) {
	// !sel()|(pre.ixCrdaccLib())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCLIB, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmCmpMNLibrary::evalButViewActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCmpMNLibrary::evalButAddAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCmpMNLibrary::evalButSubAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccCmpIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCMP, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmCmpMNLibrary::evalButSubActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

