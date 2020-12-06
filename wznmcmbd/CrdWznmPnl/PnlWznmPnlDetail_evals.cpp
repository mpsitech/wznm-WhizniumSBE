/**
	* \file PnlWznmPnlDetail_evals.cpp
	* job handler for job PnlWznmPnlDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmPnlDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxtCarActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalButCarViewAvail(
			DbsWznm* dbswznm
		) {
	// pnl.carEq(0)|(pre.ixCrdaccCar()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recPnl.carRefWznmMCard == 0);
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

bool PnlWznmPnlDetail::evalButCarViewActive(
			DbsWznm* dbswznm
		) {
	// !pnl.carEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPnl.carRefWznmMCard == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxtReuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalButReuViewAvail(
			DbsWznm* dbswznm
		) {
	// pnl.reuEq(0)|((pre.ixCrdaccMdl()&pnl.retEq(mdl)&pre.refVer())|(pre.ixCrdaccTbl()&pnl.retEq(tbl)&pre.refVer())|(pre.ixCrdaccRel()&pnl.retEq(rel)&pre.refVer())|(pre.ixCrdaccVec()&pnl.retEq(vec)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recPnl.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCMDL, jref) != 0);
	args.push_back(a);
	a = false; a = (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::MDL);
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
	a = false; a = (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::TBL);
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
	a = false; a = (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::REL);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (recPnl.refIxVTbl == VecWznmVMPanelRefTbl::VEC);
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

bool PnlWznmPnlDetail::evalButReuViewActive(
			DbsWznm* dbswznm
		) {
	// !pnl.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPnl.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxtJobActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalButJobViewAvail(
			DbsWznm* dbswznm
		) {
	// pnl.jobEq(0)|(pre.ixCrdaccJob()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recPnl.refWznmMJob == 0);
	args.push_back(a);
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

bool PnlWznmPnlDetail::evalButJobViewActive(
			DbsWznm* dbswznm
		) {
	// !pnl.jobEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPnl.refWznmMJob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalChkDetActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxfAvlActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPnlDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPnlIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
