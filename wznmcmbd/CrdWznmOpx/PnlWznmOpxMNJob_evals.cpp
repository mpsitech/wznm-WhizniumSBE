/**
	* \file PnlWznmOpxMNJob_evals.cpp
	* job handler for job PnlWznmOpxMNJob (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmOpxMNJob::evalButViewAvail(
			DbsWznm* dbswznm
		) {
	// !sel()|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
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

bool PnlWznmOpxMNJob::evalButViewActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmOpxMNJob::evalButAddAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmOpxMNJob::evalButSubAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccOpxIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCOPX, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmOpxMNJob::evalButSubActive(
			DbsWznm* dbswznm
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
