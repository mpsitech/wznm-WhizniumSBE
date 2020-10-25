#!/bin/bash
# file start.sh
# start script for Wznm combined daemon, release wznmcmbd_awsubt
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

nohup ./Wznmcmbd -nocp &
disown

