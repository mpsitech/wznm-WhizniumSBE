#!/bin/bash
# file make.sh
# make script for Wznm combined daemon, release wznmcmbd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

make Wznmcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWznm" "VecWznm" "CrdWznmNav" "CrdWznmUsg" "CrdWznmUsr" "CrdWznmPrs" "CrdWznmFil" "CrdWznmLoc" "CrdWznmTag" "CrdWznmCtp" "CrdWznmMty" "CrdWznmMch" "CrdWznmLib" "CrdWznmPrj" "CrdWznmVer" "CrdWznmCap" "CrdWznmErr" "CrdWznmTbl" "CrdWznmTco" "CrdWznmSbs" "CrdWznmRel" "CrdWznmVec" "CrdWznmVit" "CrdWznmChk" "CrdWznmStb" "CrdWznmIex" "CrdWznmIme" "CrdWznmIel" "CrdWznmPst" "CrdWznmMdl" "CrdWznmCar" "CrdWznmDlg" "CrdWznmPnl" "CrdWznmQry" "CrdWznmQco" "CrdWznmQmd" "CrdWznmCon" "CrdWznmOpk" "CrdWznmOpx" "CrdWznmJob" "CrdWznmSge" "CrdWznmMtd" "CrdWznmBlk" "CrdWznmCal" "CrdWznmCmp" "CrdWznmRls" "CrdWznmApp" "CrdWznmRtj" "CrdWznmEvt" "CrdWznmSeq" "CrdWznmSte" "CrdWznmUtl" "WznmWrweb" "WznmWrjapi" "WznmWrsrv" "WznmWrapp" "WznmWrdbs" "WznmPrcfile" "WznmPrctree" "WznmWrapi" "WznmCtpWrweb" "WznmGen" "WznmCtpWrstkit" "WznmCtpWrsrv" "WznmCompl" "WznmCtpGenjtr" "WznmCtpGenui")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j16
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wznmcmbd.h.gch

