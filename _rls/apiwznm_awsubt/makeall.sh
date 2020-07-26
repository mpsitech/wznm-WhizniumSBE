#!/bin/bash
# file makeall.sh
# make script for Wznm API library, release apiwznm_awsubt
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

make ApiWznm.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j2
if [ $? -ne 0 ]; then
	exit
fi

make install

