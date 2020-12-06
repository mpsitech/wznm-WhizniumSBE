/**
	* \file PnlWznmVecRec_evals.cpp
	* job handler for job PnlWznmVecRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmVecRec::evalPnlfct1ntablecolAvail(
			DbsWznm* dbswznm
		) {
	// !vec.hktEq(job)

	vector<bool> args;
	bool a;

	a = false; a = (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::JOB);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmVecRec::evalPnlpst1nquerymodAvail(
			DbsWznm* dbswznm
		) {
	// !vec.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recVec.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmVecRec::evalPnlmntableAvail(
			DbsWznm* dbswznm
		) {
	// vec.inSbs(kls)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetVec & VecWznmWMVectorSubset::SBSWZNMBMVECTORKLS) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecRec::evalButRegularizeActive(
			DbsWznm* dbswznm
		) {
	// pre.refVec()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVEC, jref) != 0);
	args.push_back(a);

	return(args.back());
};
