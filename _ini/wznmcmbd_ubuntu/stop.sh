#!/bin/bash
# file stop.sh
# stop script for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 16 Dec 2020
# IP header --- ABOVE

pid=$(pgrep Wznmcmbd)
kill -15 $pid
