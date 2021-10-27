#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd2_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Oct 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wznm/_rls/wznmopd2_ubuntu
./checkout.sh

cd $BUILDROOT/wznmopd2

./make.sh "$@"
