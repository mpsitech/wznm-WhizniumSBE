#!/bin/bash
# file stopall.sh
# stop script for Wznm operation daemon(s), release wznmopd2_jack
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

IFS=$'\n'
pids=$(pgrep Wznmopd2)

for var in "${pids[@]}"
do
	kill -15 $var
done

