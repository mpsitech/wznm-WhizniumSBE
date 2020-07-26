#!/bin/bash
# file checkout.sh
# checkout script for Wznm operation daemon, release wznmopd1_genio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set SRCROOT=/home/mpsitech/src
export set LIBROOT=/home/mpsitech/lib
export set BINROOT=/home/mpsitech/bin
export set REPROOT=/home/mpsitech/srcrep
export set CMBDSRCROOT=$REPROOT/wznm/wznmcmbd

mkdir $SRCROOT/wznmopd1
mkdir $SRCROOT/wznmopd1/IexWznm
mkdir $SRCROOT/wznmopd1/VecWznm
mkdir $SRCROOT/wznmopd1/WznmWrweb
mkdir $SRCROOT/wznmopd1/WznmWrsrv
mkdir $SRCROOT/wznmopd1/WznmWrjapi
mkdir $SRCROOT/wznmopd1/WznmWrdbs
mkdir $SRCROOT/wznmopd1/WznmWrapp
mkdir $SRCROOT/wznmopd1/WznmWrapi
mkdir $SRCROOT/wznmopd1/WznmPrctree
mkdir $SRCROOT/wznmopd1/WznmPrcfile
mkdir $SRCROOT/wznmopd1/WznmGen
mkdir $SRCROOT/wznmopd1/WznmCompl

mkdir $LIBROOT/wznmopd1

mkdir $BINROOT/wznmopd1

cp make.sh $SRCROOT/wznmopd1/
cp remake.sh $SRCROOT/wznmopd1/

cp Makefile.inc $SRCROOT/wznmopd1/
cp Makefile $SRCROOT/wznmopd1/

cp ../../wznmopd1/Wznmopd.h $SRCROOT/wznmopd1/
cp ../../wznmopd1/Wznmopd.cpp $SRCROOT/wznmopd1/

cp ../../wznmopd1/WznmopdEngsrv.h $SRCROOT/wznmopd1/
cp ../../wznmopd1/WznmopdEngsrv.cpp $SRCROOT/wznmopd1/

cp ../../wznmopd1/WznmopdOpprc.h $SRCROOT/wznmopd1/
cp ../../wznmopd1/WznmopdOpprc.cpp $SRCROOT/wznmopd1/

cp ../../wznmopd1/Wznmopd_exe.h $SRCROOT/wznmopd1/
cp ../../wznmopd1/Wznmopd_exe.cpp $SRCROOT/wznmopd1/

cp $CMBDSRCROOT/Wznm.h $SRCROOT/wznmopd1/
cp $CMBDSRCROOT/Wznm.cpp $SRCROOT/wznmopd1/

cp Makefile_IexWznm $SRCROOT/wznmopd1/IexWznm/Makefile

cp $CMBDSRCROOT/IexWznm/IexWznm*.h $SRCROOT/wznmopd1/IexWznm/
cp $CMBDSRCROOT/IexWznm/IexWznm*.cpp $SRCROOT/wznmopd1/IexWznm/

cp Makefile_VecWznm $SRCROOT/wznmopd1/VecWznm/Makefile

cp $CMBDSRCROOT/VecWznm/Vec*.h $SRCROOT/wznmopd1/VecWznm/
cp $CMBDSRCROOT/VecWznm/Vec*.cpp $SRCROOT/wznmopd1/VecWznm/

cp Makefile_WznmWrweb $SRCROOT/wznmopd1/WznmWrweb/Makefile

cp $CMBDSRCROOT/WznmWrweb/WznmWrweb*.h $SRCROOT/wznmopd1/WznmWrweb/
cp $CMBDSRCROOT/WznmWrweb/WznmWrweb*.cpp $SRCROOT/wznmopd1/WznmWrweb/

cp Makefile_WznmWrsrv $SRCROOT/wznmopd1/WznmWrsrv/Makefile

cp $CMBDSRCROOT/WznmWrsrv/WznmWrsrv*.h $SRCROOT/wznmopd1/WznmWrsrv/
cp $CMBDSRCROOT/WznmWrsrv/WznmWrsrv*.cpp $SRCROOT/wznmopd1/WznmWrsrv/

cp Makefile_WznmWrjapi $SRCROOT/wznmopd1/WznmWrjapi/Makefile

cp $CMBDSRCROOT/WznmWrjapi/WznmWrjapi*.h $SRCROOT/wznmopd1/WznmWrjapi/
cp $CMBDSRCROOT/WznmWrjapi/WznmWrjapi*.cpp $SRCROOT/wznmopd1/WznmWrjapi/

cp Makefile_WznmWrdbs $SRCROOT/wznmopd1/WznmWrdbs/Makefile

cp $CMBDSRCROOT/WznmWrdbs/WznmWrdbs*.h $SRCROOT/wznmopd1/WznmWrdbs/
cp $CMBDSRCROOT/WznmWrdbs/WznmWrdbs*.cpp $SRCROOT/wznmopd1/WznmWrdbs/

cp Makefile_WznmWrapp $SRCROOT/wznmopd1/WznmWrapp/Makefile

cp $CMBDSRCROOT/WznmWrapp/WznmWrapp*.h $SRCROOT/wznmopd1/WznmWrapp/
cp $CMBDSRCROOT/WznmWrapp/WznmWrapp*.cpp $SRCROOT/wznmopd1/WznmWrapp/

cp Makefile_WznmWrapi $SRCROOT/wznmopd1/WznmWrapi/Makefile

cp $CMBDSRCROOT/WznmWrapi/WznmWrapi*.h $SRCROOT/wznmopd1/WznmWrapi/
cp $CMBDSRCROOT/WznmWrapi/WznmWrapi*.cpp $SRCROOT/wznmopd1/WznmWrapi/

cp Makefile_WznmPrctree $SRCROOT/wznmopd1/WznmPrctree/Makefile

cp $CMBDSRCROOT/WznmPrctree/WznmPrctree*.h $SRCROOT/wznmopd1/WznmPrctree/
cp $CMBDSRCROOT/WznmPrctree/WznmPrctree*.cpp $SRCROOT/wznmopd1/WznmPrctree/

cp Makefile_WznmPrcfile $SRCROOT/wznmopd1/WznmPrcfile/Makefile

cp $CMBDSRCROOT/WznmPrcfile/WznmPrcfile*.h $SRCROOT/wznmopd1/WznmPrcfile/
cp $CMBDSRCROOT/WznmPrcfile/WznmPrcfile*.cpp $SRCROOT/wznmopd1/WznmPrcfile/

cp Makefile_WznmGen $SRCROOT/wznmopd1/WznmGen/Makefile

cp $CMBDSRCROOT/WznmGen/WznmGen*.h $SRCROOT/wznmopd1/WznmGen/
cp $CMBDSRCROOT/WznmGen/WznmGen*.cpp $SRCROOT/wznmopd1/WznmGen/

cp Makefile_WznmCompl $SRCROOT/wznmopd1/WznmCompl/Makefile

cp $CMBDSRCROOT/WznmCompl/WznmCompl*.h $SRCROOT/wznmopd1/WznmCompl/
cp $CMBDSRCROOT/WznmCompl/WznmCompl*.cpp $SRCROOT/wznmopd1/WznmCompl/

