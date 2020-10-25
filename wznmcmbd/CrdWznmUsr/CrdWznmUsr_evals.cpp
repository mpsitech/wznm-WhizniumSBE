/**
	* \file CrdWznmUsr_evals.cpp
	* job handler for job CrdWznmUsr (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmUsr::evalMitCrdMkpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccUsrIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCUSR, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmUsr::evalMitCrdMkpActive(
			DbsWznm* dbswznm
		) {
	// pre.refUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

