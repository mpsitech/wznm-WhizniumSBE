#!/bin/bash
# file make.sh
# make script for Wznm operation daemon, release wznmopd2_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

make Wznmopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWznm" "VecWznm" "WznmCtpWrweb" "WznmCtpWrsrv" "WznmCtpWrstkit" "WznmCtpGenui" "WznmCtpGenjtr")
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

rm Wznmopd.h.gch

