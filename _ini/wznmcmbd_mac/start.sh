#!/bin/bash
# file start.sh
# start script for Wznm combined daemon, release wznmcmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 13 Nov 2021
# IP header --- ABOVE

nohup ./Wznmcmbd -nocp &
disown
