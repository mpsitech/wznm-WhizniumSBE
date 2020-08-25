#!/bin/bash
# file start.sh
# start script for Wznm daemon, release wznmd_ungenio
# author Alexander Wirthmueller
# date created: 25 Aug 2020
# modified: 25 Aug 2020

nohup ./Wznmd -nocp &
disown

