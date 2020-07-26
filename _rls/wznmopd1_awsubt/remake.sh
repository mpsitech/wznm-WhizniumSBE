#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd1_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wznm/_rls/wznmopd1_awsubt
./checkout.sh

cd $SRCROOT/wznmopd1

./make.sh "$@"

