#!/bin/bash
# file checkout.sh
# checkout script for Wznm combined daemon, release wznmcmbd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src
export set LIBROOT=/Users/mpsitech/lib
export set BINROOT=/Users/mpsitech/bin

mkdir $SRCROOT/wznmcmbd
mkdir $SRCROOT/wznmcmbd/IexWznm
mkdir $SRCROOT/wznmcmbd/VecWznm
mkdir $SRCROOT/wznmcmbd/CrdWznmUsg
mkdir $SRCROOT/wznmcmbd/CrdWznmUsr
mkdir $SRCROOT/wznmcmbd/CrdWznmPrs
mkdir $SRCROOT/wznmcmbd/CrdWznmFil
mkdir $SRCROOT/wznmcmbd/CrdWznmNav
mkdir $SRCROOT/wznmcmbd/CrdWznmLoc
mkdir $SRCROOT/wznmcmbd/CrdWznmTag
mkdir $SRCROOT/wznmcmbd/CrdWznmCtp
mkdir $SRCROOT/wznmcmbd/CrdWznmMty
mkdir $SRCROOT/wznmcmbd/CrdWznmMch
mkdir $SRCROOT/wznmcmbd/CrdWznmLib
mkdir $SRCROOT/wznmcmbd/CrdWznmPrj
mkdir $SRCROOT/wznmcmbd/CrdWznmVer
mkdir $SRCROOT/wznmcmbd/CrdWznmCap
mkdir $SRCROOT/wznmcmbd/CrdWznmErr
mkdir $SRCROOT/wznmcmbd/CrdWznmTbl
mkdir $SRCROOT/wznmcmbd/CrdWznmTco
mkdir $SRCROOT/wznmcmbd/CrdWznmSbs
mkdir $SRCROOT/wznmcmbd/CrdWznmRel
mkdir $SRCROOT/wznmcmbd/CrdWznmVec
mkdir $SRCROOT/wznmcmbd/CrdWznmVit
mkdir $SRCROOT/wznmcmbd/CrdWznmChk
mkdir $SRCROOT/wznmcmbd/CrdWznmStb
mkdir $SRCROOT/wznmcmbd/CrdWznmIex
mkdir $SRCROOT/wznmcmbd/CrdWznmIme
mkdir $SRCROOT/wznmcmbd/CrdWznmIel
mkdir $SRCROOT/wznmcmbd/CrdWznmPst
mkdir $SRCROOT/wznmcmbd/CrdWznmMdl
mkdir $SRCROOT/wznmcmbd/CrdWznmCar
mkdir $SRCROOT/wznmcmbd/CrdWznmDlg
mkdir $SRCROOT/wznmcmbd/CrdWznmPnl
mkdir $SRCROOT/wznmcmbd/CrdWznmQry
mkdir $SRCROOT/wznmcmbd/CrdWznmQco
mkdir $SRCROOT/wznmcmbd/CrdWznmQmd
mkdir $SRCROOT/wznmcmbd/CrdWznmCon
mkdir $SRCROOT/wznmcmbd/CrdWznmOpk
mkdir $SRCROOT/wznmcmbd/CrdWznmOpx
mkdir $SRCROOT/wznmcmbd/CrdWznmJob
mkdir $SRCROOT/wznmcmbd/CrdWznmSge
mkdir $SRCROOT/wznmcmbd/CrdWznmMtd
mkdir $SRCROOT/wznmcmbd/CrdWznmBlk
mkdir $SRCROOT/wznmcmbd/CrdWznmCal
mkdir $SRCROOT/wznmcmbd/CrdWznmCmp
mkdir $SRCROOT/wznmcmbd/CrdWznmRls
mkdir $SRCROOT/wznmcmbd/CrdWznmApp
mkdir $SRCROOT/wznmcmbd/CrdWznmRtj
mkdir $SRCROOT/wznmcmbd/CrdWznmSeq
mkdir $SRCROOT/wznmcmbd/CrdWznmSte
mkdir $SRCROOT/wznmcmbd/CrdWznmUtl
mkdir $SRCROOT/wznmcmbd/WznmWrweb
mkdir $SRCROOT/wznmcmbd/WznmWrjapi
mkdir $SRCROOT/wznmcmbd/WznmWrsrv
mkdir $SRCROOT/wznmcmbd/WznmWrdbs
mkdir $SRCROOT/wznmcmbd/WznmWrapp
mkdir $SRCROOT/wznmcmbd/WznmPrctree
mkdir $SRCROOT/wznmcmbd/WznmWrapi
mkdir $SRCROOT/wznmcmbd/WznmGen
mkdir $SRCROOT/wznmcmbd/WznmPrcfile
mkdir $SRCROOT/wznmcmbd/WznmCtpWrsrv
mkdir $SRCROOT/wznmcmbd/WznmCtpWrweb
mkdir $SRCROOT/wznmcmbd/WznmCtpWrstkit
mkdir $SRCROOT/wznmcmbd/WznmCtpGenui
mkdir $SRCROOT/wznmcmbd/WznmCompl
mkdir $SRCROOT/wznmcmbd/WznmCtpGenjtr

mkdir $LIBROOT/wznmcmbd

mkdir $BINROOT/wznmcmbd

cp make.sh $SRCROOT/wznmcmbd/
cp remake.sh $SRCROOT/wznmcmbd/

cp Makefile.inc $SRCROOT/wznmcmbd/
cp Makefile $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/Wznmcmbd.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/Wznmcmbd.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdAppsrv.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdAppsrv.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdJobprc.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdJobprc.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdOpprc.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdOpprc.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/Wznmcmbd_exe.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/Wznmcmbd_exe.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/Wznm.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/Wznm.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/Root*.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/Root*.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/Sess*.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/Sess*.cpp $SRCROOT/wznmcmbd/

cp ../../wznmcmbd/gbl/*.h $SRCROOT/wznmcmbd/
cp ../../wznmcmbd/gbl/*.cpp $SRCROOT/wznmcmbd/

cp Makefile_IexWznm $SRCROOT/wznmcmbd/IexWznm/Makefile

cp ../../wznmcmbd/IexWznm/IexWznm*.h $SRCROOT/wznmcmbd/IexWznm/
cp ../../wznmcmbd/IexWznm/IexWznm*.cpp $SRCROOT/wznmcmbd/IexWznm/

cp ../../wznmcmbd/IexWznm/JobWznmIex*.h $SRCROOT/wznmcmbd/IexWznm/
cp ../../wznmcmbd/IexWznm/JobWznmIex*.cpp $SRCROOT/wznmcmbd/IexWznm/

cp Makefile_VecWznm $SRCROOT/wznmcmbd/VecWznm/Makefile

cp ../../wznmcmbd/VecWznm/Vec*.h $SRCROOT/wznmcmbd/VecWznm/
cp ../../wznmcmbd/VecWznm/Vec*.cpp $SRCROOT/wznmcmbd/VecWznm/

cp Makefile_CrdWznmUsg $SRCROOT/wznmcmbd/CrdWznmUsg/Makefile

cp ../../wznmcmbd/CrdWznmUsg/*.h $SRCROOT/wznmcmbd/CrdWznmUsg/
cp ../../wznmcmbd/CrdWznmUsg/*.cpp $SRCROOT/wznmcmbd/CrdWznmUsg/

cp Makefile_CrdWznmUsr $SRCROOT/wznmcmbd/CrdWznmUsr/Makefile

cp ../../wznmcmbd/CrdWznmUsr/*.h $SRCROOT/wznmcmbd/CrdWznmUsr/
cp ../../wznmcmbd/CrdWznmUsr/*.cpp $SRCROOT/wznmcmbd/CrdWznmUsr/

cp Makefile_CrdWznmPrs $SRCROOT/wznmcmbd/CrdWznmPrs/Makefile

cp ../../wznmcmbd/CrdWznmPrs/*.h $SRCROOT/wznmcmbd/CrdWznmPrs/
cp ../../wznmcmbd/CrdWznmPrs/*.cpp $SRCROOT/wznmcmbd/CrdWznmPrs/

cp Makefile_CrdWznmFil $SRCROOT/wznmcmbd/CrdWznmFil/Makefile

cp ../../wznmcmbd/CrdWznmFil/*.h $SRCROOT/wznmcmbd/CrdWznmFil/
cp ../../wznmcmbd/CrdWznmFil/*.cpp $SRCROOT/wznmcmbd/CrdWznmFil/

cp Makefile_CrdWznmNav $SRCROOT/wznmcmbd/CrdWznmNav/Makefile

cp ../../wznmcmbd/CrdWznmNav/*.h $SRCROOT/wznmcmbd/CrdWznmNav/
cp ../../wznmcmbd/CrdWznmNav/*.cpp $SRCROOT/wznmcmbd/CrdWznmNav/

cp Makefile_CrdWznmLoc $SRCROOT/wznmcmbd/CrdWznmLoc/Makefile

cp ../../wznmcmbd/CrdWznmLoc/*.h $SRCROOT/wznmcmbd/CrdWznmLoc/
cp ../../wznmcmbd/CrdWznmLoc/*.cpp $SRCROOT/wznmcmbd/CrdWznmLoc/

cp Makefile_CrdWznmTag $SRCROOT/wznmcmbd/CrdWznmTag/Makefile

cp ../../wznmcmbd/CrdWznmTag/*.h $SRCROOT/wznmcmbd/CrdWznmTag/
cp ../../wznmcmbd/CrdWznmTag/*.cpp $SRCROOT/wznmcmbd/CrdWznmTag/

cp Makefile_CrdWznmCtp $SRCROOT/wznmcmbd/CrdWznmCtp/Makefile

cp ../../wznmcmbd/CrdWznmCtp/*.h $SRCROOT/wznmcmbd/CrdWznmCtp/
cp ../../wznmcmbd/CrdWznmCtp/*.cpp $SRCROOT/wznmcmbd/CrdWznmCtp/

cp Makefile_CrdWznmMty $SRCROOT/wznmcmbd/CrdWznmMty/Makefile

cp ../../wznmcmbd/CrdWznmMty/*.h $SRCROOT/wznmcmbd/CrdWznmMty/
cp ../../wznmcmbd/CrdWznmMty/*.cpp $SRCROOT/wznmcmbd/CrdWznmMty/

cp Makefile_CrdWznmMch $SRCROOT/wznmcmbd/CrdWznmMch/Makefile

cp ../../wznmcmbd/CrdWznmMch/*.h $SRCROOT/wznmcmbd/CrdWznmMch/
cp ../../wznmcmbd/CrdWznmMch/*.cpp $SRCROOT/wznmcmbd/CrdWznmMch/

cp Makefile_CrdWznmLib $SRCROOT/wznmcmbd/CrdWznmLib/Makefile

cp ../../wznmcmbd/CrdWznmLib/*.h $SRCROOT/wznmcmbd/CrdWznmLib/
cp ../../wznmcmbd/CrdWznmLib/*.cpp $SRCROOT/wznmcmbd/CrdWznmLib/

cp Makefile_CrdWznmPrj $SRCROOT/wznmcmbd/CrdWznmPrj/Makefile

cp ../../wznmcmbd/CrdWznmPrj/*.h $SRCROOT/wznmcmbd/CrdWznmPrj/
cp ../../wznmcmbd/CrdWznmPrj/*.cpp $SRCROOT/wznmcmbd/CrdWznmPrj/

cp Makefile_CrdWznmVer $SRCROOT/wznmcmbd/CrdWznmVer/Makefile

cp ../../wznmcmbd/CrdWznmVer/*.h $SRCROOT/wznmcmbd/CrdWznmVer/
cp ../../wznmcmbd/CrdWznmVer/*.cpp $SRCROOT/wznmcmbd/CrdWznmVer/

cp Makefile_CrdWznmCap $SRCROOT/wznmcmbd/CrdWznmCap/Makefile

cp ../../wznmcmbd/CrdWznmCap/*.h $SRCROOT/wznmcmbd/CrdWznmCap/
cp ../../wznmcmbd/CrdWznmCap/*.cpp $SRCROOT/wznmcmbd/CrdWznmCap/

cp Makefile_CrdWznmErr $SRCROOT/wznmcmbd/CrdWznmErr/Makefile

cp ../../wznmcmbd/CrdWznmErr/*.h $SRCROOT/wznmcmbd/CrdWznmErr/
cp ../../wznmcmbd/CrdWznmErr/*.cpp $SRCROOT/wznmcmbd/CrdWznmErr/

cp Makefile_CrdWznmTbl $SRCROOT/wznmcmbd/CrdWznmTbl/Makefile

cp ../../wznmcmbd/CrdWznmTbl/*.h $SRCROOT/wznmcmbd/CrdWznmTbl/
cp ../../wznmcmbd/CrdWznmTbl/*.cpp $SRCROOT/wznmcmbd/CrdWznmTbl/

cp Makefile_CrdWznmTco $SRCROOT/wznmcmbd/CrdWznmTco/Makefile

cp ../../wznmcmbd/CrdWznmTco/*.h $SRCROOT/wznmcmbd/CrdWznmTco/
cp ../../wznmcmbd/CrdWznmTco/*.cpp $SRCROOT/wznmcmbd/CrdWznmTco/

cp Makefile_CrdWznmSbs $SRCROOT/wznmcmbd/CrdWznmSbs/Makefile

cp ../../wznmcmbd/CrdWznmSbs/*.h $SRCROOT/wznmcmbd/CrdWznmSbs/
cp ../../wznmcmbd/CrdWznmSbs/*.cpp $SRCROOT/wznmcmbd/CrdWznmSbs/

cp Makefile_CrdWznmRel $SRCROOT/wznmcmbd/CrdWznmRel/Makefile

cp ../../wznmcmbd/CrdWznmRel/*.h $SRCROOT/wznmcmbd/CrdWznmRel/
cp ../../wznmcmbd/CrdWznmRel/*.cpp $SRCROOT/wznmcmbd/CrdWznmRel/

cp Makefile_CrdWznmVec $SRCROOT/wznmcmbd/CrdWznmVec/Makefile

cp ../../wznmcmbd/CrdWznmVec/*.h $SRCROOT/wznmcmbd/CrdWznmVec/
cp ../../wznmcmbd/CrdWznmVec/*.cpp $SRCROOT/wznmcmbd/CrdWznmVec/

cp Makefile_CrdWznmVit $SRCROOT/wznmcmbd/CrdWznmVit/Makefile

cp ../../wznmcmbd/CrdWznmVit/*.h $SRCROOT/wznmcmbd/CrdWznmVit/
cp ../../wznmcmbd/CrdWznmVit/*.cpp $SRCROOT/wznmcmbd/CrdWznmVit/

cp Makefile_CrdWznmChk $SRCROOT/wznmcmbd/CrdWznmChk/Makefile

cp ../../wznmcmbd/CrdWznmChk/*.h $SRCROOT/wznmcmbd/CrdWznmChk/
cp ../../wznmcmbd/CrdWznmChk/*.cpp $SRCROOT/wznmcmbd/CrdWznmChk/

cp Makefile_CrdWznmStb $SRCROOT/wznmcmbd/CrdWznmStb/Makefile

cp ../../wznmcmbd/CrdWznmStb/*.h $SRCROOT/wznmcmbd/CrdWznmStb/
cp ../../wznmcmbd/CrdWznmStb/*.cpp $SRCROOT/wznmcmbd/CrdWznmStb/

cp Makefile_CrdWznmIex $SRCROOT/wznmcmbd/CrdWznmIex/Makefile

cp ../../wznmcmbd/CrdWznmIex/*.h $SRCROOT/wznmcmbd/CrdWznmIex/
cp ../../wznmcmbd/CrdWznmIex/*.cpp $SRCROOT/wznmcmbd/CrdWznmIex/

cp Makefile_CrdWznmIme $SRCROOT/wznmcmbd/CrdWznmIme/Makefile

cp ../../wznmcmbd/CrdWznmIme/*.h $SRCROOT/wznmcmbd/CrdWznmIme/
cp ../../wznmcmbd/CrdWznmIme/*.cpp $SRCROOT/wznmcmbd/CrdWznmIme/

cp Makefile_CrdWznmIel $SRCROOT/wznmcmbd/CrdWznmIel/Makefile

cp ../../wznmcmbd/CrdWznmIel/*.h $SRCROOT/wznmcmbd/CrdWznmIel/
cp ../../wznmcmbd/CrdWznmIel/*.cpp $SRCROOT/wznmcmbd/CrdWznmIel/

cp Makefile_CrdWznmPst $SRCROOT/wznmcmbd/CrdWznmPst/Makefile

cp ../../wznmcmbd/CrdWznmPst/*.h $SRCROOT/wznmcmbd/CrdWznmPst/
cp ../../wznmcmbd/CrdWznmPst/*.cpp $SRCROOT/wznmcmbd/CrdWznmPst/

cp Makefile_CrdWznmMdl $SRCROOT/wznmcmbd/CrdWznmMdl/Makefile

cp ../../wznmcmbd/CrdWznmMdl/*.h $SRCROOT/wznmcmbd/CrdWznmMdl/
cp ../../wznmcmbd/CrdWznmMdl/*.cpp $SRCROOT/wznmcmbd/CrdWznmMdl/

cp Makefile_CrdWznmCar $SRCROOT/wznmcmbd/CrdWznmCar/Makefile

cp ../../wznmcmbd/CrdWznmCar/*.h $SRCROOT/wznmcmbd/CrdWznmCar/
cp ../../wznmcmbd/CrdWznmCar/*.cpp $SRCROOT/wznmcmbd/CrdWznmCar/

cp Makefile_CrdWznmDlg $SRCROOT/wznmcmbd/CrdWznmDlg/Makefile

cp ../../wznmcmbd/CrdWznmDlg/*.h $SRCROOT/wznmcmbd/CrdWznmDlg/
cp ../../wznmcmbd/CrdWznmDlg/*.cpp $SRCROOT/wznmcmbd/CrdWznmDlg/

cp Makefile_CrdWznmPnl $SRCROOT/wznmcmbd/CrdWznmPnl/Makefile

cp ../../wznmcmbd/CrdWznmPnl/*.h $SRCROOT/wznmcmbd/CrdWznmPnl/
cp ../../wznmcmbd/CrdWznmPnl/*.cpp $SRCROOT/wznmcmbd/CrdWznmPnl/

cp Makefile_CrdWznmQry $SRCROOT/wznmcmbd/CrdWznmQry/Makefile

cp ../../wznmcmbd/CrdWznmQry/*.h $SRCROOT/wznmcmbd/CrdWznmQry/
cp ../../wznmcmbd/CrdWznmQry/*.cpp $SRCROOT/wznmcmbd/CrdWznmQry/

cp Makefile_CrdWznmQco $SRCROOT/wznmcmbd/CrdWznmQco/Makefile

cp ../../wznmcmbd/CrdWznmQco/*.h $SRCROOT/wznmcmbd/CrdWznmQco/
cp ../../wznmcmbd/CrdWznmQco/*.cpp $SRCROOT/wznmcmbd/CrdWznmQco/

cp Makefile_CrdWznmQmd $SRCROOT/wznmcmbd/CrdWznmQmd/Makefile

cp ../../wznmcmbd/CrdWznmQmd/*.h $SRCROOT/wznmcmbd/CrdWznmQmd/
cp ../../wznmcmbd/CrdWznmQmd/*.cpp $SRCROOT/wznmcmbd/CrdWznmQmd/

cp Makefile_CrdWznmCon $SRCROOT/wznmcmbd/CrdWznmCon/Makefile

cp ../../wznmcmbd/CrdWznmCon/*.h $SRCROOT/wznmcmbd/CrdWznmCon/
cp ../../wznmcmbd/CrdWznmCon/*.cpp $SRCROOT/wznmcmbd/CrdWznmCon/

cp Makefile_CrdWznmOpk $SRCROOT/wznmcmbd/CrdWznmOpk/Makefile

cp ../../wznmcmbd/CrdWznmOpk/*.h $SRCROOT/wznmcmbd/CrdWznmOpk/
cp ../../wznmcmbd/CrdWznmOpk/*.cpp $SRCROOT/wznmcmbd/CrdWznmOpk/

cp Makefile_CrdWznmOpx $SRCROOT/wznmcmbd/CrdWznmOpx/Makefile

cp ../../wznmcmbd/CrdWznmOpx/*.h $SRCROOT/wznmcmbd/CrdWznmOpx/
cp ../../wznmcmbd/CrdWznmOpx/*.cpp $SRCROOT/wznmcmbd/CrdWznmOpx/

cp Makefile_CrdWznmJob $SRCROOT/wznmcmbd/CrdWznmJob/Makefile

cp ../../wznmcmbd/CrdWznmJob/*.h $SRCROOT/wznmcmbd/CrdWznmJob/
cp ../../wznmcmbd/CrdWznmJob/*.cpp $SRCROOT/wznmcmbd/CrdWznmJob/

cp Makefile_CrdWznmSge $SRCROOT/wznmcmbd/CrdWznmSge/Makefile

cp ../../wznmcmbd/CrdWznmSge/*.h $SRCROOT/wznmcmbd/CrdWznmSge/
cp ../../wznmcmbd/CrdWznmSge/*.cpp $SRCROOT/wznmcmbd/CrdWznmSge/

cp Makefile_CrdWznmMtd $SRCROOT/wznmcmbd/CrdWznmMtd/Makefile

cp ../../wznmcmbd/CrdWznmMtd/*.h $SRCROOT/wznmcmbd/CrdWznmMtd/
cp ../../wznmcmbd/CrdWznmMtd/*.cpp $SRCROOT/wznmcmbd/CrdWznmMtd/

cp Makefile_CrdWznmBlk $SRCROOT/wznmcmbd/CrdWznmBlk/Makefile

cp ../../wznmcmbd/CrdWznmBlk/*.h $SRCROOT/wznmcmbd/CrdWznmBlk/
cp ../../wznmcmbd/CrdWznmBlk/*.cpp $SRCROOT/wznmcmbd/CrdWznmBlk/

cp Makefile_CrdWznmCal $SRCROOT/wznmcmbd/CrdWznmCal/Makefile

cp ../../wznmcmbd/CrdWznmCal/*.h $SRCROOT/wznmcmbd/CrdWznmCal/
cp ../../wznmcmbd/CrdWznmCal/*.cpp $SRCROOT/wznmcmbd/CrdWznmCal/

cp Makefile_CrdWznmCmp $SRCROOT/wznmcmbd/CrdWznmCmp/Makefile

cp ../../wznmcmbd/CrdWznmCmp/*.h $SRCROOT/wznmcmbd/CrdWznmCmp/
cp ../../wznmcmbd/CrdWznmCmp/*.cpp $SRCROOT/wznmcmbd/CrdWznmCmp/

cp Makefile_CrdWznmRls $SRCROOT/wznmcmbd/CrdWznmRls/Makefile

cp ../../wznmcmbd/CrdWznmRls/*.h $SRCROOT/wznmcmbd/CrdWznmRls/
cp ../../wznmcmbd/CrdWznmRls/*.cpp $SRCROOT/wznmcmbd/CrdWznmRls/

cp Makefile_CrdWznmApp $SRCROOT/wznmcmbd/CrdWznmApp/Makefile

cp ../../wznmcmbd/CrdWznmApp/*.h $SRCROOT/wznmcmbd/CrdWznmApp/
cp ../../wznmcmbd/CrdWznmApp/*.cpp $SRCROOT/wznmcmbd/CrdWznmApp/

cp Makefile_CrdWznmRtj $SRCROOT/wznmcmbd/CrdWznmRtj/Makefile

cp ../../wznmcmbd/CrdWznmRtj/*.h $SRCROOT/wznmcmbd/CrdWznmRtj/
cp ../../wznmcmbd/CrdWznmRtj/*.cpp $SRCROOT/wznmcmbd/CrdWznmRtj/

cp Makefile_CrdWznmSeq $SRCROOT/wznmcmbd/CrdWznmSeq/Makefile

cp ../../wznmcmbd/CrdWznmSeq/*.h $SRCROOT/wznmcmbd/CrdWznmSeq/
cp ../../wznmcmbd/CrdWznmSeq/*.cpp $SRCROOT/wznmcmbd/CrdWznmSeq/

cp Makefile_CrdWznmSte $SRCROOT/wznmcmbd/CrdWznmSte/Makefile

cp ../../wznmcmbd/CrdWznmSte/*.h $SRCROOT/wznmcmbd/CrdWznmSte/
cp ../../wznmcmbd/CrdWznmSte/*.cpp $SRCROOT/wznmcmbd/CrdWznmSte/

cp Makefile_CrdWznmUtl $SRCROOT/wznmcmbd/CrdWznmUtl/Makefile

cp ../../wznmcmbd/CrdWznmUtl/*.h $SRCROOT/wznmcmbd/CrdWznmUtl/
cp ../../wznmcmbd/CrdWznmUtl/*.cpp $SRCROOT/wznmcmbd/CrdWznmUtl/

cp Makefile_WznmWrweb $SRCROOT/wznmcmbd/WznmWrweb/Makefile

cp ../../wznmcmbd/WznmWrweb/*.h $SRCROOT/wznmcmbd/WznmWrweb/
cp ../../wznmcmbd/WznmWrweb/*.cpp $SRCROOT/wznmcmbd/WznmWrweb/

cp Makefile_WznmWrjapi $SRCROOT/wznmcmbd/WznmWrjapi/Makefile

cp ../../wznmcmbd/WznmWrjapi/*.h $SRCROOT/wznmcmbd/WznmWrjapi/
cp ../../wznmcmbd/WznmWrjapi/*.cpp $SRCROOT/wznmcmbd/WznmWrjapi/

cp Makefile_WznmWrsrv $SRCROOT/wznmcmbd/WznmWrsrv/Makefile

cp ../../wznmcmbd/WznmWrsrv/*.h $SRCROOT/wznmcmbd/WznmWrsrv/
cp ../../wznmcmbd/WznmWrsrv/*.cpp $SRCROOT/wznmcmbd/WznmWrsrv/

cp Makefile_WznmWrdbs $SRCROOT/wznmcmbd/WznmWrdbs/Makefile

cp ../../wznmcmbd/WznmWrdbs/*.h $SRCROOT/wznmcmbd/WznmWrdbs/
cp ../../wznmcmbd/WznmWrdbs/*.cpp $SRCROOT/wznmcmbd/WznmWrdbs/

cp Makefile_WznmWrapp $SRCROOT/wznmcmbd/WznmWrapp/Makefile

cp ../../wznmcmbd/WznmWrapp/*.h $SRCROOT/wznmcmbd/WznmWrapp/
cp ../../wznmcmbd/WznmWrapp/*.cpp $SRCROOT/wznmcmbd/WznmWrapp/

cp Makefile_WznmPrctree $SRCROOT/wznmcmbd/WznmPrctree/Makefile

cp ../../wznmcmbd/WznmPrctree/*.h $SRCROOT/wznmcmbd/WznmPrctree/
cp ../../wznmcmbd/WznmPrctree/*.cpp $SRCROOT/wznmcmbd/WznmPrctree/

cp Makefile_WznmWrapi $SRCROOT/wznmcmbd/WznmWrapi/Makefile

cp ../../wznmcmbd/WznmWrapi/*.h $SRCROOT/wznmcmbd/WznmWrapi/
cp ../../wznmcmbd/WznmWrapi/*.cpp $SRCROOT/wznmcmbd/WznmWrapi/

cp Makefile_WznmGen $SRCROOT/wznmcmbd/WznmGen/Makefile

cp ../../wznmcmbd/WznmGen/*.h $SRCROOT/wznmcmbd/WznmGen/
cp ../../wznmcmbd/WznmGen/*.cpp $SRCROOT/wznmcmbd/WznmGen/

cp Makefile_WznmPrcfile $SRCROOT/wznmcmbd/WznmPrcfile/Makefile

cp ../../wznmcmbd/WznmPrcfile/*.h $SRCROOT/wznmcmbd/WznmPrcfile/
cp ../../wznmcmbd/WznmPrcfile/*.cpp $SRCROOT/wznmcmbd/WznmPrcfile/

cp Makefile_WznmCtpWrsrv $SRCROOT/wznmcmbd/WznmCtpWrsrv/Makefile

cp ../../wznmcmbd/WznmCtpWrsrv/*.h $SRCROOT/wznmcmbd/WznmCtpWrsrv/
cp ../../wznmcmbd/WznmCtpWrsrv/*.cpp $SRCROOT/wznmcmbd/WznmCtpWrsrv/

cp Makefile_WznmCtpWrweb $SRCROOT/wznmcmbd/WznmCtpWrweb/Makefile

cp ../../wznmcmbd/WznmCtpWrweb/*.h $SRCROOT/wznmcmbd/WznmCtpWrweb/
cp ../../wznmcmbd/WznmCtpWrweb/*.cpp $SRCROOT/wznmcmbd/WznmCtpWrweb/

cp Makefile_WznmCtpWrstkit $SRCROOT/wznmcmbd/WznmCtpWrstkit/Makefile

cp ../../wznmcmbd/WznmCtpWrstkit/*.h $SRCROOT/wznmcmbd/WznmCtpWrstkit/
cp ../../wznmcmbd/WznmCtpWrstkit/*.cpp $SRCROOT/wznmcmbd/WznmCtpWrstkit/

cp Makefile_WznmCtpGenui $SRCROOT/wznmcmbd/WznmCtpGenui/Makefile

cp ../../wznmcmbd/WznmCtpGenui/*.h $SRCROOT/wznmcmbd/WznmCtpGenui/
cp ../../wznmcmbd/WznmCtpGenui/*.cpp $SRCROOT/wznmcmbd/WznmCtpGenui/

cp Makefile_WznmCompl $SRCROOT/wznmcmbd/WznmCompl/Makefile

cp ../../wznmcmbd/WznmCompl/*.h $SRCROOT/wznmcmbd/WznmCompl/
cp ../../wznmcmbd/WznmCompl/*.cpp $SRCROOT/wznmcmbd/WznmCompl/

cp Makefile_WznmCtpGenjtr $SRCROOT/wznmcmbd/WznmCtpGenjtr/Makefile

cp ../../wznmcmbd/WznmCtpGenjtr/*.h $SRCROOT/wznmcmbd/WznmCtpGenjtr/
cp ../../wznmcmbd/WznmCtpGenjtr/*.cpp $SRCROOT/wznmcmbd/WznmCtpGenjtr/

