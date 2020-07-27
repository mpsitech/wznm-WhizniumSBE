#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd1_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set REPROOT=/home/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmopd1_jack
./checkout.sh

cd $SRCROOT/wznmopd1

./make.sh "$@"
