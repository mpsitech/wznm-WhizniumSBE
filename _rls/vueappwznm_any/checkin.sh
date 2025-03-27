#!/bin/bash
# file checkin.sh
# checkin script for Wznm Vue.js UI, release vueappwznm_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Jan 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp AppWznm.vue $REPROOT/wznm/vueappwznm/
cp main.js $REPROOT/wznm/vueappwznm/

cp assets/* $REPROOT/wznm/vueappwznm/assets/
cp ../public/favicon.ico $REPROOT/wznm/vueappwznm/assets/
touch $REPROOT/wznm/vueappwznm/assets/"IP folder --- KEEP"

cp -r components/* $REPROOT/wznm/vueappwznm/

cp -r scripts $REPROOT/wznm/vueappwznm/
