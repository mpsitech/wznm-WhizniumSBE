#!/bin/bash
# file stopall.sh
# stop script for Wznm operation daemon(s), release wznmopd2_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Nov 2021
# IP header --- ABOVE

IFS=$'\n'
pids=$(pgrep Wznmopd2)

for var in "${pids[@]}"
do
	kill -15 $var
done
