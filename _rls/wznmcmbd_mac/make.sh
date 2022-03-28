#!/bin/bash
# file make.sh
# make script for Wznm combined daemon, release wznmcmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 28 Mar 2022
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
	subs=("IexWznm" "VecWznm" "CrdWznmUsg" "CrdWznmUsr" "CrdWznmPrs" "CrdWznmFil" "CrdWznmNav" "CrdWznmLoc" "CrdWznmTag" "CrdWznmCtp" "CrdWznmMch" "CrdWznmLib" "CrdWznmPrj" "CrdWznmVer" "CrdWznmCap" "CrdWznmErr" "CrdWznmTbl" "CrdWznmTco" "CrdWznmSbs" "CrdWznmRel" "CrdWznmVec" "CrdWznmVit" "CrdWznmChk" "CrdWznmStb" "CrdWznmIex" "CrdWznmIme" "CrdWznmIel" "CrdWznmPst" "CrdWznmMdl" "CrdWznmCar" "CrdWznmDlg" "CrdWznmPnl" "CrdWznmQry" "CrdWznmQco" "CrdWznmQmd" "CrdWznmCon" "CrdWznmOpk" "CrdWznmOpx" "CrdWznmJob" "CrdWznmSge" "CrdWznmMtd" "CrdWznmBlk" "CrdWznmCal" "CrdWznmCmp" "CrdWznmRls" "CrdWznmApp" "CrdWznmRtj" "CrdWznmEvt" "CrdWznmSeq" "CrdWznmSte" "CrdWznmUtl" "WznmWrweb" "WznmWrvue" "WznmWrsrv" "WznmWrsapi" "WznmWrjapi" "WznmWrdbs" "WznmWrapp" "WznmWrapi" "WznmPrctree" "WznmCtpWrstkit" "WznmCtpWrweb" "WznmGen" "WznmPrcfile" "WznmCtpWrsrv" "WznmCtpGenui" "WznmCompl" "WznmCtpGenjtr")
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
