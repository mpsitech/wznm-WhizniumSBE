#!/bin/bash
# file makeall.sh
# make script for Wznm database access library, release dbswznm_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

make DbsWznm.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j16
if [ $? -ne 0 ]; then
	exit
fi

make install

