#!/bin/bash
# file make.sh
# make script for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wznmcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWznm" "VecWznm" "CrdWznmNav" "CrdWznmUsg" "CrdWznmUsr" "CrdWznmPrs" "CrdWznmFil" "CrdWznmLoc" "CrdWznmTag" "CrdWznmCtp" "CrdWznmMch" "CrdWznmLib" "CrdWznmPrj" "CrdWznmVer" "CrdWznmCap" "CrdWznmErr" "CrdWznmTbl" "CrdWznmTco" "CrdWznmSbs" "CrdWznmRel" "CrdWznmVec" "CrdWznmVit" "CrdWznmChk" "CrdWznmStb" "CrdWznmIex" "CrdWznmIme" "CrdWznmIel" "CrdWznmPst" "CrdWznmMdl" "CrdWznmCar" "CrdWznmDlg" "CrdWznmPnl" "CrdWznmQry" "CrdWznmQco" "CrdWznmQmd" "CrdWznmCon" "CrdWznmOpk" "CrdWznmOpx" "CrdWznmJob" "CrdWznmSge" "CrdWznmMtd" "CrdWznmBlk" "CrdWznmCal" "CrdWznmCmp" "CrdWznmRls" "CrdWznmApp" "CrdWznmRtj" "CrdWznmEvt" "CrdWznmSeq" "CrdWznmSte" "CrdWznmUtl" "WznmWrweb" "WznmWrjapi" "WznmWrsrv" "WznmWrdbs" "WznmWrapi" "WznmWrapp" "WznmPrcfile" "WznmPrctree" "WznmCtpWrsrv" "WznmCtpWrstkit" "WznmCtpWrweb" "WznmGen" "WznmCtpGenui" "WznmCtpGenjtr" "WznmCompl")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j4
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wznmcmbd.h.gch
