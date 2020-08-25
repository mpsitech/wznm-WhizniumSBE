#!/bin/bash
# file checkout.sh
# checkout script for Wznm daemon, release wznmd_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set LIBROOT=/home/ubuntu/lib
export set BINROOT=/home/ubuntu/bin
export set REPROOT=/home/ubuntu/srcrep
export set CMBDSRCROOT=$REPROOT/wznm/wznmcmbd

mkdir $SRCROOT/wznmd
mkdir $SRCROOT/wznmd/IexWznm
mkdir $SRCROOT/wznmd/VecWznm
mkdir $SRCROOT/wznmd/CrdWznmUsg
mkdir $SRCROOT/wznmd/CrdWznmUsr
mkdir $SRCROOT/wznmd/CrdWznmPrs
mkdir $SRCROOT/wznmd/CrdWznmFil
mkdir $SRCROOT/wznmd/CrdWznmNav
mkdir $SRCROOT/wznmd/CrdWznmLoc
mkdir $SRCROOT/wznmd/CrdWznmTag
mkdir $SRCROOT/wznmd/CrdWznmCtp
mkdir $SRCROOT/wznmd/CrdWznmMty
mkdir $SRCROOT/wznmd/CrdWznmMch
mkdir $SRCROOT/wznmd/CrdWznmLib
mkdir $SRCROOT/wznmd/CrdWznmPrj
mkdir $SRCROOT/wznmd/CrdWznmVer
mkdir $SRCROOT/wznmd/CrdWznmCap
mkdir $SRCROOT/wznmd/CrdWznmErr
mkdir $SRCROOT/wznmd/CrdWznmTbl
mkdir $SRCROOT/wznmd/CrdWznmTco
mkdir $SRCROOT/wznmd/CrdWznmSbs
mkdir $SRCROOT/wznmd/CrdWznmRel
mkdir $SRCROOT/wznmd/CrdWznmVec
mkdir $SRCROOT/wznmd/CrdWznmVit
mkdir $SRCROOT/wznmd/CrdWznmChk
mkdir $SRCROOT/wznmd/CrdWznmStb
mkdir $SRCROOT/wznmd/CrdWznmIex
mkdir $SRCROOT/wznmd/CrdWznmIme
mkdir $SRCROOT/wznmd/CrdWznmIel
mkdir $SRCROOT/wznmd/CrdWznmPst
mkdir $SRCROOT/wznmd/CrdWznmMdl
mkdir $SRCROOT/wznmd/CrdWznmCar
mkdir $SRCROOT/wznmd/CrdWznmDlg
mkdir $SRCROOT/wznmd/CrdWznmPnl
mkdir $SRCROOT/wznmd/CrdWznmQry
mkdir $SRCROOT/wznmd/CrdWznmQco
mkdir $SRCROOT/wznmd/CrdWznmQmd
mkdir $SRCROOT/wznmd/CrdWznmCon
mkdir $SRCROOT/wznmd/CrdWznmOpk
mkdir $SRCROOT/wznmd/CrdWznmOpx
mkdir $SRCROOT/wznmd/CrdWznmJob
mkdir $SRCROOT/wznmd/CrdWznmSge
mkdir $SRCROOT/wznmd/CrdWznmMtd
mkdir $SRCROOT/wznmd/CrdWznmBlk
mkdir $SRCROOT/wznmd/CrdWznmCal
mkdir $SRCROOT/wznmd/CrdWznmCmp
mkdir $SRCROOT/wznmd/CrdWznmRls
mkdir $SRCROOT/wznmd/CrdWznmApp
mkdir $SRCROOT/wznmd/CrdWznmRtj
mkdir $SRCROOT/wznmd/CrdWznmEvt
mkdir $SRCROOT/wznmd/CrdWznmSeq
mkdir $SRCROOT/wznmd/CrdWznmSte
mkdir $SRCROOT/wznmd/CrdWznmUtl

mkdir $LIBROOT/wznmd

mkdir $BINROOT/wznmd

cp make.sh $SRCROOT/wznmd/
cp remake.sh $SRCROOT/wznmd/

cp Makefile.inc $SRCROOT/wznmd/
cp Makefile $SRCROOT/wznmd/

cp ../../wznmd/Wznmd.h $SRCROOT/wznmd/
cp ../../wznmd/Wznmd.cpp $SRCROOT/wznmd/

cp ../../wznmd/WznmdAppsrv.h $SRCROOT/wznmd/
cp ../../wznmd/WznmdAppsrv.cpp $SRCROOT/wznmd/

cp ../../wznmd/WznmdJobprc.h $SRCROOT/wznmd/
cp ../../wznmd/WznmdJobprc.cpp $SRCROOT/wznmd/

cp ../../wznmd/WznmdOpprc.h $SRCROOT/wznmd/
cp ../../wznmd/WznmdOpprc.cpp $SRCROOT/wznmd/

cp ../../wznmd/WznmdOpengsrv.h $SRCROOT/wznmd/
cp ../../wznmd/WznmdOpengsrv.cpp $SRCROOT/wznmd/

cp ../../wznmd/WznmdOpengcli.h $SRCROOT/wznmd/
cp ../../wznmd/WznmdOpengcli.cpp $SRCROOT/wznmd/

cp ../../wznmd/Wznmd_exe.h $SRCROOT/wznmd/
cp ../../wznmd/Wznmd_exe.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/Wznm.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/Wznm.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/Root*.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/Root*.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/Sess*.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/Sess*.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/gbl/*.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/gbl/*.cpp $SRCROOT/wznmd/

cp Makefile_IexWznm $SRCROOT/wznmd/IexWznm/Makefile

cp $CMBDSRCROOT/IexWznm/IexWznm*.h $SRCROOT/wznmd/IexWznm/
cp $CMBDSRCROOT/IexWznm/IexWznm*.cpp $SRCROOT/wznmd/IexWznm/

cp $CMBDSRCROOT/IexWznm/JobWznmIex*.h $SRCROOT/wznmd/IexWznm/
cp $CMBDSRCROOT/IexWznm/JobWznmIex*.cpp $SRCROOT/wznmd/IexWznm/

cp Makefile_VecWznm $SRCROOT/wznmd/VecWznm/Makefile

cp $CMBDSRCROOT/VecWznm/Vec*.h $SRCROOT/wznmd/VecWznm/
cp $CMBDSRCROOT/VecWznm/Vec*.cpp $SRCROOT/wznmd/VecWznm/

cp Makefile_CrdWznmUsg $SRCROOT/wznmd/CrdWznmUsg/Makefile

cp $CMBDSRCROOT/CrdWznmUsg/*.h $SRCROOT/wznmd/CrdWznmUsg/
cp $CMBDSRCROOT/CrdWznmUsg/*.cpp $SRCROOT/wznmd/CrdWznmUsg/

cp Makefile_CrdWznmUsr $SRCROOT/wznmd/CrdWznmUsr/Makefile

cp $CMBDSRCROOT/CrdWznmUsr/*.h $SRCROOT/wznmd/CrdWznmUsr/
cp $CMBDSRCROOT/CrdWznmUsr/*.cpp $SRCROOT/wznmd/CrdWznmUsr/

cp Makefile_CrdWznmPrs $SRCROOT/wznmd/CrdWznmPrs/Makefile

cp $CMBDSRCROOT/CrdWznmPrs/*.h $SRCROOT/wznmd/CrdWznmPrs/
cp $CMBDSRCROOT/CrdWznmPrs/*.cpp $SRCROOT/wznmd/CrdWznmPrs/

cp Makefile_CrdWznmFil $SRCROOT/wznmd/CrdWznmFil/Makefile

cp $CMBDSRCROOT/CrdWznmFil/*.h $SRCROOT/wznmd/CrdWznmFil/
cp $CMBDSRCROOT/CrdWznmFil/*.cpp $SRCROOT/wznmd/CrdWznmFil/

cp Makefile_CrdWznmNav $SRCROOT/wznmd/CrdWznmNav/Makefile

cp $CMBDSRCROOT/CrdWznmNav/*.h $SRCROOT/wznmd/CrdWznmNav/
cp $CMBDSRCROOT/CrdWznmNav/*.cpp $SRCROOT/wznmd/CrdWznmNav/

cp Makefile_CrdWznmLoc $SRCROOT/wznmd/CrdWznmLoc/Makefile

cp $CMBDSRCROOT/CrdWznmLoc/*.h $SRCROOT/wznmd/CrdWznmLoc/
cp $CMBDSRCROOT/CrdWznmLoc/*.cpp $SRCROOT/wznmd/CrdWznmLoc/

cp Makefile_CrdWznmTag $SRCROOT/wznmd/CrdWznmTag/Makefile

cp $CMBDSRCROOT/CrdWznmTag/*.h $SRCROOT/wznmd/CrdWznmTag/
cp $CMBDSRCROOT/CrdWznmTag/*.cpp $SRCROOT/wznmd/CrdWznmTag/

cp Makefile_CrdWznmCtp $SRCROOT/wznmd/CrdWznmCtp/Makefile

cp $CMBDSRCROOT/CrdWznmCtp/*.h $SRCROOT/wznmd/CrdWznmCtp/
cp $CMBDSRCROOT/CrdWznmCtp/*.cpp $SRCROOT/wznmd/CrdWznmCtp/

cp Makefile_CrdWznmMty $SRCROOT/wznmd/CrdWznmMty/Makefile

cp $CMBDSRCROOT/CrdWznmMty/*.h $SRCROOT/wznmd/CrdWznmMty/
cp $CMBDSRCROOT/CrdWznmMty/*.cpp $SRCROOT/wznmd/CrdWznmMty/

cp Makefile_CrdWznmMch $SRCROOT/wznmd/CrdWznmMch/Makefile

cp $CMBDSRCROOT/CrdWznmMch/*.h $SRCROOT/wznmd/CrdWznmMch/
cp $CMBDSRCROOT/CrdWznmMch/*.cpp $SRCROOT/wznmd/CrdWznmMch/

cp Makefile_CrdWznmLib $SRCROOT/wznmd/CrdWznmLib/Makefile

cp $CMBDSRCROOT/CrdWznmLib/*.h $SRCROOT/wznmd/CrdWznmLib/
cp $CMBDSRCROOT/CrdWznmLib/*.cpp $SRCROOT/wznmd/CrdWznmLib/

cp Makefile_CrdWznmPrj $SRCROOT/wznmd/CrdWznmPrj/Makefile

cp $CMBDSRCROOT/CrdWznmPrj/*.h $SRCROOT/wznmd/CrdWznmPrj/
cp $CMBDSRCROOT/CrdWznmPrj/*.cpp $SRCROOT/wznmd/CrdWznmPrj/

cp Makefile_CrdWznmVer $SRCROOT/wznmd/CrdWznmVer/Makefile

cp $CMBDSRCROOT/CrdWznmVer/*.h $SRCROOT/wznmd/CrdWznmVer/
cp $CMBDSRCROOT/CrdWznmVer/*.cpp $SRCROOT/wznmd/CrdWznmVer/

cp Makefile_CrdWznmCap $SRCROOT/wznmd/CrdWznmCap/Makefile

cp $CMBDSRCROOT/CrdWznmCap/*.h $SRCROOT/wznmd/CrdWznmCap/
cp $CMBDSRCROOT/CrdWznmCap/*.cpp $SRCROOT/wznmd/CrdWznmCap/

cp Makefile_CrdWznmErr $SRCROOT/wznmd/CrdWznmErr/Makefile

cp $CMBDSRCROOT/CrdWznmErr/*.h $SRCROOT/wznmd/CrdWznmErr/
cp $CMBDSRCROOT/CrdWznmErr/*.cpp $SRCROOT/wznmd/CrdWznmErr/

cp Makefile_CrdWznmTbl $SRCROOT/wznmd/CrdWznmTbl/Makefile

cp $CMBDSRCROOT/CrdWznmTbl/*.h $SRCROOT/wznmd/CrdWznmTbl/
cp $CMBDSRCROOT/CrdWznmTbl/*.cpp $SRCROOT/wznmd/CrdWznmTbl/

cp Makefile_CrdWznmTco $SRCROOT/wznmd/CrdWznmTco/Makefile

cp $CMBDSRCROOT/CrdWznmTco/*.h $SRCROOT/wznmd/CrdWznmTco/
cp $CMBDSRCROOT/CrdWznmTco/*.cpp $SRCROOT/wznmd/CrdWznmTco/

cp Makefile_CrdWznmSbs $SRCROOT/wznmd/CrdWznmSbs/Makefile

cp $CMBDSRCROOT/CrdWznmSbs/*.h $SRCROOT/wznmd/CrdWznmSbs/
cp $CMBDSRCROOT/CrdWznmSbs/*.cpp $SRCROOT/wznmd/CrdWznmSbs/

cp Makefile_CrdWznmRel $SRCROOT/wznmd/CrdWznmRel/Makefile

cp $CMBDSRCROOT/CrdWznmRel/*.h $SRCROOT/wznmd/CrdWznmRel/
cp $CMBDSRCROOT/CrdWznmRel/*.cpp $SRCROOT/wznmd/CrdWznmRel/

cp Makefile_CrdWznmVec $SRCROOT/wznmd/CrdWznmVec/Makefile

cp $CMBDSRCROOT/CrdWznmVec/*.h $SRCROOT/wznmd/CrdWznmVec/
cp $CMBDSRCROOT/CrdWznmVec/*.cpp $SRCROOT/wznmd/CrdWznmVec/

cp Makefile_CrdWznmVit $SRCROOT/wznmd/CrdWznmVit/Makefile

cp $CMBDSRCROOT/CrdWznmVit/*.h $SRCROOT/wznmd/CrdWznmVit/
cp $CMBDSRCROOT/CrdWznmVit/*.cpp $SRCROOT/wznmd/CrdWznmVit/

cp Makefile_CrdWznmChk $SRCROOT/wznmd/CrdWznmChk/Makefile

cp $CMBDSRCROOT/CrdWznmChk/*.h $SRCROOT/wznmd/CrdWznmChk/
cp $CMBDSRCROOT/CrdWznmChk/*.cpp $SRCROOT/wznmd/CrdWznmChk/

cp Makefile_CrdWznmStb $SRCROOT/wznmd/CrdWznmStb/Makefile

cp $CMBDSRCROOT/CrdWznmStb/*.h $SRCROOT/wznmd/CrdWznmStb/
cp $CMBDSRCROOT/CrdWznmStb/*.cpp $SRCROOT/wznmd/CrdWznmStb/

cp Makefile_CrdWznmIex $SRCROOT/wznmd/CrdWznmIex/Makefile

cp $CMBDSRCROOT/CrdWznmIex/*.h $SRCROOT/wznmd/CrdWznmIex/
cp $CMBDSRCROOT/CrdWznmIex/*.cpp $SRCROOT/wznmd/CrdWznmIex/

cp Makefile_CrdWznmIme $SRCROOT/wznmd/CrdWznmIme/Makefile

cp $CMBDSRCROOT/CrdWznmIme/*.h $SRCROOT/wznmd/CrdWznmIme/
cp $CMBDSRCROOT/CrdWznmIme/*.cpp $SRCROOT/wznmd/CrdWznmIme/

cp Makefile_CrdWznmIel $SRCROOT/wznmd/CrdWznmIel/Makefile

cp $CMBDSRCROOT/CrdWznmIel/*.h $SRCROOT/wznmd/CrdWznmIel/
cp $CMBDSRCROOT/CrdWznmIel/*.cpp $SRCROOT/wznmd/CrdWznmIel/

cp Makefile_CrdWznmPst $SRCROOT/wznmd/CrdWznmPst/Makefile

cp $CMBDSRCROOT/CrdWznmPst/*.h $SRCROOT/wznmd/CrdWznmPst/
cp $CMBDSRCROOT/CrdWznmPst/*.cpp $SRCROOT/wznmd/CrdWznmPst/

cp Makefile_CrdWznmMdl $SRCROOT/wznmd/CrdWznmMdl/Makefile

cp $CMBDSRCROOT/CrdWznmMdl/*.h $SRCROOT/wznmd/CrdWznmMdl/
cp $CMBDSRCROOT/CrdWznmMdl/*.cpp $SRCROOT/wznmd/CrdWznmMdl/

cp Makefile_CrdWznmCar $SRCROOT/wznmd/CrdWznmCar/Makefile

cp $CMBDSRCROOT/CrdWznmCar/*.h $SRCROOT/wznmd/CrdWznmCar/
cp $CMBDSRCROOT/CrdWznmCar/*.cpp $SRCROOT/wznmd/CrdWznmCar/

cp Makefile_CrdWznmDlg $SRCROOT/wznmd/CrdWznmDlg/Makefile

cp $CMBDSRCROOT/CrdWznmDlg/*.h $SRCROOT/wznmd/CrdWznmDlg/
cp $CMBDSRCROOT/CrdWznmDlg/*.cpp $SRCROOT/wznmd/CrdWznmDlg/

cp Makefile_CrdWznmPnl $SRCROOT/wznmd/CrdWznmPnl/Makefile

cp $CMBDSRCROOT/CrdWznmPnl/*.h $SRCROOT/wznmd/CrdWznmPnl/
cp $CMBDSRCROOT/CrdWznmPnl/*.cpp $SRCROOT/wznmd/CrdWznmPnl/

cp Makefile_CrdWznmQry $SRCROOT/wznmd/CrdWznmQry/Makefile

cp $CMBDSRCROOT/CrdWznmQry/*.h $SRCROOT/wznmd/CrdWznmQry/
cp $CMBDSRCROOT/CrdWznmQry/*.cpp $SRCROOT/wznmd/CrdWznmQry/

cp Makefile_CrdWznmQco $SRCROOT/wznmd/CrdWznmQco/Makefile

cp $CMBDSRCROOT/CrdWznmQco/*.h $SRCROOT/wznmd/CrdWznmQco/
cp $CMBDSRCROOT/CrdWznmQco/*.cpp $SRCROOT/wznmd/CrdWznmQco/

cp Makefile_CrdWznmQmd $SRCROOT/wznmd/CrdWznmQmd/Makefile

cp $CMBDSRCROOT/CrdWznmQmd/*.h $SRCROOT/wznmd/CrdWznmQmd/
cp $CMBDSRCROOT/CrdWznmQmd/*.cpp $SRCROOT/wznmd/CrdWznmQmd/

cp Makefile_CrdWznmCon $SRCROOT/wznmd/CrdWznmCon/Makefile

cp $CMBDSRCROOT/CrdWznmCon/*.h $SRCROOT/wznmd/CrdWznmCon/
cp $CMBDSRCROOT/CrdWznmCon/*.cpp $SRCROOT/wznmd/CrdWznmCon/

cp Makefile_CrdWznmOpk $SRCROOT/wznmd/CrdWznmOpk/Makefile

cp $CMBDSRCROOT/CrdWznmOpk/*.h $SRCROOT/wznmd/CrdWznmOpk/
cp $CMBDSRCROOT/CrdWznmOpk/*.cpp $SRCROOT/wznmd/CrdWznmOpk/

cp Makefile_CrdWznmOpx $SRCROOT/wznmd/CrdWznmOpx/Makefile

cp $CMBDSRCROOT/CrdWznmOpx/*.h $SRCROOT/wznmd/CrdWznmOpx/
cp $CMBDSRCROOT/CrdWznmOpx/*.cpp $SRCROOT/wznmd/CrdWznmOpx/

cp Makefile_CrdWznmJob $SRCROOT/wznmd/CrdWznmJob/Makefile

cp $CMBDSRCROOT/CrdWznmJob/*.h $SRCROOT/wznmd/CrdWznmJob/
cp $CMBDSRCROOT/CrdWznmJob/*.cpp $SRCROOT/wznmd/CrdWznmJob/

cp Makefile_CrdWznmSge $SRCROOT/wznmd/CrdWznmSge/Makefile

cp $CMBDSRCROOT/CrdWznmSge/*.h $SRCROOT/wznmd/CrdWznmSge/
cp $CMBDSRCROOT/CrdWznmSge/*.cpp $SRCROOT/wznmd/CrdWznmSge/

cp Makefile_CrdWznmMtd $SRCROOT/wznmd/CrdWznmMtd/Makefile

cp $CMBDSRCROOT/CrdWznmMtd/*.h $SRCROOT/wznmd/CrdWznmMtd/
cp $CMBDSRCROOT/CrdWznmMtd/*.cpp $SRCROOT/wznmd/CrdWznmMtd/

cp Makefile_CrdWznmBlk $SRCROOT/wznmd/CrdWznmBlk/Makefile

cp $CMBDSRCROOT/CrdWznmBlk/*.h $SRCROOT/wznmd/CrdWznmBlk/
cp $CMBDSRCROOT/CrdWznmBlk/*.cpp $SRCROOT/wznmd/CrdWznmBlk/

cp Makefile_CrdWznmCal $SRCROOT/wznmd/CrdWznmCal/Makefile

cp $CMBDSRCROOT/CrdWznmCal/*.h $SRCROOT/wznmd/CrdWznmCal/
cp $CMBDSRCROOT/CrdWznmCal/*.cpp $SRCROOT/wznmd/CrdWznmCal/

cp Makefile_CrdWznmCmp $SRCROOT/wznmd/CrdWznmCmp/Makefile

cp $CMBDSRCROOT/CrdWznmCmp/*.h $SRCROOT/wznmd/CrdWznmCmp/
cp $CMBDSRCROOT/CrdWznmCmp/*.cpp $SRCROOT/wznmd/CrdWznmCmp/

cp Makefile_CrdWznmRls $SRCROOT/wznmd/CrdWznmRls/Makefile

cp $CMBDSRCROOT/CrdWznmRls/*.h $SRCROOT/wznmd/CrdWznmRls/
cp $CMBDSRCROOT/CrdWznmRls/*.cpp $SRCROOT/wznmd/CrdWznmRls/

cp Makefile_CrdWznmApp $SRCROOT/wznmd/CrdWznmApp/Makefile

cp $CMBDSRCROOT/CrdWznmApp/*.h $SRCROOT/wznmd/CrdWznmApp/
cp $CMBDSRCROOT/CrdWznmApp/*.cpp $SRCROOT/wznmd/CrdWznmApp/

cp Makefile_CrdWznmRtj $SRCROOT/wznmd/CrdWznmRtj/Makefile

cp $CMBDSRCROOT/CrdWznmRtj/*.h $SRCROOT/wznmd/CrdWznmRtj/
cp $CMBDSRCROOT/CrdWznmRtj/*.cpp $SRCROOT/wznmd/CrdWznmRtj/

cp Makefile_CrdWznmEvt $SRCROOT/wznmd/CrdWznmEvt/Makefile

cp $CMBDSRCROOT/CrdWznmEvt/*.h $SRCROOT/wznmd/CrdWznmEvt/
cp $CMBDSRCROOT/CrdWznmEvt/*.cpp $SRCROOT/wznmd/CrdWznmEvt/

cp Makefile_CrdWznmSeq $SRCROOT/wznmd/CrdWznmSeq/Makefile

cp $CMBDSRCROOT/CrdWznmSeq/*.h $SRCROOT/wznmd/CrdWznmSeq/
cp $CMBDSRCROOT/CrdWznmSeq/*.cpp $SRCROOT/wznmd/CrdWznmSeq/

cp Makefile_CrdWznmSte $SRCROOT/wznmd/CrdWznmSte/Makefile

cp $CMBDSRCROOT/CrdWznmSte/*.h $SRCROOT/wznmd/CrdWznmSte/
cp $CMBDSRCROOT/CrdWznmSte/*.cpp $SRCROOT/wznmd/CrdWznmSte/

cp Makefile_CrdWznmUtl $SRCROOT/wznmd/CrdWznmUtl/Makefile

cp $CMBDSRCROOT/CrdWznmUtl/*.h $SRCROOT/wznmd/CrdWznmUtl/
cp $CMBDSRCROOT/CrdWznmUtl/*.cpp $SRCROOT/wznmd/CrdWznmUtl/

cp $CMBDSRCROOT/WznmWrsrv/WznmWrsrv_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrsrv/WznmWrsrv_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrsrv/SqkWznmWrsrv.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrsrv/SqkWznmWrsrv.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmWrweb/WznmWrweb_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrweb/WznmWrweb_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrweb/SqkWznmWrweb.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrweb/SqkWznmWrweb.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmWrjapi/WznmWrjapi_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrjapi/WznmWrjapi_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrjapi/SqkWznmWrjapi.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrjapi/SqkWznmWrjapi.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmWrdbs/WznmWrdbs_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrdbs/WznmWrdbs_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrdbs/SqkWznmWrdbs.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrdbs/SqkWznmWrdbs.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmPrctree/WznmPrctree_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrctree/WznmPrctree_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrctree/SqkWznmPrctree.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrctree/SqkWznmPrctree.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmWrapp/WznmWrapp_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapp/WznmWrapp_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapp/SqkWznmWrapp.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapp/SqkWznmWrapp.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmWrapi/WznmWrapi_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapi/WznmWrapi_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapi/SqkWznmWrapi.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmWrapi/SqkWznmWrapi.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmPrcfile/WznmPrcfile_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrcfile/WznmPrcfile_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrcfile/SqkWznmPrcfile.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmPrcfile/SqkWznmPrcfile.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmGen/WznmGen_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmGen/WznmGen_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmGen/SqkWznmGen.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmGen/SqkWznmGen.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCtpWrweb/WznmCtpWrweb_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrweb/WznmCtpWrweb_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrweb/SqkWznmCtpWrweb.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrweb/SqkWznmCtpWrweb.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCtpWrsrv/WznmCtpWrsrv_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrsrv/WznmCtpWrsrv_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrsrv/SqkWznmCtpWrsrv.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrsrv/SqkWznmCtpWrsrv.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCtpGenui/WznmCtpGenui_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenui/WznmCtpGenui_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenui/SqkWznmCtpGenui.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenui/SqkWznmCtpGenui.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCtpWrstkit/WznmCtpWrstkit_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrstkit/WznmCtpWrstkit_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrstkit/SqkWznmCtpWrstkit.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpWrstkit/SqkWznmCtpWrstkit.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCtpGenjtr/WznmCtpGenjtr_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenjtr/WznmCtpGenjtr_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenjtr/SqkWznmCtpGenjtr.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCtpGenjtr/SqkWznmCtpGenjtr.cpp $SRCROOT/wznmd/

cp $CMBDSRCROOT/WznmCompl/WznmCompl_blks.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCompl/WznmCompl_blks.cpp $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCompl/SqkWznmCompl.h $SRCROOT/wznmd/
cp $CMBDSRCROOT/WznmCompl/SqkWznmCompl.cpp $SRCROOT/wznmd/

