#!/bin/bash
# file remake.sh
# re-make script for Wznm combined daemon, release wznmcmbd_awsubt
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wznm/_rls/wznmcmbd_awsubt
./checkout.sh

cd $SRCROOT/wznmcmbd

./make.sh "$@"

