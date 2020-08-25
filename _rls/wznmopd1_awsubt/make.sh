#!/bin/bash
# file make.sh
# make script for Wznm operation daemon, release wznmopd1_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

make Wznmopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWznm" "VecWznm" "WznmWrweb" "WznmWrsrv" "WznmWrjapi" "WznmWrdbs" "WznmWrapp" "WznmWrapi" "WznmPrctree" "WznmPrcfile" "WznmGen" "WznmCompl")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j2
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wznmopd.h.gch

