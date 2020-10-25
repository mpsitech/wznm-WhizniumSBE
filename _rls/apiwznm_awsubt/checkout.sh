#!/bin/bash
# file checkout.sh
# checkout script for Wznm API library, release apiwznm_awsubt
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

export set SRCROOT=/home/ubuntu/src

mkdir $SRCROOT/apiwznm

cp makeall.sh $SRCROOT/apiwznm/

cp Makefile $SRCROOT/apiwznm/

cp ../../apiwznm/*.h $SRCROOT/apiwznm/
cp ../../apiwznm/*.cpp $SRCROOT/apiwznm/

