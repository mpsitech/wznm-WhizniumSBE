#!/bin/bash
# file checkout.sh
# checkout script for Wznm web-based UI, release webappwznm_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set WEBROOT=/home/mpsitech/web

mkdir $WEBROOT/appwznm

cp checkin.sh $WEBROOT/appwznm/

cp -r ../../webappwznm/* $WEBROOT/appwznm/

