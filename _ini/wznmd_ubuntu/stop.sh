#!/bin/bash
# file stop.sh
# stop script for Wznm daemon, release wznmd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Nov 2021
# IP header --- ABOVE

pid=$(pgrep Wznmd)
kill -15 $pid
