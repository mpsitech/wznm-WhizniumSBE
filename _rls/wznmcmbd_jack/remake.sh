#!/bin/bash
# file remake.sh
# re-make script for Wznm combined daemon, release wznmcmbd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmcmbd_jack
./checkout.sh

cd $SRCROOT/wznmcmbd

./make.sh "$@"

