#!/bin/bash
# file start.sh
# start script for Wznm combined daemon, release wznmcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 22 Feb 2022
# IP header --- ABOVE

nohup ./Wznmcmbd -nocp &
disown
