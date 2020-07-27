/**
	* \file PnlWznmPnlMNQuery_evals.cpp
	* job handler for job PnlWznmPnlMNQuery (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmPnlMNQuery::evalButViewAvail(
			DbsWznm* dbswznm
		) {
	// !sel()|(pre.ixCrdaccQry()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmPnlMNQuery::evalButViewActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlMNQuery::evalButAddAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlMNQuery::evalButSubAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlMNQuery::evalButSubActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
