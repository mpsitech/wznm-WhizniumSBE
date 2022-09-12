#!/bin/bash
# file checkout.sh
# checkout script for Wznm daemon, release wznmd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin
export set REPROOT=${WHIZDEVROOT}/rep
export set CMBDBUILDROOT=$REPROOT/wznm/wznmcmbd

mkdir $BUILDROOT/wznmd
mkdir $BUILDROOT/wznmd/IexWznm
mkdir $BUILDROOT/wznmd/VecWznm
mkdir $BUILDROOT/wznmd/CrdWznmNav
mkdir $BUILDROOT/wznmd/CrdWznmUsg
mkdir $BUILDROOT/wznmd/CrdWznmUsr
mkdir $BUILDROOT/wznmd/CrdWznmPrs
mkdir $BUILDROOT/wznmd/CrdWznmFil
mkdir $BUILDROOT/wznmd/CrdWznmLoc
mkdir $BUILDROOT/wznmd/CrdWznmTag
mkdir $BUILDROOT/wznmd/CrdWznmCtp
mkdir $BUILDROOT/wznmd/CrdWznmMch
mkdir $BUILDROOT/wznmd/CrdWznmLib
mkdir $BUILDROOT/wznmd/CrdWznmPrj
mkdir $BUILDROOT/wznmd/CrdWznmVer
mkdir $BUILDROOT/wznmd/CrdWznmCap
mkdir $BUILDROOT/wznmd/CrdWznmErr
mkdir $BUILDROOT/wznmd/CrdWznmTbl
mkdir $BUILDROOT/wznmd/CrdWznmTco
mkdir $BUILDROOT/wznmd/CrdWznmSbs
mkdir $BUILDROOT/wznmd/CrdWznmRel
mkdir $BUILDROOT/wznmd/CrdWznmVec
mkdir $BUILDROOT/wznmd/CrdWznmVit
mkdir $BUILDROOT/wznmd/CrdWznmChk
mkdir $BUILDROOT/wznmd/CrdWznmStb
mkdir $BUILDROOT/wznmd/CrdWznmIex
mkdir $BUILDROOT/wznmd/CrdWznmIme
mkdir $BUILDROOT/wznmd/CrdWznmIel
mkdir $BUILDROOT/wznmd/CrdWznmPst
mkdir $BUILDROOT/wznmd/CrdWznmMdl
mkdir $BUILDROOT/wznmd/CrdWznmCar
mkdir $BUILDROOT/wznmd/CrdWznmDlg
mkdir $BUILDROOT/wznmd/CrdWznmPnl
mkdir $BUILDROOT/wznmd/CrdWznmQry
mkdir $BUILDROOT/wznmd/CrdWznmQco
mkdir $BUILDROOT/wznmd/CrdWznmQmd
mkdir $BUILDROOT/wznmd/CrdWznmCon
mkdir $BUILDROOT/wznmd/CrdWznmOpk
mkdir $BUILDROOT/wznmd/CrdWznmOpx
mkdir $BUILDROOT/wznmd/CrdWznmJob
mkdir $BUILDROOT/wznmd/CrdWznmSge
mkdir $BUILDROOT/wznmd/CrdWznmMtd
mkdir $BUILDROOT/wznmd/CrdWznmBlk
mkdir $BUILDROOT/wznmd/CrdWznmCal
mkdir $BUILDROOT/wznmd/CrdWznmCmp
mkdir $BUILDROOT/wznmd/CrdWznmRls
mkdir $BUILDROOT/wznmd/CrdWznmApp
mkdir $BUILDROOT/wznmd/CrdWznmRtj
mkdir $BUILDROOT/wznmd/CrdWznmEvt
mkdir $BUILDROOT/wznmd/CrdWznmSeq
mkdir $BUILDROOT/wznmd/CrdWznmSte
mkdir $BUILDROOT/wznmd/CrdWznmUtl

mkdir $LIBROOT/wznmd

mkdir $BINROOT/wznmd

cp make.sh $BUILDROOT/wznmd/
cp remake.sh $BUILDROOT/wznmd/

cp Makefile.inc $BUILDROOT/wznmd/
cp Makefile $BUILDROOT/wznmd/

cp ../../wznmd/Wznmd.h $BUILDROOT/wznmd/
cp ../../wznmd/Wznmd.cpp $BUILDROOT/wznmd/

cp ../../wznmd/WznmdAppsrv.h $BUILDROOT/wznmd/
cp ../../wznmd/WznmdAppsrv.cpp $BUILDROOT/wznmd/

cp ../../wznmd/WznmdJobprc.h $BUILDROOT/wznmd/
cp ../../wznmd/WznmdJobprc.cpp $BUILDROOT/wznmd/

cp ../../wznmd/WznmdOpprc.h $BUILDROOT/wznmd/
cp ../../wznmd/WznmdOpprc.cpp $BUILDROOT/wznmd/

cp ../../wznmd/WznmdOpengsrv.h $BUILDROOT/wznmd/
cp ../../wznmd/WznmdOpengsrv.cpp $BUILDROOT/wznmd/

cp ../../wznmd/WznmdOpengcli.h $BUILDROOT/wznmd/
cp ../../wznmd/WznmdOpengcli.cpp $BUILDROOT/wznmd/

cp ../../wznmd/Wznmd_exe.h $BUILDROOT/wznmd/
cp ../../wznmd/Wznmd_exe.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/Wznm.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/Wznm.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/Root*.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/Root*.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/Sess*.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/Sess*.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/gbl/*.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/gbl/*.cpp $BUILDROOT/wznmd/

cp Makefile_IexWznm $BUILDROOT/wznmd/IexWznm/Makefile

cp $CMBDBUILDROOT/IexWznm/IexWznm*.h $BUILDROOT/wznmd/IexWznm/
cp $CMBDBUILDROOT/IexWznm/IexWznm*.cpp $BUILDROOT/wznmd/IexWznm/

cp $CMBDBUILDROOT/IexWznm/JobWznmIex*.h $BUILDROOT/wznmd/IexWznm/
cp $CMBDBUILDROOT/IexWznm/JobWznmIex*.cpp $BUILDROOT/wznmd/IexWznm/

cp Makefile_VecWznm $BUILDROOT/wznmd/VecWznm/Makefile

cp $CMBDBUILDROOT/VecWznm/Vec*.h $BUILDROOT/wznmd/VecWznm/
cp $CMBDBUILDROOT/VecWznm/Vec*.cpp $BUILDROOT/wznmd/VecWznm/

cp Makefile_CrdWznmNav $BUILDROOT/wznmd/CrdWznmNav/Makefile

cp $CMBDBUILDROOT/CrdWznmNav/*.h $BUILDROOT/wznmd/CrdWznmNav/
cp $CMBDBUILDROOT/CrdWznmNav/*.cpp $BUILDROOT/wznmd/CrdWznmNav/

cp Makefile_CrdWznmUsg $BUILDROOT/wznmd/CrdWznmUsg/Makefile

cp $CMBDBUILDROOT/CrdWznmUsg/*.h $BUILDROOT/wznmd/CrdWznmUsg/
cp $CMBDBUILDROOT/CrdWznmUsg/*.cpp $BUILDROOT/wznmd/CrdWznmUsg/

cp Makefile_CrdWznmUsr $BUILDROOT/wznmd/CrdWznmUsr/Makefile

cp $CMBDBUILDROOT/CrdWznmUsr/*.h $BUILDROOT/wznmd/CrdWznmUsr/
cp $CMBDBUILDROOT/CrdWznmUsr/*.cpp $BUILDROOT/wznmd/CrdWznmUsr/

cp Makefile_CrdWznmPrs $BUILDROOT/wznmd/CrdWznmPrs/Makefile

cp $CMBDBUILDROOT/CrdWznmPrs/*.h $BUILDROOT/wznmd/CrdWznmPrs/
cp $CMBDBUILDROOT/CrdWznmPrs/*.cpp $BUILDROOT/wznmd/CrdWznmPrs/

cp Makefile_CrdWznmFil $BUILDROOT/wznmd/CrdWznmFil/Makefile

cp $CMBDBUILDROOT/CrdWznmFil/*.h $BUILDROOT/wznmd/CrdWznmFil/
cp $CMBDBUILDROOT/CrdWznmFil/*.cpp $BUILDROOT/wznmd/CrdWznmFil/

cp Makefile_CrdWznmLoc $BUILDROOT/wznmd/CrdWznmLoc/Makefile

cp $CMBDBUILDROOT/CrdWznmLoc/*.h $BUILDROOT/wznmd/CrdWznmLoc/
cp $CMBDBUILDROOT/CrdWznmLoc/*.cpp $BUILDROOT/wznmd/CrdWznmLoc/

cp Makefile_CrdWznmTag $BUILDROOT/wznmd/CrdWznmTag/Makefile

cp $CMBDBUILDROOT/CrdWznmTag/*.h $BUILDROOT/wznmd/CrdWznmTag/
cp $CMBDBUILDROOT/CrdWznmTag/*.cpp $BUILDROOT/wznmd/CrdWznmTag/

cp Makefile_CrdWznmCtp $BUILDROOT/wznmd/CrdWznmCtp/Makefile

cp $CMBDBUILDROOT/CrdWznmCtp/*.h $BUILDROOT/wznmd/CrdWznmCtp/
cp $CMBDBUILDROOT/CrdWznmCtp/*.cpp $BUILDROOT/wznmd/CrdWznmCtp/

cp Makefile_CrdWznmMch $BUILDROOT/wznmd/CrdWznmMch/Makefile

cp $CMBDBUILDROOT/CrdWznmMch/*.h $BUILDROOT/wznmd/CrdWznmMch/
cp $CMBDBUILDROOT/CrdWznmMch/*.cpp $BUILDROOT/wznmd/CrdWznmMch/

cp Makefile_CrdWznmLib $BUILDROOT/wznmd/CrdWznmLib/Makefile

cp $CMBDBUILDROOT/CrdWznmLib/*.h $BUILDROOT/wznmd/CrdWznmLib/
cp $CMBDBUILDROOT/CrdWznmLib/*.cpp $BUILDROOT/wznmd/CrdWznmLib/

cp Makefile_CrdWznmPrj $BUILDROOT/wznmd/CrdWznmPrj/Makefile

cp $CMBDBUILDROOT/CrdWznmPrj/*.h $BUILDROOT/wznmd/CrdWznmPrj/
cp $CMBDBUILDROOT/CrdWznmPrj/*.cpp $BUILDROOT/wznmd/CrdWznmPrj/

cp Makefile_CrdWznmVer $BUILDROOT/wznmd/CrdWznmVer/Makefile

cp $CMBDBUILDROOT/CrdWznmVer/*.h $BUILDROOT/wznmd/CrdWznmVer/
cp $CMBDBUILDROOT/CrdWznmVer/*.cpp $BUILDROOT/wznmd/CrdWznmVer/

cp Makefile_CrdWznmCap $BUILDROOT/wznmd/CrdWznmCap/Makefile

cp $CMBDBUILDROOT/CrdWznmCap/*.h $BUILDROOT/wznmd/CrdWznmCap/
cp $CMBDBUILDROOT/CrdWznmCap/*.cpp $BUILDROOT/wznmd/CrdWznmCap/

cp Makefile_CrdWznmErr $BUILDROOT/wznmd/CrdWznmErr/Makefile

cp $CMBDBUILDROOT/CrdWznmErr/*.h $BUILDROOT/wznmd/CrdWznmErr/
cp $CMBDBUILDROOT/CrdWznmErr/*.cpp $BUILDROOT/wznmd/CrdWznmErr/

cp Makefile_CrdWznmTbl $BUILDROOT/wznmd/CrdWznmTbl/Makefile

cp $CMBDBUILDROOT/CrdWznmTbl/*.h $BUILDROOT/wznmd/CrdWznmTbl/
cp $CMBDBUILDROOT/CrdWznmTbl/*.cpp $BUILDROOT/wznmd/CrdWznmTbl/

cp Makefile_CrdWznmTco $BUILDROOT/wznmd/CrdWznmTco/Makefile

cp $CMBDBUILDROOT/CrdWznmTco/*.h $BUILDROOT/wznmd/CrdWznmTco/
cp $CMBDBUILDROOT/CrdWznmTco/*.cpp $BUILDROOT/wznmd/CrdWznmTco/

cp Makefile_CrdWznmSbs $BUILDROOT/wznmd/CrdWznmSbs/Makefile

cp $CMBDBUILDROOT/CrdWznmSbs/*.h $BUILDROOT/wznmd/CrdWznmSbs/
cp $CMBDBUILDROOT/CrdWznmSbs/*.cpp $BUILDROOT/wznmd/CrdWznmSbs/

cp Makefile_CrdWznmRel $BUILDROOT/wznmd/CrdWznmRel/Makefile

cp $CMBDBUILDROOT/CrdWznmRel/*.h $BUILDROOT/wznmd/CrdWznmRel/
cp $CMBDBUILDROOT/CrdWznmRel/*.cpp $BUILDROOT/wznmd/CrdWznmRel/

cp Makefile_CrdWznmVec $BUILDROOT/wznmd/CrdWznmVec/Makefile

cp $CMBDBUILDROOT/CrdWznmVec/*.h $BUILDROOT/wznmd/CrdWznmVec/
cp $CMBDBUILDROOT/CrdWznmVec/*.cpp $BUILDROOT/wznmd/CrdWznmVec/

cp Makefile_CrdWznmVit $BUILDROOT/wznmd/CrdWznmVit/Makefile

cp $CMBDBUILDROOT/CrdWznmVit/*.h $BUILDROOT/wznmd/CrdWznmVit/
cp $CMBDBUILDROOT/CrdWznmVit/*.cpp $BUILDROOT/wznmd/CrdWznmVit/

cp Makefile_CrdWznmChk $BUILDROOT/wznmd/CrdWznmChk/Makefile

cp $CMBDBUILDROOT/CrdWznmChk/*.h $BUILDROOT/wznmd/CrdWznmChk/
cp $CMBDBUILDROOT/CrdWznmChk/*.cpp $BUILDROOT/wznmd/CrdWznmChk/

cp Makefile_CrdWznmStb $BUILDROOT/wznmd/CrdWznmStb/Makefile

cp $CMBDBUILDROOT/CrdWznmStb/*.h $BUILDROOT/wznmd/CrdWznmStb/
cp $CMBDBUILDROOT/CrdWznmStb/*.cpp $BUILDROOT/wznmd/CrdWznmStb/

cp Makefile_CrdWznmIex $BUILDROOT/wznmd/CrdWznmIex/Makefile

cp $CMBDBUILDROOT/CrdWznmIex/*.h $BUILDROOT/wznmd/CrdWznmIex/
cp $CMBDBUILDROOT/CrdWznmIex/*.cpp $BUILDROOT/wznmd/CrdWznmIex/

cp Makefile_CrdWznmIme $BUILDROOT/wznmd/CrdWznmIme/Makefile

cp $CMBDBUILDROOT/CrdWznmIme/*.h $BUILDROOT/wznmd/CrdWznmIme/
cp $CMBDBUILDROOT/CrdWznmIme/*.cpp $BUILDROOT/wznmd/CrdWznmIme/

cp Makefile_CrdWznmIel $BUILDROOT/wznmd/CrdWznmIel/Makefile

cp $CMBDBUILDROOT/CrdWznmIel/*.h $BUILDROOT/wznmd/CrdWznmIel/
cp $CMBDBUILDROOT/CrdWznmIel/*.cpp $BUILDROOT/wznmd/CrdWznmIel/

cp Makefile_CrdWznmPst $BUILDROOT/wznmd/CrdWznmPst/Makefile

cp $CMBDBUILDROOT/CrdWznmPst/*.h $BUILDROOT/wznmd/CrdWznmPst/
cp $CMBDBUILDROOT/CrdWznmPst/*.cpp $BUILDROOT/wznmd/CrdWznmPst/

cp Makefile_CrdWznmMdl $BUILDROOT/wznmd/CrdWznmMdl/Makefile

cp $CMBDBUILDROOT/CrdWznmMdl/*.h $BUILDROOT/wznmd/CrdWznmMdl/
cp $CMBDBUILDROOT/CrdWznmMdl/*.cpp $BUILDROOT/wznmd/CrdWznmMdl/

cp Makefile_CrdWznmCar $BUILDROOT/wznmd/CrdWznmCar/Makefile

cp $CMBDBUILDROOT/CrdWznmCar/*.h $BUILDROOT/wznmd/CrdWznmCar/
cp $CMBDBUILDROOT/CrdWznmCar/*.cpp $BUILDROOT/wznmd/CrdWznmCar/

cp Makefile_CrdWznmDlg $BUILDROOT/wznmd/CrdWznmDlg/Makefile

cp $CMBDBUILDROOT/CrdWznmDlg/*.h $BUILDROOT/wznmd/CrdWznmDlg/
cp $CMBDBUILDROOT/CrdWznmDlg/*.cpp $BUILDROOT/wznmd/CrdWznmDlg/

cp Makefile_CrdWznmPnl $BUILDROOT/wznmd/CrdWznmPnl/Makefile

cp $CMBDBUILDROOT/CrdWznmPnl/*.h $BUILDROOT/wznmd/CrdWznmPnl/
cp $CMBDBUILDROOT/CrdWznmPnl/*.cpp $BUILDROOT/wznmd/CrdWznmPnl/

cp Makefile_CrdWznmQry $BUILDROOT/wznmd/CrdWznmQry/Makefile

cp $CMBDBUILDROOT/CrdWznmQry/*.h $BUILDROOT/wznmd/CrdWznmQry/
cp $CMBDBUILDROOT/CrdWznmQry/*.cpp $BUILDROOT/wznmd/CrdWznmQry/

cp Makefile_CrdWznmQco $BUILDROOT/wznmd/CrdWznmQco/Makefile

cp $CMBDBUILDROOT/CrdWznmQco/*.h $BUILDROOT/wznmd/CrdWznmQco/
cp $CMBDBUILDROOT/CrdWznmQco/*.cpp $BUILDROOT/wznmd/CrdWznmQco/

cp Makefile_CrdWznmQmd $BUILDROOT/wznmd/CrdWznmQmd/Makefile

cp $CMBDBUILDROOT/CrdWznmQmd/*.h $BUILDROOT/wznmd/CrdWznmQmd/
cp $CMBDBUILDROOT/CrdWznmQmd/*.cpp $BUILDROOT/wznmd/CrdWznmQmd/

cp Makefile_CrdWznmCon $BUILDROOT/wznmd/CrdWznmCon/Makefile

cp $CMBDBUILDROOT/CrdWznmCon/*.h $BUILDROOT/wznmd/CrdWznmCon/
cp $CMBDBUILDROOT/CrdWznmCon/*.cpp $BUILDROOT/wznmd/CrdWznmCon/

cp Makefile_CrdWznmOpk $BUILDROOT/wznmd/CrdWznmOpk/Makefile

cp $CMBDBUILDROOT/CrdWznmOpk/*.h $BUILDROOT/wznmd/CrdWznmOpk/
cp $CMBDBUILDROOT/CrdWznmOpk/*.cpp $BUILDROOT/wznmd/CrdWznmOpk/

cp Makefile_CrdWznmOpx $BUILDROOT/wznmd/CrdWznmOpx/Makefile

cp $CMBDBUILDROOT/CrdWznmOpx/*.h $BUILDROOT/wznmd/CrdWznmOpx/
cp $CMBDBUILDROOT/CrdWznmOpx/*.cpp $BUILDROOT/wznmd/CrdWznmOpx/

cp Makefile_CrdWznmJob $BUILDROOT/wznmd/CrdWznmJob/Makefile

cp $CMBDBUILDROOT/CrdWznmJob/*.h $BUILDROOT/wznmd/CrdWznmJob/
cp $CMBDBUILDROOT/CrdWznmJob/*.cpp $BUILDROOT/wznmd/CrdWznmJob/

cp Makefile_CrdWznmSge $BUILDROOT/wznmd/CrdWznmSge/Makefile

cp $CMBDBUILDROOT/CrdWznmSge/*.h $BUILDROOT/wznmd/CrdWznmSge/
cp $CMBDBUILDROOT/CrdWznmSge/*.cpp $BUILDROOT/wznmd/CrdWznmSge/

cp Makefile_CrdWznmMtd $BUILDROOT/wznmd/CrdWznmMtd/Makefile

cp $CMBDBUILDROOT/CrdWznmMtd/*.h $BUILDROOT/wznmd/CrdWznmMtd/
cp $CMBDBUILDROOT/CrdWznmMtd/*.cpp $BUILDROOT/wznmd/CrdWznmMtd/

cp Makefile_CrdWznmBlk $BUILDROOT/wznmd/CrdWznmBlk/Makefile

cp $CMBDBUILDROOT/CrdWznmBlk/*.h $BUILDROOT/wznmd/CrdWznmBlk/
cp $CMBDBUILDROOT/CrdWznmBlk/*.cpp $BUILDROOT/wznmd/CrdWznmBlk/

cp Makefile_CrdWznmCal $BUILDROOT/wznmd/CrdWznmCal/Makefile

cp $CMBDBUILDROOT/CrdWznmCal/*.h $BUILDROOT/wznmd/CrdWznmCal/
cp $CMBDBUILDROOT/CrdWznmCal/*.cpp $BUILDROOT/wznmd/CrdWznmCal/

cp Makefile_CrdWznmCmp $BUILDROOT/wznmd/CrdWznmCmp/Makefile

cp $CMBDBUILDROOT/CrdWznmCmp/*.h $BUILDROOT/wznmd/CrdWznmCmp/
cp $CMBDBUILDROOT/CrdWznmCmp/*.cpp $BUILDROOT/wznmd/CrdWznmCmp/

cp Makefile_CrdWznmRls $BUILDROOT/wznmd/CrdWznmRls/Makefile

cp $CMBDBUILDROOT/CrdWznmRls/*.h $BUILDROOT/wznmd/CrdWznmRls/
cp $CMBDBUILDROOT/CrdWznmRls/*.cpp $BUILDROOT/wznmd/CrdWznmRls/

cp Makefile_CrdWznmApp $BUILDROOT/wznmd/CrdWznmApp/Makefile

cp $CMBDBUILDROOT/CrdWznmApp/*.h $BUILDROOT/wznmd/CrdWznmApp/
cp $CMBDBUILDROOT/CrdWznmApp/*.cpp $BUILDROOT/wznmd/CrdWznmApp/

cp Makefile_CrdWznmRtj $BUILDROOT/wznmd/CrdWznmRtj/Makefile

cp $CMBDBUILDROOT/CrdWznmRtj/*.h $BUILDROOT/wznmd/CrdWznmRtj/
cp $CMBDBUILDROOT/CrdWznmRtj/*.cpp $BUILDROOT/wznmd/CrdWznmRtj/

cp Makefile_CrdWznmEvt $BUILDROOT/wznmd/CrdWznmEvt/Makefile

cp $CMBDBUILDROOT/CrdWznmEvt/*.h $BUILDROOT/wznmd/CrdWznmEvt/
cp $CMBDBUILDROOT/CrdWznmEvt/*.cpp $BUILDROOT/wznmd/CrdWznmEvt/

cp Makefile_CrdWznmSeq $BUILDROOT/wznmd/CrdWznmSeq/Makefile

cp $CMBDBUILDROOT/CrdWznmSeq/*.h $BUILDROOT/wznmd/CrdWznmSeq/
cp $CMBDBUILDROOT/CrdWznmSeq/*.cpp $BUILDROOT/wznmd/CrdWznmSeq/

cp Makefile_CrdWznmSte $BUILDROOT/wznmd/CrdWznmSte/Makefile

cp $CMBDBUILDROOT/CrdWznmSte/*.h $BUILDROOT/wznmd/CrdWznmSte/
cp $CMBDBUILDROOT/CrdWznmSte/*.cpp $BUILDROOT/wznmd/CrdWznmSte/

cp Makefile_CrdWznmUtl $BUILDROOT/wznmd/CrdWznmUtl/Makefile

cp $CMBDBUILDROOT/CrdWznmUtl/*.h $BUILDROOT/wznmd/CrdWznmUtl/
cp $CMBDBUILDROOT/CrdWznmUtl/*.cpp $BUILDROOT/wznmd/CrdWznmUtl/

cp $CMBDBUILDROOT/WznmWrvue/WznmWrvue_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrvue/WznmWrvue_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrvue/SqkWznmWrvue.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrvue/SqkWznmWrvue.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrweb/WznmWrweb_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrweb/WznmWrweb_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrweb/SqkWznmWrweb.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrweb/SqkWznmWrweb.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrswapi/WznmWrswapi_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrswapi/WznmWrswapi_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrswapi/SqkWznmWrswapi.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrswapi/SqkWznmWrswapi.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrsrv/WznmWrsrv_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrsrv/WznmWrsrv_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrsrv/SqkWznmWrsrv.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrsrv/SqkWznmWrsrv.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrpyapi/WznmWrpyapi_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrpyapi/WznmWrpyapi_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrpyapi/SqkWznmWrpyapi.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrpyapi/SqkWznmWrpyapi.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrjapi/WznmWrjapi_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrjapi/WznmWrjapi_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrjapi/SqkWznmWrjapi.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrjapi/SqkWznmWrjapi.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrdbs/WznmWrdbs_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrdbs/WznmWrdbs_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrdbs/SqkWznmWrdbs.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrdbs/SqkWznmWrdbs.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrapp/WznmWrapp_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapp/WznmWrapp_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapp/SqkWznmWrapp.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapp/SqkWznmWrapp.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrcsapi/WznmWrcsapi_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrcsapi/WznmWrcsapi_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrcsapi/SqkWznmWrcsapi.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrcsapi/SqkWznmWrcsapi.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmWrapi/WznmWrapi_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapi/WznmWrapi_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapi/SqkWznmWrapi.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmWrapi/SqkWznmWrapi.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmGen/WznmGen_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmGen/WznmGen_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmGen/SqkWznmGen.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmGen/SqkWznmGen.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmPrcfile/WznmPrcfile_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrcfile/WznmPrcfile_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrcfile/SqkWznmPrcfile.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrcfile/SqkWznmPrcfile.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmPrctree/WznmPrctree_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrctree/WznmPrctree_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrctree/SqkWznmPrctree.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmPrctree/SqkWznmPrctree.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCtpWrweb/WznmCtpWrweb_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrweb/WznmCtpWrweb_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrweb/SqkWznmCtpWrweb.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrweb/SqkWznmCtpWrweb.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCtpWrstkit/WznmCtpWrstkit_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrstkit/WznmCtpWrstkit_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrstkit/SqkWznmCtpWrstkit.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrstkit/SqkWznmCtpWrstkit.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCtpWrsrv/WznmCtpWrsrv_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrsrv/WznmCtpWrsrv_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrsrv/SqkWznmCtpWrsrv.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpWrsrv/SqkWznmCtpWrsrv.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCtpGenui/WznmCtpGenui_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenui/WznmCtpGenui_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenui/SqkWznmCtpGenui.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenui/SqkWznmCtpGenui.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCtpGenjtr/WznmCtpGenjtr_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenjtr/WznmCtpGenjtr_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenjtr/SqkWznmCtpGenjtr.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCtpGenjtr/SqkWznmCtpGenjtr.cpp $BUILDROOT/wznmd/

cp $CMBDBUILDROOT/WznmCompl/WznmCompl_blks.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCompl/WznmCompl_blks.cpp $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCompl/SqkWznmCompl.h $BUILDROOT/wznmd/
cp $CMBDBUILDROOT/WznmCompl/SqkWznmCompl.cpp $BUILDROOT/wznmd/
