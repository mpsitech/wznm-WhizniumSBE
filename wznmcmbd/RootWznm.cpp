/**
	* \file RootWznm.cpp
	* job handler for job RootWznm (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#ifdef WZNMCMBD
	#include <Wznmcmbd.h>
#else
	#include <Wznmd.h>
#endif

#include "RootWznm.h"

#include "RootWznm_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class RootWznm
 ******************************************************************************/

RootWznm::RootWznm(
			XchgWznm* xchg
			, DbsWznm* dbswznm
			, const ubigint jrefSup
			, const bool _clearAll
		) :
			JobWznm(xchg, VecWznmVJob::ROOTWZNM, jrefSup, VecWznmVLocale::ENUS)
		{
	jref = xchg->addJob(dbswznm, this, jrefSup);

	license = NULL;

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbswznm);
	else clearQtb(dbswznm);

	license = new JobWznmLicense(xchg, dbswznm, jref, ixWznmVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWznmVCall::CALLWZNMREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWznmVCall::CALLWZNMLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	if (xchg->stgwznmbehavior.roottterm != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * xchg->stgwznmbehavior.roottterm);
};

RootWznm::~RootWznm() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void RootWznm::clearAll(
			DbsWznm* dbswznm
		) {
	WznmMUsergroup* usg = NULL;
	WznmRMUserMUsergroup* uru = NULL;
	WznmMUser* usr = NULL;
	WznmMPerson* prs = NULL;

	time_t now;

	string s;

	// empty out tables
	dbswznm->executeQuery("DELETE FROM TblWznmAccRMUserUniversal");
	dbswznm->executeQuery("DELETE FROM TblWznmAMBlockItem");
	dbswznm->executeQuery("DELETE FROM TblWznmAMCapabilityPar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMControlPar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMJobCmd");
	dbswznm->executeQuery("DELETE FROM TblWznmAMJobVar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMLibraryMakefile");
	dbswznm->executeQuery("DELETE FROM TblWznmAMLibraryPkglist");
	dbswznm->executeQuery("DELETE FROM TblWznmAMMachineMakefile");
	dbswznm->executeQuery("DELETE FROM TblWznmAMMachinePar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMMethodInvpar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMMethodRetpar");
	dbswznm->executeQuery("DELETE FROM TblWznmAMOpInvarg");
	dbswznm->executeQuery("DELETE FROM TblWznmAMOppackInvarg");
	dbswznm->executeQuery("DELETE FROM TblWznmAMOppackRetval");
	dbswznm->executeQuery("DELETE FROM TblWznmAMOpRetval");
	dbswznm->executeQuery("DELETE FROM TblWznmAMPersonDetail");
	dbswznm->executeQuery("DELETE FROM TblWznmAMQueryClause");
	dbswznm->executeQuery("DELETE FROM TblWznmAMQueryOrder");
	dbswznm->executeQuery("DELETE FROM TblWznmAMRelationTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmAMStateAction");
	dbswznm->executeQuery("DELETE FROM TblWznmAMStateTrig");
	dbswznm->executeQuery("DELETE FROM TblWznmAMSubsetTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmAMTablecolTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmAMTableLoadfct");
	dbswznm->executeQuery("DELETE FROM TblWznmAMTableTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmAMUserAccess");
	dbswznm->executeQuery("DELETE FROM TblWznmAMUsergroupAccess");
	dbswznm->executeQuery("DELETE FROM TblWznmAMVectorTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmAVControlPar");
	dbswznm->executeQuery("DELETE FROM TblWznmAVKeylistKey");
	dbswznm->executeQuery("DELETE FROM TblWznmAVValuelistVal");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMBlockItem");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMBlockItem RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMJobVar");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMJobVar RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMOpInvarg");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMOpInvarg RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMOppackInvarg");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMOppackInvarg RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMOppackRetval");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMOppackRetval RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCAMOpRetval");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCAMOpRetval RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCControl");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCControl RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCFile");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCFile RESTART WITH 1");
	if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::MY) dbswznm->executeQuery("DELETE FROM TblWznmCRelation");
	else if (dbswznm->ixDbsVDbstype == VecDbsVDbstype::PG) dbswznm->executeQuery("ALTER SEQUENCE TblWznmCRelation RESTART WITH 1");
	dbswznm->executeQuery("DELETE FROM TblWznmHistRMUserUniversal");
	dbswznm->executeQuery("DELETE FROM TblWznmJAMBlockItem");
	dbswznm->executeQuery("DELETE FROM TblWznmJAMStateTrigCond");
	dbswznm->executeQuery("DELETE FROM TblWznmJAVKeylistKey");
	dbswznm->executeQuery("DELETE FROM TblWznmJMCardTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMControl");
	dbswznm->executeQuery("DELETE FROM TblWznmJMControlTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMErrorTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMImpexpcolStub");
	dbswznm->executeQuery("DELETE FROM TblWznmJMImpexpcplxTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMLocaleTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMModule");
	dbswznm->executeQuery("DELETE FROM TblWznmJMPersonLastname");
	dbswznm->executeQuery("DELETE FROM TblWznmJMPresetTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMQuerycolStub");
	dbswznm->executeQuery("DELETE FROM TblWznmJMSquawkTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMTagTitle");
	dbswznm->executeQuery("DELETE FROM TblWznmJMUserState");
	dbswznm->executeQuery("DELETE FROM TblWznmJMVectoritem");
	dbswznm->executeQuery("DELETE FROM TblWznmJMVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmJMVersionState");
	dbswznm->executeQuery("DELETE FROM TblWznmMApp");
	dbswznm->executeQuery("DELETE FROM TblWznmMBlock");
	dbswznm->executeQuery("DELETE FROM TblWznmMBox");
	dbswznm->executeQuery("DELETE FROM TblWznmMCall");
	dbswznm->executeQuery("DELETE FROM TblWznmMCapability");
	dbswznm->executeQuery("DELETE FROM TblWznmMCard");
	dbswznm->executeQuery("DELETE FROM TblWznmMCheck");
	dbswznm->executeQuery("DELETE FROM TblWznmMComponent");
	dbswznm->executeQuery("DELETE FROM TblWznmMControl");
	dbswznm->executeQuery("DELETE FROM TblWznmMDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmMError");
	dbswznm->executeQuery("DELETE FROM TblWznmMEvent");
	dbswznm->executeQuery("DELETE FROM TblWznmMFeed");
	dbswznm->executeQuery("DELETE FROM TblWznmMFile");
	dbswznm->executeQuery("DELETE FROM TblWznmMImpexp");
	dbswznm->executeQuery("DELETE FROM TblWznmMImpexpcol");
	dbswznm->executeQuery("DELETE FROM TblWznmMImpexpcplx");
	dbswznm->executeQuery("DELETE FROM TblWznmMJob");
	dbswznm->executeQuery("DELETE FROM TblWznmMLibrary");
	dbswznm->executeQuery("DELETE FROM TblWznmMLocale");
	dbswznm->executeQuery("DELETE FROM TblWznmMMachine");
	dbswznm->executeQuery("DELETE FROM TblWznmMMethod");
	dbswznm->executeQuery("DELETE FROM TblWznmMModule");
	dbswznm->executeQuery("DELETE FROM TblWznmMOp");
	dbswznm->executeQuery("DELETE FROM TblWznmMOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmMPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmMPerson");
	dbswznm->executeQuery("DELETE FROM TblWznmMPreset");
	dbswznm->executeQuery("DELETE FROM TblWznmMProject");
	dbswznm->executeQuery("DELETE FROM TblWznmMQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmMQuerycol");
	dbswznm->executeQuery("DELETE FROM TblWznmMQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmMRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmMRelease");
	dbswznm->executeQuery("DELETE FROM TblWznmMRtblock");
	dbswznm->executeQuery("DELETE FROM TblWznmMRtdpch");
	dbswznm->executeQuery("DELETE FROM TblWznmMRtjob");
	dbswznm->executeQuery("DELETE FROM TblWznmMSensitivity");
	dbswznm->executeQuery("DELETE FROM TblWznmMSequence");
	dbswznm->executeQuery("DELETE FROM TblWznmMSession");
	dbswznm->executeQuery("DELETE FROM TblWznmMSheet");
	dbswznm->executeQuery("DELETE FROM TblWznmMSquawk");
	dbswznm->executeQuery("DELETE FROM TblWznmMStage");
	dbswznm->executeQuery("DELETE FROM TblWznmMState");
	dbswznm->executeQuery("DELETE FROM TblWznmMStub");
	dbswznm->executeQuery("DELETE FROM TblWznmMSubset");
	dbswznm->executeQuery("DELETE FROM TblWznmMTable");
	dbswznm->executeQuery("DELETE FROM TblWznmMTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmMTag");
	dbswznm->executeQuery("DELETE FROM TblWznmMUser");
	dbswznm->executeQuery("DELETE FROM TblWznmMUsergroup");
	dbswznm->executeQuery("DELETE FROM TblWznmMVector");
	dbswznm->executeQuery("DELETE FROM TblWznmMVectoritem");
	dbswznm->executeQuery("DELETE FROM TblWznmMVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmMVisual");
	dbswznm->executeQuery("DELETE FROM TblWznmRMBoxMBox");
	dbswznm->executeQuery("DELETE FROM TblWznmRMCallMStub");
	dbswznm->executeQuery("DELETE FROM TblWznmRMCapabilityUniversal");
	dbswznm->executeQuery("DELETE FROM TblWznmRMComponentMLibrary");
	dbswznm->executeQuery("DELETE FROM TblWznmRMComponentMOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmRMDialogMQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmRMJobMJob");
	dbswznm->executeQuery("DELETE FROM TblWznmRMJobMOp");
	dbswznm->executeQuery("DELETE FROM TblWznmRMJobMOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmRMLibraryMOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmRMLocaleMVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmRMPanelMQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmRMPersonMProject");
	dbswznm->executeQuery("DELETE FROM TblWznmRMQueryMTable");
	dbswznm->executeQuery("DELETE FROM TblWznmRMSquawkMStub");
	dbswznm->executeQuery("DELETE FROM TblWznmRMStubMStub");
	dbswznm->executeQuery("DELETE FROM TblWznmRMSubsetMSubset");
	dbswznm->executeQuery("DELETE FROM TblWznmRMTableMVector");
	dbswznm->executeQuery("DELETE FROM TblWznmRMUsergroupUniversal");
	dbswznm->executeQuery("DELETE FROM TblWznmRMUserMUsergroup");
	dbswznm->executeQuery("DELETE FROM TblWznmTMQuerymodMQuery");

	clearQtb(dbswznm);

	// generate a temporary user such that a session can be generated
	time(&now);

	dbswznm->tblwznmmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbswznm->tblwznmamusergroupaccess->insertNewRec(NULL, usg->ref, VecWznmVFeatgroup::VECWZNMVCARD, "CrdWznmNav", VecWznmWAccess::EDIT + VecWznmWAccess::EXEC + VecWznmWAccess::VIEW);
	dbswznm->tblwznmrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecWznmVUserlevel::GADM);
	dbswznm->tblwznmmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecWznmVMUserState::DUE, VecWznmVLocale::ENUS, VecWznmVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	usr->refJState = dbswznm->tblwznmjmuserstate->insertNewRec(NULL, usr->ref, 0, VecWznmVMUserState::DUE);
	dbswznm->tblwznmjmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, VecWznmVMUserState::EXP);
	usr->refWznmMPerson = dbswznm->tblwznmmperson->insertNewRec(&prs, usg->ref, usr->ref, VecWznmWMPersonDerivate::USR, VecWznmVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	prs->refJLastname = dbswznm->tblwznmjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbswznm->tblwznmmusergroup->updateRec(usg);

	uru->refWznmMUser = usr->ref;
	dbswznm->tblwznmrmusermusergroup->updateRec(uru);

	dbswznm->tblwznmmuser->updateRec(usr);

	dbswznm->tblwznmmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::stamp(now + 24*3600) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootWznm::clearQtb(
			DbsWznm* dbswznm
		) {
	dbswznm->executeQuery("DELETE FROM TblWznmQApp1NEvent");
	dbswznm->executeQuery("DELETE FROM TblWznmQApp1NRtjob");
	dbswznm->executeQuery("DELETE FROM TblWznmQAppApp1NSequence");
	dbswznm->executeQuery("DELETE FROM TblWznmQAppList");
	dbswznm->executeQuery("DELETE FROM TblWznmQAppRef1NFile");
	dbswznm->executeQuery("DELETE FROM TblWznmQBlk1NRtdpch");
	dbswznm->executeQuery("DELETE FROM TblWznmQBlkAItem");
	dbswznm->executeQuery("DELETE FROM TblWznmQBlkList");
	dbswznm->executeQuery("DELETE FROM TblWznmQBlkRef1NRtblock");
	dbswznm->executeQuery("DELETE FROM TblWznmQBoxDstMNBox");
	dbswznm->executeQuery("DELETE FROM TblWznmQBoxList");
	dbswznm->executeQuery("DELETE FROM TblWznmQBoxOrgMNBox");
	dbswznm->executeQuery("DELETE FROM TblWznmQCal1NSensitivity");
	dbswznm->executeQuery("DELETE FROM TblWznmQCalList");
	dbswznm->executeQuery("DELETE FROM TblWznmQCalMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQCapAPar");
	dbswznm->executeQuery("DELETE FROM TblWznmQCapList");
	dbswznm->executeQuery("DELETE FROM TblWznmQCar1NDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmQCarCar1NPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQCarHk1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQCarList");
	dbswznm->executeQuery("DELETE FROM TblWznmQChkList");
	dbswznm->executeQuery("DELETE FROM TblWznmQChkRef1NCall");
	dbswznm->executeQuery("DELETE FROM TblWznmQCmp1NRelease");
	dbswznm->executeQuery("DELETE FROM TblWznmQCmpList");
	dbswznm->executeQuery("DELETE FROM TblWznmQCmpMNLibrary");
	dbswznm->executeQuery("DELETE FROM TblWznmQCmpMNOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmQConAPar");
	dbswznm->executeQuery("DELETE FROM TblWznmQConFedRef1NRtblock");
	dbswznm->executeQuery("DELETE FROM TblWznmQConList");
	dbswznm->executeQuery("DELETE FROM TblWznmQConSup1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtp1NTag");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtpAPar");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtpKKey");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtpKParKey");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtpList");
	dbswznm->executeQuery("DELETE FROM TblWznmQCtpTpl1NCapability");
	dbswznm->executeQuery("DELETE FROM TblWznmQDlgHk1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQDlgList");
	dbswznm->executeQuery("DELETE FROM TblWznmQDlgMNQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmQDlgRef1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQErrList");
	dbswznm->executeQuery("DELETE FROM TblWznmQEvtList");
	dbswznm->executeQuery("DELETE FROM TblWznmQFilList");
	dbswznm->executeQuery("DELETE FROM TblWznmQIelList");
	dbswznm->executeQuery("DELETE FROM TblWznmQIex1NImpexp");
	dbswznm->executeQuery("DELETE FROM TblWznmQIexHk1NVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQIexList");
	dbswznm->executeQuery("DELETE FROM TblWznmQIexRef1NDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmQImeHk1NVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQImeIme1NImpexpcol");
	dbswznm->executeQuery("DELETE FROM TblWznmQImeList");
	dbswznm->executeQuery("DELETE FROM TblWznmQImeSup1NImpexp");
	dbswznm->executeQuery("DELETE FROM TblWznmQJob1NMethod");
	dbswznm->executeQuery("DELETE FROM TblWznmQJob1NRtjob");
	dbswznm->executeQuery("DELETE FROM TblWznmQJob1NSensitivity");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobACmd");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobAVar");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobHk1NVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobJob1NStage");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobList");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobMNOp");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobMNOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobRef1NBlock");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobSubMNJob");
	dbswznm->executeQuery("DELETE FROM TblWznmQJobSupMNJob");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibAMakefile");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibAPkglist");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibList");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibMNComponent");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibMNOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmQLibRef1NFile");
	dbswznm->executeQuery("DELETE FROM TblWznmQLocList");
	dbswznm->executeQuery("DELETE FROM TblWznmQLocMNVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmQMch1NRelease");
	dbswznm->executeQuery("DELETE FROM TblWznmQMchAMakefile");
	dbswznm->executeQuery("DELETE FROM TblWznmQMchAPar");
	dbswznm->executeQuery("DELETE FROM TblWznmQMchList");
	dbswznm->executeQuery("DELETE FROM TblWznmQMchSup1NMachine");
	dbswznm->executeQuery("DELETE FROM TblWznmQMdlList");
	dbswznm->executeQuery("DELETE FROM TblWznmQMdlMdl1NCard");
	dbswznm->executeQuery("DELETE FROM TblWznmQMdlRef1NPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQMtdAInvpar");
	dbswznm->executeQuery("DELETE FROM TblWznmQMtdARetpar");
	dbswznm->executeQuery("DELETE FROM TblWznmQMtdList");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpk1NOp");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkAInvarg");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkARetval");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkList");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkMNComponent");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkMNJob");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkMNLibrary");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkRef1NBlock");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpkSqkMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxAInvarg");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxARetval");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxList");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxMNJob");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxRef1NBlock");
	dbswznm->executeQuery("DELETE FROM TblWznmQOpxSqkMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQPnlHk1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQPnlList");
	dbswznm->executeQuery("DELETE FROM TblWznmQPnlMNQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmQPreselect");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrjList");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrjMNPerson");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrjPrj1NVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrsADetail");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrsList");
	dbswznm->executeQuery("DELETE FROM TblWznmQPrsMNProject");
	dbswznm->executeQuery("DELETE FROM TblWznmQPst1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQPstList");
	dbswznm->executeQuery("DELETE FROM TblWznmQQcoList");
	dbswznm->executeQuery("DELETE FROM TblWznmQQcoRef1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQQmdList");
	dbswznm->executeQuery("DELETE FROM TblWznmQQry1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryAClause");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryAOrder");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryList");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryMNDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryMNPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryMNTable");
	dbswznm->executeQuery("DELETE FROM TblWznmQQryQry1NQuerycol");
	dbswznm->executeQuery("DELETE FROM TblWznmQQrySup1NQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmQRel1NTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelATitle");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelList");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelRef1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelRef1NDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelRef1NPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQRelSup1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQRlsList");
	dbswznm->executeQuery("DELETE FROM TblWznmQRtj1NRtblock");
	dbswznm->executeQuery("DELETE FROM TblWznmQRtj1NRtdpch");
	dbswznm->executeQuery("DELETE FROM TblWznmQRtjList");
	dbswznm->executeQuery("DELETE FROM TblWznmQRtjSup1NRtjob");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbs1NStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbs1NTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsAsbMNSubset");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsATitle");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsBsbMNSubset");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsFrs1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsList");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsPst1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQSbsTos1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQSelect");
	dbswznm->executeQuery("DELETE FROM TblWznmQSeqList");
	dbswznm->executeQuery("DELETE FROM TblWznmQSeqSeq1NState");
	dbswznm->executeQuery("DELETE FROM TblWznmQSge1NSensitivity");
	dbswznm->executeQuery("DELETE FROM TblWznmQSgeList");
	dbswznm->executeQuery("DELETE FROM TblWznmQSgeSqkMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQSht1NBox");
	dbswznm->executeQuery("DELETE FROM TblWznmQShtList");
	dbswznm->executeQuery("DELETE FROM TblWznmQStbList");
	dbswznm->executeQuery("DELETE FROM TblWznmQStbMNCall");
	dbswznm->executeQuery("DELETE FROM TblWznmQStbMNSquawk");
	dbswznm->executeQuery("DELETE FROM TblWznmQStbSubMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQStbSupMNStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQSteAAction");
	dbswznm->executeQuery("DELETE FROM TblWznmQSteATrig");
	dbswznm->executeQuery("DELETE FROM TblWznmQSteList");
	dbswznm->executeQuery("DELETE FROM TblWznmQTagList");
	dbswznm->executeQuery("DELETE FROM TblWznmQTbl1NCheck");
	dbswznm->executeQuery("DELETE FROM TblWznmQTbl1NImpexp");
	dbswznm->executeQuery("DELETE FROM TblWznmQTbl1NStub");
	dbswznm->executeQuery("DELETE FROM TblWznmQTbl1NSubset");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblALoadfct");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblATitle");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblFct1NTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblFr1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblHk1NVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblList");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblMNQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblMNVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblPst1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblRef1NCall");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblRef1NDialog");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblRef1NPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblRef1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblRef1NRtblock");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblSrc1NFeed");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblTbl1NTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmQTblTo1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQTco1NCheck");
	dbswznm->executeQuery("DELETE FROM TblWznmQTco1NImpexpcol");
	dbswznm->executeQuery("DELETE FROM TblWznmQTco1NQuerycol");
	dbswznm->executeQuery("DELETE FROM TblWznmQTcoATitle");
	dbswznm->executeQuery("DELETE FROM TblWznmQTcoList");
	dbswznm->executeQuery("DELETE FROM TblWznmQTcoRef1NControl");
	dbswznm->executeQuery("DELETE FROM TblWznmQTcoRef1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsgAAccess");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsgList");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsgMNUser");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsr1NSession");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsrAAccess");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsrList");
	dbswznm->executeQuery("DELETE FROM TblWznmQUsrMNUsergroup");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecATitle");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecFct1NTablecol");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecList");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecMNTable");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecPst1NQuerymod");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecRef1NPanel");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecSrc1NFeed");
	dbswznm->executeQuery("DELETE FROM TblWznmQVecVec1NVectoritem");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NBlock");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NCall");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NCapability");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NComponent");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NImpexpcplx");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NJob");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NOppack");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NPreset");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NQuery");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NRelation");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NTable");
	dbswznm->executeQuery("DELETE FROM TblWznmQVer1NVector");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerBvr1NVersion");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerList");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerMNLocale");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerRef1NFile");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerVer1NApp");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerVer1NError");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerVer1NModule");
	dbswznm->executeQuery("DELETE FROM TblWznmQVerVer1NVisual");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisBoxctx");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisLinkctx");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisList");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisRef1NFile");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisRowctx");
	dbswznm->executeQuery("DELETE FROM TblWznmQVisVis1NSheet");
	dbswznm->executeQuery("DELETE FROM TblWznmQVitList");
};

bool RootWznm::authenticate(
			DbsWznm* dbswznm
			, const string& username
			, const string& password
			, ubigint& refWznmMUser
		) {
	bool valid = false;

	ubigint ref;

	WznmMUser* usr = NULL;

	time_t now;

	refWznmMUser = 0;

	if (dbswznm->tblwznmmuser->loadRecBySrfPwd(username, password, &usr)) {
		if ((usr->ixVState == VecWznmVMUserState::DSG) || (usr->ixVState == VecWznmVMUserState::DUE)) {
			// check if expired
			time(&now);

			if (dbswznm->loadRefBySQL("SELECT ref FROM TblWznmJMUserState WHERE refWznmMUser = " + to_string(usr->ref) + " AND x1Start < " + to_string(now) + " AND ixVState = " + to_string(VecWznmVMUserState::EXP) + " ORDER BY x1Start DESC LIMIT 1", ref)) {
				usr->refJState = ref;
				usr->ixVState = VecWznmVMUserState::EXP;
				dbswznm->tblwznmmuser->updateRec(usr);
			};
		};

		valid = ((usr->ixVState == VecWznmVMUserState::ACT) || (usr->ixVState == VecWznmVMUserState::DUE));

		if (valid) refWznmMUser = usr->ref;

		delete usr;
	};

	return valid;
};

void RootWznm::termSess(
			DbsWznm* dbswznm
			, const ubigint jref
		) {
	JobWznm* job = NULL;

	job = xchg->getJobByJref(jref);

	if (job) {
		if (job->ixWznmVJob == VecWznmVJob::SESSWZNM) ((SessWznm*) job)->term(dbswznm);
	};
};

void RootWznm::handleRequest(
			DbsWznm* dbswznm
			, ReqWznm* req
		) {
	if (req->ixVBasetype == ReqWznm::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
			cout << "\texportIni" << endl;
			cout << "\ttest" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbswznm);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbswznm);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbswznm);

		} else if (req->cmd == "exportIni") {
			req->retain = handleExportIni(dbswznm);

		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswznm);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWznmVDpch == VecWznmVDpch::DPCHAPPROOTWZNMLOGIN) {
			handleDpchAppLogin(dbswznm, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWznm::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::IDLE)) handleTimerWithSrefMonInSgeIdle(dbswznm);
		else if (req->sref == "warnterm") handleTimerWithSrefWarnterm(dbswznm);
	};
};

bool RootWznm::handleClearAll(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	clearAll(dbswznm);
	return retval;
};

bool RootWznm::handleCreateSess(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswznm, input, input2, refUsr)) {
		xchg->jrefCmd = insertSubjob(sesss, new SessWznm(xchg, dbswznm, jref, refUsr, "127.0.0.1"));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;

		if ((xchg->stgwznmbehavior.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwznmbehavior.sesstterm - xchg->stgwznmbehavior.sesstwarn));

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return retval;
};

bool RootWznm::handleEraseSess(
			DbsWznm* dbswznm
		) {
	bool retval = false;

	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	termSess(dbswznm, iinput);

	if (!eraseSubjobByJref(sesss, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tsession erased." << endl;

	return retval;
};

bool RootWznm::handleExportIni(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleExportIni --- IBEGIN

	// (re-)export initialization data
	vector<ubigint> refs;

	map<uint,uint> icsWznmVIop;

	JobWznmIexIni* iexini = NULL;
	iexini = new JobWznmIexIni(xchg, dbswznm, jref, ixWznmVLocale);

	iexini->reset(dbswznm);

	// ImeIMFile
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMFile WHERE refIxVTbl = " + to_string(VecWznmVMFileRefTbl::VOID) + " ORDER BY Filename ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimfile.nodes.push_back(new ImeitemIWznmIniMFile(dbswznm, refs[i]));

	// ImeIMUsergroup
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMUsergroup ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimusergroup.nodes.push_back(new ImeitemIWznmIniMUsergroup(dbswznm, refs[i]));

	// ImeIMLocale
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMLocale ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimlocale.nodes.push_back(new ImeitemIWznmIniMLocale(dbswznm, refs[i]));

	// ImeIMTag1
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMTag ORDER BY osrefWznmKTaggrp ASC, sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimtag1.nodes.push_back(new ImeitemIWznmIniMTag1(dbswznm, refs[i]));

	// ImeIMMachine
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMMachine ORDER BY supRefWznmMMachine ASC, sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimmachine.nodes.push_back(new ImeitemIWznmIniMMachine(dbswznm, refs[i]));

	// ImeIMLibrary
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMLibrary ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimlibrary.nodes.push_back(new ImeitemIWznmIniMLibrary(dbswznm, refs[i]));

	// ImeIMCapability
	dbswznm->loadRefsBySQL("SELECT ref FROM TblWznmMCapability WHERE tplRefWznmMCapability = 0 ORDER BY sref ASC", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) iexini->imeimcapability.nodes.push_back(new ImeitemIWznmIniMCapability(dbswznm, refs[i]));

	icsWznmVIop = IexWznmIni::icsWznmVIopInsAll();

	iexini->collect(dbswznm, icsWznmVIop);

	iexini->exportToFile(dbswznm, "./IexWznmIni_exported.txt", false);

	delete iexini;

	// IP handleExportIni --- IEND
	return retval;
};

bool RootWznm::handleTest(
			DbsWznm* dbswznm
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN

	// derive hash from list of projects
	string hash;

	ListWznmMProject prjs;
	WznmMProject* prj = NULL;

	dbswznm->tblwznmmproject->loadRstBySQL("SELECT * FROM TblWznmMProject ORDER BY Short ASC", false, prjs);

	for (unsigned int i = 0; i < prjs.nodes.size(); i++) {
		prj = prjs.nodes[i];
		hash += prj->Short + prj->Title;
	};

	cout << "project list hash: '" << hash << "'" << endl;

	// derive hash for (build-ready) versions
	//string hash;
	ubigint refWznmMProject;

	ListWznmMVersion vers;
	WznmMVersion* ver = NULL;

//	ListWznmJMVersionState verJstes;
//	WznmJMVersionState* verJste = NULL;

	ListWznmMTable tbls;
	WznmMTable* tbl = NULL;

	ListWznmMVector vecs;
	WznmMVector* vec = NULL;

	ListWznmMImpexp imes;
	WznmMImpexp* ime = NULL;

	ListWznmMPreset psts;
	WznmMPreset* pst = NULL;

	ListWznmMOp ops;
	WznmMOp* op = NULL;

	ListWznmMBlock blks;
	WznmMBlock* blk = NULL;

	ListWznmMRelease rlss;
	WznmMRelease* rls = NULL;

	for (unsigned int k = 0; k < prjs.nodes.size(); k++) {
		prj = prjs.nodes[k];

		refWznmMProject = prj->ref;

		dbswznm->tblwznmmversion->loadRstBySQL("SELECT * FROM TblWznmMVersion WHERE prjRefWznmMProject = " + to_string(refWznmMProject) + " AND ixVState = " + to_string(VecWznmVMVersionState::READY)
					+ " ORDER BY Major ASC, Minor ASC, Sub ASC", false, vers);
		for (unsigned int i = 0; i < vers.nodes.size(); i++) {
			ver = vers.nodes[i];

			hash = to_string(ver->Major) + to_string(ver->Minor) + to_string(ver->Sub);

/*
			dbswznm->tblwznmjmversionstate->loadRstByVer(ver->ref, false, verJstes);
			for (unsigned int j = 0; j < verJstes.nodes.size(); j++) {
				verJste = verJstes.nodes[j];
				hash += to_string(verJste->x1Start) + VecWznmVMVersionState::getSref(verJste->ixVState);
			};
*/

			dbswznm->tblwznmmtable->loadRstByVer(ver->ref, false, tbls);
			for (unsigned int j = 0; j < tbls.nodes.size(); j++) {
				tbl = tbls.nodes[j];
				hash += tbl->sref;
			};

			dbswznm->tblwznmmvector->loadRstByVer(ver->ref, false, vecs);
			for (unsigned int j = 0; j < vecs.nodes.size(); j++) {
				vec = vecs.nodes[j];
				hash += vec->sref;
			};

			dbswznm->tblwznmmimpexp->loadRstBySQL("SELECT TblWznmMImpexp.* FROM TblWznmMImpexpcplx, TblWznmMImpexp WHERE TblWznmMImpexp.refWznmMImpexpcplx = TblWznmMImpexpcplx.ref AND TblWznmMImpexpcplx.refWznmMVersion = "
						+ to_string(ver->ref) + " ORDER BY TblWznmMImpexp.sref ASC", false, imes);
			for (unsigned int j = 0; j < imes.nodes.size(); j++) {
				ime = imes.nodes[j];
				hash += ime->sref;
			};

			dbswznm->tblwznmmpreset->loadRstByVer(ver->ref, false, psts);
			for (unsigned int j = 0; j < psts.nodes.size(); j++) {
				pst = psts.nodes[j];
				hash += pst->sref;
			};

			dbswznm->tblwznmmop->loadRstBySQL("SELECT TblWznmMOp.* FROM TblWznmMOppack, TblWznmMOp WHERE TblWznmMOp.refWznmMOppack = TblWznmMOppack.ref AND TblWznmMOppack.refWznmMVersion = " + to_string(ver->ref)
						+ " ORDER BY TblWznmMOp.sref ASC", false, ops);
			for (unsigned int j = 0; j < ops.nodes.size(); j++) {
				op = ops.nodes[j];
				hash += op->sref;
			};

			dbswznm->tblwznmmblock->loadRstByVer(ver->ref, false, blks);
			for (unsigned int j = 0; j < blks.nodes.size(); j++) {
				blk = blks.nodes[j];
				hash += blk->sref;
			};

			dbswznm->tblwznmmrelease->loadRstBySQL("SELECT TblWznmMRelease.* FROM TblWznmMComponent, TblWznmMRelease WHERE TblWznmMRelease.refWznmMComponent = TblWznmMComponent.ref AND TblWznmMComponent.refWznmMVersion = "
						+ to_string(ver->ref) + " ORDER BY TblWznmMRelease.sref ASC", false, rlss);
			for (unsigned int j = 0; j < rlss.nodes.size(); j++) {
				rls = rlss.nodes[j];
				hash += rls->sref;
			};

			cout << "hash for build-ready version " << prj->Short << " " << to_string(ver->Major) << "." << to_string(ver->Minor) << "." << to_string(ver->Sub) << " is '" << hash << "'" << endl;
		};
	};

	unsigned char md[SHA256_DIGEST_LENGTH];
	SHA256_CTX context;

	bool success;

	success = SHA256_Init(&context);

	if (success) success = SHA256_Update(&context, (const unsigned char*) hash.c_str(), hash.length());

	if (success) success = SHA256_Final(md, &context);

	if (success) cout << "success." << endl;

	// IP handleTest --- IEND
	return retval;
};

void RootWznm::handleDpchAppLogin(
			DbsWznm* dbswznm
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngWznm** dpcheng
		) {
	ubigint refUsr;

	ubigint jrefSess;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswznm, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwznmbehavior.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					jrefSess = it->second->jref;

					if (xchg->getRefPreset(VecWznmVPreset::PREWZNMOWNER, jrefSess) == refUsr) {
						if (xchg->getBoolvalPreset(VecWznmVPreset::PREWZNMSUSPSESS, jrefSess)) {
							xchg->addTxtvalPreset(VecWznmVPreset::PREWZNMIP, jrefSess, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(jrefSess), StubWznm::getStubSesStd(dbswznm, xchg->getRefPreset(VecWznmVPreset::PREWZNMSESS, jrefSess)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				jrefSess = insertSubjob(sesss, new SessWznm(xchg, dbswznm, jref, refUsr, ip));

				if ((xchg->stgwznmbehavior.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwznmbehavior.sesstterm - xchg->stgwznmbehavior.sesstwarn));

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWznmConfirm(true, jrefSess, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngWznmConfirm(false, 0, "");
	};
};

void RootWznm::handleTimerWithSrefMonInSgeIdle(
			DbsWznm* dbswznm
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 240000000, true);
	changeStage(dbswznm, VecVSge::IDLE); // IP handleTimerWithSrefMonInSgeIdle --- ILINE
};

void RootWznm::handleTimerWithSrefWarnterm(
			DbsWznm* dbswznm
		) {
	SessWznm* sess = NULL;

	time_t tlast;
	time_t tnext = 0;

	time_t rawtime;
	time(&rawtime);

	bool term;

	if (xchg->stgwznmbehavior.sesstterm != 0) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = (SessWznm*) it->second;

			term = false;

			tlast = xchg->getRefPreset(VecWznmVPreset::PREWZNMTLAST, sess->jref);

			if ((tlast + ((int) xchg->stgwznmbehavior.sesstterm)) <= rawtime) term = true;
			else if ((tlast + ((int) xchg->stgwznmbehavior.sesstterm) - ((int) xchg->stgwznmbehavior.sesstwarn)) <= rawtime) {
				sess->warnTerm(dbswznm);
				if ((tnext == 0) || ((tlast + ((int) xchg->stgwznmbehavior.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stgwznmbehavior.sesstterm);
			} else if ((tnext == 0) || ((tlast + ((int) xchg->stgwznmbehavior.sesstterm) - ((int) xchg->stgwznmbehavior.sesstwarn)) < tnext)) tnext = tlast + xchg->stgwznmbehavior.sesstterm - xchg->stgwznmbehavior.sesstwarn;

			if (term) {
				sess->term(dbswznm);
				it = sesss.erase(it);

				delete sess;

			} else it++;
		};
	};

	term = false;

	if (xchg->stgwznmbehavior.roottterm != 0) {
		tlast = xchg->getRefPreset(VecWznmVPreset::PREWZNMTLAST, jref);

		if ((tlast + ((int) xchg->stgwznmbehavior.roottterm)) <= rawtime) term = true;
		else if ((tnext == 0) || ((tlast + ((int) xchg->stgwznmbehavior.roottterm)) < tnext)) tnext = tlast + xchg->stgwznmbehavior.roottterm;
	};

	if (term) {
		cout << endl << "\tterminating due to inactivity" << endl;
		kill(getpid(), SIGTERM);
	} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (tnext - rawtime));
};

void RootWznm::handleCall(
			DbsWznm* dbswznm
			, Call* call
		) {
	if (call->ixVCall == VecWznmVCall::CALLWZNMREFPRESET) {
		call->abort = handleCallWznmRefPreSet(dbswznm, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMSUSPSESS) {
		call->abort = handleCallWznmSuspsess(dbswznm, call->jref);
	} else if (call->ixVCall == VecWznmVCall::CALLWZNMLOGOUT) {
		call->abort = handleCallWznmLogout(dbswznm, call->jref, call->argInv.boolval);
	};
};

bool RootWznm::handleCallWznmRefPreSet(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWznmVPreset::PREWZNMTLAST) {
		xchg->addRefPreset(ixInv, jref, refInv);
	};

	return retval;
};

bool RootWznm::handleCallWznmSuspsess(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecWznmVPreset::PREWZNMSUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};

bool RootWznm::handleCallWznmLogout(
			DbsWznm* dbswznm
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	time_t rawtime;

	termSess(dbswznm, jrefTrig);

	if (!boolvalInv) {
		eraseSubjobByJref(sesss, jrefTrig);

		if (xchg->stgwznmbehavior.roottterm) {
			time(&rawtime);
			xchg->addRefPreset(VecWznmVPreset::PREWZNMTLAST, jref, rawtime);
		};
	};

	return retval;
};

void RootWznm::changeStage(
			DbsWznm* dbswznm
			, uint _ixVSge
			, DpchEngWznm** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswznm); break;
				case VecVSge::SYNC: leaveSgeSync(dbswznm); break;
			};

			setStage(dbswznm, _ixVSge);
			reenter = false;
			refreshWithDpchEng(dbswznm, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswznm, reenter); break;
			case VecVSge::SYNC: _ixVSge = enterSgeSync(dbswznm, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string RootWznm::getSquawk(
			DbsWznm* dbswznm
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::SYNC) ) {
		if (ixWznmVLocale == VecWznmVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::SYNC) retval = "synchronizing projects and versions with licensing server";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint RootWznm::enterSgeIdle(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 240000000, true);

	// IP enterSgeIdle --- IBEGIN

	// notify license server of whether there are active sessions (4 min interval)
	license->heartbeat(!sesss.empty());

	// IP enterSgeIdle --- IEND

	return retval;
};

void RootWznm::leaveSgeIdle(
			DbsWznm* dbswznm
		) {
	invalidateWakeups();
	// IP leaveSgeIdle --- INSERT
};

uint RootWznm::enterSgeSync(
			DbsWznm* dbswznm
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::IDLE;
	retval = nextIxVSgeSuccess;

	// IP enterSgeSync --- INSERT

	return retval;
};

void RootWznm::leaveSgeSync(
			DbsWznm* dbswznm
		) {
	// IP leaveSgeSync --- INSERT
};
