#########################################################################
# File Name:    build.sh
# Author:       zhangliang
# Created Time: 四  8/ 3 19:56:36 2023
#########################################################################
#!/bin/bash

set -x -e

rm -rf mybuild
mkdir mybuild
cd mybuild
cmake ..
make
./main

