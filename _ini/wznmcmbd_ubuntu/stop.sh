#!/bin/bash
# file stop.sh
# stop script for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Oct 2021
# IP header --- ABOVE

pid=$(pgrep Wznmcmbd)
kill -15 $pid
