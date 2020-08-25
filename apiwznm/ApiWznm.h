/**
	* \file ApiWznm.h
	* Wznm API library global functionality (declarations)
	* \author Alexander Wirthmueller
	* \date created: 25 Aug 2020
	* \date modified: 25 Aug 2020
	*/

#ifndef APIWZNM_H
#define APIWZNM_H

#define WZNM_VERSION "1.0.6"
#define WZNM_VERSION_MAJOR 1
#define WZNM_VERSION_MINOR 0
#define WZNM_VERSION_SUB 6

#include "ApiWznm_blks.h"

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

#include "CrdWznmApp.h"
#include "CrdWznmBlk.h"
#include "CrdWznmCal.h"
#include "CrdWznmCap.h"
#include "CrdWznmCar.h"
#include "CrdWznmChk.h"
#include "CrdWznmCmp.h"
#include "CrdWznmCon.h"
#include "CrdWznmCtp.h"
#include "CrdWznmDlg.h"
#include "CrdWznmErr.h"
#include "CrdWznmEvt.h"
#include "CrdWznmFil.h"
#include "CrdWznmIel.h"
#include "CrdWznmIex.h"
#include "CrdWznmIme.h"
#include "CrdWznmJob.h"
#include "CrdWznmLib.h"
#include "CrdWznmLoc.h"
#include "CrdWznmMch.h"
#include "CrdWznmMdl.h"
#include "CrdWznmMtd.h"
#include "CrdWznmMty.h"
#include "CrdWznmNav.h"
#include "CrdWznmOpk.h"
#include "CrdWznmOpx.h"
#include "CrdWznmPnl.h"
#include "CrdWznmPrj.h"
#include "CrdWznmPrs.h"
#include "CrdWznmPst.h"
#include "CrdWznmQco.h"
#include "CrdWznmQmd.h"
#include "CrdWznmQry.h"
#include "CrdWznmRel.h"
#include "CrdWznmRls.h"
#include "CrdWznmRtj.h"
#include "CrdWznmSbs.h"
#include "CrdWznmSeq.h"
#include "CrdWznmSge.h"
#include "CrdWznmStb.h"
#include "CrdWznmSte.h"
#include "CrdWznmTag.h"
#include "CrdWznmTbl.h"
#include "CrdWznmTco.h"
#include "CrdWznmUsg.h"
#include "CrdWznmUsr.h"
#include "CrdWznmUtl.h"
#include "CrdWznmVec.h"
#include "CrdWznmVer.h"
#include "CrdWznmVit.h"
#include "DlgWznmAppImpstr.h"
#include "DlgWznmAppNew.h"
#include "DlgWznmAppWrite.h"
#include "DlgWznmFilDownload.h"
#include "DlgWznmFilNew.h"
#include "DlgWznmNavLoaini.h"
#include "DlgWznmNavMnglic.h"
#include "DlgWznmPrjImpex.h"
#include "DlgWznmPrjNew.h"
#include "DlgWznmRlsFinreptr.h"
#include "DlgWznmRlsStareptr.h"
#include "DlgWznmRlsWrite.h"
#include "DlgWznmUsrMngkeypair.h"
#include "DlgWznmUtlExtrip.h"
#include "DlgWznmUtlIexconv.h"
#include "DlgWznmUtlMrgip.h"
#include "DlgWznmVerBscui.h"
#include "DlgWznmVerCustjob.h"
#include "DlgWznmVerCustjtr.h"
#include "DlgWznmVerCustui.h"
#include "DlgWznmVerDbstr.h"
#include "DlgWznmVerDeploy.h"
#include "DlgWznmVerFinmod.h"
#include "DlgWznmVerGenjtr.h"
#include "DlgWznmVerGenui.h"
#include "DlgWznmVerGlobal.h"
#include "DlgWznmVerImpexp.h"
#include "DlgWznmVerNew.h"
#include "DlgWznmVerOppack.h"
#include "DlgWznmVerWrstkit.h"
#include "PnlWznmApp1NEvent.h"
#include "PnlWznmApp1NRtjob.h"
#include "PnlWznmAppApp1NSequence.h"
#include "PnlWznmAppDetail.h"
#include "PnlWznmAppHeadbar.h"
#include "PnlWznmAppList.h"
#include "PnlWznmAppRec.h"
#include "PnlWznmAppRef1NFile.h"
#include "PnlWznmBlk1NRtdpch.h"
#include "PnlWznmBlkAItem.h"
#include "PnlWznmBlkDetail.h"
#include "PnlWznmBlkHeadbar.h"
#include "PnlWznmBlkList.h"
#include "PnlWznmBlkRec.h"
#include "PnlWznmBlkRef1NRtblock.h"
#include "PnlWznmCal1NSensitivity.h"
#include "PnlWznmCalDetail.h"
#include "PnlWznmCalHeadbar.h"
#include "PnlWznmCalList.h"
#include "PnlWznmCalMNStub.h"
#include "PnlWznmCalRec.h"
#include "PnlWznmCapAPar.h"
#include "PnlWznmCapDetail.h"
#include "PnlWznmCapHeadbar.h"
#include "PnlWznmCapList.h"
#include "PnlWznmCapRec.h"
#include "PnlWznmCar1NDialog.h"
#include "PnlWznmCarCar1NPanel.h"
#include "PnlWznmCarDetail.h"
#include "PnlWznmCarHeadbar.h"
#include "PnlWznmCarHk1NControl.h"
#include "PnlWznmCarList.h"
#include "PnlWznmCarRec.h"
#include "PnlWznmChkDetail.h"
#include "PnlWznmChkHeadbar.h"
#include "PnlWznmChkList.h"
#include "PnlWznmChkRec.h"
#include "PnlWznmChkRef1NCall.h"
#include "PnlWznmCmp1NRelease.h"
#include "PnlWznmCmpDetail.h"
#include "PnlWznmCmpHeadbar.h"
#include "PnlWznmCmpList.h"
#include "PnlWznmCmpMNLibrary.h"
#include "PnlWznmCmpMNOppack.h"
#include "PnlWznmCmpRec.h"
#include "PnlWznmConAPar.h"
#include "PnlWznmConDetail.h"
#include "PnlWznmConFedRef1NRtblock.h"
#include "PnlWznmConHeadbar.h"
#include "PnlWznmConList.h"
#include "PnlWznmConRec.h"
#include "PnlWznmConSup1NControl.h"
#include "PnlWznmCtp1NTag.h"
#include "PnlWznmCtpAPar.h"
#include "PnlWznmCtpDetail.h"
#include "PnlWznmCtpHeadbar.h"
#include "PnlWznmCtpKKey.h"
#include "PnlWznmCtpKParKey.h"
#include "PnlWznmCtpList.h"
#include "PnlWznmCtpRec.h"
#include "PnlWznmCtpTpl1NCapability.h"
#include "PnlWznmDlgDetail.h"
#include "PnlWznmDlgHeadbar.h"
#include "PnlWznmDlgHk1NControl.h"
#include "PnlWznmDlgList.h"
#include "PnlWznmDlgMNQuery.h"
#include "PnlWznmDlgRec.h"
#include "PnlWznmDlgRef1NControl.h"
#include "PnlWznmErrDetail.h"
#include "PnlWznmErrHeadbar.h"
#include "PnlWznmErrList.h"
#include "PnlWznmErrRec.h"
#include "PnlWznmEvtDetail.h"
#include "PnlWznmEvtHeadbar.h"
#include "PnlWznmEvtList.h"
#include "PnlWznmEvtRec.h"
#include "PnlWznmFilDetail.h"
#include "PnlWznmFilHeadbar.h"
#include "PnlWznmFilList.h"
#include "PnlWznmFilRec.h"
#include "PnlWznmIelDetail.h"
#include "PnlWznmIelHeadbar.h"
#include "PnlWznmIelList.h"
#include "PnlWznmIelRec.h"
#include "PnlWznmIex1NImpexp.h"
#include "PnlWznmIexDetail.h"
#include "PnlWznmIexHeadbar.h"
#include "PnlWznmIexHk1NVector.h"
#include "PnlWznmIexList.h"
#include "PnlWznmIexRec.h"
#include "PnlWznmIexRef1NDialog.h"
#include "PnlWznmImeDetail.h"
#include "PnlWznmImeHeadbar.h"
#include "PnlWznmImeHk1NVector.h"
#include "PnlWznmImeIme1NImpexpcol.h"
#include "PnlWznmImeList.h"
#include "PnlWznmImeRec.h"
#include "PnlWznmImeSup1NImpexp.h"
#include "PnlWznmJob1NMethod.h"
#include "PnlWznmJob1NRtjob.h"
#include "PnlWznmJob1NSensitivity.h"
#include "PnlWznmJobACmd.h"
#include "PnlWznmJobAVar.h"
#include "PnlWznmJobDetail.h"
#include "PnlWznmJobHeadbar.h"
#include "PnlWznmJobHk1NVector.h"
#include "PnlWznmJobJob1NStage.h"
#include "PnlWznmJobList.h"
#include "PnlWznmJobMNOp.h"
#include "PnlWznmJobMNOppack.h"
#include "PnlWznmJobRec.h"
#include "PnlWznmJobRef1NBlock.h"
#include "PnlWznmJobSubMNJob.h"
#include "PnlWznmJobSupMNJob.h"
#include "PnlWznmLibAMakefile.h"
#include "PnlWznmLibAPkglist.h"
#include "PnlWznmLibDetail.h"
#include "PnlWznmLibHeadbar.h"
#include "PnlWznmLibList.h"
#include "PnlWznmLibMNComponent.h"
#include "PnlWznmLibMNOppack.h"
#include "PnlWznmLibRec.h"
#include "PnlWznmLibRef1NFile.h"
#include "PnlWznmLocDetail.h"
#include "PnlWznmLocHeadbar.h"
#include "PnlWznmLocList.h"
#include "PnlWznmLocMNVersion.h"
#include "PnlWznmLocRec.h"
#include "PnlWznmMch1NRelease.h"
#include "PnlWznmMchAPar.h"
#include "PnlWznmMchDetail.h"
#include "PnlWznmMchHeadbar.h"
#include "PnlWznmMchList.h"
#include "PnlWznmMchRec.h"
#include "PnlWznmMdlDetail.h"
#include "PnlWznmMdlHeadbar.h"
#include "PnlWznmMdlList.h"
#include "PnlWznmMdlMdl1NCard.h"
#include "PnlWznmMdlRec.h"
#include "PnlWznmMdlRef1NPanel.h"
#include "PnlWznmMtdAInvpar.h"
#include "PnlWznmMtdARetpar.h"
#include "PnlWznmMtdDetail.h"
#include "PnlWznmMtdHeadbar.h"
#include "PnlWznmMtdList.h"
#include "PnlWznmMtdRec.h"
#include "PnlWznmMty1NMachine.h"
#include "PnlWznmMtyAMakefile.h"
#include "PnlWznmMtyDetail.h"
#include "PnlWznmMtyHeadbar.h"
#include "PnlWznmMtyList.h"
#include "PnlWznmMtyRec.h"
#include "PnlWznmNavAdmin.h"
#include "PnlWznmNavAppdev.h"
#include "PnlWznmNavAuxfct.h"
#include "PnlWznmNavComp.h"
#include "PnlWznmNavDbstr.h"
#include "PnlWznmNavDeploy.h"
#include "PnlWznmNavGlobal.h"
#include "PnlWznmNavHeadbar.h"
#include "PnlWznmNavJob.h"
#include "PnlWznmNavPre.h"
#include "PnlWznmNavProject.h"
#include "PnlWznmNavUix.h"
#include "PnlWznmOpk1NOp.h"
#include "PnlWznmOpkAInvarg.h"
#include "PnlWznmOpkARetval.h"
#include "PnlWznmOpkDetail.h"
#include "PnlWznmOpkHeadbar.h"
#include "PnlWznmOpkList.h"
#include "PnlWznmOpkMNComponent.h"
#include "PnlWznmOpkMNJob.h"
#include "PnlWznmOpkMNLibrary.h"
#include "PnlWznmOpkRec.h"
#include "PnlWznmOpkRef1NBlock.h"
#include "PnlWznmOpkSqkMNStub.h"
#include "PnlWznmOpxAInvarg.h"
#include "PnlWznmOpxARetval.h"
#include "PnlWznmOpxDetail.h"
#include "PnlWznmOpxHeadbar.h"
#include "PnlWznmOpxList.h"
#include "PnlWznmOpxMNJob.h"
#include "PnlWznmOpxRec.h"
#include "PnlWznmOpxRef1NBlock.h"
#include "PnlWznmOpxSqkMNStub.h"
#include "PnlWznmPnlDetail.h"
#include "PnlWznmPnlHeadbar.h"
#include "PnlWznmPnlHk1NControl.h"
#include "PnlWznmPnlList.h"
#include "PnlWznmPnlMNQuery.h"
#include "PnlWznmPnlRec.h"
#include "PnlWznmPrj1NVersion.h"
#include "PnlWznmPrjDetail.h"
#include "PnlWznmPrjHeadbar.h"
#include "PnlWznmPrjList.h"
#include "PnlWznmPrjMNPerson.h"
#include "PnlWznmPrjRec.h"
#include "PnlWznmPrsADetail.h"
#include "PnlWznmPrsDetail.h"
#include "PnlWznmPrsHeadbar.h"
#include "PnlWznmPrsList.h"
#include "PnlWznmPrsMNProject.h"
#include "PnlWznmPrsRec.h"
#include "PnlWznmPst1NQuerymod.h"
#include "PnlWznmPstDetail.h"
#include "PnlWznmPstHeadbar.h"
#include "PnlWznmPstList.h"
#include "PnlWznmPstRec.h"
#include "PnlWznmQcoDetail.h"
#include "PnlWznmQcoHeadbar.h"
#include "PnlWznmQcoList.h"
#include "PnlWznmQcoRec.h"
#include "PnlWznmQcoRef1NControl.h"
#include "PnlWznmQmdDetail.h"
#include "PnlWznmQmdHeadbar.h"
#include "PnlWznmQmdList.h"
#include "PnlWznmQmdRec.h"
#include "PnlWznmQry1NQuerymod.h"
#include "PnlWznmQryAClause.h"
#include "PnlWznmQryAOrder.h"
#include "PnlWznmQryDetail.h"
#include "PnlWznmQryHeadbar.h"
#include "PnlWznmQryList.h"
#include "PnlWznmQryMNDialog.h"
#include "PnlWznmQryMNPanel.h"
#include "PnlWznmQryMNTable.h"
#include "PnlWznmQryQry1NQuerycol.h"
#include "PnlWznmQryRec.h"
#include "PnlWznmQrySup1NQuery.h"
#include "PnlWznmRel1NTablecol.h"
#include "PnlWznmRelATitle.h"
#include "PnlWznmRelDetail.h"
#include "PnlWznmRelHeadbar.h"
#include "PnlWznmRelList.h"
#include "PnlWznmRelRec.h"
#include "PnlWznmRelRef1NControl.h"
#include "PnlWznmRelRef1NDialog.h"
#include "PnlWznmRelRef1NPanel.h"
#include "PnlWznmRelSup1NRelation.h"
#include "PnlWznmRlsDetail.h"
#include "PnlWznmRlsHeadbar.h"
#include "PnlWznmRlsList.h"
#include "PnlWznmRlsRec.h"
#include "PnlWznmRtj1NRtblock.h"
#include "PnlWznmRtj1NRtdpch.h"
#include "PnlWznmRtjDetail.h"
#include "PnlWznmRtjHeadbar.h"
#include "PnlWznmRtjList.h"
#include "PnlWznmRtjRec.h"
#include "PnlWznmRtjSup1NRtjob.h"
#include "PnlWznmSbs1NStub.h"
#include "PnlWznmSbs1NTablecol.h"
#include "PnlWznmSbsAsbMNSubset.h"
#include "PnlWznmSbsATitle.h"
#include "PnlWznmSbsBsbMNSubset.h"
#include "PnlWznmSbsDetail.h"
#include "PnlWznmSbsFrs1NRelation.h"
#include "PnlWznmSbsHeadbar.h"
#include "PnlWznmSbsList.h"
#include "PnlWznmSbsPst1NQuerymod.h"
#include "PnlWznmSbsRec.h"
#include "PnlWznmSbsTos1NRelation.h"
#include "PnlWznmSeqDetail.h"
#include "PnlWznmSeqHeadbar.h"
#include "PnlWznmSeqList.h"
#include "PnlWznmSeqRec.h"
#include "PnlWznmSeqSeq1NState.h"
#include "PnlWznmSge1NSensitivity.h"
#include "PnlWznmSgeDetail.h"
#include "PnlWznmSgeHeadbar.h"
#include "PnlWznmSgeList.h"
#include "PnlWznmSgeRec.h"
#include "PnlWznmSgeSqkMNStub.h"
#include "PnlWznmStbDetail.h"
#include "PnlWznmStbHeadbar.h"
#include "PnlWznmStbList.h"
#include "PnlWznmStbMNCall.h"
#include "PnlWznmStbMNSquawk.h"
#include "PnlWznmStbRec.h"
#include "PnlWznmStbSubMNStub.h"
#include "PnlWznmStbSupMNStub.h"
#include "PnlWznmSteATrig.h"
#include "PnlWznmSteDetail.h"
#include "PnlWznmSteHeadbar.h"
#include "PnlWznmSteList.h"
#include "PnlWznmSteRec.h"
#include "PnlWznmTagDetail.h"
#include "PnlWznmTagHeadbar.h"
#include "PnlWznmTagList.h"
#include "PnlWznmTagRec.h"
#include "PnlWznmTbl1NCheck.h"
#include "PnlWznmTbl1NImpexp.h"
#include "PnlWznmTbl1NStub.h"
#include "PnlWznmTbl1NSubset.h"
#include "PnlWznmTblALoadfct.h"
#include "PnlWznmTblATitle.h"
#include "PnlWznmTblDetail.h"
#include "PnlWznmTblFct1NTablecol.h"
#include "PnlWznmTblFr1NRelation.h"
#include "PnlWznmTblHeadbar.h"
#include "PnlWznmTblHk1NVector.h"
#include "PnlWznmTblList.h"
#include "PnlWznmTblMNQuery.h"
#include "PnlWznmTblMNVector.h"
#include "PnlWznmTblPst1NQuerymod.h"
#include "PnlWznmTblRec.h"
#include "PnlWznmTblRef1NCall.h"
#include "PnlWznmTblRef1NDialog.h"
#include "PnlWznmTblRef1NPanel.h"
#include "PnlWznmTblRef1NQuerymod.h"
#include "PnlWznmTblRef1NRtblock.h"
#include "PnlWznmTblSrc1NFeed.h"
#include "PnlWznmTblTbl1NTablecol.h"
#include "PnlWznmTblTo1NRelation.h"
#include "PnlWznmTco1NCheck.h"
#include "PnlWznmTco1NImpexpcol.h"
#include "PnlWznmTco1NQuerycol.h"
#include "PnlWznmTcoATitle.h"
#include "PnlWznmTcoDetail.h"
#include "PnlWznmTcoHeadbar.h"
#include "PnlWznmTcoList.h"
#include "PnlWznmTcoRec.h"
#include "PnlWznmTcoRef1NControl.h"
#include "PnlWznmTcoRef1NQuerymod.h"
#include "PnlWznmUsgAAccess.h"
#include "PnlWznmUsgDetail.h"
#include "PnlWznmUsgHeadbar.h"
#include "PnlWznmUsgList.h"
#include "PnlWznmUsgMNUser.h"
#include "PnlWznmUsgRec.h"
#include "PnlWznmUsr1NSession.h"
#include "PnlWznmUsrAAccess.h"
#include "PnlWznmUsrDetail.h"
#include "PnlWznmUsrHeadbar.h"
#include "PnlWznmUsrList.h"
#include "PnlWznmUsrMNUsergroup.h"
#include "PnlWznmUsrRec.h"
#include "PnlWznmUtlHeadbar.h"
#include "PnlWznmVecATitle.h"
#include "PnlWznmVecDetail.h"
#include "PnlWznmVecFct1NTablecol.h"
#include "PnlWznmVecHeadbar.h"
#include "PnlWznmVecList.h"
#include "PnlWznmVecMNTable.h"
#include "PnlWznmVecPst1NQuerymod.h"
#include "PnlWznmVecRec.h"
#include "PnlWznmVecRef1NPanel.h"
#include "PnlWznmVecSrc1NFeed.h"
#include "PnlWznmVecVec1NVectoritem.h"
#include "PnlWznmVer1NBlock.h"
#include "PnlWznmVer1NCall.h"
#include "PnlWznmVer1NCapability.h"
#include "PnlWznmVer1NComponent.h"
#include "PnlWznmVer1NImpexpcplx.h"
#include "PnlWznmVer1NJob.h"
#include "PnlWznmVer1NOppack.h"
#include "PnlWznmVer1NPreset.h"
#include "PnlWznmVer1NQuery.h"
#include "PnlWznmVer1NRelation.h"
#include "PnlWznmVer1NTable.h"
#include "PnlWznmVer1NVector.h"
#include "PnlWznmVerBvr1NVersion.h"
#include "PnlWznmVerDetail.h"
#include "PnlWznmVerHeadbar.h"
#include "PnlWznmVerList.h"
#include "PnlWznmVerMNLocale.h"
#include "PnlWznmVerRec.h"
#include "PnlWznmVerRef1NFile.h"
#include "PnlWznmVerVer1NApp.h"
#include "PnlWznmVerVer1NError.h"
#include "PnlWznmVerVer1NModule.h"
#include "PnlWznmVitDetail.h"
#include "PnlWznmVitHeadbar.h"
#include "PnlWznmVitList.h"
#include "PnlWznmVitRec.h"
#include "QryWznmApp1NEvent.h"
#include "QryWznmApp1NRtjob.h"
#include "QryWznmAppApp1NSequence.h"
#include "QryWznmAppList.h"
#include "QryWznmAppRef1NFile.h"
#include "QryWznmBlk1NRtdpch.h"
#include "QryWznmBlkAItem.h"
#include "QryWznmBlkList.h"
#include "QryWznmBlkRef1NRtblock.h"
#include "QryWznmCal1NSensitivity.h"
#include "QryWznmCalList.h"
#include "QryWznmCalMNStub.h"
#include "QryWznmCapAPar.h"
#include "QryWznmCapList.h"
#include "QryWznmCar1NDialog.h"
#include "QryWznmCarCar1NPanel.h"
#include "QryWznmCarHk1NControl.h"
#include "QryWznmCarList.h"
#include "QryWznmChkList.h"
#include "QryWznmChkRef1NCall.h"
#include "QryWznmCmp1NRelease.h"
#include "QryWznmCmpList.h"
#include "QryWznmCmpMNLibrary.h"
#include "QryWznmCmpMNOppack.h"
#include "QryWznmConAPar.h"
#include "QryWznmConFedRef1NRtblock.h"
#include "QryWznmConList.h"
#include "QryWznmConSup1NControl.h"
#include "QryWznmCtp1NTag.h"
#include "QryWznmCtpAPar.h"
#include "QryWznmCtpKKey.h"
#include "QryWznmCtpKParKey.h"
#include "QryWznmCtpList.h"
#include "QryWznmCtpTpl1NCapability.h"
#include "QryWznmDlgHk1NControl.h"
#include "QryWznmDlgList.h"
#include "QryWznmDlgMNQuery.h"
#include "QryWznmDlgRef1NControl.h"
#include "QryWznmErrList.h"
#include "QryWznmEvtList.h"
#include "QryWznmFilList.h"
#include "QryWznmIelList.h"
#include "QryWznmIex1NImpexp.h"
#include "QryWznmIexHk1NVector.h"
#include "QryWznmIexList.h"
#include "QryWznmIexRef1NDialog.h"
#include "QryWznmImeHk1NVector.h"
#include "QryWznmImeIme1NImpexpcol.h"
#include "QryWznmImeList.h"
#include "QryWznmImeSup1NImpexp.h"
#include "QryWznmJob1NMethod.h"
#include "QryWznmJob1NRtjob.h"
#include "QryWznmJob1NSensitivity.h"
#include "QryWznmJobACmd.h"
#include "QryWznmJobAVar.h"
#include "QryWznmJobHk1NVector.h"
#include "QryWznmJobJob1NStage.h"
#include "QryWznmJobList.h"
#include "QryWznmJobMNOp.h"
#include "QryWznmJobMNOppack.h"
#include "QryWznmJobRef1NBlock.h"
#include "QryWznmJobSubMNJob.h"
#include "QryWznmJobSupMNJob.h"
#include "QryWznmLibAMakefile.h"
#include "QryWznmLibAPkglist.h"
#include "QryWznmLibList.h"
#include "QryWznmLibMNComponent.h"
#include "QryWznmLibMNOppack.h"
#include "QryWznmLibRef1NFile.h"
#include "QryWznmLocList.h"
#include "QryWznmLocMNVersion.h"
#include "QryWznmMch1NRelease.h"
#include "QryWznmMchAPar.h"
#include "QryWznmMchList.h"
#include "QryWznmMdlList.h"
#include "QryWznmMdlMdl1NCard.h"
#include "QryWznmMdlRef1NPanel.h"
#include "QryWznmMtdAInvpar.h"
#include "QryWznmMtdARetpar.h"
#include "QryWznmMtdList.h"
#include "QryWznmMty1NMachine.h"
#include "QryWznmMtyAMakefile.h"
#include "QryWznmMtyList.h"
#include "QryWznmOpk1NOp.h"
#include "QryWznmOpkAInvarg.h"
#include "QryWznmOpkARetval.h"
#include "QryWznmOpkList.h"
#include "QryWznmOpkMNComponent.h"
#include "QryWznmOpkMNJob.h"
#include "QryWznmOpkMNLibrary.h"
#include "QryWznmOpkRef1NBlock.h"
#include "QryWznmOpkSqkMNStub.h"
#include "QryWznmOpxAInvarg.h"
#include "QryWznmOpxARetval.h"
#include "QryWznmOpxList.h"
#include "QryWznmOpxMNJob.h"
#include "QryWznmOpxRef1NBlock.h"
#include "QryWznmOpxSqkMNStub.h"
#include "QryWznmPnlHk1NControl.h"
#include "QryWznmPnlList.h"
#include "QryWznmPnlMNQuery.h"
#include "QryWznmPrj1NVersion.h"
#include "QryWznmPrjList.h"
#include "QryWznmPrjMNPerson.h"
#include "QryWznmPrsADetail.h"
#include "QryWznmPrsList.h"
#include "QryWznmPrsMNProject.h"
#include "QryWznmPst1NQuerymod.h"
#include "QryWznmPstList.h"
#include "QryWznmQcoList.h"
#include "QryWznmQcoRef1NControl.h"
#include "QryWznmQmdList.h"
#include "QryWznmQry1NQuerymod.h"
#include "QryWznmQryAClause.h"
#include "QryWznmQryAOrder.h"
#include "QryWznmQryList.h"
#include "QryWznmQryMNDialog.h"
#include "QryWznmQryMNPanel.h"
#include "QryWznmQryMNTable.h"
#include "QryWznmQryQry1NQuerycol.h"
#include "QryWznmQrySup1NQuery.h"
#include "QryWznmRel1NTablecol.h"
#include "QryWznmRelATitle.h"
#include "QryWznmRelList.h"
#include "QryWznmRelRef1NControl.h"
#include "QryWznmRelRef1NDialog.h"
#include "QryWznmRelRef1NPanel.h"
#include "QryWznmRelSup1NRelation.h"
#include "QryWznmRlsList.h"
#include "QryWznmRtj1NRtblock.h"
#include "QryWznmRtj1NRtdpch.h"
#include "QryWznmRtjList.h"
#include "QryWznmRtjSup1NRtjob.h"
#include "QryWznmSbs1NStub.h"
#include "QryWznmSbs1NTablecol.h"
#include "QryWznmSbsAsbMNSubset.h"
#include "QryWznmSbsATitle.h"
#include "QryWznmSbsBsbMNSubset.h"
#include "QryWznmSbsFrs1NRelation.h"
#include "QryWznmSbsList.h"
#include "QryWznmSbsPst1NQuerymod.h"
#include "QryWznmSbsTos1NRelation.h"
#include "QryWznmSeqList.h"
#include "QryWznmSeqSeq1NState.h"
#include "QryWznmSge1NSensitivity.h"
#include "QryWznmSgeList.h"
#include "QryWznmSgeSqkMNStub.h"
#include "QryWznmStbList.h"
#include "QryWznmStbMNCall.h"
#include "QryWznmStbMNSquawk.h"
#include "QryWznmStbSubMNStub.h"
#include "QryWznmStbSupMNStub.h"
#include "QryWznmSteATrig.h"
#include "QryWznmSteList.h"
#include "QryWznmTagList.h"
#include "QryWznmTbl1NCheck.h"
#include "QryWznmTbl1NImpexp.h"
#include "QryWznmTbl1NStub.h"
#include "QryWznmTbl1NSubset.h"
#include "QryWznmTblALoadfct.h"
#include "QryWznmTblATitle.h"
#include "QryWznmTblFct1NTablecol.h"
#include "QryWznmTblFr1NRelation.h"
#include "QryWznmTblHk1NVector.h"
#include "QryWznmTblList.h"
#include "QryWznmTblMNQuery.h"
#include "QryWznmTblMNVector.h"
#include "QryWznmTblPst1NQuerymod.h"
#include "QryWznmTblRef1NCall.h"
#include "QryWznmTblRef1NDialog.h"
#include "QryWznmTblRef1NPanel.h"
#include "QryWznmTblRef1NQuerymod.h"
#include "QryWznmTblRef1NRtblock.h"
#include "QryWznmTblSrc1NFeed.h"
#include "QryWznmTblTbl1NTablecol.h"
#include "QryWznmTblTo1NRelation.h"
#include "QryWznmTco1NCheck.h"
#include "QryWznmTco1NImpexpcol.h"
#include "QryWznmTco1NQuerycol.h"
#include "QryWznmTcoATitle.h"
#include "QryWznmTcoList.h"
#include "QryWznmTcoRef1NControl.h"
#include "QryWznmTcoRef1NQuerymod.h"
#include "QryWznmUsgAAccess.h"
#include "QryWznmUsgList.h"
#include "QryWznmUsgMNUser.h"
#include "QryWznmUsr1NSession.h"
#include "QryWznmUsrAAccess.h"
#include "QryWznmUsrList.h"
#include "QryWznmUsrMNUsergroup.h"
#include "QryWznmVecATitle.h"
#include "QryWznmVecFct1NTablecol.h"
#include "QryWznmVecList.h"
#include "QryWznmVecMNTable.h"
#include "QryWznmVecPst1NQuerymod.h"
#include "QryWznmVecRef1NPanel.h"
#include "QryWznmVecSrc1NFeed.h"
#include "QryWznmVecVec1NVectoritem.h"
#include "QryWznmVer1NBlock.h"
#include "QryWznmVer1NCall.h"
#include "QryWznmVer1NCapability.h"
#include "QryWznmVer1NComponent.h"
#include "QryWznmVer1NImpexpcplx.h"
#include "QryWznmVer1NJob.h"
#include "QryWznmVer1NOppack.h"
#include "QryWznmVer1NPreset.h"
#include "QryWznmVer1NQuery.h"
#include "QryWznmVer1NRelation.h"
#include "QryWznmVer1NTable.h"
#include "QryWznmVer1NVector.h"
#include "QryWznmVerBvr1NVersion.h"
#include "QryWznmVerList.h"
#include "QryWznmVerMNLocale.h"
#include "QryWznmVerRef1NFile.h"
#include "QryWznmVerVer1NApp.h"
#include "QryWznmVerVer1NError.h"
#include "QryWznmVerVer1NModule.h"
#include "QryWznmVitList.h"
#include "RootWznm.h"
#include "SessWznm.h"

/**
	* StgWznmapi
	*/
class StgWznmapi : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint ENGIP = 1;
	static const Sbecore::uint ENGPORT = 2;
	static const Sbecore::uint USERNAME = 3;
	static const Sbecore::uint PASSWORD = 4;

public:
	StgWznmapi(const std::string engip = "", const Sbecore::uint engport = 0, const std::string username = "", const std::string password = "");

public:
	std::string engip;
	Sbecore::uint engport;
	std::string username;
	std::string password;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const StgWznmapi* comp);
};

/**
	* ApiWznm
	*/
namespace ApiWznm {
	Sbecore::uint readDpchEng(char* buf, unsigned long buflen, DpchEngWznm** dpcheng);
	void writeDpchApp(DpchAppWznm* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif

