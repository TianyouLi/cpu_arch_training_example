
#!/bin/bash

###############################################################
#
# Top level build script to get all QA dependent frameworks
#
###############################################################

CUR_DIR=`pwd`
BLD_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
cd ${BLD_DIR}


mkdir -p wasm

emcc -O3 -o wasm/fib.js fib.c

gcc -O3 -o fib-native fib.c

cd ${CUR_DIR}
