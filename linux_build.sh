#!/bin/bash

cd build 
cmake ../ -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_CXX_FLAGS="-Xlinker --verbose" 
cmake --build ./ --config release --target install