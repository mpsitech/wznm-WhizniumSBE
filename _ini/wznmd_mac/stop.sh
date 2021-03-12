#!/bin/bash
# file stop.sh
# stop script for Wznm daemon, release wznmd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

pid=$(pgrep Wznmd)
kill -15 $pid
