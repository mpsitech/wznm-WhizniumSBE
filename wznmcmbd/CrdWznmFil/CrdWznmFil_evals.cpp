/**
	* \file CrdWznmFil_evals.cpp
	* job handler for job CrdWznmFil (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmFil::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmFil::evalMitCrdNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccFilIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmFil::evalMitCrdDldAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccFilIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCFIL, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmFil::evalMitCrdDldActive(
			DbsWznm* dbswznm
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};
