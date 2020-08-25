#!/bin/bash
# file checkin.sh
# checkin script for Wznm web-based UI, release webappwznm_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set REPROOT=/Users/mpsitech/srcrep

cp -r * $REPROOT/wznm/webappwznm/

rm $REPROOT/wznm/webappwznm/checkin.sh

