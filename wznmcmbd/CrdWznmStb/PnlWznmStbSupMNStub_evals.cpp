/**
	* \file PnlWznmStbSupMNStub_evals.cpp
	* job handler for job PnlWznmStbSupMNStub (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmStbSupMNStub::evalButViewAvail(
			DbsWznm* dbswznm
		) {
	// !sel()|(pre.ixCrdaccStb()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
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

bool PnlWznmStbSupMNStub::evalButViewActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbSupMNStub::evalButAddAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbSupMNStub::evalButSubAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccStbIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmStbSupMNStub::evalButSubActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
