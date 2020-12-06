/**
	* \file CrdWznmMch_evals.cpp
	* job handler for job CrdWznmMch (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmMch::evalMitCrdWisAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccMchIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMCH, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmMch::evalMitCrdWisActive(
			DbsWznm* dbswznm
		) {
	// pre.refMch()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFMCH, jref) != 0);
	args.push_back(a);

	return(args.back());
};
