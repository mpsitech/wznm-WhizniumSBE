#!/bin/bash
# file checkin.sh
# checkin script for Wznm web-based UI, release webappwznm_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set REPROOT=/home/ubuntu/srcrep

cp -r * $REPROOT/wznm/webappwznm/

rm $REPROOT/wznm/webappwznm/checkin.sh

