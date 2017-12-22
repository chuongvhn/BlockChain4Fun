#!/bin/bash

cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=./
cmake --build ./ --config release --target install
cd ..