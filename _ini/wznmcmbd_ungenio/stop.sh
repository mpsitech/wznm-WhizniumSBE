#!/bin/bash
# file stop.sh
# stop script for Wznm combined daemon, release wznmcmbd_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

pid=$(pgrep Wznmcmbd)
kill -15 $pid

