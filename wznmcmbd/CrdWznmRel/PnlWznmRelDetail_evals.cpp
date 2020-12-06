/**
	* \file PnlWznmRelDetail_evals.cpp
	* job handler for job PnlWznmRelDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmRelDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtFrtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtFrsActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButFrsViewAvail(
			DbsWznm* dbswznm
		) {
	// rel.frsEq(0)|(pre.ixCrdaccSbs()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRel.frsRefWznmMSubset == 0);
	args.push_back(a);
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

	return(args.back());
};

bool PnlWznmRelDetail::evalButFrsViewActive(
			DbsWznm* dbswznm
		) {
	// !rel.frsEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRel.frsRefWznmMSubset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtTotActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtTosActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButTosViewAvail(
			DbsWznm* dbswznm
		) {
	// rel.tosEq(0)|(pre.ixCrdaccSbs()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRel.tosRefWznmMSubset == 0);
	args.push_back(a);
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

	return(args.back());
};

bool PnlWznmRelDetail::evalButTosViewActive(
			DbsWznm* dbswznm
		) {
	// !rel.tosEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRel.tosRefWznmMSubset == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRelDetail::evalPupTypActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalLstCluActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButCluViewActive(
			DbsWznm* dbswznm
		) {
	// LstClu.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClu != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButCluClusterAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)&rel.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recRel.refWznmCRelation == 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmRelDetail::evalButCluUnclusterAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)&!rel.cluEq(0)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (recRel.refWznmCRelation == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButVerViewAvail(
			DbsWznm* dbswznm
		) {
	// rel.verEq(0)|(pre.ixCrdaccVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRel.refWznmMVersion == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmRelDetail::evalButVerViewActive(
			DbsWznm* dbswznm
		) {
	// !rel.verEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRel.refWznmMVersion == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtSupActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButSupViewAvail(
			DbsWznm* dbswznm
		) {
	// rel.supEq(0)|(pre.ixCrdaccRel()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recRel.supRefWznmMRelation == 0);
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

bool PnlWznmRelDetail::evalButSupViewActive(
			DbsWznm* dbswznm
		) {
	// !rel.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recRel.supRefWznmMRelation == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxtTblActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalTxfPfxActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalLstOptActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccRelIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCREL, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmRelDetail::evalButOptEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.adm()

	vector<bool> args;
	bool a;

	a = false;
	args.push_back(a);

	return(args.back());
};
