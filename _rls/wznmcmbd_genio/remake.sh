#!/bin/bash
# file remake.sh
# re-make script for Wznm combined daemon, release wznmcmbd_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmcmbd_genio
./checkout.sh

cd $SRCROOT/wznmcmbd

./make.sh "$@"

