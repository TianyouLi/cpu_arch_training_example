#!/bin/bash

###############################################################
#
# Top level build script to get all QA dependent frameworks
#
###############################################################

CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd ${BLD_DIR}


g++ -O1 -std=c++11 -o test main.cc

perf stat -B -e L1-icache-load-misses,instructions,cycles,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-dcache-store-misses ./test 10000 0
perf stat -B -e L1-icache-load-misses,instructions,cycles,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-dcache-store-misses ./test 10000 1


cd ${CUR_DIR}
