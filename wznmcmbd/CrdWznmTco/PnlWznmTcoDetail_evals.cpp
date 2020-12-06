/**
	* \file PnlWznmTcoDetail_evals.cpp
	* job handler for job PnlWznmTcoDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmTcoDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxfShoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtTblActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButTblViewAvail(
			DbsWznm* dbswznm
		) {
	// tco.tblEq(0)|(pre.ixCrdaccTbl()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTco.tblRefWznmMTable == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
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

bool PnlWznmTcoDetail::evalButTblViewActive(
			DbsWznm* dbswznm
		) {
	// !tco.tblEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTco.tblRefWznmMTable == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtSbsAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtSbsActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButSbsViewAvail(
			DbsWznm* dbswznm
		) {
	// tco.sbsEq(0)|((pre.ixCrdaccSbs()&pre.refTbl())|(pre.ixCrdaccSbs()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recTco.refWznmMSubset == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFTBL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButSbsViewActive(
			DbsWznm* dbswznm
		) {
	// !tco.sbsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTco.refWznmMSubset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtRelAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtRelActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButRelViewAvail(
			DbsWznm* dbswznm
		) {
	// tco.relEq(0)|(pre.ixCrdaccRel()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTco.refWznmMRelation == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
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

bool PnlWznmTcoDetail::evalButRelViewActive(
			DbsWznm* dbswznm
		) {
	// !tco.relEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTco.refWznmMRelation == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtFcuAvail(
			DbsWznm* dbswznm
		) {
	// tco.inSbs(stc)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTco & VecWznmWMTablecolSubset::SBSWZNMBMTABLECOLSTC) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalTxtFcuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButFcuViewAvail(
			DbsWznm* dbswznm
		) {
	// tco.fcuEq(0)|(pre.ixCrdaccVec()&tco.fctEq(vec)&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTco.fctUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (recTco.fctIxVTbl == VecWznmVMTablecolFctTbl::VEC);
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

	return(args.back());
};

bool PnlWznmTcoDetail::evalButFcuViewActive(
			DbsWznm* dbswznm
		) {
	// !tco.fcuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTco.fctUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalPupStyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalPupAxfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalLstOptActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalButOptEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalChkPncActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTcoDetail::evalChkEpoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTcoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
