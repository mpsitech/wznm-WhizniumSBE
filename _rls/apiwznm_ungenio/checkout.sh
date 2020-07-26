#!/bin/bash
# file checkout.sh
# checkout script for Wznm API library, release apiwznm_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/Users/mpsitech/src

mkdir $SRCROOT/apiwznm

cp makeall.sh $SRCROOT/apiwznm/

cp Makefile $SRCROOT/apiwznm/

cp ../../apiwznm/*.h $SRCROOT/apiwznm/
cp ../../apiwznm/*.cpp $SRCROOT/apiwznm/

