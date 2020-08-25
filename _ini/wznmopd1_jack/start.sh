#!/bin/bash
# file start.sh
# start script for Wznm operation daemon(s), release wznmopd1_jack
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

num='^[0-9]+$'

if [ "$#" -eq 0 ] ; then
	nohup ./Wznmopd1 &
	disown
elif [ "$#" -eq 1 ] && [[ "$1" =~ $num ]] ; then
	i=0

	while [ $i -lt "$1" ]
	do
		nohup ./Wznmopd1 -engsrvportofs=$i &
		i=`expr $i + 1`
	done

	disown
else
  echo "usage: $0 <N>" >&2
  exit 1
fi

