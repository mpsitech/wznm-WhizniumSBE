#!/bin/bash
# file stop.sh
# stop script for Wznm combined daemon, release wznmcmbd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

pid=$(pgrep Wznmcmbd)
kill -15 $pid

