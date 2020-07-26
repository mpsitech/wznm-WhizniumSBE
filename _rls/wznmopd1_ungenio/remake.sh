#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd1_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmopd1_ungenio
./checkout.sh

cd $SRCROOT/wznmopd1

./make.sh "$@"

