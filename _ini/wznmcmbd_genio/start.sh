#!/bin/bash
# file start.sh
# start script for Wznm combined daemon, release wznmcmbd_genio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

nohup ./Wznmcmbd -nocp &
disown

