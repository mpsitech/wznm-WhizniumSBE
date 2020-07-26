/**
	* \file CrdWznmVer_evals.cpp
	* job handler for job CrdWznmVer (implementation of availability/activation evaluation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWznmVer::evalMspCrd1Avail(
			DbsWznm* dbswznm
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswznm);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdNewAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdPcvAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdPcvActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMspCrd3Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIdpAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIdpActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(newcre|newimp)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::NEWCRE, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::NEWIMP, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIgbAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIgbActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsndeploy)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNDEPLOY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMspCrd4Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdWskAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdWskActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMspCrd5Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIdbAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIdbActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsndeploy|dsnglobal)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNDEPLOY, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNGLOBAL, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIbuAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIbuActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsndbstr)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNDBSTR, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIieAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit&exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIieActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsnbscui)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNBSCUI, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIopAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIopActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsnimpexp)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNIMPEXP, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIcjAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdIcjActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsnimpexp|dsnoppack)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNIMPEXP, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNOPPACK, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMspCrd6Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit|exec)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdGuiAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdGuiActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsnimpexp|dsnoppack|dsncustjob)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNIMPEXP, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNOPPACK, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNCUSTJOB, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdAuiAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdAuiActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsngenui)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNGENUI, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdGjtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdGjtActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsngenui|dsncustui)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNGENUI, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNCUSTUI, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdAjtAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdAjtActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsngenjtr)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNGENJTR, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool CrdWznmVer::evalMspCrd7Avail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdFnmAvail(
			DbsWznm* dbswznm
		) {
	// pre.ixCrdaccVerIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWznmVPreset::PREWZNMIXCRDACCVER, jref) & VecWznmWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWznmVer::evalMitCrdFnmActive(
			DbsWznm* dbswznm
		) {
	// pre.refVer()&ver.steEq(dsngenjtr|dsncustjtr)

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getRefPreset(VecWznmVPreset::PREWZNMREFVER, jref) != 0);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNGENJTR, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbswznm, VecWznmVCall::CALLWZNMVER_STEEQ, statshr.jrefRec, VecWznmVMVersionState::DSNCUSTJTR, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

