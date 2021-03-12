#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd1_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wznm/_rls/wznmopd1_mac
./checkout.sh

cd $BUILDROOT/wznmopd1

./make.sh "$@"
