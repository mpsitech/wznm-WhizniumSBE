#!/bin/bash
# file remake.sh
# re-make script for Wznm combined daemon, release wznmcmbd_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmcmbd_ungenio
./checkout.sh

cd $SRCROOT/wznmcmbd

./make.sh "$@"

