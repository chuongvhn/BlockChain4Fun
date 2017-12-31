# BlockChain4Fun
Inspired by https://github.com/dvf/blockchain (written in Python) to port to C++

[![Travis Build](https://travis-ci.org/chuongvhn/BlockChain4Fun.svg?branch=master)](https://travis-ci.org/chuongvhn/BlockChain4Fun)

## Prerequisites 

1. CMAKE 3.0 or higher  
**Note**: 3.8 or higher is required to make VC\_DEBUGGING\_WORKING_DIR works
2. Microsoft/cpprestsdk  
2.1. Windows: there's many choices to install the library and among of them is via vcpkg  
 * install vcpkg: find instruction on [vcpkg GitHub](https://github.com/Microsoft/vcpkg)
 * install [cpprestsdk](https://github.com/Microsoft/cpprestsdk): vcpkg install cpprestsdk
 * _optional_: $./vcpkg integrate install   
 2.2. Linux(ubuntu):  $sudo apt-get install libcpprest-dev 



## Build 

**Alternative 1**: End-to-End build:
 
 run wins_build.bat or linux_build.sh

```  
$./wins_build.bat  
or
$chmod +x linux_build.sh  
$./linux_build.sh
```   

 Binary is found in build/install
 
**Alternative 2**: Generate project artifacts

- Open CMAKE GUI:
	+ Where is source code: BlockChain4Fun
	+ Where to build the binary: BlockChain4Fun/build
- Configure compiler/IDE of your choice
- Set CMAKE_INSTALL_PREFIX to BlockChain4Fun/build
- Generate project artifacts
- Open project and choose "install" target to deploy .DLL to running folder (build/install)
 
