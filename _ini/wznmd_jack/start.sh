#!/bin/bash
# file start.sh
# start script for Wznm daemon, release wznmd_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

nohup ./Wznmd -nocp &
disown

