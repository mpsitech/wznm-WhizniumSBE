#!/bin/bash
# file checkout.sh
# checkout script for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Nov 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin

mkdir $BUILDROOT/wznmcmbd
mkdir $BUILDROOT/wznmcmbd/IexWznm
mkdir $BUILDROOT/wznmcmbd/VecWznm
mkdir $BUILDROOT/wznmcmbd/CrdWznmUsg
mkdir $BUILDROOT/wznmcmbd/CrdWznmUsr
mkdir $BUILDROOT/wznmcmbd/CrdWznmPrs
mkdir $BUILDROOT/wznmcmbd/CrdWznmFil
mkdir $BUILDROOT/wznmcmbd/CrdWznmNav
mkdir $BUILDROOT/wznmcmbd/CrdWznmLoc
mkdir $BUILDROOT/wznmcmbd/CrdWznmTag
mkdir $BUILDROOT/wznmcmbd/CrdWznmCtp
mkdir $BUILDROOT/wznmcmbd/CrdWznmMch
mkdir $BUILDROOT/wznmcmbd/CrdWznmLib
mkdir $BUILDROOT/wznmcmbd/CrdWznmPrj
mkdir $BUILDROOT/wznmcmbd/CrdWznmVer
mkdir $BUILDROOT/wznmcmbd/CrdWznmCap
mkdir $BUILDROOT/wznmcmbd/CrdWznmErr
mkdir $BUILDROOT/wznmcmbd/CrdWznmTbl
mkdir $BUILDROOT/wznmcmbd/CrdWznmTco
mkdir $BUILDROOT/wznmcmbd/CrdWznmSbs
mkdir $BUILDROOT/wznmcmbd/CrdWznmRel
mkdir $BUILDROOT/wznmcmbd/CrdWznmVec
mkdir $BUILDROOT/wznmcmbd/CrdWznmVit
mkdir $BUILDROOT/wznmcmbd/CrdWznmChk
mkdir $BUILDROOT/wznmcmbd/CrdWznmStb
mkdir $BUILDROOT/wznmcmbd/CrdWznmIex
mkdir $BUILDROOT/wznmcmbd/CrdWznmIme
mkdir $BUILDROOT/wznmcmbd/CrdWznmIel
mkdir $BUILDROOT/wznmcmbd/CrdWznmPst
mkdir $BUILDROOT/wznmcmbd/CrdWznmMdl
mkdir $BUILDROOT/wznmcmbd/CrdWznmCar
mkdir $BUILDROOT/wznmcmbd/CrdWznmDlg
mkdir $BUILDROOT/wznmcmbd/CrdWznmPnl
mkdir $BUILDROOT/wznmcmbd/CrdWznmQry
mkdir $BUILDROOT/wznmcmbd/CrdWznmQco
mkdir $BUILDROOT/wznmcmbd/CrdWznmQmd
mkdir $BUILDROOT/wznmcmbd/CrdWznmCon
mkdir $BUILDROOT/wznmcmbd/CrdWznmOpk
mkdir $BUILDROOT/wznmcmbd/CrdWznmOpx
mkdir $BUILDROOT/wznmcmbd/CrdWznmJob
mkdir $BUILDROOT/wznmcmbd/CrdWznmSge
mkdir $BUILDROOT/wznmcmbd/CrdWznmMtd
mkdir $BUILDROOT/wznmcmbd/CrdWznmBlk
mkdir $BUILDROOT/wznmcmbd/CrdWznmCal
mkdir $BUILDROOT/wznmcmbd/CrdWznmCmp
mkdir $BUILDROOT/wznmcmbd/CrdWznmRls
mkdir $BUILDROOT/wznmcmbd/CrdWznmApp
mkdir $BUILDROOT/wznmcmbd/CrdWznmRtj
mkdir $BUILDROOT/wznmcmbd/CrdWznmEvt
mkdir $BUILDROOT/wznmcmbd/CrdWznmSeq
mkdir $BUILDROOT/wznmcmbd/CrdWznmSte
mkdir $BUILDROOT/wznmcmbd/CrdWznmUtl
mkdir $BUILDROOT/wznmcmbd/WznmWrjapi
mkdir $BUILDROOT/wznmcmbd/WznmWrsrv
mkdir $BUILDROOT/wznmcmbd/WznmWrweb
mkdir $BUILDROOT/wznmcmbd/WznmWrdbs
mkdir $BUILDROOT/wznmcmbd/WznmWrapp
mkdir $BUILDROOT/wznmcmbd/WznmPrctree
mkdir $BUILDROOT/wznmcmbd/WznmWrapi
mkdir $BUILDROOT/wznmcmbd/WznmGen
mkdir $BUILDROOT/wznmcmbd/WznmPrcfile
mkdir $BUILDROOT/wznmcmbd/WznmCtpWrweb
mkdir $BUILDROOT/wznmcmbd/WznmCtpWrstkit
mkdir $BUILDROOT/wznmcmbd/WznmCtpWrsrv
mkdir $BUILDROOT/wznmcmbd/WznmCtpGenui
mkdir $BUILDROOT/wznmcmbd/WznmCtpGenjtr
mkdir $BUILDROOT/wznmcmbd/WznmCompl

mkdir $LIBROOT/wznmcmbd

mkdir $BINROOT/wznmcmbd

cp make.sh $BUILDROOT/wznmcmbd/
cp remake.sh $BUILDROOT/wznmcmbd/

cp Makefile.inc $BUILDROOT/wznmcmbd/
cp Makefile $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/Wznmcmbd.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/Wznmcmbd.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdAppsrv.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdAppsrv.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdJobprc.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdJobprc.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/WznmcmbdOpprc.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/WznmcmbdOpprc.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/Wznmcmbd_exe.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/Wznmcmbd_exe.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/Wznm.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/Wznm.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/Root*.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/Root*.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/Sess*.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/Sess*.cpp $BUILDROOT/wznmcmbd/

cp ../../wznmcmbd/gbl/*.h $BUILDROOT/wznmcmbd/
cp ../../wznmcmbd/gbl/*.cpp $BUILDROOT/wznmcmbd/

cp Makefile_IexWznm $BUILDROOT/wznmcmbd/IexWznm/Makefile

cp ../../wznmcmbd/IexWznm/IexWznm*.h $BUILDROOT/wznmcmbd/IexWznm/
cp ../../wznmcmbd/IexWznm/IexWznm*.cpp $BUILDROOT/wznmcmbd/IexWznm/

cp ../../wznmcmbd/IexWznm/JobWznmIex*.h $BUILDROOT/wznmcmbd/IexWznm/
cp ../../wznmcmbd/IexWznm/JobWznmIex*.cpp $BUILDROOT/wznmcmbd/IexWznm/

cp Makefile_VecWznm $BUILDROOT/wznmcmbd/VecWznm/Makefile

cp ../../wznmcmbd/VecWznm/Vec*.h $BUILDROOT/wznmcmbd/VecWznm/
cp ../../wznmcmbd/VecWznm/Vec*.cpp $BUILDROOT/wznmcmbd/VecWznm/

cp Makefile_CrdWznmUsg $BUILDROOT/wznmcmbd/CrdWznmUsg/Makefile

cp ../../wznmcmbd/CrdWznmUsg/*.h $BUILDROOT/wznmcmbd/CrdWznmUsg/
cp ../../wznmcmbd/CrdWznmUsg/*.cpp $BUILDROOT/wznmcmbd/CrdWznmUsg/

cp Makefile_CrdWznmUsr $BUILDROOT/wznmcmbd/CrdWznmUsr/Makefile

cp ../../wznmcmbd/CrdWznmUsr/*.h $BUILDROOT/wznmcmbd/CrdWznmUsr/
cp ../../wznmcmbd/CrdWznmUsr/*.cpp $BUILDROOT/wznmcmbd/CrdWznmUsr/

cp Makefile_CrdWznmPrs $BUILDROOT/wznmcmbd/CrdWznmPrs/Makefile

cp ../../wznmcmbd/CrdWznmPrs/*.h $BUILDROOT/wznmcmbd/CrdWznmPrs/
cp ../../wznmcmbd/CrdWznmPrs/*.cpp $BUILDROOT/wznmcmbd/CrdWznmPrs/

cp Makefile_CrdWznmFil $BUILDROOT/wznmcmbd/CrdWznmFil/Makefile

cp ../../wznmcmbd/CrdWznmFil/*.h $BUILDROOT/wznmcmbd/CrdWznmFil/
cp ../../wznmcmbd/CrdWznmFil/*.cpp $BUILDROOT/wznmcmbd/CrdWznmFil/

cp Makefile_CrdWznmNav $BUILDROOT/wznmcmbd/CrdWznmNav/Makefile

cp ../../wznmcmbd/CrdWznmNav/*.h $BUILDROOT/wznmcmbd/CrdWznmNav/
cp ../../wznmcmbd/CrdWznmNav/*.cpp $BUILDROOT/wznmcmbd/CrdWznmNav/

cp Makefile_CrdWznmLoc $BUILDROOT/wznmcmbd/CrdWznmLoc/Makefile

cp ../../wznmcmbd/CrdWznmLoc/*.h $BUILDROOT/wznmcmbd/CrdWznmLoc/
cp ../../wznmcmbd/CrdWznmLoc/*.cpp $BUILDROOT/wznmcmbd/CrdWznmLoc/

cp Makefile_CrdWznmTag $BUILDROOT/wznmcmbd/CrdWznmTag/Makefile

cp ../../wznmcmbd/CrdWznmTag/*.h $BUILDROOT/wznmcmbd/CrdWznmTag/
cp ../../wznmcmbd/CrdWznmTag/*.cpp $BUILDROOT/wznmcmbd/CrdWznmTag/

cp Makefile_CrdWznmCtp $BUILDROOT/wznmcmbd/CrdWznmCtp/Makefile

cp ../../wznmcmbd/CrdWznmCtp/*.h $BUILDROOT/wznmcmbd/CrdWznmCtp/
cp ../../wznmcmbd/CrdWznmCtp/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCtp/

cp Makefile_CrdWznmMch $BUILDROOT/wznmcmbd/CrdWznmMch/Makefile

cp ../../wznmcmbd/CrdWznmMch/*.h $BUILDROOT/wznmcmbd/CrdWznmMch/
cp ../../wznmcmbd/CrdWznmMch/*.cpp $BUILDROOT/wznmcmbd/CrdWznmMch/

cp Makefile_CrdWznmLib $BUILDROOT/wznmcmbd/CrdWznmLib/Makefile

cp ../../wznmcmbd/CrdWznmLib/*.h $BUILDROOT/wznmcmbd/CrdWznmLib/
cp ../../wznmcmbd/CrdWznmLib/*.cpp $BUILDROOT/wznmcmbd/CrdWznmLib/

cp Makefile_CrdWznmPrj $BUILDROOT/wznmcmbd/CrdWznmPrj/Makefile

cp ../../wznmcmbd/CrdWznmPrj/*.h $BUILDROOT/wznmcmbd/CrdWznmPrj/
cp ../../wznmcmbd/CrdWznmPrj/*.cpp $BUILDROOT/wznmcmbd/CrdWznmPrj/

cp Makefile_CrdWznmVer $BUILDROOT/wznmcmbd/CrdWznmVer/Makefile

cp ../../wznmcmbd/CrdWznmVer/*.h $BUILDROOT/wznmcmbd/CrdWznmVer/
cp ../../wznmcmbd/CrdWznmVer/*.cpp $BUILDROOT/wznmcmbd/CrdWznmVer/

cp Makefile_CrdWznmCap $BUILDROOT/wznmcmbd/CrdWznmCap/Makefile

cp ../../wznmcmbd/CrdWznmCap/*.h $BUILDROOT/wznmcmbd/CrdWznmCap/
cp ../../wznmcmbd/CrdWznmCap/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCap/

cp Makefile_CrdWznmErr $BUILDROOT/wznmcmbd/CrdWznmErr/Makefile

cp ../../wznmcmbd/CrdWznmErr/*.h $BUILDROOT/wznmcmbd/CrdWznmErr/
cp ../../wznmcmbd/CrdWznmErr/*.cpp $BUILDROOT/wznmcmbd/CrdWznmErr/

cp Makefile_CrdWznmTbl $BUILDROOT/wznmcmbd/CrdWznmTbl/Makefile

cp ../../wznmcmbd/CrdWznmTbl/*.h $BUILDROOT/wznmcmbd/CrdWznmTbl/
cp ../../wznmcmbd/CrdWznmTbl/*.cpp $BUILDROOT/wznmcmbd/CrdWznmTbl/

cp Makefile_CrdWznmTco $BUILDROOT/wznmcmbd/CrdWznmTco/Makefile

cp ../../wznmcmbd/CrdWznmTco/*.h $BUILDROOT/wznmcmbd/CrdWznmTco/
cp ../../wznmcmbd/CrdWznmTco/*.cpp $BUILDROOT/wznmcmbd/CrdWznmTco/

cp Makefile_CrdWznmSbs $BUILDROOT/wznmcmbd/CrdWznmSbs/Makefile

cp ../../wznmcmbd/CrdWznmSbs/*.h $BUILDROOT/wznmcmbd/CrdWznmSbs/
cp ../../wznmcmbd/CrdWznmSbs/*.cpp $BUILDROOT/wznmcmbd/CrdWznmSbs/

cp Makefile_CrdWznmRel $BUILDROOT/wznmcmbd/CrdWznmRel/Makefile

cp ../../wznmcmbd/CrdWznmRel/*.h $BUILDROOT/wznmcmbd/CrdWznmRel/
cp ../../wznmcmbd/CrdWznmRel/*.cpp $BUILDROOT/wznmcmbd/CrdWznmRel/

cp Makefile_CrdWznmVec $BUILDROOT/wznmcmbd/CrdWznmVec/Makefile

cp ../../wznmcmbd/CrdWznmVec/*.h $BUILDROOT/wznmcmbd/CrdWznmVec/
cp ../../wznmcmbd/CrdWznmVec/*.cpp $BUILDROOT/wznmcmbd/CrdWznmVec/

cp Makefile_CrdWznmVit $BUILDROOT/wznmcmbd/CrdWznmVit/Makefile

cp ../../wznmcmbd/CrdWznmVit/*.h $BUILDROOT/wznmcmbd/CrdWznmVit/
cp ../../wznmcmbd/CrdWznmVit/*.cpp $BUILDROOT/wznmcmbd/CrdWznmVit/

cp Makefile_CrdWznmChk $BUILDROOT/wznmcmbd/CrdWznmChk/Makefile

cp ../../wznmcmbd/CrdWznmChk/*.h $BUILDROOT/wznmcmbd/CrdWznmChk/
cp ../../wznmcmbd/CrdWznmChk/*.cpp $BUILDROOT/wznmcmbd/CrdWznmChk/

cp Makefile_CrdWznmStb $BUILDROOT/wznmcmbd/CrdWznmStb/Makefile

cp ../../wznmcmbd/CrdWznmStb/*.h $BUILDROOT/wznmcmbd/CrdWznmStb/
cp ../../wznmcmbd/CrdWznmStb/*.cpp $BUILDROOT/wznmcmbd/CrdWznmStb/

cp Makefile_CrdWznmIex $BUILDROOT/wznmcmbd/CrdWznmIex/Makefile

cp ../../wznmcmbd/CrdWznmIex/*.h $BUILDROOT/wznmcmbd/CrdWznmIex/
cp ../../wznmcmbd/CrdWznmIex/*.cpp $BUILDROOT/wznmcmbd/CrdWznmIex/

cp Makefile_CrdWznmIme $BUILDROOT/wznmcmbd/CrdWznmIme/Makefile

cp ../../wznmcmbd/CrdWznmIme/*.h $BUILDROOT/wznmcmbd/CrdWznmIme/
cp ../../wznmcmbd/CrdWznmIme/*.cpp $BUILDROOT/wznmcmbd/CrdWznmIme/

cp Makefile_CrdWznmIel $BUILDROOT/wznmcmbd/CrdWznmIel/Makefile

cp ../../wznmcmbd/CrdWznmIel/*.h $BUILDROOT/wznmcmbd/CrdWznmIel/
cp ../../wznmcmbd/CrdWznmIel/*.cpp $BUILDROOT/wznmcmbd/CrdWznmIel/

cp Makefile_CrdWznmPst $BUILDROOT/wznmcmbd/CrdWznmPst/Makefile

cp ../../wznmcmbd/CrdWznmPst/*.h $BUILDROOT/wznmcmbd/CrdWznmPst/
cp ../../wznmcmbd/CrdWznmPst/*.cpp $BUILDROOT/wznmcmbd/CrdWznmPst/

cp Makefile_CrdWznmMdl $BUILDROOT/wznmcmbd/CrdWznmMdl/Makefile

cp ../../wznmcmbd/CrdWznmMdl/*.h $BUILDROOT/wznmcmbd/CrdWznmMdl/
cp ../../wznmcmbd/CrdWznmMdl/*.cpp $BUILDROOT/wznmcmbd/CrdWznmMdl/

cp Makefile_CrdWznmCar $BUILDROOT/wznmcmbd/CrdWznmCar/Makefile

cp ../../wznmcmbd/CrdWznmCar/*.h $BUILDROOT/wznmcmbd/CrdWznmCar/
cp ../../wznmcmbd/CrdWznmCar/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCar/

cp Makefile_CrdWznmDlg $BUILDROOT/wznmcmbd/CrdWznmDlg/Makefile

cp ../../wznmcmbd/CrdWznmDlg/*.h $BUILDROOT/wznmcmbd/CrdWznmDlg/
cp ../../wznmcmbd/CrdWznmDlg/*.cpp $BUILDROOT/wznmcmbd/CrdWznmDlg/

cp Makefile_CrdWznmPnl $BUILDROOT/wznmcmbd/CrdWznmPnl/Makefile

cp ../../wznmcmbd/CrdWznmPnl/*.h $BUILDROOT/wznmcmbd/CrdWznmPnl/
cp ../../wznmcmbd/CrdWznmPnl/*.cpp $BUILDROOT/wznmcmbd/CrdWznmPnl/

cp Makefile_CrdWznmQry $BUILDROOT/wznmcmbd/CrdWznmQry/Makefile

cp ../../wznmcmbd/CrdWznmQry/*.h $BUILDROOT/wznmcmbd/CrdWznmQry/
cp ../../wznmcmbd/CrdWznmQry/*.cpp $BUILDROOT/wznmcmbd/CrdWznmQry/

cp Makefile_CrdWznmQco $BUILDROOT/wznmcmbd/CrdWznmQco/Makefile

cp ../../wznmcmbd/CrdWznmQco/*.h $BUILDROOT/wznmcmbd/CrdWznmQco/
cp ../../wznmcmbd/CrdWznmQco/*.cpp $BUILDROOT/wznmcmbd/CrdWznmQco/

cp Makefile_CrdWznmQmd $BUILDROOT/wznmcmbd/CrdWznmQmd/Makefile

cp ../../wznmcmbd/CrdWznmQmd/*.h $BUILDROOT/wznmcmbd/CrdWznmQmd/
cp ../../wznmcmbd/CrdWznmQmd/*.cpp $BUILDROOT/wznmcmbd/CrdWznmQmd/

cp Makefile_CrdWznmCon $BUILDROOT/wznmcmbd/CrdWznmCon/Makefile

cp ../../wznmcmbd/CrdWznmCon/*.h $BUILDROOT/wznmcmbd/CrdWznmCon/
cp ../../wznmcmbd/CrdWznmCon/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCon/

cp Makefile_CrdWznmOpk $BUILDROOT/wznmcmbd/CrdWznmOpk/Makefile

cp ../../wznmcmbd/CrdWznmOpk/*.h $BUILDROOT/wznmcmbd/CrdWznmOpk/
cp ../../wznmcmbd/CrdWznmOpk/*.cpp $BUILDROOT/wznmcmbd/CrdWznmOpk/

cp Makefile_CrdWznmOpx $BUILDROOT/wznmcmbd/CrdWznmOpx/Makefile

cp ../../wznmcmbd/CrdWznmOpx/*.h $BUILDROOT/wznmcmbd/CrdWznmOpx/
cp ../../wznmcmbd/CrdWznmOpx/*.cpp $BUILDROOT/wznmcmbd/CrdWznmOpx/

cp Makefile_CrdWznmJob $BUILDROOT/wznmcmbd/CrdWznmJob/Makefile

cp ../../wznmcmbd/CrdWznmJob/*.h $BUILDROOT/wznmcmbd/CrdWznmJob/
cp ../../wznmcmbd/CrdWznmJob/*.cpp $BUILDROOT/wznmcmbd/CrdWznmJob/

cp Makefile_CrdWznmSge $BUILDROOT/wznmcmbd/CrdWznmSge/Makefile

cp ../../wznmcmbd/CrdWznmSge/*.h $BUILDROOT/wznmcmbd/CrdWznmSge/
cp ../../wznmcmbd/CrdWznmSge/*.cpp $BUILDROOT/wznmcmbd/CrdWznmSge/

cp Makefile_CrdWznmMtd $BUILDROOT/wznmcmbd/CrdWznmMtd/Makefile

cp ../../wznmcmbd/CrdWznmMtd/*.h $BUILDROOT/wznmcmbd/CrdWznmMtd/
cp ../../wznmcmbd/CrdWznmMtd/*.cpp $BUILDROOT/wznmcmbd/CrdWznmMtd/

cp Makefile_CrdWznmBlk $BUILDROOT/wznmcmbd/CrdWznmBlk/Makefile

cp ../../wznmcmbd/CrdWznmBlk/*.h $BUILDROOT/wznmcmbd/CrdWznmBlk/
cp ../../wznmcmbd/CrdWznmBlk/*.cpp $BUILDROOT/wznmcmbd/CrdWznmBlk/

cp Makefile_CrdWznmCal $BUILDROOT/wznmcmbd/CrdWznmCal/Makefile

cp ../../wznmcmbd/CrdWznmCal/*.h $BUILDROOT/wznmcmbd/CrdWznmCal/
cp ../../wznmcmbd/CrdWznmCal/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCal/

cp Makefile_CrdWznmCmp $BUILDROOT/wznmcmbd/CrdWznmCmp/Makefile

cp ../../wznmcmbd/CrdWznmCmp/*.h $BUILDROOT/wznmcmbd/CrdWznmCmp/
cp ../../wznmcmbd/CrdWznmCmp/*.cpp $BUILDROOT/wznmcmbd/CrdWznmCmp/

cp Makefile_CrdWznmRls $BUILDROOT/wznmcmbd/CrdWznmRls/Makefile

cp ../../wznmcmbd/CrdWznmRls/*.h $BUILDROOT/wznmcmbd/CrdWznmRls/
cp ../../wznmcmbd/CrdWznmRls/*.cpp $BUILDROOT/wznmcmbd/CrdWznmRls/

cp Makefile_CrdWznmApp $BUILDROOT/wznmcmbd/CrdWznmApp/Makefile

cp ../../wznmcmbd/CrdWznmApp/*.h $BUILDROOT/wznmcmbd/CrdWznmApp/
cp ../../wznmcmbd/CrdWznmApp/*.cpp $BUILDROOT/wznmcmbd/CrdWznmApp/

cp Makefile_CrdWznmRtj $BUILDROOT/wznmcmbd/CrdWznmRtj/Makefile

cp ../../wznmcmbd/CrdWznmRtj/*.h $BUILDROOT/wznmcmbd/CrdWznmRtj/
cp ../../wznmcmbd/CrdWznmRtj/*.cpp $BUILDROOT/wznmcmbd/CrdWznmRtj/

cp Makefile_CrdWznmEvt $BUILDROOT/wznmcmbd/CrdWznmEvt/Makefile

cp ../../wznmcmbd/CrdWznmEvt/*.h $BUILDROOT/wznmcmbd/CrdWznmEvt/
cp ../../wznmcmbd/CrdWznmEvt/*.cpp $BUILDROOT/wznmcmbd/CrdWznmEvt/

cp Makefile_CrdWznmSeq $BUILDROOT/wznmcmbd/CrdWznmSeq/Makefile

cp ../../wznmcmbd/CrdWznmSeq/*.h $BUILDROOT/wznmcmbd/CrdWznmSeq/
cp ../../wznmcmbd/CrdWznmSeq/*.cpp $BUILDROOT/wznmcmbd/CrdWznmSeq/

cp Makefile_CrdWznmSte $BUILDROOT/wznmcmbd/CrdWznmSte/Makefile

cp ../../wznmcmbd/CrdWznmSte/*.h $BUILDROOT/wznmcmbd/CrdWznmSte/
cp ../../wznmcmbd/CrdWznmSte/*.cpp $BUILDROOT/wznmcmbd/CrdWznmSte/

cp Makefile_CrdWznmUtl $BUILDROOT/wznmcmbd/CrdWznmUtl/Makefile

cp ../../wznmcmbd/CrdWznmUtl/*.h $BUILDROOT/wznmcmbd/CrdWznmUtl/
cp ../../wznmcmbd/CrdWznmUtl/*.cpp $BUILDROOT/wznmcmbd/CrdWznmUtl/

cp Makefile_WznmWrjapi $BUILDROOT/wznmcmbd/WznmWrjapi/Makefile

cp ../../wznmcmbd/WznmWrjapi/*.h $BUILDROOT/wznmcmbd/WznmWrjapi/
cp ../../wznmcmbd/WznmWrjapi/*.cpp $BUILDROOT/wznmcmbd/WznmWrjapi/

cp Makefile_WznmWrsrv $BUILDROOT/wznmcmbd/WznmWrsrv/Makefile

cp ../../wznmcmbd/WznmWrsrv/*.h $BUILDROOT/wznmcmbd/WznmWrsrv/
cp ../../wznmcmbd/WznmWrsrv/*.cpp $BUILDROOT/wznmcmbd/WznmWrsrv/

cp Makefile_WznmWrweb $BUILDROOT/wznmcmbd/WznmWrweb/Makefile

cp ../../wznmcmbd/WznmWrweb/*.h $BUILDROOT/wznmcmbd/WznmWrweb/
cp ../../wznmcmbd/WznmWrweb/*.cpp $BUILDROOT/wznmcmbd/WznmWrweb/

cp Makefile_WznmWrdbs $BUILDROOT/wznmcmbd/WznmWrdbs/Makefile

cp ../../wznmcmbd/WznmWrdbs/*.h $BUILDROOT/wznmcmbd/WznmWrdbs/
cp ../../wznmcmbd/WznmWrdbs/*.cpp $BUILDROOT/wznmcmbd/WznmWrdbs/

cp Makefile_WznmWrapp $BUILDROOT/wznmcmbd/WznmWrapp/Makefile

cp ../../wznmcmbd/WznmWrapp/*.h $BUILDROOT/wznmcmbd/WznmWrapp/
cp ../../wznmcmbd/WznmWrapp/*.cpp $BUILDROOT/wznmcmbd/WznmWrapp/

cp Makefile_WznmPrctree $BUILDROOT/wznmcmbd/WznmPrctree/Makefile

cp ../../wznmcmbd/WznmPrctree/*.h $BUILDROOT/wznmcmbd/WznmPrctree/
cp ../../wznmcmbd/WznmPrctree/*.cpp $BUILDROOT/wznmcmbd/WznmPrctree/

cp Makefile_WznmWrapi $BUILDROOT/wznmcmbd/WznmWrapi/Makefile

cp ../../wznmcmbd/WznmWrapi/*.h $BUILDROOT/wznmcmbd/WznmWrapi/
cp ../../wznmcmbd/WznmWrapi/*.cpp $BUILDROOT/wznmcmbd/WznmWrapi/

cp Makefile_WznmGen $BUILDROOT/wznmcmbd/WznmGen/Makefile

cp ../../wznmcmbd/WznmGen/*.h $BUILDROOT/wznmcmbd/WznmGen/
cp ../../wznmcmbd/WznmGen/*.cpp $BUILDROOT/wznmcmbd/WznmGen/

cp Makefile_WznmPrcfile $BUILDROOT/wznmcmbd/WznmPrcfile/Makefile

cp ../../wznmcmbd/WznmPrcfile/*.h $BUILDROOT/wznmcmbd/WznmPrcfile/
cp ../../wznmcmbd/WznmPrcfile/*.cpp $BUILDROOT/wznmcmbd/WznmPrcfile/

cp Makefile_WznmCtpWrweb $BUILDROOT/wznmcmbd/WznmCtpWrweb/Makefile

cp ../../wznmcmbd/WznmCtpWrweb/*.h $BUILDROOT/wznmcmbd/WznmCtpWrweb/
cp ../../wznmcmbd/WznmCtpWrweb/*.cpp $BUILDROOT/wznmcmbd/WznmCtpWrweb/

cp Makefile_WznmCtpWrstkit $BUILDROOT/wznmcmbd/WznmCtpWrstkit/Makefile

cp ../../wznmcmbd/WznmCtpWrstkit/*.h $BUILDROOT/wznmcmbd/WznmCtpWrstkit/
cp ../../wznmcmbd/WznmCtpWrstkit/*.cpp $BUILDROOT/wznmcmbd/WznmCtpWrstkit/

cp Makefile_WznmCtpWrsrv $BUILDROOT/wznmcmbd/WznmCtpWrsrv/Makefile

cp ../../wznmcmbd/WznmCtpWrsrv/*.h $BUILDROOT/wznmcmbd/WznmCtpWrsrv/
cp ../../wznmcmbd/WznmCtpWrsrv/*.cpp $BUILDROOT/wznmcmbd/WznmCtpWrsrv/

cp Makefile_WznmCtpGenui $BUILDROOT/wznmcmbd/WznmCtpGenui/Makefile

cp ../../wznmcmbd/WznmCtpGenui/*.h $BUILDROOT/wznmcmbd/WznmCtpGenui/
cp ../../wznmcmbd/WznmCtpGenui/*.cpp $BUILDROOT/wznmcmbd/WznmCtpGenui/

cp Makefile_WznmCtpGenjtr $BUILDROOT/wznmcmbd/WznmCtpGenjtr/Makefile

cp ../../wznmcmbd/WznmCtpGenjtr/*.h $BUILDROOT/wznmcmbd/WznmCtpGenjtr/
cp ../../wznmcmbd/WznmCtpGenjtr/*.cpp $BUILDROOT/wznmcmbd/WznmCtpGenjtr/

cp Makefile_WznmCompl $BUILDROOT/wznmcmbd/WznmCompl/Makefile

cp ../../wznmcmbd/WznmCompl/*.h $BUILDROOT/wznmcmbd/WznmCompl/
cp ../../wznmcmbd/WznmCompl/*.cpp $BUILDROOT/wznmcmbd/WznmCompl/
