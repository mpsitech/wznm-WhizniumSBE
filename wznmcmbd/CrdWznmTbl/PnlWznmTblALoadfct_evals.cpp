/**
	* \file PnlWznmTblALoadfct_evals.cpp
	* job handler for job PnlWznmTblALoadfct (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmTblALoadfct::evalButNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblALoadfct::evalButDuplicateAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblALoadfct::evalButDuplicateActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblALoadfct::evalButDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblALoadfct::evalButDeleteActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
