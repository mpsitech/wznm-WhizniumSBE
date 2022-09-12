/**
	* \file PnlWznmConDetail_evals.cpp
	* job handler for job PnlWznmConDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmConDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalPupJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstCluActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButCluViewActive(
			DbsWznm* dbswznm
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButCluClusterAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)&con.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recCon.refWznmCControl == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmConDetail::evalButCluUnclusterAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)&!con.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recCon.refWznmCControl == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtHkuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButHkuViewAvail(
			DbsWznm* dbswznm
		) {
	// con.hkuEq(0)|((pre.ixCrdaccCar()&con.hktEq(car)&pre.refVer())|(pre.ixCrdaccDlg()&con.hktEq(dlg)&pre.refCar())|(pre.ixCrdaccDlg()&con.hktEq(dlg)&pre.refVer())|(pre.ixCrdaccPnl()&con.hktEq(pnl)&pre.refCar())|(pre.ixCrdaccPnl()&con.hktEq(pnl)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.hkUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCAR, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.hkIxVTbl == VecWznmVMControlHkTbl::CAR);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.hkIxVTbl == VecWznmVMControlHkTbl::DLG);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.hkIxVTbl == VecWznmVMControlHkTbl::DLG);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.hkIxVTbl == VecWznmVMControlHkTbl::PNL);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPNL, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.hkIxVTbl == VecWznmVMControlHkTbl::PNL);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmConDetail::evalButHkuViewActive(
			DbsWznm* dbswznm
		) {
	// !con.hkuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.hkUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtReuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButReuViewAvail(
			DbsWznm* dbswznm
		) {
	// con.reuEq(0)|((pre.ixCrdaccRel()&con.retEq(rel)&pre.refVer())|(pre.ixCrdaccQco()&con.retEq(qco)&pre.refVer())|(pre.ixCrdaccDlg()&con.retEq(dlg)&pre.refCar())|(pre.ixCrdaccDlg()&con.retEq(dlg)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.refIxVTbl == VecWznmVMControlRefTbl::REL);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCQCO, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.refIxVTbl == VecWznmVMControlRefTbl::QCO);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.refIxVTbl == VecWznmVMControlRefTbl::DLG);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCDLG, jref) != 0);
	args.push_back(a);
	a = false; a = (recCon.refIxVTbl == VecWznmVMControlRefTbl::DLG);
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

bool PnlWznmConDetail::evalButReuViewActive(
			DbsWznm* dbswznm
		) {
	// !con.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtSupActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButSupViewAvail(
			DbsWznm* dbswznm
		) {
	// con.supEq(0)|((pre.ixCrdaccCon()&pre.refPnl())|(pre.ixCrdaccCon()&pre.refDlg())|(pre.ixCrdaccCon()&pre.refCar())|(pre.ixCrdaccCon()&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.supRefWznmMControl == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFPNL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFDLG, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFCAR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) != 0);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmConDetail::evalButSupViewActive(
			DbsWznm* dbswznm
		) {
	// !con.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.supRefWznmMControl == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalPupScoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalPupStyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstTagActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButTagViewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTag()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButTagViewActive(
			DbsWznm* dbswznm
		) {
	// LstTag.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTag != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtStsActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButStsViewAvail(
			DbsWznm* dbswznm
		) {
	// con.stsEq(0)|(pre.ixCrdaccStb()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.stdRefWznmMStub == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
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

bool PnlWznmConDetail::evalButStsViewActive(
			DbsWznm* dbswznm
		) {
	// !con.stsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.stdRefWznmMStub == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtShsActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButShsViewAvail(
			DbsWznm* dbswznm
		) {
	// con.shsEq(0)|(pre.ixCrdaccStb()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recCon.shoRefWznmMStub == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTB, jref) != 0);
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

bool PnlWznmConDetail::evalButShsViewActive(
			DbsWznm* dbswznm
		) {
	// !con.shsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.shoRefWznmMStub == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxfAvlActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxfActActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstOptActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButOptEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalSepFedAvail(
			DbsWznm* dbswznm
		) {
	// con.inSbs(cfb)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetCon & VecWznmWMControlSubset::SBSWZNMBMCONTROLCFB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalHdgFedAvail(
			DbsWznm* dbswznm
		) {
	// con.inSbs(cfb)

	vector<bool> args;
	bool a;

	a = false; a = ((ixWSubsetCon & VecWznmWMControlSubset::SBSWZNMBMCONTROLCFB) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)&con.fedEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedDeleteAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)&!con.fedEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtFedSrfAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtFedSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtFedSruAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxtFedSruActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedSruViewAvail(
			DbsWznm* dbswznm
		) {
	// fed.sruEq(0)|((pre.ixCrdaccTbl()&fed.srtEq(tbl)&pre.refVer())|(pre.ixCrdaccVec()&fed.srtEq(vec)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recFed.srcUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTBL, jref) != 0);
	args.push_back(a);
	a = false; a = (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::TBL);
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
	a = false; a = (recFed.srcIxVTbl == VecWznmVMFeedSrcTbl::VEC);
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

bool PnlWznmConDetail::evalButFedSruViewActive(
			DbsWznm* dbswznm
		) {
	// !fed.sruEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recFed.srcUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstFedVitAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstFedVitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedVitViewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVit()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedVitViewActive(
			DbsWznm* dbswznm
		) {
	// LstFedVit.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFedVit != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstFedTagAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalLstFedTagActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedTagViewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccTag()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCTAG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalButFedTagViewActive(
			DbsWznm* dbswznm
		) {
	// LstFedTag.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFedTag != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxfFedCmtAvail(
			DbsWznm* dbswznm
		) {
	// !con.fedEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recCon.refWznmMFeed == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmConDetail::evalTxfFedCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccConIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCCON, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};
