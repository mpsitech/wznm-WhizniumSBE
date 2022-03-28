#!/bin/bash
# file checkout.sh
# checkout script for Wznm database access library, release dbswznm_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 28 Mar 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbswznm

cp makeall.sh $BUILDROOT/dbswznm/

cp Makefile $BUILDROOT/dbswznm/

cp ../../dbswznm/DbsWznm.h $BUILDROOT/dbswznm/
cp ../../dbswznm/DbsWznm_vecs.cpp $BUILDROOT/dbswznm/
cp ../../dbswznm/DbsWznm.cpp $BUILDROOT/dbswznm/

cp ../../dbswznm/Wznm*.h $BUILDROOT/dbswznm/
cp ../../dbswznm/Wznm*.cpp $BUILDROOT/dbswznm/
