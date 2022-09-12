#!/bin/bash
# file make.sh
# make script for Wznm daemon, release wznmd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

if [ "$1" = "all" ] || [ "$1" = "clean" ]; then
	subs=("IexWznm" "VecWznm" "CrdWznmNav" "CrdWznmUsg" "CrdWznmUsr" "CrdWznmPrs" "CrdWznmFil" "CrdWznmLoc" "CrdWznmTag" "CrdWznmCtp" "CrdWznmMch" "CrdWznmLib" "CrdWznmPrj" "CrdWznmVer" "CrdWznmCap" "CrdWznmErr" "CrdWznmTbl" "CrdWznmTco" "CrdWznmSbs" "CrdWznmRel" "CrdWznmVec" "CrdWznmVit" "CrdWznmChk" "CrdWznmStb" "CrdWznmIex" "CrdWznmIme" "CrdWznmIel" "CrdWznmPst" "CrdWznmMdl" "CrdWznmCar" "CrdWznmDlg" "CrdWznmPnl" "CrdWznmQry" "CrdWznmQco" "CrdWznmQmd" "CrdWznmCon" "CrdWznmOpk" "CrdWznmOpx" "CrdWznmJob" "CrdWznmSge" "CrdWznmMtd" "CrdWznmBlk" "CrdWznmCal" "CrdWznmCmp" "CrdWznmRls" "CrdWznmApp" "CrdWznmRtj" "CrdWznmEvt" "CrdWznmSeq" "CrdWznmSte" "CrdWznmUtl")
else
	subs=("$@")
fi

if [ "$1" = "clean" ]; then
	for var in "${subs[@]}"
	do
		cd "$var"
		make clean
		cd ..
	done

	make clean
else
	make Wznmd.h.gch
	if [ $? -ne 0 ]; then
		exit
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

	rm Wznmd.h.gch
fi
