#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd1_genio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmopd1_genio
./checkout.sh

cd $SRCROOT/wznmopd1

./make.sh "$@"

