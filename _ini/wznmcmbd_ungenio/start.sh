#!/bin/bash
# file start.sh
# start script for Wznm combined daemon, release wznmcmbd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

nohup ./Wznmcmbd -nocp &
disown
