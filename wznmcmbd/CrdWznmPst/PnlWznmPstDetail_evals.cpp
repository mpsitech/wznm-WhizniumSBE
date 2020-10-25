/**
	* \file PnlWznmPstDetail_evals.cpp
	* job handler for job PnlWznmPstDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmPstDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalPupJtiActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalButJtiEditAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalTxtTitActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalTxtVerActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalButVerViewAvail(
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

bool PnlWznmPstDetail::evalButVerViewActive(
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

bool PnlWznmPstDetail::evalTxtReuActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalButReuViewAvail(
			DbsWznm* dbswznm
		) {
	// pst.reuEq(0)|((pre.ixCrdaccVec()&pst.retEq(vec)&pre.refVer())|(pre.ixCrdaccSbs()&pst.retEq(sbs)&pre.refVer()))

	vector<bool> args;
	bool a, b;

	a = false; a = (recPst.refUref == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
	args.push_back(a);
	a = false; a = (recPst.refIxVTbl == VecWznmVMPresetRefTbl::VEC);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSBS, jref) != 0);
	args.push_back(a);
	a = false; a = (recPst.refIxVTbl == VecWznmVMPresetRefTbl::SBS);
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

bool PnlWznmPstDetail::evalButReuViewActive(
			DbsWznm* dbswznm
		) {
	// !pst.reuEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recPst.refUref == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmPstDetail::evalPupScoActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmPstDetail::evalPupAtyActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccPstIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCPST, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

