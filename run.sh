#!/bin/bash

read -p "Please input number of state in proto: " proto_state
read -p "Please input number of gaussians: " gaussian
read -p "Please input sil num: " sil
read -p "Please input WTF num: " wtf
./set $gaussian $sil $proto_state $wtf
mv -f proto lib/proto
mv mix2_10.hed lib/mix2_10.hed


sh 00_clean_all.sh
sh 01_run_HCopy.sh
sh 02_run_HCompV.sh
sh 03_training.sh
sh 04_testing.sh

echo "proto_state:$proto_state"
echo "gaussians:$gaussian"
echo "sil:$sil"
echo "wtf:$wtf" 

cat result/accuracy
##./readAcc
