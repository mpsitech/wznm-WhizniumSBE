/**
	* \file CrdWznmRls_evals.cpp
	* job handler for job CrdWznmRls (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmRls::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdSrtAvail()|MitCrdCrtAvail()|MitCrdFrtAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdSrtAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdCrtAvail(dbswznm);
	args.push_back(a);
	a = false; a = evalMitCrdFrtAvail(dbswznm);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdSrtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdSrtActive(
			DbsWznm* dbswznm
		) {
	// !pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdCrtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdCrtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdFrtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdFrtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixBasereptype()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXBASEREPTYPE, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdWcoAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRlsIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRLS, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmRls::evalMitCrdWcoActive(
			DbsWznm* dbswznm
		) {
	// pre.refRls()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFRLS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

