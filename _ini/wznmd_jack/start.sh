#!/bin/bash
# file start.sh
# start script for Wznm daemon, release wznmd_jack
# author Alexander Wirthmueller
# date created: 27 Aug 2020
# modified: 27 Aug 2020

nohup ./Wznmd -nocp &
disown

