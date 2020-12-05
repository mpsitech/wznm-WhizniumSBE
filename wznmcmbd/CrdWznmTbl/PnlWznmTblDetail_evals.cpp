/**
	* \file PnlWznmTblDetail_evals.cpp
	* job handler for job PnlWznmTblDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmTblDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxfShoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButVerViewAvail(
			DbsWznm* dbswznm
		) {
	// tbl.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTbl.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmTblDetail::evalButVerViewActive(
			DbsWznm* dbswznm
		) {
	// !tbl.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtReuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButReuViewAvail(
			DbsWznm* dbswznm
		) {
	// tbl.reuEq(0)|((pre.ixCrdaccQry()&tbl.retEq(qry)&pre.refVer())|(pre.ixCrdaccRel()&tbl.retEq(rel)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recTbl.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQRY, jref) != 0);
	args.push_back(a);
	a = false; a = (recTbl.refIxVTbl == VecWznmVMTableRefTbl::QRY);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);
	a = false; a = (recTbl.refIxVTbl == VecWznmVMTableRefTbl::REL);
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

	return(args.back());
};

bool PnlWznmTblDetail::evalButReuViewActive(
			DbsWznm* dbswznm
		) {
	// !tbl.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtCarAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtCarActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButCarViewAvail(
			DbsWznm* dbswznm
		) {
	// tbl.carEq(0)|(pre.ixCrdaccCar()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recTbl.refWznmMCard == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
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

bool PnlWznmTblDetail::evalButCarViewActive(
			DbsWznm* dbswznm
		) {
	// !tbl.carEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMCard == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalLstUnqAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalLstUnqActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButUnqViewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTco()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTCO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButUnqViewActive(
			DbsWznm* dbswznm
		) {
	// LstUnq.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUnq != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalSepPstAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalHdgPstAvail(
			DbsWznm* dbswznm
		) {
	// tbl.inSbs(stt)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetTbl & VecWznmWMTableSubset::SBSWZNMBMTABLESTT) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButPstNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)&tbl.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmTblDetail::evalButPstDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)&!tbl.pstEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstSrfAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupPstJtiAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupPstJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButPstJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstTitAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstVerAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalTxtPstVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalButPstVerViewAvail(
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

bool PnlWznmTblDetail::evalButPstVerViewActive(
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

bool PnlWznmTblDetail::evalPupPstScoAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupPstScoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupPstAtyAvail(
			DbsWznm* dbswznm
		) {
	// !tbl.pstEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recTbl.refWznmMPreset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmTblDetail::evalPupPstAtyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTblIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};



