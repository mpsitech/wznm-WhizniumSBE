#!/bin/bash
# file remake.sh
# re-make script for Wznm daemon, release wznmd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmd_jack
./checkout.sh

cd $SRCROOT/wznmd

./make.sh "$@"

