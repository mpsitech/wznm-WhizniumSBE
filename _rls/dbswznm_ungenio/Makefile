# file Makefile
# make file for Wznm database access library, release dbswznm_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

LIBROOT = /Users/mpsitech/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I/Library/PostgreSQL/9.6/include -I/usr/local/include -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = DbsWznm.h.gch

OBJS = DbsWznm.o
OBJS += WznmAccRMUserUniversal.o WznmAMBlockItem.o WznmAMCapabilityPar.o WznmAMControlPar.o WznmAMJobCmd.o WznmAMJobVar.o WznmAMLibraryMakefile.o WznmAMLibraryPkglist.o WznmAMMachinePar.o WznmAMMachtypeMakefile.o WznmAMMethodInvpar.o WznmAMMethodRetpar.o WznmAMOpInvarg.o WznmAMOppackInvarg.o WznmAMOppackRetval.o WznmAMOpRetval.o WznmAMPersonDetail.o WznmAMQueryClause.o WznmAMQueryOrder.o WznmAMRelationTitle.o WznmAMStateAction.o WznmAMStateTrig.o WznmAMSubsetTitle.o WznmAMTablecolTitle.o WznmAMTableLoadfct.o WznmAMTableTitle.o WznmAMUserAccess.o WznmAMUsergroupAccess.o WznmAMVectorTitle.o WznmAVControlPar.o WznmAVKeylistKey.o WznmAVValuelistVal.o WznmCAMBlockItem.o WznmCAMJobVar.o WznmCAMOpInvarg.o WznmCAMOppackInvarg.o WznmCAMOppackRetval.o WznmCAMOpRetval.o WznmCControl.o WznmCFile.o WznmCRelation.o WznmHistRMUserUniversal.o WznmJAMBlockItem.o WznmJAMStateTrigCond.o WznmJAVKeylistKey.o WznmJMCardTitle.o WznmJMControl.o WznmJMControlTitle.o WznmJMErrorTitle.o WznmJMImpexpcolStub.o WznmJMImpexpcplxTitle.o WznmJMLocaleTitle.o WznmJMModule.o WznmJMPersonLastname.o WznmJMPresetTitle.o WznmJMQuerycolStub.o WznmJMSquawkTitle.o WznmJMTagTitle.o WznmJMUserState.o WznmJMVectoritem.o WznmJMVersion.o WznmJMVersionState.o WznmMApp.o WznmMBlock.o WznmMCall.o WznmMCapability.o WznmMCard.o WznmMCheck.o WznmMComponent.o WznmMControl.o WznmMDialog.o WznmMError.o WznmMEvent.o WznmMFeed.o WznmMFile.o WznmMImpexp.o WznmMImpexpcol.o WznmMImpexpcplx.o WznmMJob.o WznmMLibrary.o WznmMLocale.o WznmMMachine.o WznmMMachtype.o WznmMMethod.o WznmMModule.o WznmMOp.o WznmMOppack.o WznmMPanel.o WznmMPerson.o WznmMPreset.o WznmMProject.o WznmMQuery.o WznmMQuerycol.o WznmMQuerymod.o WznmMRelation.o WznmMRelease.o WznmMRtblock.o WznmMRtdpch.o WznmMRtjob.o WznmMSensitivity.o WznmMSequence.o WznmMSession.o WznmMSquawk.o WznmMStage.o WznmMState.o WznmMStub.o WznmMSubset.o WznmMTable.o WznmMTablecol.o WznmMTag.o WznmMUser.o WznmMUsergroup.o WznmMVector.o WznmMVectoritem.o WznmMVersion.o WznmRMCallMStub.o WznmRMCapabilityUniversal.o WznmRMComponentMLibrary.o WznmRMComponentMOppack.o WznmRMDialogMQuery.o WznmRMJobMJob.o WznmRMJobMOp.o WznmRMJobMOppack.o WznmRMLibraryMOppack.o WznmRMLocaleMVersion.o WznmRMPanelMQuery.o WznmRMPersonMProject.o WznmRMQueryMTable.o WznmRMSquawkMStub.o WznmRMStubMStub.o WznmRMSubsetMSubset.o WznmRMTableMVector.o WznmRMUsergroupUniversal.o WznmRMUserMUsergroup.o WznmTMQuerymodMQuery.o
OBJS += WznmQApp1NEvent.o WznmQApp1NRtjob.o WznmQAppApp1NSequence.o WznmQAppList.o WznmQAppRef1NFile.o WznmQBlk1NRtdpch.o WznmQBlkAItem.o WznmQBlkList.o WznmQBlkRef1NRtblock.o WznmQCal1NSensitivity.o WznmQCalList.o WznmQCalMNStub.o WznmQCapAPar.o WznmQCapList.o WznmQCar1NDialog.o WznmQCarCar1NPanel.o WznmQCarHk1NControl.o WznmQCarList.o WznmQChkList.o WznmQChkRef1NCall.o WznmQCmp1NRelease.o WznmQCmpList.o WznmQCmpMNLibrary.o WznmQCmpMNOppack.o WznmQConAPar.o WznmQConFedRef1NRtblock.o WznmQConList.o WznmQConSup1NControl.o WznmQCtp1NTag.o WznmQCtpAPar.o WznmQCtpKKey.o WznmQCtpKParKey.o WznmQCtpList.o WznmQCtpTpl1NCapability.o WznmQDlgHk1NControl.o WznmQDlgList.o WznmQDlgMNQuery.o WznmQDlgRef1NControl.o WznmQErrList.o WznmQEvtList.o WznmQFilList.o WznmQIelList.o WznmQIex1NImpexp.o WznmQIexHk1NVector.o WznmQIexList.o WznmQIexRef1NDialog.o WznmQImeHk1NVector.o WznmQImeIme1NImpexpcol.o WznmQImeList.o WznmQImeSup1NImpexp.o WznmQJob1NMethod.o WznmQJob1NRtjob.o WznmQJob1NSensitivity.o WznmQJobACmd.o WznmQJobAVar.o WznmQJobHk1NVector.o WznmQJobJob1NStage.o WznmQJobList.o WznmQJobMNOp.o WznmQJobMNOppack.o WznmQJobRef1NBlock.o WznmQJobSubMNJob.o WznmQJobSupMNJob.o WznmQLibAMakefile.o WznmQLibAPkglist.o WznmQLibList.o WznmQLibMNComponent.o WznmQLibMNOppack.o WznmQLibRef1NFile.o WznmQLocList.o WznmQLocMNVersion.o WznmQMch1NRelease.o WznmQMchAPar.o WznmQMchList.o WznmQMdlList.o WznmQMdlMdl1NCard.o WznmQMdlRef1NPanel.o WznmQMtdAInvpar.o WznmQMtdARetpar.o WznmQMtdList.o WznmQMty1NMachine.o WznmQMtyAMakefile.o WznmQMtyList.o WznmQOpk1NOp.o WznmQOpkAInvarg.o WznmQOpkARetval.o WznmQOpkList.o WznmQOpkMNComponent.o WznmQOpkMNJob.o WznmQOpkMNLibrary.o WznmQOpkRef1NBlock.o WznmQOpkSqkMNStub.o WznmQOpxAInvarg.o WznmQOpxARetval.o WznmQOpxList.o WznmQOpxMNJob.o WznmQOpxRef1NBlock.o WznmQOpxSqkMNStub.o WznmQPnlHk1NControl.o WznmQPnlList.o WznmQPnlMNQuery.o WznmQPreselect.o WznmQPrj1NVersion.o WznmQPrjList.o WznmQPrjMNPerson.o WznmQPrsADetail.o WznmQPrsList.o WznmQPrsMNProject.o WznmQPst1NQuerymod.o WznmQPstList.o WznmQQcoList.o WznmQQcoRef1NControl.o WznmQQmdList.o WznmQQry1NQuerymod.o WznmQQryAClause.o WznmQQryAOrder.o WznmQQryList.o WznmQQryMNDialog.o WznmQQryMNPanel.o WznmQQryMNTable.o WznmQQryQry1NQuerycol.o WznmQQrySup1NQuery.o WznmQRel1NTablecol.o WznmQRelATitle.o WznmQRelList.o WznmQRelRef1NControl.o WznmQRelRef1NDialog.o WznmQRelRef1NPanel.o WznmQRelSup1NRelation.o WznmQRlsList.o WznmQRtj1NRtblock.o WznmQRtj1NRtdpch.o WznmQRtjList.o WznmQRtjSup1NRtjob.o WznmQSbs1NStub.o WznmQSbs1NTablecol.o WznmQSbsAsbMNSubset.o WznmQSbsATitle.o WznmQSbsBsbMNSubset.o WznmQSbsFrs1NRelation.o WznmQSbsList.o WznmQSbsPst1NQuerymod.o WznmQSbsTos1NRelation.o WznmQSelect.o WznmQSeqList.o WznmQSeqSeq1NState.o WznmQSge1NSensitivity.o WznmQSgeList.o WznmQSgeSqkMNStub.o WznmQStbList.o WznmQStbMNCall.o WznmQStbMNSquawk.o WznmQStbSubMNStub.o WznmQStbSupMNStub.o WznmQSteATrig.o WznmQSteList.o WznmQTagList.o WznmQTbl1NCheck.o WznmQTbl1NImpexp.o WznmQTbl1NStub.o WznmQTbl1NSubset.o WznmQTblALoadfct.o WznmQTblATitle.o WznmQTblFct1NTablecol.o WznmQTblFr1NRelation.o WznmQTblHk1NVector.o WznmQTblList.o WznmQTblMNQuery.o WznmQTblMNVector.o WznmQTblPst1NQuerymod.o WznmQTblRef1NCall.o WznmQTblRef1NDialog.o WznmQTblRef1NPanel.o WznmQTblRef1NQuerymod.o WznmQTblRef1NRtblock.o WznmQTblSrc1NFeed.o WznmQTblTbl1NTablecol.o WznmQTblTo1NRelation.o WznmQTco1NCheck.o WznmQTco1NImpexpcol.o WznmQTco1NQuerycol.o WznmQTcoATitle.o WznmQTcoList.o WznmQTcoRef1NControl.o WznmQTcoRef1NQuerymod.o WznmQUsgAAccess.o WznmQUsgList.o WznmQUsgMNUser.o WznmQUsr1NSession.o WznmQUsrAAccess.o WznmQUsrList.o WznmQUsrMNUsergroup.o WznmQVecATitle.o WznmQVecFct1NTablecol.o WznmQVecList.o WznmQVecMNTable.o WznmQVecPst1NQuerymod.o WznmQVecRef1NPanel.o WznmQVecSrc1NFeed.o WznmQVecVec1NVectoritem.o WznmQVer1NBlock.o WznmQVer1NCall.o WznmQVer1NCapability.o WznmQVer1NComponent.o WznmQVer1NImpexpcplx.o WznmQVer1NJob.o WznmQVer1NOppack.o WznmQVer1NPreset.o WznmQVer1NQuery.o WznmQVer1NRelation.o WznmQVer1NTable.o WznmQVer1NVector.o WznmQVerBvr1NVersion.o WznmQVerList.o WznmQVerMNLocale.o WznmQVerRef1NFile.o WznmQVerVer1NApp.o WznmQVerVer1NError.o WznmQVerVer1NModule.o WznmQVitList.o

LIB = libdbswznm

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

