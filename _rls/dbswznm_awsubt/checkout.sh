#!/bin/bash
# file checkout.sh
# checkout script for Wznm database access library, release dbswznm_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/ubuntu/src

mkdir $SRCROOT/dbswznm

cp makeall.sh $SRCROOT/dbswznm/

cp Makefile $SRCROOT/dbswznm/

cp ../../dbswznm/DbsWznm.h $SRCROOT/dbswznm/
cp ../../dbswznm/DbsWznm_vecs.cpp $SRCROOT/dbswznm/
cp ../../dbswznm/DbsWznm.cpp $SRCROOT/dbswznm/

cp ../../dbswznm/Wznm*.h $SRCROOT/dbswznm/
cp ../../dbswznm/Wznm*.cpp $SRCROOT/dbswznm/

