#!/bin/bash
# file remake.sh
# re-make script for Wznm daemon, release wznmd_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set REPROOT=/home/ubuntu/srcrep

cd $REPROOT/wznm/_rls/wznmd_awsubt
./checkout.sh

cd $SRCROOT/wznmd

./make.sh "$@"

