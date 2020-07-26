#!/bin/bash
# file checkout.sh
# checkout script for Wznm Java API library, release &rlssref;
# author &author;
# date created: 11 Jul 2020
# modified: 11 Jul 2020

export set JAVAROOT=/Users/mpsitech/srcjava

mkdir $JAVAROOT/apiwznm
mkdir $JAVAROOT/apiwznm/src
mkdir $JAVAROOT/apiwznm/src/apiwznm
mkdir $JAVAROOT/apiwznm/bin
mkdir $JAVAROOT/apiwznm/bin/apiwznm

cp ../../japiwznm/*.java $JAVAROOT/apiwznm/src/apiwznm/

