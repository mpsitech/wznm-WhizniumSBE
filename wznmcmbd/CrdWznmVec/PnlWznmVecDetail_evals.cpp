/**
	* \file PnlWznmVecDetail_evals.cpp
	* job handler for job PnlWznmVecDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmVecDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButVerViewAvail(
			DbsWznm* dbswznm
		) {
	// vec.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recVec.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmVecDetail::evalButVerViewActive(
			DbsWznm* dbswznm
		) {
	// !vec.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recVec.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtHkuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButHkuViewAvail(
			DbsWznm* dbswznm
		) {
	// vec.hkuEq(0)|((pre.ixCrdaccJob()&vec.hktEq(job)&pre.refVer())|(pre.ixCrdaccTbl()&vec.hktEq(tbl)&pre.refVer())|(pre.ixCrdaccIex()&vec.hktEq(iex)&pre.refVer())|(pre.ixCrdaccIme()&vec.hktEq(ime)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recVec.hkUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCJOB, jref) != 0);
	args.push_back(a);
	a = false; a = (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::JOB);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);
	a = false; a = (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::TBL);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIEX, jref) != 0);
	args.push_back(a);
	a = false; a = (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IEX);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCIME, jref) != 0);
	args.push_back(a);
	a = false; a = (recVec.hkIxVTbl == VecWznmVMVectorHkTbl::IME);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmVecDetail::evalButHkuViewActive(
			DbsWznm* dbswznm
		) {
	// !vec.hkuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recVec.hkUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmVecDetail::evalPupTgrActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButTgrEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalLstOptActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButOptEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButPstNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)&vec.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recVec.refWznmMPreset == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmVecDetail::evalButPstDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)&!vec.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recVec.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtPstSrfAvail(
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

bool PnlWznmVecDetail::evalTxtPstSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalPupPstJtiAvail(
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

bool PnlWznmVecDetail::evalPupPstJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButPstJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtPstTitAvail(
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

bool PnlWznmVecDetail::evalTxtPstTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalTxtPstVerAvail(
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

bool PnlWznmVecDetail::evalTxtPstVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalButPstVerViewAvail(
			DbsWznm* dbswznm
		) {
	// pst.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recPst.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmVecDetail::evalButPstVerViewActive(
			DbsWznm* dbswznm
		) {
	// !pst.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPst.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmVecDetail::evalPupPstScoAvail(
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

bool PnlWznmVecDetail::evalPupPstScoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmVecDetail::evalPupPstAtyAvail(
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

bool PnlWznmVecDetail::evalPupPstAtyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVecIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

