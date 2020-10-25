#!/bin/bash
# file stop.sh
# stop script for Wznm daemon, release wznmd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

pid=$(pgrep Wznmd)
kill -15 $pid

