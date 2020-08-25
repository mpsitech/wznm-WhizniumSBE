#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd2_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/Users/mpsitech/src
export set REPROOT=/Users/mpsitech/srcrep

cd $REPROOT/wznm/_rls/wznmopd2_ungenio
./checkout.sh

cd $SRCROOT/wznmopd2

./make.sh "$@"

