/**
	* \file DbsWznm.h
	* C++ wrapper for database DbsWznm (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef DBSWZNM_H
#define DBSWZNM_H

#define WZNM_VERSION "1.1.9"
#define WZNM_VERSION_MAJOR 1
#define WZNM_VERSION_MINOR 1
#define WZNM_VERSION_SUB 9

#include <sbecore/Types.h>

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	#include <sbecore/MyDbs.h>
#endif
#if defined(SBECORE_PG)
	#include <sbecore/PgDbs.h>
#endif

#include "WznmAccRMUserUniversal.h"
#include "WznmAMBlockItem.h"
#include "WznmAMCapabilityPar.h"
#include "WznmAMControlPar.h"
#include "WznmAMJobCmd.h"
#include "WznmAMJobVar.h"
#include "WznmAMLibraryMakefile.h"
#include "WznmAMLibraryPkglist.h"
#include "WznmAMMachineMakefile.h"
#include "WznmAMMachinePar.h"
#include "WznmAMMethodInvpar.h"
#include "WznmAMMethodRetpar.h"
#include "WznmAMOpInvarg.h"
#include "WznmAMOppackInvarg.h"
#include "WznmAMOppackRetval.h"
#include "WznmAMOpRetval.h"
#include "WznmAMPersonDetail.h"
#include "WznmAMQueryClause.h"
#include "WznmAMQueryOrder.h"
#include "WznmAMRelationTitle.h"
#include "WznmAMStateAction.h"
#include "WznmAMStateTrig.h"
#include "WznmAMSubsetTitle.h"
#include "WznmAMTablecolTitle.h"
#include "WznmAMTableLoadfct.h"
#include "WznmAMTableTitle.h"
#include "WznmAMUserAccess.h"
#include "WznmAMUsergroupAccess.h"
#include "WznmAMVectorTitle.h"
#include "WznmAVControlPar.h"
#include "WznmAVKeylistKey.h"
#include "WznmAVValuelistVal.h"
#include "WznmCAMBlockItem.h"
#include "WznmCAMJobVar.h"
#include "WznmCAMOpInvarg.h"
#include "WznmCAMOppackInvarg.h"
#include "WznmCAMOppackRetval.h"
#include "WznmCAMOpRetval.h"
#include "WznmCControl.h"
#include "WznmCFile.h"
#include "WznmCRelation.h"
#include "WznmHistRMUserUniversal.h"
#include "WznmJAMBlockItem.h"
#include "WznmJAMStateTrigCond.h"
#include "WznmJAVKeylistKey.h"
#include "WznmJMCardTitle.h"
#include "WznmJMControl.h"
#include "WznmJMControlTitle.h"
#include "WznmJMErrorTitle.h"
#include "WznmJMImpexpcolStub.h"
#include "WznmJMImpexpcplxTitle.h"
#include "WznmJMLocaleTitle.h"
#include "WznmJMModule.h"
#include "WznmJMPersonLastname.h"
#include "WznmJMPresetTitle.h"
#include "WznmJMQuerycolStub.h"
#include "WznmJMSquawkTitle.h"
#include "WznmJMTagTitle.h"
#include "WznmJMUserState.h"
#include "WznmJMVectoritem.h"
#include "WznmJMVersion.h"
#include "WznmJMVersionState.h"
#include "WznmMApp.h"
#include "WznmMBlock.h"
#include "WznmMCall.h"
#include "WznmMCapability.h"
#include "WznmMCard.h"
#include "WznmMCheck.h"
#include "WznmMComponent.h"
#include "WznmMControl.h"
#include "WznmMDialog.h"
#include "WznmMError.h"
#include "WznmMEvent.h"
#include "WznmMFeed.h"
#include "WznmMFile.h"
#include "WznmMImpexp.h"
#include "WznmMImpexpcol.h"
#include "WznmMImpexpcplx.h"
#include "WznmMJob.h"
#include "WznmMLibrary.h"
#include "WznmMLocale.h"
#include "WznmMMachine.h"
#include "WznmMMethod.h"
#include "WznmMModule.h"
#include "WznmMOp.h"
#include "WznmMOppack.h"
#include "WznmMPanel.h"
#include "WznmMPerson.h"
#include "WznmMPreset.h"
#include "WznmMProject.h"
#include "WznmMQuery.h"
#include "WznmMQuerycol.h"
#include "WznmMQuerymod.h"
#include "WznmMRelation.h"
#include "WznmMRelease.h"
#include "WznmMRtblock.h"
#include "WznmMRtdpch.h"
#include "WznmMRtjob.h"
#include "WznmMSensitivity.h"
#include "WznmMSequence.h"
#include "WznmMSession.h"
#include "WznmMSquawk.h"
#include "WznmMStage.h"
#include "WznmMState.h"
#include "WznmMStub.h"
#include "WznmMSubset.h"
#include "WznmMTable.h"
#include "WznmMTablecol.h"
#include "WznmMTag.h"
#include "WznmMUser.h"
#include "WznmMUsergroup.h"
#include "WznmMVector.h"
#include "WznmMVectoritem.h"
#include "WznmMVersion.h"
#include "WznmRMCallMStub.h"
#include "WznmRMCapabilityUniversal.h"
#include "WznmRMComponentMLibrary.h"
#include "WznmRMComponentMOppack.h"
#include "WznmRMDialogMQuery.h"
#include "WznmRMJobMJob.h"
#include "WznmRMJobMOp.h"
#include "WznmRMJobMOppack.h"
#include "WznmRMLibraryMOppack.h"
#include "WznmRMLocaleMVersion.h"
#include "WznmRMPanelMQuery.h"
#include "WznmRMPersonMProject.h"
#include "WznmRMQueryMTable.h"
#include "WznmRMSquawkMStub.h"
#include "WznmRMStubMStub.h"
#include "WznmRMSubsetMSubset.h"
#include "WznmRMTableMVector.h"
#include "WznmRMUsergroupUniversal.h"
#include "WznmRMUserMUsergroup.h"
#include "WznmTMQuerymodMQuery.h"

#include "WznmQApp1NEvent.h"
#include "WznmQApp1NRtjob.h"
#include "WznmQAppApp1NSequence.h"
#include "WznmQAppList.h"
#include "WznmQAppRef1NFile.h"
#include "WznmQBlk1NRtdpch.h"
#include "WznmQBlkAItem.h"
#include "WznmQBlkList.h"
#include "WznmQBlkRef1NRtblock.h"
#include "WznmQCal1NSensitivity.h"
#include "WznmQCalList.h"
#include "WznmQCalMNStub.h"
#include "WznmQCapAPar.h"
#include "WznmQCapList.h"
#include "WznmQCar1NDialog.h"
#include "WznmQCarCar1NPanel.h"
#include "WznmQCarHk1NControl.h"
#include "WznmQCarList.h"
#include "WznmQChkList.h"
#include "WznmQChkRef1NCall.h"
#include "WznmQCmp1NRelease.h"
#include "WznmQCmpList.h"
#include "WznmQCmpMNLibrary.h"
#include "WznmQCmpMNOppack.h"
#include "WznmQConAPar.h"
#include "WznmQConFedRef1NRtblock.h"
#include "WznmQConList.h"
#include "WznmQConSup1NControl.h"
#include "WznmQCtp1NTag.h"
#include "WznmQCtpAPar.h"
#include "WznmQCtpKKey.h"
#include "WznmQCtpKParKey.h"
#include "WznmQCtpList.h"
#include "WznmQCtpTpl1NCapability.h"
#include "WznmQDlgHk1NControl.h"
#include "WznmQDlgList.h"
#include "WznmQDlgMNQuery.h"
#include "WznmQDlgRef1NControl.h"
#include "WznmQErrList.h"
#include "WznmQEvtList.h"
#include "WznmQFilList.h"
#include "WznmQIelList.h"
#include "WznmQIex1NImpexp.h"
#include "WznmQIexHk1NVector.h"
#include "WznmQIexList.h"
#include "WznmQIexRef1NDialog.h"
#include "WznmQImeHk1NVector.h"
#include "WznmQImeIme1NImpexpcol.h"
#include "WznmQImeList.h"
#include "WznmQImeSup1NImpexp.h"
#include "WznmQJob1NMethod.h"
#include "WznmQJob1NRtjob.h"
#include "WznmQJob1NSensitivity.h"
#include "WznmQJobACmd.h"
#include "WznmQJobAVar.h"
#include "WznmQJobHk1NVector.h"
#include "WznmQJobJob1NStage.h"
#include "WznmQJobList.h"
#include "WznmQJobMNOp.h"
#include "WznmQJobMNOppack.h"
#include "WznmQJobRef1NBlock.h"
#include "WznmQJobSubMNJob.h"
#include "WznmQJobSupMNJob.h"
#include "WznmQLibAMakefile.h"
#include "WznmQLibAPkglist.h"
#include "WznmQLibList.h"
#include "WznmQLibMNComponent.h"
#include "WznmQLibMNOppack.h"
#include "WznmQLibRef1NFile.h"
#include "WznmQLocList.h"
#include "WznmQLocMNVersion.h"
#include "WznmQMch1NRelease.h"
#include "WznmQMchAMakefile.h"
#include "WznmQMchAPar.h"
#include "WznmQMchList.h"
#include "WznmQMchSup1NMachine.h"
#include "WznmQMdlList.h"
#include "WznmQMdlMdl1NCard.h"
#include "WznmQMdlRef1NPanel.h"
#include "WznmQMtdAInvpar.h"
#include "WznmQMtdARetpar.h"
#include "WznmQMtdList.h"
#include "WznmQOpk1NOp.h"
#include "WznmQOpkAInvarg.h"
#include "WznmQOpkARetval.h"
#include "WznmQOpkList.h"
#include "WznmQOpkMNComponent.h"
#include "WznmQOpkMNJob.h"
#include "WznmQOpkMNLibrary.h"
#include "WznmQOpkRef1NBlock.h"
#include "WznmQOpkSqkMNStub.h"
#include "WznmQOpxAInvarg.h"
#include "WznmQOpxARetval.h"
#include "WznmQOpxList.h"
#include "WznmQOpxMNJob.h"
#include "WznmQOpxRef1NBlock.h"
#include "WznmQOpxSqkMNStub.h"
#include "WznmQPnlHk1NControl.h"
#include "WznmQPnlList.h"
#include "WznmQPnlMNQuery.h"
#include "WznmQPreselect.h"
#include "WznmQPrjList.h"
#include "WznmQPrjMNPerson.h"
#include "WznmQPrjPrj1NVersion.h"
#include "WznmQPrsADetail.h"
#include "WznmQPrsList.h"
#include "WznmQPrsMNProject.h"
#include "WznmQPst1NQuerymod.h"
#include "WznmQPstList.h"
#include "WznmQQcoList.h"
#include "WznmQQcoRef1NControl.h"
#include "WznmQQmdList.h"
#include "WznmQQry1NQuerymod.h"
#include "WznmQQryAClause.h"
#include "WznmQQryAOrder.h"
#include "WznmQQryList.h"
#include "WznmQQryMNDialog.h"
#include "WznmQQryMNPanel.h"
#include "WznmQQryMNTable.h"
#include "WznmQQryQry1NQuerycol.h"
#include "WznmQQrySup1NQuery.h"
#include "WznmQRel1NTablecol.h"
#include "WznmQRelATitle.h"
#include "WznmQRelList.h"
#include "WznmQRelRef1NControl.h"
#include "WznmQRelRef1NDialog.h"
#include "WznmQRelRef1NPanel.h"
#include "WznmQRelSup1NRelation.h"
#include "WznmQRlsList.h"
#include "WznmQRtj1NRtblock.h"
#include "WznmQRtj1NRtdpch.h"
#include "WznmQRtjList.h"
#include "WznmQRtjSup1NRtjob.h"
#include "WznmQSbs1NStub.h"
#include "WznmQSbs1NTablecol.h"
#include "WznmQSbsAsbMNSubset.h"
#include "WznmQSbsATitle.h"
#include "WznmQSbsBsbMNSubset.h"
#include "WznmQSbsFrs1NRelation.h"
#include "WznmQSbsList.h"
#include "WznmQSbsPst1NQuerymod.h"
#include "WznmQSbsTos1NRelation.h"
#include "WznmQSelect.h"
#include "WznmQSeqList.h"
#include "WznmQSeqSeq1NState.h"
#include "WznmQSge1NSensitivity.h"
#include "WznmQSgeList.h"
#include "WznmQSgeSqkMNStub.h"
#include "WznmQStbList.h"
#include "WznmQStbMNCall.h"
#include "WznmQStbMNSquawk.h"
#include "WznmQStbSubMNStub.h"
#include "WznmQStbSupMNStub.h"
#include "WznmQSteAAction.h"
#include "WznmQSteATrig.h"
#include "WznmQSteList.h"
#include "WznmQTagList.h"
#include "WznmQTbl1NCheck.h"
#include "WznmQTbl1NImpexp.h"
#include "WznmQTbl1NStub.h"
#include "WznmQTbl1NSubset.h"
#include "WznmQTblALoadfct.h"
#include "WznmQTblATitle.h"
#include "WznmQTblFct1NTablecol.h"
#include "WznmQTblFr1NRelation.h"
#include "WznmQTblHk1NVector.h"
#include "WznmQTblList.h"
#include "WznmQTblMNQuery.h"
#include "WznmQTblMNVector.h"
#include "WznmQTblPst1NQuerymod.h"
#include "WznmQTblRef1NCall.h"
#include "WznmQTblRef1NDialog.h"
#include "WznmQTblRef1NPanel.h"
#include "WznmQTblRef1NQuerymod.h"
#include "WznmQTblRef1NRtblock.h"
#include "WznmQTblSrc1NFeed.h"
#include "WznmQTblTbl1NTablecol.h"
#include "WznmQTblTo1NRelation.h"
#include "WznmQTco1NCheck.h"
#include "WznmQTco1NImpexpcol.h"
#include "WznmQTco1NQuerycol.h"
#include "WznmQTcoATitle.h"
#include "WznmQTcoList.h"
#include "WznmQTcoRef1NControl.h"
#include "WznmQTcoRef1NQuerymod.h"
#include "WznmQUsgAAccess.h"
#include "WznmQUsgList.h"
#include "WznmQUsgMNUser.h"
#include "WznmQUsr1NSession.h"
#include "WznmQUsrAAccess.h"
#include "WznmQUsrList.h"
#include "WznmQUsrMNUsergroup.h"
#include "WznmQVecATitle.h"
#include "WznmQVecFct1NTablecol.h"
#include "WznmQVecList.h"
#include "WznmQVecMNTable.h"
#include "WznmQVecPst1NQuerymod.h"
#include "WznmQVecRef1NPanel.h"
#include "WznmQVecSrc1NFeed.h"
#include "WznmQVecVec1NVectoritem.h"
#include "WznmQVer1NBlock.h"
#include "WznmQVer1NCall.h"
#include "WznmQVer1NCapability.h"
#include "WznmQVer1NComponent.h"
#include "WznmQVer1NImpexpcplx.h"
#include "WznmQVer1NJob.h"
#include "WznmQVer1NOppack.h"
#include "WznmQVer1NPreset.h"
#include "WznmQVer1NQuery.h"
#include "WznmQVer1NRelation.h"
#include "WznmQVer1NTable.h"
#include "WznmQVer1NVector.h"
#include "WznmQVerBvr1NVersion.h"
#include "WznmQVerList.h"
#include "WznmQVerMNLocale.h"
#include "WznmQVerRef1NFile.h"
#include "WznmQVerVer1NApp.h"
#include "WznmQVerVer1NError.h"
#include "WznmQVerVer1NModule.h"
#include "WznmQVitList.h"

#define VecWznmVApptarget DbsWznm::VecVApptarget
#define VecWznmVCard DbsWznm::VecVCard
#define VecWznmVControl DbsWznm::VecVControl
#define VecWznmVFeatgroup DbsWznm::VecVFeatgroup
#define VecWznmVGender DbsWznm::VecVGender
#define VecWznmVKeylist DbsWznm::VecVKeylist
#define VecWznmVLat DbsWznm::VecVLat
#define VecWznmVLocale DbsWznm::VecVLocale
#define VecWznmVLop DbsWznm::VecVLop
#define VecWznmVMaintable DbsWznm::VecVMaintable
#define VecWznmVOolop DbsWznm::VecVOolop
#define VecWznmVPreset DbsWznm::VecVPreset
#define VecWznmVRecaccess DbsWznm::VecVRecaccess
#define VecWznmVUserlevel DbsWznm::VecVUserlevel
#define VecWznmVValuelist DbsWznm::VecVValuelist
#define VecWznmVVartype DbsWznm::VecVVartype
#define VecWznmWAccess DbsWznm::VecWAccess
#define VecWznmWArgtype DbsWznm::VecWArgtype
#define VecWznmWScope DbsWznm::VecWScope

/**
	* DbsWznm
	*/
class DbsWznm {

public:
	/**
		* VecVApptarget (full: VecWznmVApptarget)
		*/
	class VecVApptarget {

	public:
		static const Sbecore::uint COCOA_SWIFT = 1;
		static const Sbecore::uint DOTNET_CS = 2;
		static const Sbecore::uint JAVA = 3;
		static const Sbecore::uint POSIX_CPP = 4;
		static const Sbecore::uint PY = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVCard (full: VecWznmVCard)
		*/
	class VecVCard {

	public:
		static const Sbecore::uint CRDWZNMNAV = 1;
		static const Sbecore::uint CRDWZNMUSG = 2;
		static const Sbecore::uint CRDWZNMUSR = 3;
		static const Sbecore::uint CRDWZNMPRS = 4;
		static const Sbecore::uint CRDWZNMFIL = 5;
		static const Sbecore::uint CRDWZNMLOC = 6;
		static const Sbecore::uint CRDWZNMTAG = 7;
		static const Sbecore::uint CRDWZNMCTP = 8;
		static const Sbecore::uint CRDWZNMMCH = 9;
		static const Sbecore::uint CRDWZNMLIB = 10;
		static const Sbecore::uint CRDWZNMPRJ = 11;
		static const Sbecore::uint CRDWZNMVER = 12;
		static const Sbecore::uint CRDWZNMCAP = 13;
		static const Sbecore::uint CRDWZNMERR = 14;
		static const Sbecore::uint CRDWZNMTBL = 15;
		static const Sbecore::uint CRDWZNMTCO = 16;
		static const Sbecore::uint CRDWZNMSBS = 17;
		static const Sbecore::uint CRDWZNMREL = 18;
		static const Sbecore::uint CRDWZNMVEC = 19;
		static const Sbecore::uint CRDWZNMVIT = 20;
		static const Sbecore::uint CRDWZNMCHK = 21;
		static const Sbecore::uint CRDWZNMSTB = 22;
		static const Sbecore::uint CRDWZNMIEX = 23;
		static const Sbecore::uint CRDWZNMIME = 24;
		static const Sbecore::uint CRDWZNMIEL = 25;
		static const Sbecore::uint CRDWZNMPST = 26;
		static const Sbecore::uint CRDWZNMMDL = 27;
		static const Sbecore::uint CRDWZNMCAR = 28;
		static const Sbecore::uint CRDWZNMDLG = 29;
		static const Sbecore::uint CRDWZNMPNL = 30;
		static const Sbecore::uint CRDWZNMQRY = 31;
		static const Sbecore::uint CRDWZNMQCO = 32;
		static const Sbecore::uint CRDWZNMQMD = 33;
		static const Sbecore::uint CRDWZNMCON = 34;
		static const Sbecore::uint CRDWZNMOPK = 35;
		static const Sbecore::uint CRDWZNMOPX = 36;
		static const Sbecore::uint CRDWZNMJOB = 37;
		static const Sbecore::uint CRDWZNMSGE = 38;
		static const Sbecore::uint CRDWZNMMTD = 39;
		static const Sbecore::uint CRDWZNMBLK = 40;
		static const Sbecore::uint CRDWZNMCAL = 41;
		static const Sbecore::uint CRDWZNMCMP = 42;
		static const Sbecore::uint CRDWZNMRLS = 43;
		static const Sbecore::uint CRDWZNMAPP = 44;
		static const Sbecore::uint CRDWZNMRTJ = 45;
		static const Sbecore::uint CRDWZNMEVT = 46;
		static const Sbecore::uint CRDWZNMSEQ = 47;
		static const Sbecore::uint CRDWZNMSTE = 48;
		static const Sbecore::uint CRDWZNMUTL = 49;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVControl (full: VecWznmVControl)
		*/
	class VecVControl {

	public:
		static const Sbecore::uint PNLWZNMUSGLIST_TCOGRP = 1;
		static const Sbecore::uint PNLWZNMUSGLIST_TCOOWN = 2;
		static const Sbecore::uint PNLWZNMUSGLIST_TCOSRF = 3;
		static const Sbecore::uint PNLWZNMUSGAACCESS_TCOFEG = 4;
		static const Sbecore::uint PNLWZNMUSGAACCESS_TCOFEA = 5;
		static const Sbecore::uint PNLWZNMUSGAACCESS_TCOACC = 6;
		static const Sbecore::uint PNLWZNMUSGMNUSER_TCOMREF = 7;
		static const Sbecore::uint PNLWZNMUSGMNUSER_TCOULV = 8;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOGRP = 9;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOOWN = 10;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOPRS = 11;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOSRF = 12;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOUSG = 13;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOSTE = 14;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOLCL = 15;
		static const Sbecore::uint PNLWZNMUSRLIST_TCOULV = 16;
		static const Sbecore::uint PNLWZNMUSRAACCESS_TCOFEG = 17;
		static const Sbecore::uint PNLWZNMUSRAACCESS_TCOFEA = 18;
		static const Sbecore::uint PNLWZNMUSRAACCESS_TCOACC = 19;
		static const Sbecore::uint PNLWZNMUSR1NSESSION_TCOREF = 20;
		static const Sbecore::uint PNLWZNMUSRMNUSERGROUP_TCOMREF = 21;
		static const Sbecore::uint PNLWZNMUSRMNUSERGROUP_TCOULV = 22;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOGRP = 23;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOOWN = 24;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOTIT = 25;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOFNM = 26;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOLNM = 27;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOSEX = 28;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOTEL = 29;
		static const Sbecore::uint PNLWZNMPRSLIST_TCOEML = 30;
		static const Sbecore::uint PNLWZNMPRSADETAIL_TCOTYP = 31;
		static const Sbecore::uint PNLWZNMPRSADETAIL_TCOVAL = 32;
		static const Sbecore::uint PNLWZNMPRSMNPROJECT_TCOMREF = 33;
		static const Sbecore::uint PNLWZNMPRSMNPROJECT_TCOSTA = 34;
		static const Sbecore::uint PNLWZNMPRSMNPROJECT_TCOSTO = 35;
		static const Sbecore::uint PNLWZNMPRSMNPROJECT_TCOFCT = 36;
		static const Sbecore::uint PNLWZNMFILLIST_TCOGRP = 37;
		static const Sbecore::uint PNLWZNMFILLIST_TCOOWN = 38;
		static const Sbecore::uint PNLWZNMFILLIST_TCOFNM = 39;
		static const Sbecore::uint PNLWZNMFILLIST_TCORET = 40;
		static const Sbecore::uint PNLWZNMFILLIST_TCOREU = 41;
		static const Sbecore::uint PNLWZNMFILLIST_TCOCNT = 42;
		static const Sbecore::uint PNLWZNMFILLIST_TCOMIM = 43;
		static const Sbecore::uint PNLWZNMFILLIST_TCOSIZ = 44;
		static const Sbecore::uint PNLWZNMLOCLIST_TCOSRF = 45;
		static const Sbecore::uint PNLWZNMLOCLIST_TCOTIT = 46;
		static const Sbecore::uint PNLWZNMLOCMNVERSION_TCOMREF = 47;
		static const Sbecore::uint PNLWZNMTAGLIST_TCOSRF = 48;
		static const Sbecore::uint PNLWZNMTAGLIST_TCOTIT = 49;
		static const Sbecore::uint PNLWZNMTAGLIST_TCOCPB = 50;
		static const Sbecore::uint PNLWZNMTAGLIST_TCOGRP = 51;
		static const Sbecore::uint PNLWZNMCTPLIST_TCOSRF = 52;
		static const Sbecore::uint PNLWZNMCTPLIST_TCOTIT = 53;
		static const Sbecore::uint PNLWZNMCTPLIST_TCOVER = 54;
		static const Sbecore::uint PNLWZNMCTPLIST_TCOATF = 55;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOFIX = 56;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOSRF = 57;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOAVL = 58;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOIMP = 59;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOTIT = 60;
		static const Sbecore::uint PNLWZNMCTPKPARKEY_TCOCMT = 61;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOFIX = 62;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOSRF = 63;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOAVL = 64;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOIMP = 65;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOTIT = 66;
		static const Sbecore::uint PNLWZNMCTPKKEY_TCOCMT = 67;
		static const Sbecore::uint PNLWZNMCTPAPAR_TCOKEY = 68;
		static const Sbecore::uint PNLWZNMCTPAPAR_TCOVAL = 69;
		static const Sbecore::uint PNLWZNMCTPTPL1NCAPABILITY_TCOREF = 70;
		static const Sbecore::uint PNLWZNMCTP1NTAG_TCOREF = 71;
		static const Sbecore::uint PNLWZNMMCHLIST_TCOSRF = 72;
		static const Sbecore::uint PNLWZNMMCHLIST_TCOSUP = 73;
		static const Sbecore::uint PNLWZNMMCHAMAKEFILE_TCOTAG = 74;
		static const Sbecore::uint PNLWZNMMCHAMAKEFILE_TCOVAL = 75;
		static const Sbecore::uint PNLWZNMMCHAPAR_TCOKEY = 76;
		static const Sbecore::uint PNLWZNMMCHAPAR_TCOVAL = 77;
		static const Sbecore::uint PNLWZNMMCH1NRELEASE_TCOREF = 78;
		static const Sbecore::uint PNLWZNMMCHSUP1NMACHINE_TCOREF = 79;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOSRF = 80;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOTIT = 81;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOVER = 82;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOLTY = 83;
		static const Sbecore::uint PNLWZNMLIBAPKGLIST_TCOMCH = 84;
		static const Sbecore::uint PNLWZNMLIBAPKGLIST_TCOPKL = 85;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOMCH = 86;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOTAG = 87;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOVAL = 88;
		static const Sbecore::uint PNLWZNMLIBREF1NFILE_TCOREF = 89;
		static const Sbecore::uint PNLWZNMLIBMNOPPACK_TCOMREF = 90;
		static const Sbecore::uint PNLWZNMLIBMNCOMPONENT_TCOMREF = 91;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOGRP = 92;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOOWN = 93;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOSHO = 94;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOTIT = 95;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOVER = 96;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOGRL = 97;
		static const Sbecore::uint PNLWZNMPRJPRJ1NVERSION_TCOREF = 98;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOMREF = 99;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOSTA = 100;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOSTO = 101;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOFCT = 102;
		static const Sbecore::uint PNLWZNMVERLIST_TCOGRP = 103;
		static const Sbecore::uint PNLWZNMVERLIST_TCOOWN = 104;
		static const Sbecore::uint PNLWZNMVERLIST_TCOPRJ = 105;
		static const Sbecore::uint PNLWZNMVERLIST_TCOMAJ = 106;
		static const Sbecore::uint PNLWZNMVERLIST_TCOMIN = 107;
		static const Sbecore::uint PNLWZNMVERLIST_TCOSUB = 108;
		static const Sbecore::uint PNLWZNMVERLIST_TCOBVR = 109;
		static const Sbecore::uint PNLWZNMVERLIST_TCOLOC = 110;
		static const Sbecore::uint PNLWZNMVERLIST_TCOSTE = 111;
		static const Sbecore::uint PNLWZNMVERLIST_TCODTY = 112;
		static const Sbecore::uint PNLWZNMVERVER1NERROR_TCOREF = 113;
		static const Sbecore::uint PNLWZNMVERVER1NAPP_TCOREF = 114;
		static const Sbecore::uint PNLWZNMVER1NCAPABILITY_TCOREF = 115;
		static const Sbecore::uint PNLWZNMVER1NVECTOR_TCOREF = 116;
		static const Sbecore::uint PNLWZNMVER1NTABLE_TCOREF = 117;
		static const Sbecore::uint PNLWZNMVER1NRELATION_TCOREF = 118;
		static const Sbecore::uint PNLWZNMVER1NQUERY_TCOREF = 119;
		static const Sbecore::uint PNLWZNMVER1NPRESET_TCOREF = 120;
		static const Sbecore::uint PNLWZNMVERVER1NMODULE_TCOREF = 121;
		static const Sbecore::uint PNLWZNMVER1NOPPACK_TCOREF = 122;
		static const Sbecore::uint PNLWZNMVER1NJOB_TCOREF = 123;
		static const Sbecore::uint PNLWZNMVER1NIMPEXPCPLX_TCOREF = 124;
		static const Sbecore::uint PNLWZNMVER1NCALL_TCOREF = 125;
		static const Sbecore::uint PNLWZNMVER1NCOMPONENT_TCOREF = 126;
		static const Sbecore::uint PNLWZNMVERBVR1NVERSION_TCOREF = 127;
		static const Sbecore::uint PNLWZNMVER1NBLOCK_TCOREF = 128;
		static const Sbecore::uint PNLWZNMVERREF1NFILE_TCOREF = 129;
		static const Sbecore::uint PNLWZNMVERMNLOCALE_TCOMREF = 130;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOSRF = 131;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOTIT = 132;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOVER = 133;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOTPL = 134;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOATF = 135;
		static const Sbecore::uint PNLWZNMCAPAPAR_TCOKEY = 136;
		static const Sbecore::uint PNLWZNMCAPAPAR_TCOVAL = 137;
		static const Sbecore::uint PNLWZNMERRLIST_TCOSRF = 138;
		static const Sbecore::uint PNLWZNMERRLIST_TCOTIT = 139;
		static const Sbecore::uint PNLWZNMERRLIST_TCOVER = 140;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOSRF = 141;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOSHO = 142;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOTYP = 143;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOVER = 144;
		static const Sbecore::uint PNLWZNMTBLLIST_TCORET = 145;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOREU = 146;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLOT = 147;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOFNA = 148;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLDX = 149;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLBY = 150;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOORD = 151;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLIT = 152;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOTYP = 153;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOLOC = 154;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOGND = 155;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOTIT = 156;
		static const Sbecore::uint PNLWZNMTBL1NSTUB_TCOREF = 157;
		static const Sbecore::uint PNLWZNMTBL1NSUBSET_TCOREF = 158;
		static const Sbecore::uint PNLWZNMTBLTBL1NTABLECOL_TCOREF = 159;
		static const Sbecore::uint PNLWZNMTBLTO1NRELATION_TCOREF = 160;
		static const Sbecore::uint PNLWZNMTBLFR1NRELATION_TCOREF = 161;
		static const Sbecore::uint PNLWZNMTBL1NCHECK_TCOREF = 162;
		static const Sbecore::uint PNLWZNMTBL1NIMPEXP_TCOREF = 163;
		static const Sbecore::uint PNLWZNMTBLREF1NQUERYMOD_TCOREF = 164;
		static const Sbecore::uint PNLWZNMTBLREF1NRTBLOCK_TCOREF = 165;
		static const Sbecore::uint PNLWZNMTBLHK1NVECTOR_TCOREF = 166;
		static const Sbecore::uint PNLWZNMTBLFCT1NTABLECOL_TCOREF = 167;
		static const Sbecore::uint PNLWZNMTBLSRC1NFEED_TCOREF = 168;
		static const Sbecore::uint PNLWZNMTBLREF1NPANEL_TCOREF = 169;
		static const Sbecore::uint PNLWZNMTBLREF1NCALL_TCOREF = 170;
		static const Sbecore::uint PNLWZNMTBLREF1NDIALOG_TCOREF = 171;
		static const Sbecore::uint PNLWZNMTBLPST1NQUERYMOD_TCOREF = 172;
		static const Sbecore::uint PNLWZNMTBLMNVECTOR_TCOMREF = 173;
		static const Sbecore::uint PNLWZNMTBLMNVECTOR_TCOSBS = 174;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOMREF = 175;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOTQMD = 176;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOSRC = 177;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOPFX = 178;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSRF = 179;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSHO = 180;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOTYP = 181;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOTBL = 182;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOFCT = 183;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSTY = 184;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOAXF = 185;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOTYP = 186;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOLOC = 187;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOTIT = 188;
		static const Sbecore::uint PNLWZNMTCO1NQUERYCOL_TCOREF = 189;
		static const Sbecore::uint PNLWZNMTCO1NIMPEXPCOL_TCOREF = 190;
		static const Sbecore::uint PNLWZNMTCOREF1NQUERYMOD_TCOREF = 191;
		static const Sbecore::uint PNLWZNMTCOREF1NCONTROL_TCOREF = 192;
		static const Sbecore::uint PNLWZNMTCO1NCHECK_TCOREF = 193;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOSRF = 194;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOSHO = 195;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOTBL = 196;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOTYP = 197;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOLOC = 198;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOGND = 199;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOTIT = 200;
		static const Sbecore::uint PNLWZNMSBS1NSTUB_TCOREF = 201;
		static const Sbecore::uint PNLWZNMSBS1NTABLECOL_TCOREF = 202;
		static const Sbecore::uint PNLWZNMSBSTOS1NRELATION_TCOREF = 203;
		static const Sbecore::uint PNLWZNMSBSFRS1NRELATION_TCOREF = 204;
		static const Sbecore::uint PNLWZNMSBSPST1NQUERYMOD_TCOREF = 205;
		static const Sbecore::uint PNLWZNMSBSASBMNSUBSET_TCOMREF = 206;
		static const Sbecore::uint PNLWZNMSBSASBMNSUBSET_TCORTY = 207;
		static const Sbecore::uint PNLWZNMSBSBSBMNSUBSET_TCOMREF = 208;
		static const Sbecore::uint PNLWZNMSBSBSBMNSUBSET_TCORTY = 209;
		static const Sbecore::uint PNLWZNMRELLIST_TCOFRT = 210;
		static const Sbecore::uint PNLWZNMRELLIST_TCOFRS = 211;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTOT = 212;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTOS = 213;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTYP = 214;
		static const Sbecore::uint PNLWZNMRELLIST_TCOVER = 215;
		static const Sbecore::uint PNLWZNMRELLIST_TCOSUP = 216;
		static const Sbecore::uint PNLWZNMRELLIST_TCOSRL = 217;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTBL = 218;
		static const Sbecore::uint PNLWZNMRELLIST_TCOPFX = 219;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOTYP = 220;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOLOC = 221;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOTIT = 222;
		static const Sbecore::uint PNLWZNMREL1NTABLECOL_TCOREF = 223;
		static const Sbecore::uint PNLWZNMRELSUP1NRELATION_TCOREF = 224;
		static const Sbecore::uint PNLWZNMRELREF1NPANEL_TCOREF = 225;
		static const Sbecore::uint PNLWZNMRELREF1NDIALOG_TCOREF = 226;
		static const Sbecore::uint PNLWZNMRELREF1NCONTROL_TCOREF = 227;
		static const Sbecore::uint PNLWZNMVECLIST_TCOSRF = 228;
		static const Sbecore::uint PNLWZNMVECLIST_TCOTYP = 229;
		static const Sbecore::uint PNLWZNMVECLIST_TCOVER = 230;
		static const Sbecore::uint PNLWZNMVECLIST_TCOHKT = 231;
		static const Sbecore::uint PNLWZNMVECLIST_TCOHKU = 232;
		static const Sbecore::uint PNLWZNMVECLIST_TCOTGR = 233;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOTYP = 234;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOLOC = 235;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOTIT = 236;
		static const Sbecore::uint PNLWZNMVECVEC1NVECTORITEM_TCOREF = 237;
		static const Sbecore::uint PNLWZNMVECFCT1NTABLECOL_TCOREF = 238;
		static const Sbecore::uint PNLWZNMVECREF1NPANEL_TCOREF = 239;
		static const Sbecore::uint PNLWZNMVECSRC1NFEED_TCOREF = 240;
		static const Sbecore::uint PNLWZNMVECPST1NQUERYMOD_TCOREF = 241;
		static const Sbecore::uint PNLWZNMVECMNTABLE_TCOMREF = 242;
		static const Sbecore::uint PNLWZNMVECMNTABLE_TCOSBS = 243;
		static const Sbecore::uint PNLWZNMVITLIST_TCOSRF = 244;
		static const Sbecore::uint PNLWZNMVITLIST_TCOTIT = 245;
		static const Sbecore::uint PNLWZNMVITLIST_TCOVEC = 246;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOSRF = 247;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTYP = 248;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTBL = 249;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTCO = 250;
		static const Sbecore::uint PNLWZNMCHKREF1NCALL_TCOREF = 251;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOSRF = 252;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOTYP = 253;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOTBL = 254;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOSBS = 255;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOEXA = 256;
		static const Sbecore::uint PNLWZNMSTBSUPMNSTUB_TCOMREF = 257;
		static const Sbecore::uint PNLWZNMSTBSUBMNSTUB_TCOMREF = 258;
		static const Sbecore::uint PNLWZNMSTBMNSQUAWK_TCOMREF = 259;
		static const Sbecore::uint PNLWZNMSTBMNCALL_TCOMREF = 260;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOSRF = 261;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOSHO = 262;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOTIT = 263;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOVER = 264;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOMIV = 265;
		static const Sbecore::uint PNLWZNMIEX1NIMPEXP_TCOREF = 266;
		static const Sbecore::uint PNLWZNMIEXHK1NVECTOR_TCOREF = 267;
		static const Sbecore::uint PNLWZNMIEXREF1NDIALOG_TCOREF = 268;
		static const Sbecore::uint PNLWZNMIMELIST_TCOSRF = 269;
		static const Sbecore::uint PNLWZNMIMELIST_TCOIEX = 270;
		static const Sbecore::uint PNLWZNMIMELIST_TCOSUP = 271;
		static const Sbecore::uint PNLWZNMIMELIST_TCOTBL = 272;
		static const Sbecore::uint PNLWZNMIMEIME1NIMPEXPCOL_TCOREF = 273;
		static const Sbecore::uint PNLWZNMIMESUP1NIMPEXP_TCOREF = 274;
		static const Sbecore::uint PNLWZNMIMEHK1NVECTOR_TCOREF = 275;
		static const Sbecore::uint PNLWZNMIELLIST_TCOSRF = 276;
		static const Sbecore::uint PNLWZNMIELLIST_TCOSHO = 277;
		static const Sbecore::uint PNLWZNMIELLIST_TCOTYP = 278;
		static const Sbecore::uint PNLWZNMIELLIST_TCOIME = 279;
		static const Sbecore::uint PNLWZNMIELLIST_TCOTCO = 280;
		static const Sbecore::uint PNLWZNMIELLIST_TCOCTY = 281;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOSRF = 282;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOTIT = 283;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOVER = 284;
		static const Sbecore::uint PNLWZNMPSTLIST_TCORET = 285;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOREU = 286;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOATY = 287;
		static const Sbecore::uint PNLWZNMPST1NQUERYMOD_TCOREF = 288;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOSRF = 289;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOTIT = 290;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOVER = 291;
		static const Sbecore::uint PNLWZNMMDLMDL1NCARD_TCOREF = 292;
		static const Sbecore::uint PNLWZNMMDLREF1NPANEL_TCOREF = 293;
		static const Sbecore::uint PNLWZNMCARLIST_TCOSRF = 294;
		static const Sbecore::uint PNLWZNMCARLIST_TCOTIT = 295;
		static const Sbecore::uint PNLWZNMCARLIST_TCOMDL = 296;
		static const Sbecore::uint PNLWZNMCARLIST_TCORET = 297;
		static const Sbecore::uint PNLWZNMCARLIST_TCOREU = 298;
		static const Sbecore::uint PNLWZNMCARCAR1NPANEL_TCOREF = 299;
		static const Sbecore::uint PNLWZNMCAR1NDIALOG_TCOREF = 300;
		static const Sbecore::uint PNLWZNMCARHK1NCONTROL_TCOREF = 301;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOSRF = 302;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOTYP = 303;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOCAR = 304;
		static const Sbecore::uint PNLWZNMDLGLIST_TCORET = 305;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOREU = 306;
		static const Sbecore::uint PNLWZNMDLGHK1NCONTROL_TCOREF = 307;
		static const Sbecore::uint PNLWZNMDLGREF1NCONTROL_TCOREF = 308;
		static const Sbecore::uint PNLWZNMDLGMNQUERY_TCOMREF = 309;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOSRF = 310;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOTYP = 311;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOCAR = 312;
		static const Sbecore::uint PNLWZNMPNLLIST_TCORET = 313;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOREU = 314;
		static const Sbecore::uint PNLWZNMPNLHK1NCONTROL_TCOREF = 315;
		static const Sbecore::uint PNLWZNMPNLMNQUERY_TCOMREF = 316;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSRF = 317;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOTYP = 318;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOVER = 319;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSUP = 320;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSRL = 321;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOTBL = 322;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOQTB = 323;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOQMD = 324;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOTYP = 325;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOCSE = 326;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOPST = 327;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOVEC = 328;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOVIT = 329;
		static const Sbecore::uint PNLWZNMQRYAORDER_TCOSHO = 330;
		static const Sbecore::uint PNLWZNMQRYAORDER_TCOTCO = 331;
		static const Sbecore::uint PNLWZNMQRY1NQUERYMOD_TCOREF = 332;
		static const Sbecore::uint PNLWZNMQRYQRY1NQUERYCOL_TCOREF = 333;
		static const Sbecore::uint PNLWZNMQRYSUP1NQUERY_TCOREF = 334;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOMREF = 335;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOTQMD = 336;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOSRC = 337;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOPFX = 338;
		static const Sbecore::uint PNLWZNMQRYMNPANEL_TCOMREF = 339;
		static const Sbecore::uint PNLWZNMQRYMNDIALOG_TCOMREF = 340;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOSRF = 341;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOSHO = 342;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOTYP = 343;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOQRY = 344;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOTCO = 345;
		static const Sbecore::uint PNLWZNMQCOREF1NCONTROL_TCOREF = 346;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOTYP = 347;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOQRY = 348;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOPST = 349;
		static const Sbecore::uint PNLWZNMQMDLIST_TCORET = 350;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOREU = 351;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSRF = 352;
		static const Sbecore::uint PNLWZNMCONLIST_TCOTIT = 353;
		static const Sbecore::uint PNLWZNMCONLIST_TCOTYP = 354;
		static const Sbecore::uint PNLWZNMCONLIST_TCOHKT = 355;
		static const Sbecore::uint PNLWZNMCONLIST_TCOHKU = 356;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSCT = 357;
		static const Sbecore::uint PNLWZNMCONLIST_TCORET = 358;
		static const Sbecore::uint PNLWZNMCONLIST_TCOREU = 359;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSUP = 360;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSTY = 361;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOKEY = 362;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOLOC = 363;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOVAL = 364;
		static const Sbecore::uint PNLWZNMCONSUP1NCONTROL_TCOREF = 365;
		static const Sbecore::uint PNLWZNMCONFEDREF1NRTBLOCK_TCOREF = 366;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOSRF = 367;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOTIT = 368;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOTYP = 369;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOVER = 370;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOSHD = 371;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOSRF = 372;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOVTY = 373;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOVEC = 374;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOCMT = 375;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOSRF = 376;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVTY = 377;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVEC = 378;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCODVL = 379;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVIT = 380;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOCMT = 381;
		static const Sbecore::uint PNLWZNMOPK1NOP_TCOREF = 382;
		static const Sbecore::uint PNLWZNMOPKREF1NBLOCK_TCOREF = 383;
		static const Sbecore::uint PNLWZNMOPKMNJOB_TCOMREF = 384;
		static const Sbecore::uint PNLWZNMOPKMNCOMPONENT_TCOMREF = 385;
		static const Sbecore::uint PNLWZNMOPKMNLIBRARY_TCOMREF = 386;
		static const Sbecore::uint PNLWZNMOPKSQKMNSTUB_TCOMREF = 387;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOSRF = 388;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOOPK = 389;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOSHD = 390;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOSRF = 391;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVTY = 392;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVEC = 393;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCODVL = 394;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVIT = 395;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOCMT = 396;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOSRF = 397;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOVTY = 398;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOVEC = 399;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOCMT = 400;
		static const Sbecore::uint PNLWZNMOPXREF1NBLOCK_TCOREF = 401;
		static const Sbecore::uint PNLWZNMOPXMNJOB_TCOMREF = 402;
		static const Sbecore::uint PNLWZNMOPXSQKMNSTUB_TCOMREF = 403;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOSRF = 404;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOTYP = 405;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOVER = 406;
		static const Sbecore::uint PNLWZNMJOBLIST_TCORET = 407;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOREU = 408;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOGBL = 409;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOCLS = 410;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOSHD = 411;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOSRF = 412;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOVTY = 413;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOVEC = 414;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOLEN = 415;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOSHR = 416;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOCMT = 417;
		static const Sbecore::uint PNLWZNMJOBACMD_TCOSRF = 418;
		static const Sbecore::uint PNLWZNMJOBACMD_TCOCMT = 419;
		static const Sbecore::uint PNLWZNMJOB1NMETHOD_TCOREF = 420;
		static const Sbecore::uint PNLWZNMJOB1NRTJOB_TCOREF = 421;
		static const Sbecore::uint PNLWZNMJOBJOB1NSTAGE_TCOREF = 422;
		static const Sbecore::uint PNLWZNMJOB1NSENSITIVITY_TCOREF = 423;
		static const Sbecore::uint PNLWZNMJOBHK1NVECTOR_TCOREF = 424;
		static const Sbecore::uint PNLWZNMJOBREF1NBLOCK_TCOREF = 425;
		static const Sbecore::uint PNLWZNMJOBMNOPPACK_TCOMREF = 426;
		static const Sbecore::uint PNLWZNMJOBMNOP_TCOMREF = 427;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOMREF = 428;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOSHO = 429;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOMLT = 430;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOCSA = 431;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOMREF = 432;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOSHO = 433;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOMLT = 434;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOCSA = 435;
		static const Sbecore::uint PNLWZNMSGELIST_TCOSRF = 436;
		static const Sbecore::uint PNLWZNMSGELIST_TCOTYP = 437;
		static const Sbecore::uint PNLWZNMSGELIST_TCOJOB = 438;
		static const Sbecore::uint PNLWZNMSGE1NSENSITIVITY_TCOREF = 439;
		static const Sbecore::uint PNLWZNMSGESQKMNSTUB_TCOMREF = 440;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOSRF = 441;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOJOB = 442;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOEXS = 443;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOSRF = 444;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOVTY = 445;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOVEC = 446;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOLEN = 447;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOCMT = 448;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOSRF = 449;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOVTY = 450;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOVEC = 451;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOLEN = 452;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOCMT = 453;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOSRF = 454;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOTYP = 455;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOVER = 456;
		static const Sbecore::uint PNLWZNMBLKLIST_TCORET = 457;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOREU = 458;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOTYP = 459;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOSRF = 460;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVTY = 461;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOCON = 462;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVEC = 463;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOFED = 464;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOTBL = 465;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOBL2 = 466;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCODFV = 467;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVIT = 468;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOCMT = 469;
		static const Sbecore::uint PNLWZNMBLK1NRTDPCH_TCOREF = 470;
		static const Sbecore::uint PNLWZNMBLKREF1NRTBLOCK_TCOREF = 471;
		static const Sbecore::uint PNLWZNMCALLIST_TCOSRF = 472;
		static const Sbecore::uint PNLWZNMCALLIST_TCOTYP = 473;
		static const Sbecore::uint PNLWZNMCALLIST_TCOVER = 474;
		static const Sbecore::uint PNLWZNMCALLIST_TCORET = 475;
		static const Sbecore::uint PNLWZNMCALLIST_TCOREU = 476;
		static const Sbecore::uint PNLWZNMCALLIST_TCOIAT = 477;
		static const Sbecore::uint PNLWZNMCALLIST_TCORAT = 478;
		static const Sbecore::uint PNLWZNMCAL1NSENSITIVITY_TCOREF = 479;
		static const Sbecore::uint PNLWZNMCALMNSTUB_TCOMREF = 480;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOSRF = 481;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOTIT = 482;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOTYP = 483;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOVER = 484;
		static const Sbecore::uint PNLWZNMCMP1NRELEASE_TCOREF = 485;
		static const Sbecore::uint PNLWZNMCMPMNOPPACK_TCOMREF = 486;
		static const Sbecore::uint PNLWZNMCMPMNLIBRARY_TCOMREF = 487;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOSRF = 488;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOCMP = 489;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOMCH = 490;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOGRP = 491;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOOWN = 492;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOSHO = 493;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOTIT = 494;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOTRG = 495;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOVER = 496;
		static const Sbecore::uint PNLWZNMAPP1NEVENT_TCOREF = 497;
		static const Sbecore::uint PNLWZNMAPP1NRTJOB_TCOREF = 498;
		static const Sbecore::uint PNLWZNMAPPAPP1NSEQUENCE_TCOREF = 499;
		static const Sbecore::uint PNLWZNMAPPREF1NFILE_TCOREF = 500;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOSRF = 501;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOAPP = 502;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOSUP = 503;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOJOB = 504;
		static const Sbecore::uint PNLWZNMRTJ1NRTDPCH_TCOREF = 505;
		static const Sbecore::uint PNLWZNMRTJ1NRTBLOCK_TCOREF = 506;
		static const Sbecore::uint PNLWZNMRTJSUP1NRTJOB_TCOREF = 507;
		static const Sbecore::uint PNLWZNMEVTLIST_TCOSRF = 508;
		static const Sbecore::uint PNLWZNMEVTLIST_TCOAPP = 509;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOSRF = 510;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOTIT = 511;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOAPP = 512;
		static const Sbecore::uint PNLWZNMSEQSEQ1NSTATE_TCOREF = 513;
		static const Sbecore::uint PNLWZNMSTELIST_TCOSRF = 514;
		static const Sbecore::uint PNLWZNMSTELIST_TCOSEQ = 515;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSCT = 516;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTYP = 517;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTRJ = 518;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOVEC = 519;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOVIT = 520;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSNX = 521;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSEQ = 522;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR1 = 523;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP1 = 524;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR2 = 525;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP2 = 526;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR3 = 527;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP3 = 528;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR4 = 529;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP4 = 530;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOSRF = 531;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOTYP = 532;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOEVT = 533;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCORTJ = 534;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOVIT = 535;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOXSR = 536;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCORTD = 537;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOMSK = 538;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOCND = 539;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVFeatgroup (full: VecWznmVFeatgroup)
		*/
	class VecVFeatgroup {

	public:
		static const Sbecore::uint VECWZNMVCARD = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVGender (full: VecWznmVGender)
		*/
	class VecVGender {

	public:
		static const Sbecore::uint M = 1;
		static const Sbecore::uint F = 2;
		static const Sbecore::uint N = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecVKeylist (full: VecWznmVKeylist)
		*/
	class VecVKeylist {

	public:
		static const Sbecore::uint KLSTWZNMKAMCAPABILITYPARKEY = 1;
		static const Sbecore::uint KLSTWZNMKAMCONTROLPARKEY = 2;
		static const Sbecore::uint KLSTWZNMKAMCONTROLPARVAL = 3;
		static const Sbecore::uint KLSTWZNMKAMLIBRARYMAKEFILETAG = 4;
		static const Sbecore::uint KLSTWZNMKAMMACHINEMAKEFILETAG = 5;
		static const Sbecore::uint KLSTWZNMKAMMACHINEPARKEY = 6;
		static const Sbecore::uint KLSTWZNMKAMPERSONDETAILTYPE = 7;
		static const Sbecore::uint KLSTWZNMKMCONTROLOPTION = 8;
		static const Sbecore::uint KLSTWZNMKMFILECONTENT = 9;
		static const Sbecore::uint KLSTWZNMKMFILEMIMETYPE = 10;
		static const Sbecore::uint KLSTWZNMKMLIBRARYLICTYPE = 11;
		static const Sbecore::uint KLSTWZNMKMMACHINEPKGMGR = 12;
		static const Sbecore::uint KLSTWZNMKMRELATIONOPTION = 13;
		static const Sbecore::uint KLSTWZNMKMRELEASEOPTION = 14;
		static const Sbecore::uint KLSTWZNMKMTABLECOLOPTION = 15;
		static const Sbecore::uint KLSTWZNMKMVECTOROPTION = 16;
		static const Sbecore::uint KLSTWZNMKRMCAPABILITYUNIVERSALKEY = 17;
		static const Sbecore::uint KLSTWZNMKRMPERSONMPROJECTFUNCTION = 18;
		static const Sbecore::uint KLSTWZNMKTAGGRP = 19;
		static const Sbecore::uint KLSTKWZNMCTPGENJTRCUSTOP = 20;
		static const Sbecore::uint KLSTKWZNMCTPGENUICUSTOP = 21;
		static const Sbecore::uint KLSTKWZNMCTPWRSRVCUSTOP = 22;
		static const Sbecore::uint KLSTKWZNMCTPWRSTKITCUSTOP = 23;
		static const Sbecore::uint KLSTKWZNMCTPWRWEBCUSTOP = 24;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

	/**
		* VecVLat (full: VecWznmVLat)
		*/
	class VecVLat {

	public:
		static const Sbecore::uint DLO = 1;
		static const Sbecore::uint INI = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVLocale (full: VecWznmVLocale)
		*/
	class VecVLocale {

	public:
		static const Sbecore::uint ENUS = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVLop (full: VecWznmVLop)
		*/
	class VecVLop {

	public:
		static const Sbecore::uint INS = 1;
		static const Sbecore::uint RMV = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMaintable (full: VecWznmVMaintable)
		*/
	class VecVMaintable {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint TBLWZNMMAPP = 2;
		static const Sbecore::uint TBLWZNMMBLOCK = 3;
		static const Sbecore::uint TBLWZNMMCALL = 4;
		static const Sbecore::uint TBLWZNMMCAPABILITY = 5;
		static const Sbecore::uint TBLWZNMMCARD = 6;
		static const Sbecore::uint TBLWZNMMCHECK = 7;
		static const Sbecore::uint TBLWZNMMCOMPONENT = 8;
		static const Sbecore::uint TBLWZNMMCONTROL = 9;
		static const Sbecore::uint TBLWZNMMDIALOG = 10;
		static const Sbecore::uint TBLWZNMMERROR = 11;
		static const Sbecore::uint TBLWZNMMEVENT = 12;
		static const Sbecore::uint TBLWZNMMFEED = 13;
		static const Sbecore::uint TBLWZNMMFILE = 14;
		static const Sbecore::uint TBLWZNMMIMPEXP = 15;
		static const Sbecore::uint TBLWZNMMIMPEXPCOL = 16;
		static const Sbecore::uint TBLWZNMMIMPEXPCPLX = 17;
		static const Sbecore::uint TBLWZNMMJOB = 18;
		static const Sbecore::uint TBLWZNMMLIBRARY = 19;
		static const Sbecore::uint TBLWZNMMLOCALE = 20;
		static const Sbecore::uint TBLWZNMMMACHINE = 21;
		static const Sbecore::uint TBLWZNMMMETHOD = 22;
		static const Sbecore::uint TBLWZNMMMODULE = 23;
		static const Sbecore::uint TBLWZNMMOP = 24;
		static const Sbecore::uint TBLWZNMMOPPACK = 25;
		static const Sbecore::uint TBLWZNMMPANEL = 26;
		static const Sbecore::uint TBLWZNMMPERSON = 27;
		static const Sbecore::uint TBLWZNMMPRESET = 28;
		static const Sbecore::uint TBLWZNMMPROJECT = 29;
		static const Sbecore::uint TBLWZNMMQUERY = 30;
		static const Sbecore::uint TBLWZNMMQUERYCOL = 31;
		static const Sbecore::uint TBLWZNMMQUERYMOD = 32;
		static const Sbecore::uint TBLWZNMMRELATION = 33;
		static const Sbecore::uint TBLWZNMMRELEASE = 34;
		static const Sbecore::uint TBLWZNMMRTBLOCK = 35;
		static const Sbecore::uint TBLWZNMMRTDPCH = 36;
		static const Sbecore::uint TBLWZNMMRTJOB = 37;
		static const Sbecore::uint TBLWZNMMSENSITIVITY = 38;
		static const Sbecore::uint TBLWZNMMSEQUENCE = 39;
		static const Sbecore::uint TBLWZNMMSESSION = 40;
		static const Sbecore::uint TBLWZNMMSQUAWK = 41;
		static const Sbecore::uint TBLWZNMMSTAGE = 42;
		static const Sbecore::uint TBLWZNMMSTATE = 43;
		static const Sbecore::uint TBLWZNMMSTUB = 44;
		static const Sbecore::uint TBLWZNMMSUBSET = 45;
		static const Sbecore::uint TBLWZNMMTABLE = 46;
		static const Sbecore::uint TBLWZNMMTABLECOL = 47;
		static const Sbecore::uint TBLWZNMMTAG = 48;
		static const Sbecore::uint TBLWZNMMUSER = 49;
		static const Sbecore::uint TBLWZNMMUSERGROUP = 50;
		static const Sbecore::uint TBLWZNMMVECTOR = 51;
		static const Sbecore::uint TBLWZNMMVECTORITEM = 52;
		static const Sbecore::uint TBLWZNMMVERSION = 53;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVOolop (full: VecWznmVOolop)
		*/
	class VecVOolop {

	public:
		static const Sbecore::uint INA = 1;
		static const Sbecore::uint INB = 2;
		static const Sbecore::uint RMV = 3;
		static const Sbecore::uint SWP = 4;
		static const Sbecore::uint TOA = 5;
		static const Sbecore::uint TOB = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVPreset (full: VecWznmVPreset)
		*/
	class VecVPreset {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint PREWZNMADMIN = 2;
		static const Sbecore::uint PREWZNMAPPLIST_GRP = 3;
		static const Sbecore::uint PREWZNMAPPLIST_OWN = 4;
		static const Sbecore::uint PREWZNMAPPLIST_TIT = 5;
		static const Sbecore::uint PREWZNMAPPLIST_TRG = 6;
		static const Sbecore::uint PREWZNMAPPLIST_VER = 7;
		static const Sbecore::uint PREWZNMBLKLIST_RET = 8;
		static const Sbecore::uint PREWZNMBLKLIST_REU = 9;
		static const Sbecore::uint PREWZNMBLKLIST_SRF = 10;
		static const Sbecore::uint PREWZNMBLKLIST_TYP = 11;
		static const Sbecore::uint PREWZNMBLKLIST_VER = 12;
		static const Sbecore::uint PREWZNMCALLIST_IAT = 13;
		static const Sbecore::uint PREWZNMCALLIST_RAT = 14;
		static const Sbecore::uint PREWZNMCALLIST_RET = 15;
		static const Sbecore::uint PREWZNMCALLIST_REU = 16;
		static const Sbecore::uint PREWZNMCALLIST_SRF = 17;
		static const Sbecore::uint PREWZNMCALLIST_TYP = 18;
		static const Sbecore::uint PREWZNMCALLIST_VER = 19;
		static const Sbecore::uint PREWZNMCAPAPAR_X1 = 20;
		static const Sbecore::uint PREWZNMCAPLIST_SRF = 21;
		static const Sbecore::uint PREWZNMCAPLIST_TPL = 22;
		static const Sbecore::uint PREWZNMCAPLIST_VER = 23;
		static const Sbecore::uint PREWZNMCARLIST_MDL = 24;
		static const Sbecore::uint PREWZNMCARLIST_RET = 25;
		static const Sbecore::uint PREWZNMCARLIST_REU = 26;
		static const Sbecore::uint PREWZNMCARLIST_SRF = 27;
		static const Sbecore::uint PREWZNMCHKLIST_SRF = 28;
		static const Sbecore::uint PREWZNMCHKLIST_TBL = 29;
		static const Sbecore::uint PREWZNMCHKLIST_TCO = 30;
		static const Sbecore::uint PREWZNMCHKLIST_TYP = 31;
		static const Sbecore::uint PREWZNMCMPLIST_SRF = 32;
		static const Sbecore::uint PREWZNMCMPLIST_TYP = 33;
		static const Sbecore::uint PREWZNMCMPLIST_VER = 34;
		static const Sbecore::uint PREWZNMCONAPAR_X1 = 35;
		static const Sbecore::uint PREWZNMCONAPAR_X2 = 36;
		static const Sbecore::uint PREWZNMCONLIST_HKT = 37;
		static const Sbecore::uint PREWZNMCONLIST_HKU = 38;
		static const Sbecore::uint PREWZNMCONLIST_RET = 39;
		static const Sbecore::uint PREWZNMCONLIST_REU = 40;
		static const Sbecore::uint PREWZNMCONLIST_SCT = 41;
		static const Sbecore::uint PREWZNMCONLIST_SRF = 42;
		static const Sbecore::uint PREWZNMCONLIST_SUP = 43;
		static const Sbecore::uint PREWZNMCONLIST_TYP = 44;
		static const Sbecore::uint PREWZNMCTPAPAR_X1 = 45;
		static const Sbecore::uint PREWZNMCTPLIST_SRF = 46;
		static const Sbecore::uint PREWZNMCTPLIST_VER = 47;
		static const Sbecore::uint PREWZNMDLGLIST_CAR = 48;
		static const Sbecore::uint PREWZNMDLGLIST_RET = 49;
		static const Sbecore::uint PREWZNMDLGLIST_REU = 50;
		static const Sbecore::uint PREWZNMDLGLIST_SRF = 51;
		static const Sbecore::uint PREWZNMDLGLIST_TYP = 52;
		static const Sbecore::uint PREWZNMERRLIST_SRF = 53;
		static const Sbecore::uint PREWZNMERRLIST_VER = 54;
		static const Sbecore::uint PREWZNMEVTLIST_APP = 55;
		static const Sbecore::uint PREWZNMEVTLIST_SRF = 56;
		static const Sbecore::uint PREWZNMEXTFOLDER = 57;
		static const Sbecore::uint PREWZNMFILLIST_FNM = 58;
		static const Sbecore::uint PREWZNMFILLIST_GRP = 59;
		static const Sbecore::uint PREWZNMFILLIST_OWN = 60;
		static const Sbecore::uint PREWZNMFILLIST_RET = 61;
		static const Sbecore::uint PREWZNMFILLIST_REU = 62;
		static const Sbecore::uint PREWZNMGITURL = 63;
		static const Sbecore::uint PREWZNMGROUP = 64;
		static const Sbecore::uint PREWZNMIELLIST_IME = 65;
		static const Sbecore::uint PREWZNMIELLIST_SRF = 66;
		static const Sbecore::uint PREWZNMIELLIST_TCO = 67;
		static const Sbecore::uint PREWZNMIELLIST_TYP = 68;
		static const Sbecore::uint PREWZNMIEXLIST_SRF = 69;
		static const Sbecore::uint PREWZNMIEXLIST_VER = 70;
		static const Sbecore::uint PREWZNMIMELIST_IEX = 71;
		static const Sbecore::uint PREWZNMIMELIST_SRF = 72;
		static const Sbecore::uint PREWZNMIMELIST_SUP = 73;
		static const Sbecore::uint PREWZNMIMELIST_TBL = 74;
		static const Sbecore::uint PREWZNMIP = 75;
		static const Sbecore::uint PREWZNMIXBASEREPTYPE = 76;
		static const Sbecore::uint PREWZNMIXCRDACCAPP = 77;
		static const Sbecore::uint PREWZNMIXCRDACCBLK = 78;
		static const Sbecore::uint PREWZNMIXCRDACCCAL = 79;
		static const Sbecore::uint PREWZNMIXCRDACCCAP = 80;
		static const Sbecore::uint PREWZNMIXCRDACCCAR = 81;
		static const Sbecore::uint PREWZNMIXCRDACCCHK = 82;
		static const Sbecore::uint PREWZNMIXCRDACCCMP = 83;
		static const Sbecore::uint PREWZNMIXCRDACCCON = 84;
		static const Sbecore::uint PREWZNMIXCRDACCCTP = 85;
		static const Sbecore::uint PREWZNMIXCRDACCDLG = 86;
		static const Sbecore::uint PREWZNMIXCRDACCERR = 87;
		static const Sbecore::uint PREWZNMIXCRDACCEVT = 88;
		static const Sbecore::uint PREWZNMIXCRDACCFIL = 89;
		static const Sbecore::uint PREWZNMIXCRDACCIEL = 90;
		static const Sbecore::uint PREWZNMIXCRDACCIEX = 91;
		static const Sbecore::uint PREWZNMIXCRDACCIME = 92;
		static const Sbecore::uint PREWZNMIXCRDACCJOB = 93;
		static const Sbecore::uint PREWZNMIXCRDACCLIB = 94;
		static const Sbecore::uint PREWZNMIXCRDACCLOC = 95;
		static const Sbecore::uint PREWZNMIXCRDACCMCH = 96;
		static const Sbecore::uint PREWZNMIXCRDACCMDL = 97;
		static const Sbecore::uint PREWZNMIXCRDACCMTD = 98;
		static const Sbecore::uint PREWZNMIXCRDACCOPK = 99;
		static const Sbecore::uint PREWZNMIXCRDACCOPX = 100;
		static const Sbecore::uint PREWZNMIXCRDACCPNL = 101;
		static const Sbecore::uint PREWZNMIXCRDACCPRJ = 102;
		static const Sbecore::uint PREWZNMIXCRDACCPRS = 103;
		static const Sbecore::uint PREWZNMIXCRDACCPST = 104;
		static const Sbecore::uint PREWZNMIXCRDACCQCO = 105;
		static const Sbecore::uint PREWZNMIXCRDACCQMD = 106;
		static const Sbecore::uint PREWZNMIXCRDACCQRY = 107;
		static const Sbecore::uint PREWZNMIXCRDACCREL = 108;
		static const Sbecore::uint PREWZNMIXCRDACCRLS = 109;
		static const Sbecore::uint PREWZNMIXCRDACCRTJ = 110;
		static const Sbecore::uint PREWZNMIXCRDACCSBS = 111;
		static const Sbecore::uint PREWZNMIXCRDACCSEQ = 112;
		static const Sbecore::uint PREWZNMIXCRDACCSGE = 113;
		static const Sbecore::uint PREWZNMIXCRDACCSTB = 114;
		static const Sbecore::uint PREWZNMIXCRDACCSTE = 115;
		static const Sbecore::uint PREWZNMIXCRDACCTAG = 116;
		static const Sbecore::uint PREWZNMIXCRDACCTBL = 117;
		static const Sbecore::uint PREWZNMIXCRDACCTCO = 118;
		static const Sbecore::uint PREWZNMIXCRDACCUSG = 119;
		static const Sbecore::uint PREWZNMIXCRDACCUSR = 120;
		static const Sbecore::uint PREWZNMIXCRDACCUTL = 121;
		static const Sbecore::uint PREWZNMIXCRDACCVEC = 122;
		static const Sbecore::uint PREWZNMIXCRDACCVER = 123;
		static const Sbecore::uint PREWZNMIXCRDACCVIT = 124;
		static const Sbecore::uint PREWZNMIXLCL = 125;
		static const Sbecore::uint PREWZNMIXORD = 126;
		static const Sbecore::uint PREWZNMIXPRE = 127;
		static const Sbecore::uint PREWZNMIXRECACC = 128;
		static const Sbecore::uint PREWZNMJOBLIST_GBL = 129;
		static const Sbecore::uint PREWZNMJOBLIST_RET = 130;
		static const Sbecore::uint PREWZNMJOBLIST_REU = 131;
		static const Sbecore::uint PREWZNMJOBLIST_SRF = 132;
		static const Sbecore::uint PREWZNMJOBLIST_TYP = 133;
		static const Sbecore::uint PREWZNMJOBLIST_VER = 134;
		static const Sbecore::uint PREWZNMJREFNOTIFY = 135;
		static const Sbecore::uint PREWZNMJREFSESS = 136;
		static const Sbecore::uint PREWZNMLIBAMAKEFILE_X1 = 137;
		static const Sbecore::uint PREWZNMLIBAMAKEFILE_X2 = 138;
		static const Sbecore::uint PREWZNMLIBAPKGLIST_X1 = 139;
		static const Sbecore::uint PREWZNMLIBLIST_SRF = 140;
		static const Sbecore::uint PREWZNMLOCLIST_SRF = 141;
		static const Sbecore::uint PREWZNMMCHAMAKEFILE_X1 = 142;
		static const Sbecore::uint PREWZNMMCHAPAR_X1 = 143;
		static const Sbecore::uint PREWZNMMCHLIST_SRF = 144;
		static const Sbecore::uint PREWZNMMCHLIST_SUP = 145;
		static const Sbecore::uint PREWZNMMDLLIST_SRF = 146;
		static const Sbecore::uint PREWZNMMDLLIST_VER = 147;
		static const Sbecore::uint PREWZNMMTDLIST_JOB = 148;
		static const Sbecore::uint PREWZNMMTDLIST_SRF = 149;
		static const Sbecore::uint PREWZNMNOADM = 150;
		static const Sbecore::uint PREWZNMOPKLIST_SRF = 151;
		static const Sbecore::uint PREWZNMOPKLIST_TYP = 152;
		static const Sbecore::uint PREWZNMOPKLIST_VER = 153;
		static const Sbecore::uint PREWZNMOPXLIST_OPK = 154;
		static const Sbecore::uint PREWZNMOPXLIST_SRF = 155;
		static const Sbecore::uint PREWZNMOWNER = 156;
		static const Sbecore::uint PREWZNMPNLLIST_CAR = 157;
		static const Sbecore::uint PREWZNMPNLLIST_RET = 158;
		static const Sbecore::uint PREWZNMPNLLIST_REU = 159;
		static const Sbecore::uint PREWZNMPNLLIST_SRF = 160;
		static const Sbecore::uint PREWZNMPNLLIST_TYP = 161;
		static const Sbecore::uint PREWZNMPRJLIST_GRP = 162;
		static const Sbecore::uint PREWZNMPRJLIST_OWN = 163;
		static const Sbecore::uint PREWZNMPRJLIST_SHO = 164;
		static const Sbecore::uint PREWZNMPRJLIST_TIT = 165;
		static const Sbecore::uint PREWZNMPRJLIST_VER = 166;
		static const Sbecore::uint PREWZNMPRJMNPERSON_X1 = 167;
		static const Sbecore::uint PREWZNMPRSADETAIL_X1 = 168;
		static const Sbecore::uint PREWZNMPRSLIST_GRP = 169;
		static const Sbecore::uint PREWZNMPRSLIST_LNM = 170;
		static const Sbecore::uint PREWZNMPRSLIST_OWN = 171;
		static const Sbecore::uint PREWZNMPRSMNPROJECT_X1 = 172;
		static const Sbecore::uint PREWZNMPSTLIST_ATY = 173;
		static const Sbecore::uint PREWZNMPSTLIST_RET = 174;
		static const Sbecore::uint PREWZNMPSTLIST_REU = 175;
		static const Sbecore::uint PREWZNMPSTLIST_SRF = 176;
		static const Sbecore::uint PREWZNMPSTLIST_VER = 177;
		static const Sbecore::uint PREWZNMQCOLIST_QRY = 178;
		static const Sbecore::uint PREWZNMQCOLIST_SRF = 179;
		static const Sbecore::uint PREWZNMQCOLIST_TCO = 180;
		static const Sbecore::uint PREWZNMQCOLIST_TYP = 181;
		static const Sbecore::uint PREWZNMQMDLIST_PST = 182;
		static const Sbecore::uint PREWZNMQMDLIST_QRY = 183;
		static const Sbecore::uint PREWZNMQMDLIST_RET = 184;
		static const Sbecore::uint PREWZNMQMDLIST_REU = 185;
		static const Sbecore::uint PREWZNMQMDLIST_TYP = 186;
		static const Sbecore::uint PREWZNMQRYACLAUSE_X1 = 187;
		static const Sbecore::uint PREWZNMQRYLIST_QTB = 188;
		static const Sbecore::uint PREWZNMQRYLIST_SRF = 189;
		static const Sbecore::uint PREWZNMQRYLIST_SRL = 190;
		static const Sbecore::uint PREWZNMQRYLIST_SUP = 191;
		static const Sbecore::uint PREWZNMQRYLIST_TBL = 192;
		static const Sbecore::uint PREWZNMQRYLIST_TYP = 193;
		static const Sbecore::uint PREWZNMQRYLIST_VER = 194;
		static const Sbecore::uint PREWZNMREFAPP = 195;
		static const Sbecore::uint PREWZNMREFBLK = 196;
		static const Sbecore::uint PREWZNMREFCAI = 197;
		static const Sbecore::uint PREWZNMREFCAL = 198;
		static const Sbecore::uint PREWZNMREFCAP = 199;
		static const Sbecore::uint PREWZNMREFCAR = 200;
		static const Sbecore::uint PREWZNMREFCCP = 201;
		static const Sbecore::uint PREWZNMREFCDC = 202;
		static const Sbecore::uint PREWZNMREFCFB = 203;
		static const Sbecore::uint PREWZNMREFCHK = 204;
		static const Sbecore::uint PREWZNMREFCMP = 205;
		static const Sbecore::uint PREWZNMREFCON = 206;
		static const Sbecore::uint PREWZNMREFCPB = 207;
		static const Sbecore::uint PREWZNMREFCTP = 208;
		static const Sbecore::uint PREWZNMREFDLG = 209;
		static const Sbecore::uint PREWZNMREFERR = 210;
		static const Sbecore::uint PREWZNMREFEVT = 211;
		static const Sbecore::uint PREWZNMREFFED = 212;
		static const Sbecore::uint PREWZNMREFFIL = 213;
		static const Sbecore::uint PREWZNMREFIEL = 214;
		static const Sbecore::uint PREWZNMREFIEX = 215;
		static const Sbecore::uint PREWZNMREFIME = 216;
		static const Sbecore::uint PREWZNMREFJOB = 217;
		static const Sbecore::uint PREWZNMREFKLS = 218;
		static const Sbecore::uint PREWZNMREFLIB = 219;
		static const Sbecore::uint PREWZNMREFLOC = 220;
		static const Sbecore::uint PREWZNMREFMCH = 221;
		static const Sbecore::uint PREWZNMREFMDL = 222;
		static const Sbecore::uint PREWZNMREFMTB = 223;
		static const Sbecore::uint PREWZNMREFMTD = 224;
		static const Sbecore::uint PREWZNMREFOEN = 225;
		static const Sbecore::uint PREWZNMREFOPK = 226;
		static const Sbecore::uint PREWZNMREFOPX = 227;
		static const Sbecore::uint PREWZNMREFPNL = 228;
		static const Sbecore::uint PREWZNMREFPRJ = 229;
		static const Sbecore::uint PREWZNMREFPRS = 230;
		static const Sbecore::uint PREWZNMREFPST = 231;
		static const Sbecore::uint PREWZNMREFQCO = 232;
		static const Sbecore::uint PREWZNMREFQMD = 233;
		static const Sbecore::uint PREWZNMREFQRY = 234;
		static const Sbecore::uint PREWZNMREFQTB = 235;
		static const Sbecore::uint PREWZNMREFREL = 236;
		static const Sbecore::uint PREWZNMREFRLS = 237;
		static const Sbecore::uint PREWZNMREFRLT = 238;
		static const Sbecore::uint PREWZNMREFRTB = 239;
		static const Sbecore::uint PREWZNMREFRTD = 240;
		static const Sbecore::uint PREWZNMREFRTJ = 241;
		static const Sbecore::uint PREWZNMREFSBS = 242;
		static const Sbecore::uint PREWZNMREFSEL = 243;
		static const Sbecore::uint PREWZNMREFSEQ = 244;
		static const Sbecore::uint PREWZNMREFSES = 245;
		static const Sbecore::uint PREWZNMREFSGE = 246;
		static const Sbecore::uint PREWZNMREFSNS = 247;
		static const Sbecore::uint PREWZNMREFSQK = 248;
		static const Sbecore::uint PREWZNMREFSTB = 249;
		static const Sbecore::uint PREWZNMREFSTC = 250;
		static const Sbecore::uint PREWZNMREFSTE = 251;
		static const Sbecore::uint PREWZNMREFSTT = 252;
		static const Sbecore::uint PREWZNMREFTAG = 253;
		static const Sbecore::uint PREWZNMREFTBL = 254;
		static const Sbecore::uint PREWZNMREFTCO = 255;
		static const Sbecore::uint PREWZNMREFUSG = 256;
		static const Sbecore::uint PREWZNMREFUSR = 257;
		static const Sbecore::uint PREWZNMREFVEC = 258;
		static const Sbecore::uint PREWZNMREFVER = 259;
		static const Sbecore::uint PREWZNMREFVIT = 260;
		static const Sbecore::uint PREWZNMRELATITLE_X1 = 261;
		static const Sbecore::uint PREWZNMRELATITLE_X2 = 262;
		static const Sbecore::uint PREWZNMRELLIST_FRS = 263;
		static const Sbecore::uint PREWZNMRELLIST_FRT = 264;
		static const Sbecore::uint PREWZNMRELLIST_SRL = 265;
		static const Sbecore::uint PREWZNMRELLIST_SUP = 266;
		static const Sbecore::uint PREWZNMRELLIST_TBL = 267;
		static const Sbecore::uint PREWZNMRELLIST_TOS = 268;
		static const Sbecore::uint PREWZNMRELLIST_TOT = 269;
		static const Sbecore::uint PREWZNMRELLIST_TYP = 270;
		static const Sbecore::uint PREWZNMRELLIST_VER = 271;
		static const Sbecore::uint PREWZNMREPFOLDER = 272;
		static const Sbecore::uint PREWZNMRLSLIST_CMP = 273;
		static const Sbecore::uint PREWZNMRLSLIST_MCH = 274;
		static const Sbecore::uint PREWZNMRLSLIST_SRF = 275;
		static const Sbecore::uint PREWZNMRTJLIST_APP = 276;
		static const Sbecore::uint PREWZNMRTJLIST_JOB = 277;
		static const Sbecore::uint PREWZNMRTJLIST_SRF = 278;
		static const Sbecore::uint PREWZNMRTJLIST_SUP = 279;
		static const Sbecore::uint PREWZNMSBSATITLE_X1 = 280;
		static const Sbecore::uint PREWZNMSBSATITLE_X2 = 281;
		static const Sbecore::uint PREWZNMSBSLIST_SRF = 282;
		static const Sbecore::uint PREWZNMSBSLIST_TBL = 283;
		static const Sbecore::uint PREWZNMSEQLIST_APP = 284;
		static const Sbecore::uint PREWZNMSEQLIST_SRF = 285;
		static const Sbecore::uint PREWZNMSESS = 286;
		static const Sbecore::uint PREWZNMSGELIST_JOB = 287;
		static const Sbecore::uint PREWZNMSGELIST_SRF = 288;
		static const Sbecore::uint PREWZNMSGELIST_TYP = 289;
		static const Sbecore::uint PREWZNMSTBLIST_SBS = 290;
		static const Sbecore::uint PREWZNMSTBLIST_SRF = 291;
		static const Sbecore::uint PREWZNMSTBLIST_TBL = 292;
		static const Sbecore::uint PREWZNMSTBLIST_TYP = 293;
		static const Sbecore::uint PREWZNMSTELIST_SEQ = 294;
		static const Sbecore::uint PREWZNMSTELIST_SRF = 295;
		static const Sbecore::uint PREWZNMSUSPSESS = 296;
		static const Sbecore::uint PREWZNMSYSDATE = 297;
		static const Sbecore::uint PREWZNMSYSSTAMP = 298;
		static const Sbecore::uint PREWZNMSYSTIME = 299;
		static const Sbecore::uint PREWZNMTAGLIST_CPB = 300;
		static const Sbecore::uint PREWZNMTAGLIST_GRP = 301;
		static const Sbecore::uint PREWZNMTAGLIST_SRF = 302;
		static const Sbecore::uint PREWZNMTBLATITLE_X1 = 303;
		static const Sbecore::uint PREWZNMTBLATITLE_X2 = 304;
		static const Sbecore::uint PREWZNMTBLLIST_RET = 305;
		static const Sbecore::uint PREWZNMTBLLIST_REU = 306;
		static const Sbecore::uint PREWZNMTBLLIST_SRF = 307;
		static const Sbecore::uint PREWZNMTBLLIST_TYP = 308;
		static const Sbecore::uint PREWZNMTBLLIST_VER = 309;
		static const Sbecore::uint PREWZNMTCOATITLE_X1 = 310;
		static const Sbecore::uint PREWZNMTCOATITLE_X2 = 311;
		static const Sbecore::uint PREWZNMTCOLIST_FCT = 312;
		static const Sbecore::uint PREWZNMTCOLIST_SRF = 313;
		static const Sbecore::uint PREWZNMTCOLIST_TBL = 314;
		static const Sbecore::uint PREWZNMTCOLIST_TYP = 315;
		static const Sbecore::uint PREWZNMTLAST = 316;
		static const Sbecore::uint PREWZNMUSGAACCESS_X1 = 317;
		static const Sbecore::uint PREWZNMUSGAACCESS_X2 = 318;
		static const Sbecore::uint PREWZNMUSGLIST_GRP = 319;
		static const Sbecore::uint PREWZNMUSGLIST_OWN = 320;
		static const Sbecore::uint PREWZNMUSGLIST_SRF = 321;
		static const Sbecore::uint PREWZNMUSRAACCESS_X1 = 322;
		static const Sbecore::uint PREWZNMUSRAACCESS_X2 = 323;
		static const Sbecore::uint PREWZNMUSRLIST_GRP = 324;
		static const Sbecore::uint PREWZNMUSRLIST_OWN = 325;
		static const Sbecore::uint PREWZNMUSRLIST_PRS = 326;
		static const Sbecore::uint PREWZNMUSRLIST_SRF = 327;
		static const Sbecore::uint PREWZNMUSRLIST_USG = 328;
		static const Sbecore::uint PREWZNMVECATITLE_X1 = 329;
		static const Sbecore::uint PREWZNMVECATITLE_X2 = 330;
		static const Sbecore::uint PREWZNMVECLIST_HKT = 331;
		static const Sbecore::uint PREWZNMVECLIST_HKU = 332;
		static const Sbecore::uint PREWZNMVECLIST_SRF = 333;
		static const Sbecore::uint PREWZNMVECLIST_TGR = 334;
		static const Sbecore::uint PREWZNMVECLIST_TYP = 335;
		static const Sbecore::uint PREWZNMVECLIST_VER = 336;
		static const Sbecore::uint PREWZNMVERLIST_BVR = 337;
		static const Sbecore::uint PREWZNMVERLIST_GRP = 338;
		static const Sbecore::uint PREWZNMVERLIST_LOC = 339;
		static const Sbecore::uint PREWZNMVERLIST_OWN = 340;
		static const Sbecore::uint PREWZNMVERLIST_PRJ = 341;
		static const Sbecore::uint PREWZNMVERLIST_STE = 342;
		static const Sbecore::uint PREWZNMVITLIST_SRF = 343;
		static const Sbecore::uint PREWZNMVITLIST_VEC = 344;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

	/**
		* VecVRecaccess (full: VecWznmVRecaccess)
		*/
	class VecVRecaccess {

	public:
		static const Sbecore::uint FULL = 1;
		static const Sbecore::uint NONE = 2;
		static const Sbecore::uint VIEW = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVUserlevel (full: VecWznmVUserlevel)
		*/
	class VecVUserlevel {

	public:
		static const Sbecore::uint ADM = 1;
		static const Sbecore::uint GADM = 2;
		static const Sbecore::uint REG = 3;
		static const Sbecore::uint VTOR = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVValuelist (full: VecWznmVValuelist)
		*/
	class VecVValuelist {

	public:
		static const Sbecore::uint VLSTWZNMUMPERSONTITLE = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);
	};

	/**
		* VecVVartype (full: VecWznmVVartype)
		*/
	class VecVVartype {

	public:
		static const Sbecore::uint VOID = 1;
		static const Sbecore::uint BOOLEAN = 2;
		static const Sbecore::uint TINYINT = 3;
		static const Sbecore::uint UTINYINT = 4;
		static const Sbecore::uint SMALLINT = 5;
		static const Sbecore::uint USMALLINT = 6;
		static const Sbecore::uint INT = 7;
		static const Sbecore::uint UINT = 8;
		static const Sbecore::uint BIGINT = 9;
		static const Sbecore::uint UBIGINT = 10;
		static const Sbecore::uint FLOAT = 11;
		static const Sbecore::uint DOUBLE = 12;
		static const Sbecore::uint STRING = 13;
		static const Sbecore::uint BOOLEANVEC = 14;
		static const Sbecore::uint UTINYINTVEC = 15;
		static const Sbecore::uint USMALLINTVEC = 16;
		static const Sbecore::uint INTVEC = 17;
		static const Sbecore::uint UINTVEC = 18;
		static const Sbecore::uint UBIGINTVEC = 19;
		static const Sbecore::uint FLOATVEC = 20;
		static const Sbecore::uint DOUBLEVEC = 21;
		static const Sbecore::uint FLOATMAT = 22;
		static const Sbecore::uint DOUBLEMAT = 23;
		static const Sbecore::uint STRINGVEC = 24;
		static const Sbecore::uint VECSREF = 25;
		static const Sbecore::uint SCRREF = 26;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecWAccess (full: VecWznmWAccess)
		*/
	class VecWAccess {

	public:
		static const Sbecore::uint EDIT = 1;
		static const Sbecore::uint EXEC = 2;
		static const Sbecore::uint VIEW = 4;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecWArgtype (full: VecWznmWArgtype)
		*/
	class VecWArgtype {

	public:
		static const Sbecore::uint IX = 1;
		static const Sbecore::uint REF = 2;
		static const Sbecore::uint REFS = 4;
		static const Sbecore::uint SREF = 8;
		static const Sbecore::uint INTVAL = 16;
		static const Sbecore::uint DBLVAL = 32;
		static const Sbecore::uint BOOLVAL = 64;
		static const Sbecore::uint TXTVAL = 128;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* VecWScope (full: VecWznmWScope)
		*/
	class VecWScope {

	public:
		static const Sbecore::uint APP = 1;
		static const Sbecore::uint CMBENG = 2;
		static const Sbecore::uint ENG = 4;
		static const Sbecore::uint OPENG = 8;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

public:
	DbsWznm();
	~DbsWznm();

	void init(const Sbecore::uint _ixDbsVDbstype, const std::string& _dbspath, const std::string& _dbsname, const std::string& _ip, const Sbecore::uint _port, const std::string& _username, const std::string& _password);
	void term();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void initMy();
	void termMy();
#endif
#if defined(SBECORE_PG)
	void initPg();
	void termPg();
#endif

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	int port;

	bool initdone;

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	MYSQL* dbsMy;
#endif
#if defined(SBECORE_PG)
	PGconn* dbsPg;
#endif

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	void beginMy();
	bool commitMy();
	void rollbackMy();
#endif
#if defined(SBECORE_PG)
	void beginPg();
	bool commitPg();
	void rollbackPg();
#endif

	bool loadUintBySQL(const std::string& sqlstr, Sbecore::uint& val);		//!< execute a SQL query returning a single uint (arbitrary tables)
	bool loadStringBySQL(const std::string& sqlstr, std::string& val);//!< execute a SQL query returning a single string (arbitrary tables)

	bool loadRefBySQL(const std::string& sqlstr, Sbecore::ubigint& ref);	//!< execute a SQL query returning a single reference (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	Sbecore::ubigint loadRefsBySQL(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	bool loadUintBySQLMy(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLMy(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLMy(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLMy(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

#if defined(SBECORE_PG)
	bool loadUintBySQLPg(const std::string& sqlstr, Sbecore::uint& val);
	bool loadStringBySQLPg(const std::string& sqlstr, std::string& val);

	bool loadRefBySQLPg(const std::string& sqlstr, Sbecore::ubigint& ref);
	Sbecore::ubigint loadRefsBySQLPg(const std::string& sqlstr, const bool append, std::vector<Sbecore::ubigint>& refs);
#endif

	void executeQuery(const std::string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const std::string& sqlstrmy, const std::string& sqlstrpg);
	void executeFile(const std::string& fullpath);								//!< SQL file batch execution

public:
	Sbecore::uint getIxWSubsetByRefWznmMCall(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMCall(WznmMCall* rec);

	Sbecore::uint getIxWSubsetByRefWznmMCapability(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMCapability(WznmMCapability* rec);

	Sbecore::uint getIxWSubsetByRefWznmMComponent(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMComponent(WznmMComponent* rec);

	Sbecore::uint getIxWSubsetByRefWznmMControl(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMControl(WznmMControl* rec);

	Sbecore::uint getIxWSubsetByRefWznmMTable(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMTable(WznmMTable* rec);

	Sbecore::uint getIxWSubsetByRefWznmMTablecol(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMTablecol(WznmMTablecol* rec);

	Sbecore::uint getIxWSubsetByRefWznmMVector(const Sbecore::ubigint ref);
	Sbecore::uint getIxWSubsetByWznmMVector(WznmMVector* rec);

	void fillFeedFromKlst(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint x1IxWznmVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixWznmVLocale, Sbecore::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxWznmVKeylist, const std::string& sref, const Sbecore::uint ixWznmVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint x1IxWznmVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixWznmVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxWznmVValuelist, const Sbecore::uint x1IxWznmVLocale, Sbecore::Feed& feed);

public:
	TblWznmAccRMUserUniversal* tblwznmaccrmuseruniversal;
	TblWznmAMBlockItem* tblwznmamblockitem;
	TblWznmAMCapabilityPar* tblwznmamcapabilitypar;
	TblWznmAMControlPar* tblwznmamcontrolpar;
	TblWznmAMJobCmd* tblwznmamjobcmd;
	TblWznmAMJobVar* tblwznmamjobvar;
	TblWznmAMLibraryMakefile* tblwznmamlibrarymakefile;
	TblWznmAMLibraryPkglist* tblwznmamlibrarypkglist;
	TblWznmAMMachineMakefile* tblwznmammachinemakefile;
	TblWznmAMMachinePar* tblwznmammachinepar;
	TblWznmAMMethodInvpar* tblwznmammethodinvpar;
	TblWznmAMMethodRetpar* tblwznmammethodretpar;
	TblWznmAMOpInvarg* tblwznmamopinvarg;
	TblWznmAMOppackInvarg* tblwznmamoppackinvarg;
	TblWznmAMOppackRetval* tblwznmamoppackretval;
	TblWznmAMOpRetval* tblwznmamopretval;
	TblWznmAMPersonDetail* tblwznmampersondetail;
	TblWznmAMQueryClause* tblwznmamqueryclause;
	TblWznmAMQueryOrder* tblwznmamqueryorder;
	TblWznmAMRelationTitle* tblwznmamrelationtitle;
	TblWznmAMStateAction* tblwznmamstateaction;
	TblWznmAMStateTrig* tblwznmamstatetrig;
	TblWznmAMSubsetTitle* tblwznmamsubsettitle;
	TblWznmAMTablecolTitle* tblwznmamtablecoltitle;
	TblWznmAMTableLoadfct* tblwznmamtableloadfct;
	TblWznmAMTableTitle* tblwznmamtabletitle;
	TblWznmAMUserAccess* tblwznmamuseraccess;
	TblWznmAMUsergroupAccess* tblwznmamusergroupaccess;
	TblWznmAMVectorTitle* tblwznmamvectortitle;
	TblWznmAVControlPar* tblwznmavcontrolpar;
	TblWznmAVKeylistKey* tblwznmavkeylistkey;
	TblWznmAVValuelistVal* tblwznmavvaluelistval;
	TblWznmCAMBlockItem* tblwznmcamblockitem;
	TblWznmCAMJobVar* tblwznmcamjobvar;
	TblWznmCAMOpInvarg* tblwznmcamopinvarg;
	TblWznmCAMOppackInvarg* tblwznmcamoppackinvarg;
	TblWznmCAMOppackRetval* tblwznmcamoppackretval;
	TblWznmCAMOpRetval* tblwznmcamopretval;
	TblWznmCControl* tblwznmccontrol;
	TblWznmCFile* tblwznmcfile;
	TblWznmCRelation* tblwznmcrelation;
	TblWznmHistRMUserUniversal* tblwznmhistrmuseruniversal;
	TblWznmJAMBlockItem* tblwznmjamblockitem;
	TblWznmJAMStateTrigCond* tblwznmjamstatetrigcond;
	TblWznmJAVKeylistKey* tblwznmjavkeylistkey;
	TblWznmJMCardTitle* tblwznmjmcardtitle;
	TblWznmJMControl* tblwznmjmcontrol;
	TblWznmJMControlTitle* tblwznmjmcontroltitle;
	TblWznmJMErrorTitle* tblwznmjmerrortitle;
	TblWznmJMImpexpcolStub* tblwznmjmimpexpcolstub;
	TblWznmJMImpexpcplxTitle* tblwznmjmimpexpcplxtitle;
	TblWznmJMLocaleTitle* tblwznmjmlocaletitle;
	TblWznmJMModule* tblwznmjmmodule;
	TblWznmJMPersonLastname* tblwznmjmpersonlastname;
	TblWznmJMPresetTitle* tblwznmjmpresettitle;
	TblWznmJMQuerycolStub* tblwznmjmquerycolstub;
	TblWznmJMSquawkTitle* tblwznmjmsquawktitle;
	TblWznmJMTagTitle* tblwznmjmtagtitle;
	TblWznmJMUserState* tblwznmjmuserstate;
	TblWznmJMVectoritem* tblwznmjmvectoritem;
	TblWznmJMVersion* tblwznmjmversion;
	TblWznmJMVersionState* tblwznmjmversionstate;
	TblWznmMApp* tblwznmmapp;
	TblWznmMBlock* tblwznmmblock;
	TblWznmMCall* tblwznmmcall;
	TblWznmMCapability* tblwznmmcapability;
	TblWznmMCard* tblwznmmcard;
	TblWznmMCheck* tblwznmmcheck;
	TblWznmMComponent* tblwznmmcomponent;
	TblWznmMControl* tblwznmmcontrol;
	TblWznmMDialog* tblwznmmdialog;
	TblWznmMError* tblwznmmerror;
	TblWznmMEvent* tblwznmmevent;
	TblWznmMFeed* tblwznmmfeed;
	TblWznmMFile* tblwznmmfile;
	TblWznmMImpexp* tblwznmmimpexp;
	TblWznmMImpexpcol* tblwznmmimpexpcol;
	TblWznmMImpexpcplx* tblwznmmimpexpcplx;
	TblWznmMJob* tblwznmmjob;
	TblWznmMLibrary* tblwznmmlibrary;
	TblWznmMLocale* tblwznmmlocale;
	TblWznmMMachine* tblwznmmmachine;
	TblWznmMMethod* tblwznmmmethod;
	TblWznmMModule* tblwznmmmodule;
	TblWznmMOp* tblwznmmop;
	TblWznmMOppack* tblwznmmoppack;
	TblWznmMPanel* tblwznmmpanel;
	TblWznmMPerson* tblwznmmperson;
	TblWznmMPreset* tblwznmmpreset;
	TblWznmMProject* tblwznmmproject;
	TblWznmMQuery* tblwznmmquery;
	TblWznmMQuerycol* tblwznmmquerycol;
	TblWznmMQuerymod* tblwznmmquerymod;
	TblWznmMRelation* tblwznmmrelation;
	TblWznmMRelease* tblwznmmrelease;
	TblWznmMRtblock* tblwznmmrtblock;
	TblWznmMRtdpch* tblwznmmrtdpch;
	TblWznmMRtjob* tblwznmmrtjob;
	TblWznmMSensitivity* tblwznmmsensitivity;
	TblWznmMSequence* tblwznmmsequence;
	TblWznmMSession* tblwznmmsession;
	TblWznmMSquawk* tblwznmmsquawk;
	TblWznmMStage* tblwznmmstage;
	TblWznmMState* tblwznmmstate;
	TblWznmMStub* tblwznmmstub;
	TblWznmMSubset* tblwznmmsubset;
	TblWznmMTable* tblwznmmtable;
	TblWznmMTablecol* tblwznmmtablecol;
	TblWznmMTag* tblwznmmtag;
	TblWznmMUser* tblwznmmuser;
	TblWznmMUsergroup* tblwznmmusergroup;
	TblWznmMVector* tblwznmmvector;
	TblWznmMVectoritem* tblwznmmvectoritem;
	TblWznmMVersion* tblwznmmversion;
	TblWznmRMCallMStub* tblwznmrmcallmstub;
	TblWznmRMCapabilityUniversal* tblwznmrmcapabilityuniversal;
	TblWznmRMComponentMLibrary* tblwznmrmcomponentmlibrary;
	TblWznmRMComponentMOppack* tblwznmrmcomponentmoppack;
	TblWznmRMDialogMQuery* tblwznmrmdialogmquery;
	TblWznmRMJobMJob* tblwznmrmjobmjob;
	TblWznmRMJobMOp* tblwznmrmjobmop;
	TblWznmRMJobMOppack* tblwznmrmjobmoppack;
	TblWznmRMLibraryMOppack* tblwznmrmlibrarymoppack;
	TblWznmRMLocaleMVersion* tblwznmrmlocalemversion;
	TblWznmRMPanelMQuery* tblwznmrmpanelmquery;
	TblWznmRMPersonMProject* tblwznmrmpersonmproject;
	TblWznmRMQueryMTable* tblwznmrmquerymtable;
	TblWznmRMSquawkMStub* tblwznmrmsquawkmstub;
	TblWznmRMStubMStub* tblwznmrmstubmstub;
	TblWznmRMSubsetMSubset* tblwznmrmsubsetmsubset;
	TblWznmRMTableMVector* tblwznmrmtablemvector;
	TblWznmRMUsergroupUniversal* tblwznmrmusergroupuniversal;
	TblWznmRMUserMUsergroup* tblwznmrmusermusergroup;
	TblWznmTMQuerymodMQuery* tblwznmtmquerymodmquery;

	TblWznmQApp1NEvent* tblwznmqapp1nevent;
	TblWznmQApp1NRtjob* tblwznmqapp1nrtjob;
	TblWznmQAppApp1NSequence* tblwznmqappapp1nsequence;
	TblWznmQAppList* tblwznmqapplist;
	TblWznmQAppRef1NFile* tblwznmqappref1nfile;
	TblWznmQBlk1NRtdpch* tblwznmqblk1nrtdpch;
	TblWznmQBlkAItem* tblwznmqblkaitem;
	TblWznmQBlkList* tblwznmqblklist;
	TblWznmQBlkRef1NRtblock* tblwznmqblkref1nrtblock;
	TblWznmQCal1NSensitivity* tblwznmqcal1nsensitivity;
	TblWznmQCalList* tblwznmqcallist;
	TblWznmQCalMNStub* tblwznmqcalmnstub;
	TblWznmQCapAPar* tblwznmqcapapar;
	TblWznmQCapList* tblwznmqcaplist;
	TblWznmQCar1NDialog* tblwznmqcar1ndialog;
	TblWznmQCarCar1NPanel* tblwznmqcarcar1npanel;
	TblWznmQCarHk1NControl* tblwznmqcarhk1ncontrol;
	TblWznmQCarList* tblwznmqcarlist;
	TblWznmQChkList* tblwznmqchklist;
	TblWznmQChkRef1NCall* tblwznmqchkref1ncall;
	TblWznmQCmp1NRelease* tblwznmqcmp1nrelease;
	TblWznmQCmpList* tblwznmqcmplist;
	TblWznmQCmpMNLibrary* tblwznmqcmpmnlibrary;
	TblWznmQCmpMNOppack* tblwznmqcmpmnoppack;
	TblWznmQConAPar* tblwznmqconapar;
	TblWznmQConFedRef1NRtblock* tblwznmqconfedref1nrtblock;
	TblWznmQConList* tblwznmqconlist;
	TblWznmQConSup1NControl* tblwznmqconsup1ncontrol;
	TblWznmQCtp1NTag* tblwznmqctp1ntag;
	TblWznmQCtpAPar* tblwznmqctpapar;
	TblWznmQCtpKKey* tblwznmqctpkkey;
	TblWznmQCtpKParKey* tblwznmqctpkparkey;
	TblWznmQCtpList* tblwznmqctplist;
	TblWznmQCtpTpl1NCapability* tblwznmqctptpl1ncapability;
	TblWznmQDlgHk1NControl* tblwznmqdlghk1ncontrol;
	TblWznmQDlgList* tblwznmqdlglist;
	TblWznmQDlgMNQuery* tblwznmqdlgmnquery;
	TblWznmQDlgRef1NControl* tblwznmqdlgref1ncontrol;
	TblWznmQErrList* tblwznmqerrlist;
	TblWznmQEvtList* tblwznmqevtlist;
	TblWznmQFilList* tblwznmqfillist;
	TblWznmQIelList* tblwznmqiellist;
	TblWznmQIex1NImpexp* tblwznmqiex1nimpexp;
	TblWznmQIexHk1NVector* tblwznmqiexhk1nvector;
	TblWznmQIexList* tblwznmqiexlist;
	TblWznmQIexRef1NDialog* tblwznmqiexref1ndialog;
	TblWznmQImeHk1NVector* tblwznmqimehk1nvector;
	TblWznmQImeIme1NImpexpcol* tblwznmqimeime1nimpexpcol;
	TblWznmQImeList* tblwznmqimelist;
	TblWznmQImeSup1NImpexp* tblwznmqimesup1nimpexp;
	TblWznmQJob1NMethod* tblwznmqjob1nmethod;
	TblWznmQJob1NRtjob* tblwznmqjob1nrtjob;
	TblWznmQJob1NSensitivity* tblwznmqjob1nsensitivity;
	TblWznmQJobACmd* tblwznmqjobacmd;
	TblWznmQJobAVar* tblwznmqjobavar;
	TblWznmQJobHk1NVector* tblwznmqjobhk1nvector;
	TblWznmQJobJob1NStage* tblwznmqjobjob1nstage;
	TblWznmQJobList* tblwznmqjoblist;
	TblWznmQJobMNOp* tblwznmqjobmnop;
	TblWznmQJobMNOppack* tblwznmqjobmnoppack;
	TblWznmQJobRef1NBlock* tblwznmqjobref1nblock;
	TblWznmQJobSubMNJob* tblwznmqjobsubmnjob;
	TblWznmQJobSupMNJob* tblwznmqjobsupmnjob;
	TblWznmQLibAMakefile* tblwznmqlibamakefile;
	TblWznmQLibAPkglist* tblwznmqlibapkglist;
	TblWznmQLibList* tblwznmqliblist;
	TblWznmQLibMNComponent* tblwznmqlibmncomponent;
	TblWznmQLibMNOppack* tblwznmqlibmnoppack;
	TblWznmQLibRef1NFile* tblwznmqlibref1nfile;
	TblWznmQLocList* tblwznmqloclist;
	TblWznmQLocMNVersion* tblwznmqlocmnversion;
	TblWznmQMch1NRelease* tblwznmqmch1nrelease;
	TblWznmQMchAMakefile* tblwznmqmchamakefile;
	TblWznmQMchAPar* tblwznmqmchapar;
	TblWznmQMchList* tblwznmqmchlist;
	TblWznmQMchSup1NMachine* tblwznmqmchsup1nmachine;
	TblWznmQMdlList* tblwznmqmdllist;
	TblWznmQMdlMdl1NCard* tblwznmqmdlmdl1ncard;
	TblWznmQMdlRef1NPanel* tblwznmqmdlref1npanel;
	TblWznmQMtdAInvpar* tblwznmqmtdainvpar;
	TblWznmQMtdARetpar* tblwznmqmtdaretpar;
	TblWznmQMtdList* tblwznmqmtdlist;
	TblWznmQOpk1NOp* tblwznmqopk1nop;
	TblWznmQOpkAInvarg* tblwznmqopkainvarg;
	TblWznmQOpkARetval* tblwznmqopkaretval;
	TblWznmQOpkList* tblwznmqopklist;
	TblWznmQOpkMNComponent* tblwznmqopkmncomponent;
	TblWznmQOpkMNJob* tblwznmqopkmnjob;
	TblWznmQOpkMNLibrary* tblwznmqopkmnlibrary;
	TblWznmQOpkRef1NBlock* tblwznmqopkref1nblock;
	TblWznmQOpkSqkMNStub* tblwznmqopksqkmnstub;
	TblWznmQOpxAInvarg* tblwznmqopxainvarg;
	TblWznmQOpxARetval* tblwznmqopxaretval;
	TblWznmQOpxList* tblwznmqopxlist;
	TblWznmQOpxMNJob* tblwznmqopxmnjob;
	TblWznmQOpxRef1NBlock* tblwznmqopxref1nblock;
	TblWznmQOpxSqkMNStub* tblwznmqopxsqkmnstub;
	TblWznmQPnlHk1NControl* tblwznmqpnlhk1ncontrol;
	TblWznmQPnlList* tblwznmqpnllist;
	TblWznmQPnlMNQuery* tblwznmqpnlmnquery;
	TblWznmQPreselect* tblwznmqpreselect;
	TblWznmQPrjList* tblwznmqprjlist;
	TblWznmQPrjMNPerson* tblwznmqprjmnperson;
	TblWznmQPrjPrj1NVersion* tblwznmqprjprj1nversion;
	TblWznmQPrsADetail* tblwznmqprsadetail;
	TblWznmQPrsList* tblwznmqprslist;
	TblWznmQPrsMNProject* tblwznmqprsmnproject;
	TblWznmQPst1NQuerymod* tblwznmqpst1nquerymod;
	TblWznmQPstList* tblwznmqpstlist;
	TblWznmQQcoList* tblwznmqqcolist;
	TblWznmQQcoRef1NControl* tblwznmqqcoref1ncontrol;
	TblWznmQQmdList* tblwznmqqmdlist;
	TblWznmQQry1NQuerymod* tblwznmqqry1nquerymod;
	TblWznmQQryAClause* tblwznmqqryaclause;
	TblWznmQQryAOrder* tblwznmqqryaorder;
	TblWznmQQryList* tblwznmqqrylist;
	TblWznmQQryMNDialog* tblwznmqqrymndialog;
	TblWznmQQryMNPanel* tblwznmqqrymnpanel;
	TblWznmQQryMNTable* tblwznmqqrymntable;
	TblWznmQQryQry1NQuerycol* tblwznmqqryqry1nquerycol;
	TblWznmQQrySup1NQuery* tblwznmqqrysup1nquery;
	TblWznmQRel1NTablecol* tblwznmqrel1ntablecol;
	TblWznmQRelATitle* tblwznmqrelatitle;
	TblWznmQRelList* tblwznmqrellist;
	TblWznmQRelRef1NControl* tblwznmqrelref1ncontrol;
	TblWznmQRelRef1NDialog* tblwznmqrelref1ndialog;
	TblWznmQRelRef1NPanel* tblwznmqrelref1npanel;
	TblWznmQRelSup1NRelation* tblwznmqrelsup1nrelation;
	TblWznmQRlsList* tblwznmqrlslist;
	TblWznmQRtj1NRtblock* tblwznmqrtj1nrtblock;
	TblWznmQRtj1NRtdpch* tblwznmqrtj1nrtdpch;
	TblWznmQRtjList* tblwznmqrtjlist;
	TblWznmQRtjSup1NRtjob* tblwznmqrtjsup1nrtjob;
	TblWznmQSbs1NStub* tblwznmqsbs1nstub;
	TblWznmQSbs1NTablecol* tblwznmqsbs1ntablecol;
	TblWznmQSbsAsbMNSubset* tblwznmqsbsasbmnsubset;
	TblWznmQSbsATitle* tblwznmqsbsatitle;
	TblWznmQSbsBsbMNSubset* tblwznmqsbsbsbmnsubset;
	TblWznmQSbsFrs1NRelation* tblwznmqsbsfrs1nrelation;
	TblWznmQSbsList* tblwznmqsbslist;
	TblWznmQSbsPst1NQuerymod* tblwznmqsbspst1nquerymod;
	TblWznmQSbsTos1NRelation* tblwznmqsbstos1nrelation;
	TblWznmQSelect* tblwznmqselect;
	TblWznmQSeqList* tblwznmqseqlist;
	TblWznmQSeqSeq1NState* tblwznmqseqseq1nstate;
	TblWznmQSge1NSensitivity* tblwznmqsge1nsensitivity;
	TblWznmQSgeList* tblwznmqsgelist;
	TblWznmQSgeSqkMNStub* tblwznmqsgesqkmnstub;
	TblWznmQStbList* tblwznmqstblist;
	TblWznmQStbMNCall* tblwznmqstbmncall;
	TblWznmQStbMNSquawk* tblwznmqstbmnsquawk;
	TblWznmQStbSubMNStub* tblwznmqstbsubmnstub;
	TblWznmQStbSupMNStub* tblwznmqstbsupmnstub;
	TblWznmQSteAAction* tblwznmqsteaaction;
	TblWznmQSteATrig* tblwznmqsteatrig;
	TblWznmQSteList* tblwznmqstelist;
	TblWznmQTagList* tblwznmqtaglist;
	TblWznmQTbl1NCheck* tblwznmqtbl1ncheck;
	TblWznmQTbl1NImpexp* tblwznmqtbl1nimpexp;
	TblWznmQTbl1NStub* tblwznmqtbl1nstub;
	TblWznmQTbl1NSubset* tblwznmqtbl1nsubset;
	TblWznmQTblALoadfct* tblwznmqtblaloadfct;
	TblWznmQTblATitle* tblwznmqtblatitle;
	TblWznmQTblFct1NTablecol* tblwznmqtblfct1ntablecol;
	TblWznmQTblFr1NRelation* tblwznmqtblfr1nrelation;
	TblWznmQTblHk1NVector* tblwznmqtblhk1nvector;
	TblWznmQTblList* tblwznmqtbllist;
	TblWznmQTblMNQuery* tblwznmqtblmnquery;
	TblWznmQTblMNVector* tblwznmqtblmnvector;
	TblWznmQTblPst1NQuerymod* tblwznmqtblpst1nquerymod;
	TblWznmQTblRef1NCall* tblwznmqtblref1ncall;
	TblWznmQTblRef1NDialog* tblwznmqtblref1ndialog;
	TblWznmQTblRef1NPanel* tblwznmqtblref1npanel;
	TblWznmQTblRef1NQuerymod* tblwznmqtblref1nquerymod;
	TblWznmQTblRef1NRtblock* tblwznmqtblref1nrtblock;
	TblWznmQTblSrc1NFeed* tblwznmqtblsrc1nfeed;
	TblWznmQTblTbl1NTablecol* tblwznmqtbltbl1ntablecol;
	TblWznmQTblTo1NRelation* tblwznmqtblto1nrelation;
	TblWznmQTco1NCheck* tblwznmqtco1ncheck;
	TblWznmQTco1NImpexpcol* tblwznmqtco1nimpexpcol;
	TblWznmQTco1NQuerycol* tblwznmqtco1nquerycol;
	TblWznmQTcoATitle* tblwznmqtcoatitle;
	TblWznmQTcoList* tblwznmqtcolist;
	TblWznmQTcoRef1NControl* tblwznmqtcoref1ncontrol;
	TblWznmQTcoRef1NQuerymod* tblwznmqtcoref1nquerymod;
	TblWznmQUsgAAccess* tblwznmqusgaaccess;
	TblWznmQUsgList* tblwznmqusglist;
	TblWznmQUsgMNUser* tblwznmqusgmnuser;
	TblWznmQUsr1NSession* tblwznmqusr1nsession;
	TblWznmQUsrAAccess* tblwznmqusraaccess;
	TblWznmQUsrList* tblwznmqusrlist;
	TblWznmQUsrMNUsergroup* tblwznmqusrmnusergroup;
	TblWznmQVecATitle* tblwznmqvecatitle;
	TblWznmQVecFct1NTablecol* tblwznmqvecfct1ntablecol;
	TblWznmQVecList* tblwznmqveclist;
	TblWznmQVecMNTable* tblwznmqvecmntable;
	TblWznmQVecPst1NQuerymod* tblwznmqvecpst1nquerymod;
	TblWznmQVecRef1NPanel* tblwznmqvecref1npanel;
	TblWznmQVecSrc1NFeed* tblwznmqvecsrc1nfeed;
	TblWznmQVecVec1NVectoritem* tblwznmqvecvec1nvectoritem;
	TblWznmQVer1NBlock* tblwznmqver1nblock;
	TblWznmQVer1NCall* tblwznmqver1ncall;
	TblWznmQVer1NCapability* tblwznmqver1ncapability;
	TblWznmQVer1NComponent* tblwznmqver1ncomponent;
	TblWznmQVer1NImpexpcplx* tblwznmqver1nimpexpcplx;
	TblWznmQVer1NJob* tblwznmqver1njob;
	TblWznmQVer1NOppack* tblwznmqver1noppack;
	TblWznmQVer1NPreset* tblwznmqver1npreset;
	TblWznmQVer1NQuery* tblwznmqver1nquery;
	TblWznmQVer1NRelation* tblwznmqver1nrelation;
	TblWznmQVer1NTable* tblwznmqver1ntable;
	TblWznmQVer1NVector* tblwznmqver1nvector;
	TblWznmQVerBvr1NVersion* tblwznmqverbvr1nversion;
	TblWznmQVerList* tblwznmqverlist;
	TblWznmQVerMNLocale* tblwznmqvermnlocale;
	TblWznmQVerRef1NFile* tblwznmqverref1nfile;
	TblWznmQVerVer1NApp* tblwznmqverver1napp;
	TblWznmQVerVer1NError* tblwznmqverver1nerror;
	TblWznmQVerVer1NModule* tblwznmqverver1nmodule;
	TblWznmQVitList* tblwznmqvitlist;
};
#endif
