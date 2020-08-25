#!/bin/bash
# file checkout.sh
# checkout script for Wznm operation daemon, release wznmopd2_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

export set SRCROOT=/home/ubuntu/src
export set LIBROOT=/home/ubuntu/lib
export set BINROOT=/home/ubuntu/bin
export set REPROOT=/home/ubuntu/srcrep
export set CMBDSRCROOT=$REPROOT/wznm/wznmcmbd

mkdir $SRCROOT/wznmopd2
mkdir $SRCROOT/wznmopd2/IexWznm
mkdir $SRCROOT/wznmopd2/VecWznm
mkdir $SRCROOT/wznmopd2/WznmCtpWrweb
mkdir $SRCROOT/wznmopd2/WznmCtpWrsrv
mkdir $SRCROOT/wznmopd2/WznmCtpWrstkit
mkdir $SRCROOT/wznmopd2/WznmCtpGenui
mkdir $SRCROOT/wznmopd2/WznmCtpGenjtr

mkdir $LIBROOT/wznmopd2

mkdir $BINROOT/wznmopd2

cp make.sh $SRCROOT/wznmopd2/
cp remake.sh $SRCROOT/wznmopd2/

cp Makefile.inc $SRCROOT/wznmopd2/
cp Makefile $SRCROOT/wznmopd2/

cp ../../wznmopd2/Wznmopd.h $SRCROOT/wznmopd2/
cp ../../wznmopd2/Wznmopd.cpp $SRCROOT/wznmopd2/

cp ../../wznmopd2/WznmopdEngsrv.h $SRCROOT/wznmopd2/
cp ../../wznmopd2/WznmopdEngsrv.cpp $SRCROOT/wznmopd2/

cp ../../wznmopd2/WznmopdOpprc.h $SRCROOT/wznmopd2/
cp ../../wznmopd2/WznmopdOpprc.cpp $SRCROOT/wznmopd2/

cp ../../wznmopd2/Wznmopd_exe.h $SRCROOT/wznmopd2/
cp ../../wznmopd2/Wznmopd_exe.cpp $SRCROOT/wznmopd2/

cp $CMBDSRCROOT/Wznm.h $SRCROOT/wznmopd2/
cp $CMBDSRCROOT/Wznm.cpp $SRCROOT/wznmopd2/

cp Makefile_IexWznm $SRCROOT/wznmopd2/IexWznm/Makefile

cp $CMBDSRCROOT/IexWznm/IexWznm*.h $SRCROOT/wznmopd2/IexWznm/
cp $CMBDSRCROOT/IexWznm/IexWznm*.cpp $SRCROOT/wznmopd2/IexWznm/

cp Makefile_VecWznm $SRCROOT/wznmopd2/VecWznm/Makefile

cp $CMBDSRCROOT/VecWznm/Vec*.h $SRCROOT/wznmopd2/VecWznm/
cp $CMBDSRCROOT/VecWznm/Vec*.cpp $SRCROOT/wznmopd2/VecWznm/

cp Makefile_WznmCtpWrweb $SRCROOT/wznmopd2/WznmCtpWrweb/Makefile

cp $CMBDSRCROOT/WznmCtpWrweb/WznmCtpWrweb*.h $SRCROOT/wznmopd2/WznmCtpWrweb/
cp $CMBDSRCROOT/WznmCtpWrweb/WznmCtpWrweb*.cpp $SRCROOT/wznmopd2/WznmCtpWrweb/

cp Makefile_WznmCtpWrsrv $SRCROOT/wznmopd2/WznmCtpWrsrv/Makefile

cp $CMBDSRCROOT/WznmCtpWrsrv/WznmCtpWrsrv*.h $SRCROOT/wznmopd2/WznmCtpWrsrv/
cp $CMBDSRCROOT/WznmCtpWrsrv/WznmCtpWrsrv*.cpp $SRCROOT/wznmopd2/WznmCtpWrsrv/

cp Makefile_WznmCtpWrstkit $SRCROOT/wznmopd2/WznmCtpWrstkit/Makefile

cp $CMBDSRCROOT/WznmCtpWrstkit/WznmCtpWrstkit*.h $SRCROOT/wznmopd2/WznmCtpWrstkit/
cp $CMBDSRCROOT/WznmCtpWrstkit/WznmCtpWrstkit*.cpp $SRCROOT/wznmopd2/WznmCtpWrstkit/

cp Makefile_WznmCtpGenui $SRCROOT/wznmopd2/WznmCtpGenui/Makefile

cp $CMBDSRCROOT/WznmCtpGenui/WznmCtpGenui*.h $SRCROOT/wznmopd2/WznmCtpGenui/
cp $CMBDSRCROOT/WznmCtpGenui/WznmCtpGenui*.cpp $SRCROOT/wznmopd2/WznmCtpGenui/

cp Makefile_WznmCtpGenjtr $SRCROOT/wznmopd2/WznmCtpGenjtr/Makefile

cp $CMBDSRCROOT/WznmCtpGenjtr/WznmCtpGenjtr*.h $SRCROOT/wznmopd2/WznmCtpGenjtr/
cp $CMBDSRCROOT/WznmCtpGenjtr/WznmCtpGenjtr*.cpp $SRCROOT/wznmopd2/WznmCtpGenjtr/

