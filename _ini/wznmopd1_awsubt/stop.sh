#!/bin/bash
# file stopall.sh
# stop script for Wznm operation daemon(s), release wznmopd1_awsubt
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

IFS=$'\n'
pids=$(pgrep Wznmopd1)

for var in "${pids[@]}"
do
	kill -15 $var
done

