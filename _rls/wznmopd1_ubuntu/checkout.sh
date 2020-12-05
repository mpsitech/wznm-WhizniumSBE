#!/bin/bash
# file checkout.sh
# checkout script for Wznm operation daemon, release wznmopd1_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build
export set LIBROOT=${WHIZSDKROOT}/lib
export set BINROOT=${WHIZROOT}/bin
export set REPROOT=${WHIZDEVROOT}/rep
export set CMBDBUILDROOT=$REPROOT/wznm/wznmcmbd

mkdir $BUILDROOT/wznmopd1
mkdir $BUILDROOT/wznmopd1/IexWznm
mkdir $BUILDROOT/wznmopd1/VecWznm
mkdir $BUILDROOT/wznmopd1/WznmWrweb
mkdir $BUILDROOT/wznmopd1/WznmWrsrv
mkdir $BUILDROOT/wznmopd1/WznmWrjapi
mkdir $BUILDROOT/wznmopd1/WznmWrdbs
mkdir $BUILDROOT/wznmopd1/WznmWrapp
mkdir $BUILDROOT/wznmopd1/WznmWrapi
mkdir $BUILDROOT/wznmopd1/WznmPrctree
mkdir $BUILDROOT/wznmopd1/WznmPrcfile
mkdir $BUILDROOT/wznmopd1/WznmGen
mkdir $BUILDROOT/wznmopd1/WznmCompl

mkdir $LIBROOT/wznmopd1

mkdir $BINROOT/wznmopd1

cp make.sh $BUILDROOT/wznmopd1/
cp remake.sh $BUILDROOT/wznmopd1/

cp Makefile.inc $BUILDROOT/wznmopd1/
cp Makefile $BUILDROOT/wznmopd1/

cp ../../wznmopd1/Wznmopd.h $BUILDROOT/wznmopd1/
cp ../../wznmopd1/Wznmopd.cpp $BUILDROOT/wznmopd1/

cp ../../wznmopd1/WznmopdEngsrv.h $BUILDROOT/wznmopd1/
cp ../../wznmopd1/WznmopdEngsrv.cpp $BUILDROOT/wznmopd1/

cp ../../wznmopd1/WznmopdOpprc.h $BUILDROOT/wznmopd1/
cp ../../wznmopd1/WznmopdOpprc.cpp $BUILDROOT/wznmopd1/

cp ../../wznmopd1/Wznmopd_exe.h $BUILDROOT/wznmopd1/
cp ../../wznmopd1/Wznmopd_exe.cpp $BUILDROOT/wznmopd1/

cp $CMBDBUILDROOT/Wznm.h $BUILDROOT/wznmopd1/
cp $CMBDBUILDROOT/Wznm.cpp $BUILDROOT/wznmopd1/

cp Makefile_IexWznm $BUILDROOT/wznmopd1/IexWznm/Makefile

cp $CMBDBUILDROOT/IexWznm/IexWznm*.h $BUILDROOT/wznmopd1/IexWznm/
cp $CMBDBUILDROOT/IexWznm/IexWznm*.cpp $BUILDROOT/wznmopd1/IexWznm/

cp Makefile_VecWznm $BUILDROOT/wznmopd1/VecWznm/Makefile

cp $CMBDBUILDROOT/VecWznm/Vec*.h $BUILDROOT/wznmopd1/VecWznm/
cp $CMBDBUILDROOT/VecWznm/Vec*.cpp $BUILDROOT/wznmopd1/VecWznm/

cp Makefile_WznmWrweb $BUILDROOT/wznmopd1/WznmWrweb/Makefile

cp $CMBDBUILDROOT/WznmWrweb/WznmWrweb*.h $BUILDROOT/wznmopd1/WznmWrweb/
cp $CMBDBUILDROOT/WznmWrweb/WznmWrweb*.cpp $BUILDROOT/wznmopd1/WznmWrweb/

cp Makefile_WznmWrsrv $BUILDROOT/wznmopd1/WznmWrsrv/Makefile

cp $CMBDBUILDROOT/WznmWrsrv/WznmWrsrv*.h $BUILDROOT/wznmopd1/WznmWrsrv/
cp $CMBDBUILDROOT/WznmWrsrv/WznmWrsrv*.cpp $BUILDROOT/wznmopd1/WznmWrsrv/

cp Makefile_WznmWrjapi $BUILDROOT/wznmopd1/WznmWrjapi/Makefile

cp $CMBDBUILDROOT/WznmWrjapi/WznmWrjapi*.h $BUILDROOT/wznmopd1/WznmWrjapi/
cp $CMBDBUILDROOT/WznmWrjapi/WznmWrjapi*.cpp $BUILDROOT/wznmopd1/WznmWrjapi/

cp Makefile_WznmWrdbs $BUILDROOT/wznmopd1/WznmWrdbs/Makefile

cp $CMBDBUILDROOT/WznmWrdbs/WznmWrdbs*.h $BUILDROOT/wznmopd1/WznmWrdbs/
cp $CMBDBUILDROOT/WznmWrdbs/WznmWrdbs*.cpp $BUILDROOT/wznmopd1/WznmWrdbs/

cp Makefile_WznmWrapp $BUILDROOT/wznmopd1/WznmWrapp/Makefile

cp $CMBDBUILDROOT/WznmWrapp/WznmWrapp*.h $BUILDROOT/wznmopd1/WznmWrapp/
cp $CMBDBUILDROOT/WznmWrapp/WznmWrapp*.cpp $BUILDROOT/wznmopd1/WznmWrapp/

cp Makefile_WznmWrapi $BUILDROOT/wznmopd1/WznmWrapi/Makefile

cp $CMBDBUILDROOT/WznmWrapi/WznmWrapi*.h $BUILDROOT/wznmopd1/WznmWrapi/
cp $CMBDBUILDROOT/WznmWrapi/WznmWrapi*.cpp $BUILDROOT/wznmopd1/WznmWrapi/

cp Makefile_WznmPrctree $BUILDROOT/wznmopd1/WznmPrctree/Makefile

cp $CMBDBUILDROOT/WznmPrctree/WznmPrctree*.h $BUILDROOT/wznmopd1/WznmPrctree/
cp $CMBDBUILDROOT/WznmPrctree/WznmPrctree*.cpp $BUILDROOT/wznmopd1/WznmPrctree/

cp Makefile_WznmPrcfile $BUILDROOT/wznmopd1/WznmPrcfile/Makefile

cp $CMBDBUILDROOT/WznmPrcfile/WznmPrcfile*.h $BUILDROOT/wznmopd1/WznmPrcfile/
cp $CMBDBUILDROOT/WznmPrcfile/WznmPrcfile*.cpp $BUILDROOT/wznmopd1/WznmPrcfile/

cp Makefile_WznmGen $BUILDROOT/wznmopd1/WznmGen/Makefile

cp $CMBDBUILDROOT/WznmGen/WznmGen*.h $BUILDROOT/wznmopd1/WznmGen/
cp $CMBDBUILDROOT/WznmGen/WznmGen*.cpp $BUILDROOT/wznmopd1/WznmGen/

cp Makefile_WznmCompl $BUILDROOT/wznmopd1/WznmCompl/Makefile

cp $CMBDBUILDROOT/WznmCompl/WznmCompl*.h $BUILDROOT/wznmopd1/WznmCompl/
cp $CMBDBUILDROOT/WznmCompl/WznmCompl*.cpp $BUILDROOT/wznmopd1/WznmCompl/

