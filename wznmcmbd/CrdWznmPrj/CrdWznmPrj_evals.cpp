/**
	* \file CrdWznmPrj_evals.cpp
	* job handler for job CrdWznmPrj (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmPrj::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmPrj::evalMitCrdNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmPrj::evalMitCrdIpxAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPRJ, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};



