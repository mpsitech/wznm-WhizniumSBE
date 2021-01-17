#!/bin/bash
# file checkout.sh
# checkout script for Wznm operation daemon, release wznmopd2_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Jan 2021
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

mkdir $BUILDROOT/wznmopd2
mkdir $BUILDROOT/wznmopd2/IexWznm
mkdir $BUILDROOT/wznmopd2/VecWznm
mkdir $BUILDROOT/wznmopd2/WznmCtpGenjtr
mkdir $BUILDROOT/wznmopd2/WznmCtpGenui
mkdir $BUILDROOT/wznmopd2/WznmCtpWrstkit
mkdir $BUILDROOT/wznmopd2/WznmCtpWrsrv
mkdir $BUILDROOT/wznmopd2/WznmCtpWrweb

mkdir $LIBROOT/wznmopd2

mkdir $BINROOT/wznmopd2

cp make.sh $BUILDROOT/wznmopd2/
cp remake.sh $BUILDROOT/wznmopd2/

cp Makefile.inc $BUILDROOT/wznmopd2/
cp Makefile $BUILDROOT/wznmopd2/

cp ../../wznmopd2/Wznmopd.h $BUILDROOT/wznmopd2/
cp ../../wznmopd2/Wznmopd.cpp $BUILDROOT/wznmopd2/

cp ../../wznmopd2/WznmopdEngsrv.h $BUILDROOT/wznmopd2/
cp ../../wznmopd2/WznmopdEngsrv.cpp $BUILDROOT/wznmopd2/

cp ../../wznmopd2/WznmopdOpprc.h $BUILDROOT/wznmopd2/
cp ../../wznmopd2/WznmopdOpprc.cpp $BUILDROOT/wznmopd2/

cp ../../wznmopd2/Wznmopd_exe.h $BUILDROOT/wznmopd2/
cp ../../wznmopd2/Wznmopd_exe.cpp $BUILDROOT/wznmopd2/

cp $CMBDBUILDROOT/Wznm.h $BUILDROOT/wznmopd2/
cp $CMBDBUILDROOT/Wznm.cpp $BUILDROOT/wznmopd2/

cp Makefile_IexWznm $BUILDROOT/wznmopd2/IexWznm/Makefile

cp $CMBDBUILDROOT/IexWznm/IexWznm*.h $BUILDROOT/wznmopd2/IexWznm/
cp $CMBDBUILDROOT/IexWznm/IexWznm*.cpp $BUILDROOT/wznmopd2/IexWznm/

cp Makefile_VecWznm $BUILDROOT/wznmopd2/VecWznm/Makefile

cp $CMBDBUILDROOT/VecWznm/Vec*.h $BUILDROOT/wznmopd2/VecWznm/
cp $CMBDBUILDROOT/VecWznm/Vec*.cpp $BUILDROOT/wznmopd2/VecWznm/

cp Makefile_WznmCtpGenjtr $BUILDROOT/wznmopd2/WznmCtpGenjtr/Makefile

cp $CMBDBUILDROOT/WznmCtpGenjtr/WznmCtpGenjtr*.h $BUILDROOT/wznmopd2/WznmCtpGenjtr/
cp $CMBDBUILDROOT/WznmCtpGenjtr/WznmCtpGenjtr*.cpp $BUILDROOT/wznmopd2/WznmCtpGenjtr/

cp Makefile_WznmCtpGenui $BUILDROOT/wznmopd2/WznmCtpGenui/Makefile

cp $CMBDBUILDROOT/WznmCtpGenui/WznmCtpGenui*.h $BUILDROOT/wznmopd2/WznmCtpGenui/
cp $CMBDBUILDROOT/WznmCtpGenui/WznmCtpGenui*.cpp $BUILDROOT/wznmopd2/WznmCtpGenui/

cp Makefile_WznmCtpWrstkit $BUILDROOT/wznmopd2/WznmCtpWrstkit/Makefile

cp $CMBDBUILDROOT/WznmCtpWrstkit/WznmCtpWrstkit*.h $BUILDROOT/wznmopd2/WznmCtpWrstkit/
cp $CMBDBUILDROOT/WznmCtpWrstkit/WznmCtpWrstkit*.cpp $BUILDROOT/wznmopd2/WznmCtpWrstkit/

cp Makefile_WznmCtpWrsrv $BUILDROOT/wznmopd2/WznmCtpWrsrv/Makefile

cp $CMBDBUILDROOT/WznmCtpWrsrv/WznmCtpWrsrv*.h $BUILDROOT/wznmopd2/WznmCtpWrsrv/
cp $CMBDBUILDROOT/WznmCtpWrsrv/WznmCtpWrsrv*.cpp $BUILDROOT/wznmopd2/WznmCtpWrsrv/

cp Makefile_WznmCtpWrweb $BUILDROOT/wznmopd2/WznmCtpWrweb/Makefile

cp $CMBDBUILDROOT/WznmCtpWrweb/WznmCtpWrweb*.h $BUILDROOT/wznmopd2/WznmCtpWrweb/
cp $CMBDBUILDROOT/WznmCtpWrweb/WznmCtpWrweb*.cpp $BUILDROOT/wznmopd2/WznmCtpWrweb/
