#!/bin/bash
# file make.sh
# make script for Wznm operation daemon, release wznmopd1_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 22 Feb 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wznmopd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWznm" "VecWznm" "WznmCompl" "WznmGen" "WznmPrcfile" "WznmPrctree" "WznmWrapi" "WznmWrapp" "WznmWrdbs" "WznmWrjapi" "WznmWrsapi" "WznmWrsrv" "WznmWrvue" "WznmWrweb")
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
