#!/bin/bash
# file remake.sh
# re-make script for Wznm operation daemon, release wznmopd2_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wznm/_rls/wznmopd2_awsubt
./checkout.sh

cd $SRCROOT/wznmopd2

./make.sh "$@"

