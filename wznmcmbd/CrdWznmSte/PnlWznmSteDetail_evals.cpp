/**
	* \file PnlWznmSteDetail_evals.cpp
	* job handler for job PnlWznmSteDetail (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWznmSteDetail::evalButSaveAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButSaveActive(
			DbsWznm* dbswznm
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtSrfActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtSeqActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButSeqViewAvail(
			DbsWznm* dbswznm
		) {
	// ste.seqEq(0)|(pre.ixCrdaccSeq()&pre.refApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSte.seqRefWznmMSequence == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSEQ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmSteDetail::evalButSeqViewActive(
			DbsWznm* dbswznm
		) {
	// !ste.seqEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSte.seqRefWznmMSequence == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSteDetail::evalPupEacActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtErjActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButErjViewAvail(
			DbsWznm* dbswznm
		) {
	// ste.erjEq(0)|(pre.ixCrdaccRtj()&pre.refApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSte.erjRefWznmMRtjob == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCRTJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmSteDetail::evalButErjViewActive(
			DbsWznm* dbswznm
		) {
	// !ste.erjEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSte.erjRefWznmMRtjob == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtEveActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButEveViewAvail(
			DbsWznm* dbswznm
		) {
	// ste.eveEq(0)|(pre.ixCrdaccVec()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSte.eveRefWznmMVector == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVEC, jref) != 0);
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

bool PnlWznmSteDetail::evalButEveViewActive(
			DbsWznm* dbswznm
		) {
	// !ste.eveEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSte.eveRefWznmMVector == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtEviActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButEviViewAvail(
			DbsWznm* dbswznm
		) {
	// ste.eviEq(0)|(pre.ixCrdaccVit()&pre.refVer())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSte.eviRefWznmMVectoritem == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVIT, jref) != 0);
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

bool PnlWznmSteDetail::evalButEviViewActive(
			DbsWznm* dbswznm
		) {
	// !ste.eviEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSte.eviRefWznmMVectoritem == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxtEsnActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalButEsnViewAvail(
			DbsWznm* dbswznm
		) {
	// ste.esnEq(0)|(pre.ixCrdaccSte()&pre.refApp())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSte.esnRefWznmMState == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFAPP, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWznmSteDetail::evalButEsnViewActive(
			DbsWznm* dbswznm
		) {
	// !ste.esnEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSte.esnRefWznmMState == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWznmSteDetail::evalPupLacActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalChkCstActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWznmSteDetail::evalTxfCmtActive(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccSteIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCSTE, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

