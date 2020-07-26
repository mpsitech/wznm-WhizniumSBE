#!/bin/bash
# file checkin.sh
# checkin script for Wznm web-based UI, release webappwznm_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set REPROOT=/home/mpsitech/srcrep

cp -r * $REPROOT/wznm/webappwznm/

rm $REPROOT/wznm/webappwznm/checkin.sh

