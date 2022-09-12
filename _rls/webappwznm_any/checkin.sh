#!/bin/bash
# file checkin.sh
# checkin script for Wznm web-based UI, release webappwznm_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 11 Sep 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/wznm/webappwznm/
mv $REPROOT/wznm/webappwznm/favicon.ico $REPROOT/wznm/webappwznm/iconwznm/
touch $REPROOT/wznm/webappwznm/iconwznm/"IP folder --- KEEP"

rm $REPROOT/wznm/webappwznm/checkin.sh
