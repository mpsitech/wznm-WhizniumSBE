#!/bin/bash
# file remake.sh
# re-make script for Wznm daemon, release wznmd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmd_ungenio
./checkout.sh

cd $SRCROOT/wznmd

./make.sh "$@"
