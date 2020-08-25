#!/bin/bash
# file makeall.sh
# make script for Wznm database access library, release dbswznm_genio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

make DbsWznm.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

