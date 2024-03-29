#!/bin/bash
# file checkout.sh
# checkout script for Wznm web-based UI, release webappwznm_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/appwznm

cp checkin.sh $WEBROOT/appwznm/

cp -r ../../webappwznm/* $WEBROOT/appwznm/
cp ../../webappwznm/iconwznm/favicon.ico $WEBROOT/appwznm/
