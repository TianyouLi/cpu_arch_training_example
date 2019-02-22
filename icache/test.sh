#!/bin/bash

###############################################################
#
# Top level build script to get all QA dependent frameworks
#
###############################################################

CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd ${BLD_DIR}


node code_gen.js 50 > main.cc
g++ -O1 -o test50 main.cc

node code_gen.js 100 > main.cc
g++ -O1 -o test100 main.cc

node code_gen.js 1000 > main.cc
g++ -O1 -o test1000 main.cc

node code_gen.js 10000 > main.cc
g++ -O1 -o test10000 main.cc

ls -lh test50 test100 test1000 test10000

perf stat -B -e L1-icache-load-misses,instructions,cycles,branch-misses,branch-instructions,iTLB-load-misses ./test50
perf stat -B -e L1-icache-load-misses,instructions,cycles,branch-misses,branch-instructions,iTLB-load-misses ./test100
perf stat -B -e L1-icache-load-misses,instructions,cycles,branch-misses,branch-instructions,iTLB-load-misses ./test1000
perf stat -B -e L1-icache-load-misses,instructions,cycles,branch-misses,branch-instructions,iTLB-load-misses ./test10000

cd ${CUR_DIR}
