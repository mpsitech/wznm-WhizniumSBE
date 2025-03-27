/**
	* \file CrdWznmVis_evals.cpp
	* job handler for job CrdWznmVis (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Aug 2024
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmVis::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVisIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdIstAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVisIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdIstActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdCmfAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVisIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdCmfActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdWrcAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVisIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdWrcActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVis::evalMitCrdEstActive(
			DbsWznm* dbswznm
		) {
	// pre.refVis()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVIS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
