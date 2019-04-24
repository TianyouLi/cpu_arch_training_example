
#!/bin/bash

CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd ${BLD_DIR}


g++ -O3 -o test.baseline test.c
g++ -O3 -DCMP_OPT -o test.opt test.c

perf stat ./test.baseline
perf stat ./test.opt


cd ${CUR_DIR}
