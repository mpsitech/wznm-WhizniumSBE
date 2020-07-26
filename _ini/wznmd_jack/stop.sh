#!/bin/bash
# file stop.sh
# stop script for Wznm daemon, release wznmd_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

pid=$(pgrep Wznmd)
kill -15 $pid

