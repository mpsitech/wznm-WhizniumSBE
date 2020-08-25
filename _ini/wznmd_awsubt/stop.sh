#!/bin/bash
# file stop.sh
# stop script for Wznm daemon, release wznmd_awsubt
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

pid=$(pgrep Wznmd)
kill -15 $pid

