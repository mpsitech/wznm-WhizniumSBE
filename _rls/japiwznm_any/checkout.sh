#!/bin/bash
# file checkout.sh
# checkout script for Wznm Java API library, release japiwznm_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${JAVAROOT+x} ]; then
	echo "JAVAROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

mkdir $JAVAROOT/apiwznm
mkdir $JAVAROOT/apiwznm/src
mkdir $JAVAROOT/apiwznm/src/apiwznm
mkdir $JAVAROOT/apiwznm/bin
mkdir $JAVAROOT/apiwznm/bin/apiwznm

cp ../../japiwznm/*.java $JAVAROOT/apiwznm/src/apiwznm/
