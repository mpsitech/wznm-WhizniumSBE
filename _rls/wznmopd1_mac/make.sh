#!/bin/bash
# file make.sh
# make script for Wznm operation daemon, release wznmopd1_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Jan 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

if [ "$1" = "all" ] || [ "$1" = "clean" ]; then
	subs=("IexWznm" "VecWznm" "WznmWrweb" "WznmWrvue" "WznmWrvis" "WznmWrsrv" "WznmWrswapi" "WznmWrpyapi" "WznmWrjapi" "WznmWrdbs" "WznmWrcsapi" "WznmWrapp" "WznmWrapi" "WznmPrctree" "WznmPrcfile" "WznmGen" "WznmComplvis" "WznmCompl")
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
	make Wznmopd.h.gch
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

	rm Wznmopd.h.gch
fi
