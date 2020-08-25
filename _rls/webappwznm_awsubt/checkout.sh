#!/bin/bash
# file checkout.sh
# checkout script for Wznm web-based UI, release webappwznm_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set WEBROOT=/home/ubuntu/web

mkdir $WEBROOT/appwznm

cp checkin.sh $WEBROOT/appwznm/

cp -r ../../webappwznm/* $WEBROOT/appwznm/

