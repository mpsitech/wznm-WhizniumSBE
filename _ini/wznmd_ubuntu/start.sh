#!/bin/bash
# file start.sh
# start script for Wznm daemon, release wznmd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 5 Dec 2020
# IP header --- ABOVE

nohup ./Wznmd -nocp &
disown
