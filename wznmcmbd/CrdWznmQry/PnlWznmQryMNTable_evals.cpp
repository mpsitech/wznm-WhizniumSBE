/**
	* \file PnlWznmQryMNTable_evals.cpp
	* job handler for job PnlWznmQryMNTable (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmQryMNTable::evalButAddAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQryIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQryMNTable::evalButSubAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccQryIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmQryMNTable::evalButSubActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

