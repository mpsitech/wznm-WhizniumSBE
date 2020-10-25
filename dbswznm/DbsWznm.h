/**
	* \file DbsWznm.h
	* C++ wrapper for database DbsWznm (declarations)
	* \author Alexander Wirthmueller
	* \date created: 27 Aug 2020
	* \date modified: 27 Aug 2020
	*/

#ifndef DBSWZNM_H
#define DBSWZNM_H

#define WZNM_VERSION "1.0.7"
#define WZNM_VERSION_MAJOR 1
#define WZNM_VERSION_MINOR 0
#define WZNM_VERSION_SUB 7

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
#include "WznmAMMachinePar.h"
#include "WznmAMMachtypeMakefile.h"
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
#include "WznmMMachtype.h"
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
#include "WznmQMchAPar.h"
#include "WznmQMchList.h"
#include "WznmQMdlList.h"
#include "WznmQMdlMdl1NCard.h"
#include "WznmQMdlRef1NPanel.h"
#include "WznmQMtdAInvpar.h"
#include "WznmQMtdARetpar.h"
#include "WznmQMtdList.h"
#include "WznmQMty1NMachine.h"
#include "WznmQMtyAMakefile.h"
#include "WznmQMtyList.h"
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
#include "WznmQPrj1NVersion.h"
#include "WznmQPrjList.h"
#include "WznmQPrjMNPerson.h"
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
#define VecWznmWCloudtype DbsWznm::VecWCloudtype
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
		static const Sbecore::uint COCOA_OBJC = 1;
		static const Sbecore::uint DOTNET_CPPCLI = 2;
		static const Sbecore::uint JAVA = 3;
		static const Sbecore::uint JS = 4;
		static const Sbecore::uint POSIX_CPP = 5;
		static const Sbecore::uint WINRT_CPP = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
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
		static const Sbecore::uint CRDWZNMMTY = 9;
		static const Sbecore::uint CRDWZNMMCH = 10;
		static const Sbecore::uint CRDWZNMLIB = 11;
		static const Sbecore::uint CRDWZNMPRJ = 12;
		static const Sbecore::uint CRDWZNMVER = 13;
		static const Sbecore::uint CRDWZNMCAP = 14;
		static const Sbecore::uint CRDWZNMERR = 15;
		static const Sbecore::uint CRDWZNMTBL = 16;
		static const Sbecore::uint CRDWZNMTCO = 17;
		static const Sbecore::uint CRDWZNMSBS = 18;
		static const Sbecore::uint CRDWZNMREL = 19;
		static const Sbecore::uint CRDWZNMVEC = 20;
		static const Sbecore::uint CRDWZNMVIT = 21;
		static const Sbecore::uint CRDWZNMCHK = 22;
		static const Sbecore::uint CRDWZNMSTB = 23;
		static const Sbecore::uint CRDWZNMIEX = 24;
		static const Sbecore::uint CRDWZNMIME = 25;
		static const Sbecore::uint CRDWZNMIEL = 26;
		static const Sbecore::uint CRDWZNMPST = 27;
		static const Sbecore::uint CRDWZNMMDL = 28;
		static const Sbecore::uint CRDWZNMCAR = 29;
		static const Sbecore::uint CRDWZNMDLG = 30;
		static const Sbecore::uint CRDWZNMPNL = 31;
		static const Sbecore::uint CRDWZNMQRY = 32;
		static const Sbecore::uint CRDWZNMQCO = 33;
		static const Sbecore::uint CRDWZNMQMD = 34;
		static const Sbecore::uint CRDWZNMCON = 35;
		static const Sbecore::uint CRDWZNMOPK = 36;
		static const Sbecore::uint CRDWZNMOPX = 37;
		static const Sbecore::uint CRDWZNMJOB = 38;
		static const Sbecore::uint CRDWZNMSGE = 39;
		static const Sbecore::uint CRDWZNMMTD = 40;
		static const Sbecore::uint CRDWZNMBLK = 41;
		static const Sbecore::uint CRDWZNMCAL = 42;
		static const Sbecore::uint CRDWZNMCMP = 43;
		static const Sbecore::uint CRDWZNMRLS = 44;
		static const Sbecore::uint CRDWZNMAPP = 45;
		static const Sbecore::uint CRDWZNMRTJ = 46;
		static const Sbecore::uint CRDWZNMEVT = 47;
		static const Sbecore::uint CRDWZNMSEQ = 48;
		static const Sbecore::uint CRDWZNMSTE = 49;
		static const Sbecore::uint CRDWZNMUTL = 50;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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
		static const Sbecore::uint PNLWZNMCTP1NTAG_TCOREF = 70;
		static const Sbecore::uint PNLWZNMCTPTPL1NCAPABILITY_TCOREF = 71;
		static const Sbecore::uint PNLWZNMMTYLIST_TCOSRF = 72;
		static const Sbecore::uint PNLWZNMMTYLIST_TCOACH = 73;
		static const Sbecore::uint PNLWZNMMTYLIST_TCOOS = 74;
		static const Sbecore::uint PNLWZNMMTYAMAKEFILE_TCOTAG = 75;
		static const Sbecore::uint PNLWZNMMTYAMAKEFILE_TCOVAL = 76;
		static const Sbecore::uint PNLWZNMMTY1NMACHINE_TCOREF = 77;
		static const Sbecore::uint PNLWZNMMCHLIST_TCOSRF = 78;
		static const Sbecore::uint PNLWZNMMCHLIST_TCOTBL = 79;
		static const Sbecore::uint PNLWZNMMCHAPAR_TCOKEY = 80;
		static const Sbecore::uint PNLWZNMMCHAPAR_TCOVAL = 81;
		static const Sbecore::uint PNLWZNMMCH1NRELEASE_TCOREF = 82;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOSRF = 83;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOTIT = 84;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOVER = 85;
		static const Sbecore::uint PNLWZNMLIBLIST_TCOLTY = 86;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOREU = 87;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOTAG = 88;
		static const Sbecore::uint PNLWZNMLIBAMAKEFILE_TCOVAL = 89;
		static const Sbecore::uint PNLWZNMLIBAPKGLIST_TCOREU = 90;
		static const Sbecore::uint PNLWZNMLIBAPKGLIST_TCOPKL = 91;
		static const Sbecore::uint PNLWZNMLIBREF1NFILE_TCOREF = 92;
		static const Sbecore::uint PNLWZNMLIBMNOPPACK_TCOMREF = 93;
		static const Sbecore::uint PNLWZNMLIBMNCOMPONENT_TCOMREF = 94;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOGRP = 95;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOOWN = 96;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOSHO = 97;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOTIT = 98;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOVER = 99;
		static const Sbecore::uint PNLWZNMPRJLIST_TCOGRL = 100;
		static const Sbecore::uint PNLWZNMPRJ1NVERSION_TCOREF = 101;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOMREF = 102;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOSTA = 103;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOSTO = 104;
		static const Sbecore::uint PNLWZNMPRJMNPERSON_TCOFCT = 105;
		static const Sbecore::uint PNLWZNMVERLIST_TCOGRP = 106;
		static const Sbecore::uint PNLWZNMVERLIST_TCOOWN = 107;
		static const Sbecore::uint PNLWZNMVERLIST_TCOPRJ = 108;
		static const Sbecore::uint PNLWZNMVERLIST_TCOMAJ = 109;
		static const Sbecore::uint PNLWZNMVERLIST_TCOMIN = 110;
		static const Sbecore::uint PNLWZNMVERLIST_TCOSUB = 111;
		static const Sbecore::uint PNLWZNMVERLIST_TCOBVR = 112;
		static const Sbecore::uint PNLWZNMVERLIST_TCOLOC = 113;
		static const Sbecore::uint PNLWZNMVERLIST_TCOSTE = 114;
		static const Sbecore::uint PNLWZNMVERLIST_TCODTY = 115;
		static const Sbecore::uint PNLWZNMVER1NBLOCK_TCOREF = 116;
		static const Sbecore::uint PNLWZNMVERBVR1NVERSION_TCOREF = 117;
		static const Sbecore::uint PNLWZNMVER1NCOMPONENT_TCOREF = 118;
		static const Sbecore::uint PNLWZNMVER1NCALL_TCOREF = 119;
		static const Sbecore::uint PNLWZNMVER1NIMPEXPCPLX_TCOREF = 120;
		static const Sbecore::uint PNLWZNMVER1NJOB_TCOREF = 121;
		static const Sbecore::uint PNLWZNMVER1NOPPACK_TCOREF = 122;
		static const Sbecore::uint PNLWZNMVERVER1NMODULE_TCOREF = 123;
		static const Sbecore::uint PNLWZNMVER1NPRESET_TCOREF = 124;
		static const Sbecore::uint PNLWZNMVER1NQUERY_TCOREF = 125;
		static const Sbecore::uint PNLWZNMVER1NRELATION_TCOREF = 126;
		static const Sbecore::uint PNLWZNMVER1NTABLE_TCOREF = 127;
		static const Sbecore::uint PNLWZNMVER1NVECTOR_TCOREF = 128;
		static const Sbecore::uint PNLWZNMVER1NCAPABILITY_TCOREF = 129;
		static const Sbecore::uint PNLWZNMVERVER1NAPP_TCOREF = 130;
		static const Sbecore::uint PNLWZNMVERVER1NERROR_TCOREF = 131;
		static const Sbecore::uint PNLWZNMVERREF1NFILE_TCOREF = 132;
		static const Sbecore::uint PNLWZNMVERMNLOCALE_TCOMREF = 133;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOSRF = 134;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOTIT = 135;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOVER = 136;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOTPL = 137;
		static const Sbecore::uint PNLWZNMCAPLIST_TCOATF = 138;
		static const Sbecore::uint PNLWZNMCAPAPAR_TCOKEY = 139;
		static const Sbecore::uint PNLWZNMCAPAPAR_TCOVAL = 140;
		static const Sbecore::uint PNLWZNMERRLIST_TCOSRF = 141;
		static const Sbecore::uint PNLWZNMERRLIST_TCOTIT = 142;
		static const Sbecore::uint PNLWZNMERRLIST_TCOVER = 143;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOSRF = 144;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOSHO = 145;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOTYP = 146;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOVER = 147;
		static const Sbecore::uint PNLWZNMTBLLIST_TCORET = 148;
		static const Sbecore::uint PNLWZNMTBLLIST_TCOREU = 149;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLOT = 150;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOFNA = 151;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLDX = 152;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLBY = 153;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOORD = 154;
		static const Sbecore::uint PNLWZNMTBLALOADFCT_TCOLIT = 155;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOTYP = 156;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOLOC = 157;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOGND = 158;
		static const Sbecore::uint PNLWZNMTBLATITLE_TCOTIT = 159;
		static const Sbecore::uint PNLWZNMTBL1NIMPEXP_TCOREF = 160;
		static const Sbecore::uint PNLWZNMTBL1NCHECK_TCOREF = 161;
		static const Sbecore::uint PNLWZNMTBLFR1NRELATION_TCOREF = 162;
		static const Sbecore::uint PNLWZNMTBLTO1NRELATION_TCOREF = 163;
		static const Sbecore::uint PNLWZNMTBL1NSTUB_TCOREF = 164;
		static const Sbecore::uint PNLWZNMTBL1NSUBSET_TCOREF = 165;
		static const Sbecore::uint PNLWZNMTBLTBL1NTABLECOL_TCOREF = 166;
		static const Sbecore::uint PNLWZNMTBLREF1NDIALOG_TCOREF = 167;
		static const Sbecore::uint PNLWZNMTBLREF1NCALL_TCOREF = 168;
		static const Sbecore::uint PNLWZNMTBLSRC1NFEED_TCOREF = 169;
		static const Sbecore::uint PNLWZNMTBLREF1NPANEL_TCOREF = 170;
		static const Sbecore::uint PNLWZNMTBLFCT1NTABLECOL_TCOREF = 171;
		static const Sbecore::uint PNLWZNMTBLHK1NVECTOR_TCOREF = 172;
		static const Sbecore::uint PNLWZNMTBLREF1NQUERYMOD_TCOREF = 173;
		static const Sbecore::uint PNLWZNMTBLREF1NRTBLOCK_TCOREF = 174;
		static const Sbecore::uint PNLWZNMTBLPST1NQUERYMOD_TCOREF = 175;
		static const Sbecore::uint PNLWZNMTBLMNVECTOR_TCOMREF = 176;
		static const Sbecore::uint PNLWZNMTBLMNVECTOR_TCOSBS = 177;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOMREF = 178;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOTQMD = 179;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOSRC = 180;
		static const Sbecore::uint PNLWZNMTBLMNQUERY_TCOPFX = 181;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSRF = 182;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSHO = 183;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOTYP = 184;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOTBL = 185;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOFCT = 186;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOSTY = 187;
		static const Sbecore::uint PNLWZNMTCOLIST_TCOAXF = 188;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOTYP = 189;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOLOC = 190;
		static const Sbecore::uint PNLWZNMTCOATITLE_TCOTIT = 191;
		static const Sbecore::uint PNLWZNMTCO1NIMPEXPCOL_TCOREF = 192;
		static const Sbecore::uint PNLWZNMTCO1NQUERYCOL_TCOREF = 193;
		static const Sbecore::uint PNLWZNMTCOREF1NCONTROL_TCOREF = 194;
		static const Sbecore::uint PNLWZNMTCOREF1NQUERYMOD_TCOREF = 195;
		static const Sbecore::uint PNLWZNMTCO1NCHECK_TCOREF = 196;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOSRF = 197;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOSHO = 198;
		static const Sbecore::uint PNLWZNMSBSLIST_TCOTBL = 199;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOTYP = 200;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOLOC = 201;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOGND = 202;
		static const Sbecore::uint PNLWZNMSBSATITLE_TCOTIT = 203;
		static const Sbecore::uint PNLWZNMSBSFRS1NRELATION_TCOREF = 204;
		static const Sbecore::uint PNLWZNMSBSTOS1NRELATION_TCOREF = 205;
		static const Sbecore::uint PNLWZNMSBS1NTABLECOL_TCOREF = 206;
		static const Sbecore::uint PNLWZNMSBS1NSTUB_TCOREF = 207;
		static const Sbecore::uint PNLWZNMSBSPST1NQUERYMOD_TCOREF = 208;
		static const Sbecore::uint PNLWZNMSBSASBMNSUBSET_TCOMREF = 209;
		static const Sbecore::uint PNLWZNMSBSASBMNSUBSET_TCORTY = 210;
		static const Sbecore::uint PNLWZNMSBSBSBMNSUBSET_TCOMREF = 211;
		static const Sbecore::uint PNLWZNMSBSBSBMNSUBSET_TCORTY = 212;
		static const Sbecore::uint PNLWZNMRELLIST_TCOFRT = 213;
		static const Sbecore::uint PNLWZNMRELLIST_TCOFRS = 214;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTOT = 215;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTOS = 216;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTYP = 217;
		static const Sbecore::uint PNLWZNMRELLIST_TCOVER = 218;
		static const Sbecore::uint PNLWZNMRELLIST_TCOSUP = 219;
		static const Sbecore::uint PNLWZNMRELLIST_TCOSRL = 220;
		static const Sbecore::uint PNLWZNMRELLIST_TCOTBL = 221;
		static const Sbecore::uint PNLWZNMRELLIST_TCOPFX = 222;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOTYP = 223;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOLOC = 224;
		static const Sbecore::uint PNLWZNMRELATITLE_TCOTIT = 225;
		static const Sbecore::uint PNLWZNMRELSUP1NRELATION_TCOREF = 226;
		static const Sbecore::uint PNLWZNMREL1NTABLECOL_TCOREF = 227;
		static const Sbecore::uint PNLWZNMRELREF1NCONTROL_TCOREF = 228;
		static const Sbecore::uint PNLWZNMRELREF1NDIALOG_TCOREF = 229;
		static const Sbecore::uint PNLWZNMRELREF1NPANEL_TCOREF = 230;
		static const Sbecore::uint PNLWZNMVECLIST_TCOSRF = 231;
		static const Sbecore::uint PNLWZNMVECLIST_TCOTYP = 232;
		static const Sbecore::uint PNLWZNMVECLIST_TCOVER = 233;
		static const Sbecore::uint PNLWZNMVECLIST_TCOHKT = 234;
		static const Sbecore::uint PNLWZNMVECLIST_TCOHKU = 235;
		static const Sbecore::uint PNLWZNMVECLIST_TCOTGR = 236;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOTYP = 237;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOLOC = 238;
		static const Sbecore::uint PNLWZNMVECATITLE_TCOTIT = 239;
		static const Sbecore::uint PNLWZNMVECVEC1NVECTORITEM_TCOREF = 240;
		static const Sbecore::uint PNLWZNMVECSRC1NFEED_TCOREF = 241;
		static const Sbecore::uint PNLWZNMVECREF1NPANEL_TCOREF = 242;
		static const Sbecore::uint PNLWZNMVECFCT1NTABLECOL_TCOREF = 243;
		static const Sbecore::uint PNLWZNMVECPST1NQUERYMOD_TCOREF = 244;
		static const Sbecore::uint PNLWZNMVECMNTABLE_TCOMREF = 245;
		static const Sbecore::uint PNLWZNMVECMNTABLE_TCOSBS = 246;
		static const Sbecore::uint PNLWZNMVITLIST_TCOSRF = 247;
		static const Sbecore::uint PNLWZNMVITLIST_TCOTIT = 248;
		static const Sbecore::uint PNLWZNMVITLIST_TCOVEC = 249;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOSRF = 250;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTYP = 251;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTBL = 252;
		static const Sbecore::uint PNLWZNMCHKLIST_TCOTCO = 253;
		static const Sbecore::uint PNLWZNMCHKREF1NCALL_TCOREF = 254;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOSRF = 255;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOTYP = 256;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOTBL = 257;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOSBS = 258;
		static const Sbecore::uint PNLWZNMSTBLIST_TCOEXA = 259;
		static const Sbecore::uint PNLWZNMSTBSUPMNSTUB_TCOMREF = 260;
		static const Sbecore::uint PNLWZNMSTBMNCALL_TCOMREF = 261;
		static const Sbecore::uint PNLWZNMSTBMNSQUAWK_TCOMREF = 262;
		static const Sbecore::uint PNLWZNMSTBSUBMNSTUB_TCOMREF = 263;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOSRF = 264;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOSHO = 265;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOTIT = 266;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOVER = 267;
		static const Sbecore::uint PNLWZNMIEXLIST_TCOMIV = 268;
		static const Sbecore::uint PNLWZNMIEX1NIMPEXP_TCOREF = 269;
		static const Sbecore::uint PNLWZNMIEXREF1NDIALOG_TCOREF = 270;
		static const Sbecore::uint PNLWZNMIEXHK1NVECTOR_TCOREF = 271;
		static const Sbecore::uint PNLWZNMIMELIST_TCOSRF = 272;
		static const Sbecore::uint PNLWZNMIMELIST_TCOIEX = 273;
		static const Sbecore::uint PNLWZNMIMELIST_TCOSUP = 274;
		static const Sbecore::uint PNLWZNMIMELIST_TCOTBL = 275;
		static const Sbecore::uint PNLWZNMIMEIME1NIMPEXPCOL_TCOREF = 276;
		static const Sbecore::uint PNLWZNMIMESUP1NIMPEXP_TCOREF = 277;
		static const Sbecore::uint PNLWZNMIMEHK1NVECTOR_TCOREF = 278;
		static const Sbecore::uint PNLWZNMIELLIST_TCOSRF = 279;
		static const Sbecore::uint PNLWZNMIELLIST_TCOSHO = 280;
		static const Sbecore::uint PNLWZNMIELLIST_TCOTYP = 281;
		static const Sbecore::uint PNLWZNMIELLIST_TCOIME = 282;
		static const Sbecore::uint PNLWZNMIELLIST_TCOTCO = 283;
		static const Sbecore::uint PNLWZNMIELLIST_TCOCTY = 284;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOSRF = 285;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOTIT = 286;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOVER = 287;
		static const Sbecore::uint PNLWZNMPSTLIST_TCORET = 288;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOREU = 289;
		static const Sbecore::uint PNLWZNMPSTLIST_TCOATY = 290;
		static const Sbecore::uint PNLWZNMPST1NQUERYMOD_TCOREF = 291;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOSRF = 292;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOTIT = 293;
		static const Sbecore::uint PNLWZNMMDLLIST_TCOVER = 294;
		static const Sbecore::uint PNLWZNMMDLMDL1NCARD_TCOREF = 295;
		static const Sbecore::uint PNLWZNMMDLREF1NPANEL_TCOREF = 296;
		static const Sbecore::uint PNLWZNMCARLIST_TCOSRF = 297;
		static const Sbecore::uint PNLWZNMCARLIST_TCOTIT = 298;
		static const Sbecore::uint PNLWZNMCARLIST_TCOMDL = 299;
		static const Sbecore::uint PNLWZNMCARLIST_TCORET = 300;
		static const Sbecore::uint PNLWZNMCARLIST_TCOREU = 301;
		static const Sbecore::uint PNLWZNMCAR1NDIALOG_TCOREF = 302;
		static const Sbecore::uint PNLWZNMCARCAR1NPANEL_TCOREF = 303;
		static const Sbecore::uint PNLWZNMCARHK1NCONTROL_TCOREF = 304;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOSRF = 305;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOTYP = 306;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOCAR = 307;
		static const Sbecore::uint PNLWZNMDLGLIST_TCORET = 308;
		static const Sbecore::uint PNLWZNMDLGLIST_TCOREU = 309;
		static const Sbecore::uint PNLWZNMDLGHK1NCONTROL_TCOREF = 310;
		static const Sbecore::uint PNLWZNMDLGREF1NCONTROL_TCOREF = 311;
		static const Sbecore::uint PNLWZNMDLGMNQUERY_TCOMREF = 312;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOSRF = 313;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOTYP = 314;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOCAR = 315;
		static const Sbecore::uint PNLWZNMPNLLIST_TCORET = 316;
		static const Sbecore::uint PNLWZNMPNLLIST_TCOREU = 317;
		static const Sbecore::uint PNLWZNMPNLHK1NCONTROL_TCOREF = 318;
		static const Sbecore::uint PNLWZNMPNLMNQUERY_TCOMREF = 319;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSRF = 320;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOTYP = 321;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOVER = 322;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSUP = 323;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOSRL = 324;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOTBL = 325;
		static const Sbecore::uint PNLWZNMQRYLIST_TCOQTB = 326;
		static const Sbecore::uint PNLWZNMQRYAORDER_TCOSHO = 327;
		static const Sbecore::uint PNLWZNMQRYAORDER_TCOTCO = 328;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOQMD = 329;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOTYP = 330;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOCSE = 331;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOPST = 332;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOVEC = 333;
		static const Sbecore::uint PNLWZNMQRYACLAUSE_TCOVIT = 334;
		static const Sbecore::uint PNLWZNMQRYSUP1NQUERY_TCOREF = 335;
		static const Sbecore::uint PNLWZNMQRYQRY1NQUERYCOL_TCOREF = 336;
		static const Sbecore::uint PNLWZNMQRY1NQUERYMOD_TCOREF = 337;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOMREF = 338;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOTQMD = 339;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOSRC = 340;
		static const Sbecore::uint PNLWZNMQRYMNTABLE_TCOPFX = 341;
		static const Sbecore::uint PNLWZNMQRYMNDIALOG_TCOMREF = 342;
		static const Sbecore::uint PNLWZNMQRYMNPANEL_TCOMREF = 343;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOSRF = 344;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOSHO = 345;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOTYP = 346;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOQRY = 347;
		static const Sbecore::uint PNLWZNMQCOLIST_TCOTCO = 348;
		static const Sbecore::uint PNLWZNMQCOREF1NCONTROL_TCOREF = 349;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOTYP = 350;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOQRY = 351;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOPST = 352;
		static const Sbecore::uint PNLWZNMQMDLIST_TCORET = 353;
		static const Sbecore::uint PNLWZNMQMDLIST_TCOREU = 354;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSRF = 355;
		static const Sbecore::uint PNLWZNMCONLIST_TCOTIT = 356;
		static const Sbecore::uint PNLWZNMCONLIST_TCOTYP = 357;
		static const Sbecore::uint PNLWZNMCONLIST_TCOHKT = 358;
		static const Sbecore::uint PNLWZNMCONLIST_TCOHKU = 359;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSCT = 360;
		static const Sbecore::uint PNLWZNMCONLIST_TCORET = 361;
		static const Sbecore::uint PNLWZNMCONLIST_TCOREU = 362;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSUP = 363;
		static const Sbecore::uint PNLWZNMCONLIST_TCOSTY = 364;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOKEY = 365;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOLOC = 366;
		static const Sbecore::uint PNLWZNMCONAPAR_TCOVAL = 367;
		static const Sbecore::uint PNLWZNMCONSUP1NCONTROL_TCOREF = 368;
		static const Sbecore::uint PNLWZNMCONFEDREF1NRTBLOCK_TCOREF = 369;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOSRF = 370;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOTIT = 371;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOTYP = 372;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOVER = 373;
		static const Sbecore::uint PNLWZNMOPKLIST_TCOSHD = 374;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOSRF = 375;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVTY = 376;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVEC = 377;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCODVL = 378;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOVIT = 379;
		static const Sbecore::uint PNLWZNMOPKAINVARG_TCOCMT = 380;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOSRF = 381;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOVTY = 382;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOVEC = 383;
		static const Sbecore::uint PNLWZNMOPKARETVAL_TCOCMT = 384;
		static const Sbecore::uint PNLWZNMOPK1NOP_TCOREF = 385;
		static const Sbecore::uint PNLWZNMOPKREF1NBLOCK_TCOREF = 386;
		static const Sbecore::uint PNLWZNMOPKMNCOMPONENT_TCOMREF = 387;
		static const Sbecore::uint PNLWZNMOPKMNLIBRARY_TCOMREF = 388;
		static const Sbecore::uint PNLWZNMOPKMNJOB_TCOMREF = 389;
		static const Sbecore::uint PNLWZNMOPKSQKMNSTUB_TCOMREF = 390;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOSRF = 391;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOOPK = 392;
		static const Sbecore::uint PNLWZNMOPXLIST_TCOSHD = 393;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOSRF = 394;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVTY = 395;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVEC = 396;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCODVL = 397;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOVIT = 398;
		static const Sbecore::uint PNLWZNMOPXAINVARG_TCOCMT = 399;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOSRF = 400;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOVTY = 401;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOVEC = 402;
		static const Sbecore::uint PNLWZNMOPXARETVAL_TCOCMT = 403;
		static const Sbecore::uint PNLWZNMOPXREF1NBLOCK_TCOREF = 404;
		static const Sbecore::uint PNLWZNMOPXMNJOB_TCOMREF = 405;
		static const Sbecore::uint PNLWZNMOPXSQKMNSTUB_TCOMREF = 406;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOSRF = 407;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOTYP = 408;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOVER = 409;
		static const Sbecore::uint PNLWZNMJOBLIST_TCORET = 410;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOREU = 411;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOGBL = 412;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOCLS = 413;
		static const Sbecore::uint PNLWZNMJOBLIST_TCOSHD = 414;
		static const Sbecore::uint PNLWZNMJOBACMD_TCOSRF = 415;
		static const Sbecore::uint PNLWZNMJOBACMD_TCOCMT = 416;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOSRF = 417;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOVTY = 418;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOVEC = 419;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOLEN = 420;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOSHR = 421;
		static const Sbecore::uint PNLWZNMJOBAVAR_TCOCMT = 422;
		static const Sbecore::uint PNLWZNMJOB1NSENSITIVITY_TCOREF = 423;
		static const Sbecore::uint PNLWZNMJOBJOB1NSTAGE_TCOREF = 424;
		static const Sbecore::uint PNLWZNMJOB1NRTJOB_TCOREF = 425;
		static const Sbecore::uint PNLWZNMJOB1NMETHOD_TCOREF = 426;
		static const Sbecore::uint PNLWZNMJOBREF1NBLOCK_TCOREF = 427;
		static const Sbecore::uint PNLWZNMJOBHK1NVECTOR_TCOREF = 428;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOMREF = 429;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOSHO = 430;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOMLT = 431;
		static const Sbecore::uint PNLWZNMJOBSUPMNJOB_TCOCSA = 432;
		static const Sbecore::uint PNLWZNMJOBMNOP_TCOMREF = 433;
		static const Sbecore::uint PNLWZNMJOBMNOPPACK_TCOMREF = 434;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOMREF = 435;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOSHO = 436;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOMLT = 437;
		static const Sbecore::uint PNLWZNMJOBSUBMNJOB_TCOCSA = 438;
		static const Sbecore::uint PNLWZNMSGELIST_TCOSRF = 439;
		static const Sbecore::uint PNLWZNMSGELIST_TCOTYP = 440;
		static const Sbecore::uint PNLWZNMSGELIST_TCOJOB = 441;
		static const Sbecore::uint PNLWZNMSGE1NSENSITIVITY_TCOREF = 442;
		static const Sbecore::uint PNLWZNMSGESQKMNSTUB_TCOMREF = 443;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOSRF = 444;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOJOB = 445;
		static const Sbecore::uint PNLWZNMMTDLIST_TCOEXS = 446;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOSRF = 447;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOVTY = 448;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOVEC = 449;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOLEN = 450;
		static const Sbecore::uint PNLWZNMMTDAINVPAR_TCOCMT = 451;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOSRF = 452;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOVTY = 453;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOVEC = 454;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOLEN = 455;
		static const Sbecore::uint PNLWZNMMTDARETPAR_TCOCMT = 456;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOSRF = 457;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOTYP = 458;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOVER = 459;
		static const Sbecore::uint PNLWZNMBLKLIST_TCORET = 460;
		static const Sbecore::uint PNLWZNMBLKLIST_TCOREU = 461;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOTYP = 462;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOSRF = 463;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVTY = 464;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOCON = 465;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVEC = 466;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOFED = 467;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOTBL = 468;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOBL2 = 469;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCODFV = 470;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOVIT = 471;
		static const Sbecore::uint PNLWZNMBLKAITEM_TCOCMT = 472;
		static const Sbecore::uint PNLWZNMBLK1NRTDPCH_TCOREF = 473;
		static const Sbecore::uint PNLWZNMBLKREF1NRTBLOCK_TCOREF = 474;
		static const Sbecore::uint PNLWZNMCALLIST_TCOSRF = 475;
		static const Sbecore::uint PNLWZNMCALLIST_TCOTYP = 476;
		static const Sbecore::uint PNLWZNMCALLIST_TCOVER = 477;
		static const Sbecore::uint PNLWZNMCALLIST_TCORET = 478;
		static const Sbecore::uint PNLWZNMCALLIST_TCOREU = 479;
		static const Sbecore::uint PNLWZNMCALLIST_TCOIAT = 480;
		static const Sbecore::uint PNLWZNMCALLIST_TCORAT = 481;
		static const Sbecore::uint PNLWZNMCAL1NSENSITIVITY_TCOREF = 482;
		static const Sbecore::uint PNLWZNMCALMNSTUB_TCOMREF = 483;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOSRF = 484;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOTIT = 485;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOTYP = 486;
		static const Sbecore::uint PNLWZNMCMPLIST_TCOVER = 487;
		static const Sbecore::uint PNLWZNMCMP1NRELEASE_TCOREF = 488;
		static const Sbecore::uint PNLWZNMCMPMNLIBRARY_TCOMREF = 489;
		static const Sbecore::uint PNLWZNMCMPMNOPPACK_TCOMREF = 490;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOSRF = 491;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOCMP = 492;
		static const Sbecore::uint PNLWZNMRLSLIST_TCOMCH = 493;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOGRP = 494;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOOWN = 495;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOSHO = 496;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOTIT = 497;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOTRG = 498;
		static const Sbecore::uint PNLWZNMAPPLIST_TCOVER = 499;
		static const Sbecore::uint PNLWZNMAPP1NRTJOB_TCOREF = 500;
		static const Sbecore::uint PNLWZNMAPPAPP1NSEQUENCE_TCOREF = 501;
		static const Sbecore::uint PNLWZNMAPP1NEVENT_TCOREF = 502;
		static const Sbecore::uint PNLWZNMAPPREF1NFILE_TCOREF = 503;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOSRF = 504;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOAPP = 505;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOSUP = 506;
		static const Sbecore::uint PNLWZNMRTJLIST_TCOJOB = 507;
		static const Sbecore::uint PNLWZNMRTJ1NRTBLOCK_TCOREF = 508;
		static const Sbecore::uint PNLWZNMRTJ1NRTDPCH_TCOREF = 509;
		static const Sbecore::uint PNLWZNMRTJSUP1NRTJOB_TCOREF = 510;
		static const Sbecore::uint PNLWZNMEVTLIST_TCOSRF = 511;
		static const Sbecore::uint PNLWZNMEVTLIST_TCOAPP = 512;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOSRF = 513;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOTIT = 514;
		static const Sbecore::uint PNLWZNMSEQLIST_TCOAPP = 515;
		static const Sbecore::uint PNLWZNMSEQSEQ1NSTATE_TCOREF = 516;
		static const Sbecore::uint PNLWZNMSTELIST_TCOSRF = 517;
		static const Sbecore::uint PNLWZNMSTELIST_TCOSEQ = 518;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOSRF = 519;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOTYP = 520;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOEVT = 521;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCORTJ = 522;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOVIT = 523;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOXSR = 524;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCORTD = 525;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOMSK = 526;
		static const Sbecore::uint PNLWZNMSTEATRIG_TCOCND = 527;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSCT = 528;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTYP = 529;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTRJ = 530;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOVEC = 531;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOVIT = 532;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSNX = 533;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOSEQ = 534;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR1 = 535;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP1 = 536;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR2 = 537;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP2 = 538;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR3 = 539;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP3 = 540;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOTR4 = 541;
		static const Sbecore::uint PNLWZNMSTEAACTION_TCOIP4 = 542;

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

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
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
		static const Sbecore::uint KLSTWZNMKAMMACHINEPARKEY = 5;
		static const Sbecore::uint KLSTWZNMKAMMACHTYPEMAKEFILETAG = 6;
		static const Sbecore::uint KLSTWZNMKAMPERSONDETAILTYPE = 7;
		static const Sbecore::uint KLSTWZNMKMCONTROLOPTION = 8;
		static const Sbecore::uint KLSTWZNMKMFILECONTENT = 9;
		static const Sbecore::uint KLSTWZNMKMFILEMIMETYPE = 10;
		static const Sbecore::uint KLSTWZNMKMLIBRARYLICTYPE = 11;
		static const Sbecore::uint KLSTWZNMKMMACHTYPEOS = 12;
		static const Sbecore::uint KLSTWZNMKMMACHTYPEPKGMGR = 13;
		static const Sbecore::uint KLSTWZNMKMRELATIONOPTION = 14;
		static const Sbecore::uint KLSTWZNMKMRELEASEOPTION = 15;
		static const Sbecore::uint KLSTWZNMKMTABLECOLOPTION = 16;
		static const Sbecore::uint KLSTWZNMKMVECTOROPTION = 17;
		static const Sbecore::uint KLSTWZNMKRMCAPABILITYUNIVERSALKEY = 18;
		static const Sbecore::uint KLSTWZNMKRMPERSONMPROJECTFUNCTION = 19;
		static const Sbecore::uint KLSTWZNMKTAGGRP = 20;
		static const Sbecore::uint KLSTKWZNMCTPGENJTRCUSTOP = 21;
		static const Sbecore::uint KLSTKWZNMCTPGENUICUSTOP = 22;
		static const Sbecore::uint KLSTKWZNMCTPWRSRVCUSTOP = 23;
		static const Sbecore::uint KLSTKWZNMCTPWRSTKITCUSTOP = 24;
		static const Sbecore::uint KLSTKWZNMCTPWRWEBCUSTOP = 25;

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

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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
		static const Sbecore::uint TBLWZNMMMACHTYPE = 22;
		static const Sbecore::uint TBLWZNMMMETHOD = 23;
		static const Sbecore::uint TBLWZNMMMODULE = 24;
		static const Sbecore::uint TBLWZNMMOP = 25;
		static const Sbecore::uint TBLWZNMMOPPACK = 26;
		static const Sbecore::uint TBLWZNMMPANEL = 27;
		static const Sbecore::uint TBLWZNMMPERSON = 28;
		static const Sbecore::uint TBLWZNMMPRESET = 29;
		static const Sbecore::uint TBLWZNMMPROJECT = 30;
		static const Sbecore::uint TBLWZNMMQUERY = 31;
		static const Sbecore::uint TBLWZNMMQUERYCOL = 32;
		static const Sbecore::uint TBLWZNMMQUERYMOD = 33;
		static const Sbecore::uint TBLWZNMMRELATION = 34;
		static const Sbecore::uint TBLWZNMMRELEASE = 35;
		static const Sbecore::uint TBLWZNMMRTBLOCK = 36;
		static const Sbecore::uint TBLWZNMMRTDPCH = 37;
		static const Sbecore::uint TBLWZNMMRTJOB = 38;
		static const Sbecore::uint TBLWZNMMSENSITIVITY = 39;
		static const Sbecore::uint TBLWZNMMSEQUENCE = 40;
		static const Sbecore::uint TBLWZNMMSESSION = 41;
		static const Sbecore::uint TBLWZNMMSQUAWK = 42;
		static const Sbecore::uint TBLWZNMMSTAGE = 43;
		static const Sbecore::uint TBLWZNMMSTATE = 44;
		static const Sbecore::uint TBLWZNMMSTUB = 45;
		static const Sbecore::uint TBLWZNMMSUBSET = 46;
		static const Sbecore::uint TBLWZNMMTABLE = 47;
		static const Sbecore::uint TBLWZNMMTABLECOL = 48;
		static const Sbecore::uint TBLWZNMMTAG = 49;
		static const Sbecore::uint TBLWZNMMUSER = 50;
		static const Sbecore::uint TBLWZNMMUSERGROUP = 51;
		static const Sbecore::uint TBLWZNMMVECTOR = 52;
		static const Sbecore::uint TBLWZNMMVECTORITEM = 53;
		static const Sbecore::uint TBLWZNMMVERSION = 54;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWznmVLocale);

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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
		static const Sbecore::uint PREWZNMIXCRDACCMTY = 99;
		static const Sbecore::uint PREWZNMIXCRDACCOPK = 100;
		static const Sbecore::uint PREWZNMIXCRDACCOPX = 101;
		static const Sbecore::uint PREWZNMIXCRDACCPNL = 102;
		static const Sbecore::uint PREWZNMIXCRDACCPRJ = 103;
		static const Sbecore::uint PREWZNMIXCRDACCPRS = 104;
		static const Sbecore::uint PREWZNMIXCRDACCPST = 105;
		static const Sbecore::uint PREWZNMIXCRDACCQCO = 106;
		static const Sbecore::uint PREWZNMIXCRDACCQMD = 107;
		static const Sbecore::uint PREWZNMIXCRDACCQRY = 108;
		static const Sbecore::uint PREWZNMIXCRDACCREL = 109;
		static const Sbecore::uint PREWZNMIXCRDACCRLS = 110;
		static const Sbecore::uint PREWZNMIXCRDACCRTJ = 111;
		static const Sbecore::uint PREWZNMIXCRDACCSBS = 112;
		static const Sbecore::uint PREWZNMIXCRDACCSEQ = 113;
		static const Sbecore::uint PREWZNMIXCRDACCSGE = 114;
		static const Sbecore::uint PREWZNMIXCRDACCSTB = 115;
		static const Sbecore::uint PREWZNMIXCRDACCSTE = 116;
		static const Sbecore::uint PREWZNMIXCRDACCTAG = 117;
		static const Sbecore::uint PREWZNMIXCRDACCTBL = 118;
		static const Sbecore::uint PREWZNMIXCRDACCTCO = 119;
		static const Sbecore::uint PREWZNMIXCRDACCUSG = 120;
		static const Sbecore::uint PREWZNMIXCRDACCUSR = 121;
		static const Sbecore::uint PREWZNMIXCRDACCUTL = 122;
		static const Sbecore::uint PREWZNMIXCRDACCVEC = 123;
		static const Sbecore::uint PREWZNMIXCRDACCVER = 124;
		static const Sbecore::uint PREWZNMIXCRDACCVIT = 125;
		static const Sbecore::uint PREWZNMIXLCL = 126;
		static const Sbecore::uint PREWZNMIXORD = 127;
		static const Sbecore::uint PREWZNMIXPRE = 128;
		static const Sbecore::uint PREWZNMIXRECACC = 129;
		static const Sbecore::uint PREWZNMJOBLIST_GBL = 130;
		static const Sbecore::uint PREWZNMJOBLIST_RET = 131;
		static const Sbecore::uint PREWZNMJOBLIST_REU = 132;
		static const Sbecore::uint PREWZNMJOBLIST_SRF = 133;
		static const Sbecore::uint PREWZNMJOBLIST_TYP = 134;
		static const Sbecore::uint PREWZNMJOBLIST_VER = 135;
		static const Sbecore::uint PREWZNMJREFNOTIFY = 136;
		static const Sbecore::uint PREWZNMJREFSESS = 137;
		static const Sbecore::uint PREWZNMLIBAMAKEFILE_X2 = 138;
		static const Sbecore::uint PREWZNMLIBLIST_SRF = 139;
		static const Sbecore::uint PREWZNMLOCLIST_SRF = 140;
		static const Sbecore::uint PREWZNMMCHAPAR_X1 = 141;
		static const Sbecore::uint PREWZNMMCHLIST_SRF = 142;
		static const Sbecore::uint PREWZNMMCHLIST_TBL = 143;
		static const Sbecore::uint PREWZNMMDLLIST_SRF = 144;
		static const Sbecore::uint PREWZNMMDLLIST_VER = 145;
		static const Sbecore::uint PREWZNMMTDLIST_JOB = 146;
		static const Sbecore::uint PREWZNMMTDLIST_SRF = 147;
		static const Sbecore::uint PREWZNMMTYAMAKEFILE_X1 = 148;
		static const Sbecore::uint PREWZNMMTYLIST_SRF = 149;
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
		static const Sbecore::uint PREWZNMREFMTY = 225;
		static const Sbecore::uint PREWZNMREFOEN = 226;
		static const Sbecore::uint PREWZNMREFOPK = 227;
		static const Sbecore::uint PREWZNMREFOPX = 228;
		static const Sbecore::uint PREWZNMREFPNL = 229;
		static const Sbecore::uint PREWZNMREFPRJ = 230;
		static const Sbecore::uint PREWZNMREFPRS = 231;
		static const Sbecore::uint PREWZNMREFPST = 232;
		static const Sbecore::uint PREWZNMREFQCO = 233;
		static const Sbecore::uint PREWZNMREFQMD = 234;
		static const Sbecore::uint PREWZNMREFQRY = 235;
		static const Sbecore::uint PREWZNMREFQTB = 236;
		static const Sbecore::uint PREWZNMREFREL = 237;
		static const Sbecore::uint PREWZNMREFRLS = 238;
		static const Sbecore::uint PREWZNMREFRLT = 239;
		static const Sbecore::uint PREWZNMREFRTB = 240;
		static const Sbecore::uint PREWZNMREFRTD = 241;
		static const Sbecore::uint PREWZNMREFRTJ = 242;
		static const Sbecore::uint PREWZNMREFSBS = 243;
		static const Sbecore::uint PREWZNMREFSEL = 244;
		static const Sbecore::uint PREWZNMREFSEQ = 245;
		static const Sbecore::uint PREWZNMREFSES = 246;
		static const Sbecore::uint PREWZNMREFSGE = 247;
		static const Sbecore::uint PREWZNMREFSNS = 248;
		static const Sbecore::uint PREWZNMREFSQK = 249;
		static const Sbecore::uint PREWZNMREFSTB = 250;
		static const Sbecore::uint PREWZNMREFSTC = 251;
		static const Sbecore::uint PREWZNMREFSTE = 252;
		static const Sbecore::uint PREWZNMREFSTT = 253;
		static const Sbecore::uint PREWZNMREFTAG = 254;
		static const Sbecore::uint PREWZNMREFTBL = 255;
		static const Sbecore::uint PREWZNMREFTCO = 256;
		static const Sbecore::uint PREWZNMREFUSG = 257;
		static const Sbecore::uint PREWZNMREFUSR = 258;
		static const Sbecore::uint PREWZNMREFVEC = 259;
		static const Sbecore::uint PREWZNMREFVER = 260;
		static const Sbecore::uint PREWZNMREFVIT = 261;
		static const Sbecore::uint PREWZNMRELATITLE_X1 = 262;
		static const Sbecore::uint PREWZNMRELATITLE_X2 = 263;
		static const Sbecore::uint PREWZNMRELLIST_FRS = 264;
		static const Sbecore::uint PREWZNMRELLIST_FRT = 265;
		static const Sbecore::uint PREWZNMRELLIST_SRL = 266;
		static const Sbecore::uint PREWZNMRELLIST_SUP = 267;
		static const Sbecore::uint PREWZNMRELLIST_TBL = 268;
		static const Sbecore::uint PREWZNMRELLIST_TOS = 269;
		static const Sbecore::uint PREWZNMRELLIST_TOT = 270;
		static const Sbecore::uint PREWZNMRELLIST_TYP = 271;
		static const Sbecore::uint PREWZNMRELLIST_VER = 272;
		static const Sbecore::uint PREWZNMREPFOLDER = 273;
		static const Sbecore::uint PREWZNMRLSLIST_CMP = 274;
		static const Sbecore::uint PREWZNMRLSLIST_MCH = 275;
		static const Sbecore::uint PREWZNMRLSLIST_SRF = 276;
		static const Sbecore::uint PREWZNMRTJLIST_APP = 277;
		static const Sbecore::uint PREWZNMRTJLIST_JOB = 278;
		static const Sbecore::uint PREWZNMRTJLIST_SRF = 279;
		static const Sbecore::uint PREWZNMRTJLIST_SUP = 280;
		static const Sbecore::uint PREWZNMSBSATITLE_X1 = 281;
		static const Sbecore::uint PREWZNMSBSATITLE_X2 = 282;
		static const Sbecore::uint PREWZNMSBSLIST_SRF = 283;
		static const Sbecore::uint PREWZNMSBSLIST_TBL = 284;
		static const Sbecore::uint PREWZNMSEQLIST_APP = 285;
		static const Sbecore::uint PREWZNMSEQLIST_SRF = 286;
		static const Sbecore::uint PREWZNMSESS = 287;
		static const Sbecore::uint PREWZNMSGELIST_JOB = 288;
		static const Sbecore::uint PREWZNMSGELIST_SRF = 289;
		static const Sbecore::uint PREWZNMSGELIST_TYP = 290;
		static const Sbecore::uint PREWZNMSTBLIST_SBS = 291;
		static const Sbecore::uint PREWZNMSTBLIST_SRF = 292;
		static const Sbecore::uint PREWZNMSTBLIST_TBL = 293;
		static const Sbecore::uint PREWZNMSTBLIST_TYP = 294;
		static const Sbecore::uint PREWZNMSTELIST_SEQ = 295;
		static const Sbecore::uint PREWZNMSTELIST_SRF = 296;
		static const Sbecore::uint PREWZNMSUSPSESS = 297;
		static const Sbecore::uint PREWZNMSYSDATE = 298;
		static const Sbecore::uint PREWZNMSYSSTAMP = 299;
		static const Sbecore::uint PREWZNMSYSTIME = 300;
		static const Sbecore::uint PREWZNMTAGLIST_CPB = 301;
		static const Sbecore::uint PREWZNMTAGLIST_GRP = 302;
		static const Sbecore::uint PREWZNMTAGLIST_SRF = 303;
		static const Sbecore::uint PREWZNMTBLATITLE_X1 = 304;
		static const Sbecore::uint PREWZNMTBLATITLE_X2 = 305;
		static const Sbecore::uint PREWZNMTBLLIST_RET = 306;
		static const Sbecore::uint PREWZNMTBLLIST_REU = 307;
		static const Sbecore::uint PREWZNMTBLLIST_SRF = 308;
		static const Sbecore::uint PREWZNMTBLLIST_TYP = 309;
		static const Sbecore::uint PREWZNMTBLLIST_VER = 310;
		static const Sbecore::uint PREWZNMTCOATITLE_X1 = 311;
		static const Sbecore::uint PREWZNMTCOATITLE_X2 = 312;
		static const Sbecore::uint PREWZNMTCOLIST_FCT = 313;
		static const Sbecore::uint PREWZNMTCOLIST_SRF = 314;
		static const Sbecore::uint PREWZNMTCOLIST_TBL = 315;
		static const Sbecore::uint PREWZNMTCOLIST_TYP = 316;
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

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* VecWCloudtype (full: VecWznmWCloudtype)
		*/
	class VecWCloudtype {

	public:
		static const Sbecore::uint AWS = 1;
		static const Sbecore::uint AZURE = 2;

		static Sbecore::uint getIx(const std::string& srefs);
		static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
		static std::string getSrefs(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
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

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
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

	void fillFeedFromKlst(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);
	void fillFeedFromKlstByMtbUref(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint x1IxWznmVMaintable, const Sbecore::ubigint x1Uref, const Sbecore::uint ixWznmVLocale, Sbecore::Xmlio::Feed& feed);

	std::string getKlstTitleBySref(const Sbecore::uint klsIxWznmVKeylist, const std::string& sref, const Sbecore::uint ixWznmVLocale = 0);
	std::string getKlstTitleByMtbUrefSref(const Sbecore::uint klsIxWznmVKeylist, const Sbecore::uint x1IxWznmVMaintable, const Sbecore::ubigint x1Uref, const std::string& sref, const Sbecore::uint ixWznmVLocale = 0);

	void fillFeedFromVlst(const Sbecore::uint vlsIxWznmVValuelist, const Sbecore::uint x1IxWznmVLocale, Sbecore::Xmlio::Feed& feed);

public:
	TblWznmAccRMUserUniversal* tblwznmaccrmuseruniversal;
	TblWznmAMBlockItem* tblwznmamblockitem;
	TblWznmAMCapabilityPar* tblwznmamcapabilitypar;
	TblWznmAMControlPar* tblwznmamcontrolpar;
	TblWznmAMJobCmd* tblwznmamjobcmd;
	TblWznmAMJobVar* tblwznmamjobvar;
	TblWznmAMLibraryMakefile* tblwznmamlibrarymakefile;
	TblWznmAMLibraryPkglist* tblwznmamlibrarypkglist;
	TblWznmAMMachinePar* tblwznmammachinepar;
	TblWznmAMMachtypeMakefile* tblwznmammachtypemakefile;
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
	TblWznmMMachtype* tblwznmmmachtype;
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
	TblWznmQMchAPar* tblwznmqmchapar;
	TblWznmQMchList* tblwznmqmchlist;
	TblWznmQMdlList* tblwznmqmdllist;
	TblWznmQMdlMdl1NCard* tblwznmqmdlmdl1ncard;
	TblWznmQMdlRef1NPanel* tblwznmqmdlref1npanel;
	TblWznmQMtdAInvpar* tblwznmqmtdainvpar;
	TblWznmQMtdARetpar* tblwznmqmtdaretpar;
	TblWznmQMtdList* tblwznmqmtdlist;
	TblWznmQMty1NMachine* tblwznmqmty1nmachine;
	TblWznmQMtyAMakefile* tblwznmqmtyamakefile;
	TblWznmQMtyList* tblwznmqmtylist;
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
	TblWznmQPrj1NVersion* tblwznmqprj1nversion;
	TblWznmQPrjList* tblwznmqprjlist;
	TblWznmQPrjMNPerson* tblwznmqprjmnperson;
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

