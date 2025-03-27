#!/bin/bash
# file checkout.sh
# checkout script for Wznm Vue.js UI, release vueappwznm_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Jan 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/vueappwznm/src

cp checkin.sh $WEBROOT/vueappwznm/src

cp ../../vueappwznm/AppWznm.vue $WEBROOT/vueappwznm/src/
cp ../../vueappwznm/main.js $WEBROOT/vueappwznm/src/

mkdir $WEBROOT/vueappwznm/src/assets

cp ../../vueappwznm/assets/* $WEBROOT/vueappwznm/src/assets/
cp ../../vueappwznm/assets/favicon.ico $WEBROOT/vueappwznm/public/

mkdir $WEBROOT/vueappwznm/src/components

cp ../../vueappwznm/SessWznm.vue $WEBROOT/vueappwznm/src/components/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmStart

cp ../../vueappwznm/CrdWznmStart/CrdWznmStart.vue $WEBROOT/vueappwznm/src/components/CrdWznmStart/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmUsg

cp ../../vueappwznm/CrdWznmUsg/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmUsg/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmUsr

cp ../../vueappwznm/CrdWznmUsr/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmUsr/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmPrs

cp ../../vueappwznm/CrdWznmPrs/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmPrs/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmFil

cp ../../vueappwznm/CrdWznmFil/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmFil/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmNav

cp ../../vueappwznm/CrdWznmNav/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmNav/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmLoc

cp ../../vueappwznm/CrdWznmLoc/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmLoc/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmTag

cp ../../vueappwznm/CrdWznmTag/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmTag/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCtp

cp ../../vueappwznm/CrdWznmCtp/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCtp/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmMch

cp ../../vueappwznm/CrdWznmMch/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmMch/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmLib

cp ../../vueappwznm/CrdWznmLib/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmLib/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmPrj

cp ../../vueappwznm/CrdWznmPrj/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmPrj/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmVer

cp ../../vueappwznm/CrdWznmVer/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmVer/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCap

cp ../../vueappwznm/CrdWznmCap/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCap/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmErr

cp ../../vueappwznm/CrdWznmErr/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmErr/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmTbl

cp ../../vueappwznm/CrdWznmTbl/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmTbl/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmTco

cp ../../vueappwznm/CrdWznmTco/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmTco/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmSbs

cp ../../vueappwznm/CrdWznmSbs/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmSbs/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmRel

cp ../../vueappwznm/CrdWznmRel/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmRel/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmVec

cp ../../vueappwznm/CrdWznmVec/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmVec/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmVit

cp ../../vueappwznm/CrdWznmVit/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmVit/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmChk

cp ../../vueappwznm/CrdWznmChk/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmChk/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmStb

cp ../../vueappwznm/CrdWznmStb/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmStb/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmIex

cp ../../vueappwznm/CrdWznmIex/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmIex/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmIme

cp ../../vueappwznm/CrdWznmIme/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmIme/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmIel

cp ../../vueappwznm/CrdWznmIel/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmIel/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmPst

cp ../../vueappwznm/CrdWznmPst/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmPst/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmMdl

cp ../../vueappwznm/CrdWznmMdl/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmMdl/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCar

cp ../../vueappwznm/CrdWznmCar/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCar/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmDlg

cp ../../vueappwznm/CrdWznmDlg/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmDlg/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmPnl

cp ../../vueappwznm/CrdWznmPnl/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmPnl/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmQry

cp ../../vueappwznm/CrdWznmQry/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmQry/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmQco

cp ../../vueappwznm/CrdWznmQco/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmQco/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmQmd

cp ../../vueappwznm/CrdWznmQmd/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmQmd/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCon

cp ../../vueappwznm/CrdWznmCon/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCon/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmOpk

cp ../../vueappwznm/CrdWznmOpk/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmOpk/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmOpx

cp ../../vueappwznm/CrdWznmOpx/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmOpx/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmJob

cp ../../vueappwznm/CrdWznmJob/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmJob/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmSge

cp ../../vueappwznm/CrdWznmSge/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmSge/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmMtd

cp ../../vueappwznm/CrdWznmMtd/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmMtd/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmBlk

cp ../../vueappwznm/CrdWznmBlk/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmBlk/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCal

cp ../../vueappwznm/CrdWznmCal/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCal/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmCmp

cp ../../vueappwznm/CrdWznmCmp/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmCmp/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmRls

cp ../../vueappwznm/CrdWznmRls/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmRls/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmVis

cp ../../vueappwznm/CrdWznmVis/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmVis/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmSht

cp ../../vueappwznm/CrdWznmSht/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmSht/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmBox

cp ../../vueappwznm/CrdWznmBox/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmBox/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmApp

cp ../../vueappwznm/CrdWznmApp/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmApp/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmRtj

cp ../../vueappwznm/CrdWznmRtj/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmRtj/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmEvt

cp ../../vueappwznm/CrdWznmEvt/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmEvt/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmSeq

cp ../../vueappwznm/CrdWznmSeq/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmSeq/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmSte

cp ../../vueappwznm/CrdWznmSte/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmSte/

mkdir $WEBROOT/vueappwznm/src/components/CrdWznmUtl

cp ../../vueappwznm/CrdWznmUtl/*.vue $WEBROOT/vueappwznm/src/components/CrdWznmUtl/

mkdir $WEBROOT/vueappwznm/src/scripts

cp ../../vueappwznm/scripts/*.js $WEBROOT/vueappwznm/src/scripts/
