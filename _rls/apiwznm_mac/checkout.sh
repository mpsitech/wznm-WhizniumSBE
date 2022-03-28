#!/bin/bash
# file checkout.sh
# checkout script for Wznm API library, release apiwznm_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 28 Mar 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/apiwznm

cp makeall.sh $BUILDROOT/apiwznm/

cp Makefile $BUILDROOT/apiwznm/

cp ../../apiwznm/*.h $BUILDROOT/apiwznm/
cp ../../apiwznm/*.cpp $BUILDROOT/apiwznm/
