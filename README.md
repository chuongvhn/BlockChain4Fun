# BlockChain4Fun
Inspired by https://github.com/dvf/blockchain (written in Python) to port to C++

##Prerequisites 
- CMAKE 3.0 or higher  
**Note: 3.8 or higher is required to make VC\_DEBUGGING\_WORKING_DIR works

##Build 
**Alternative 1**: End-to-End build:
 
 run run_build.bat

   
    ./run_build.bat
    

 Binary is found in build/install
 
**Alternative 2**: Generate project artifacts

- Open CMAKE GUI:
	+ Where is source code: BlockChain4Fun
	+ Where to build the binary: BlockChain4Fun/build
- Configure compiler/IDE of your choice
- Set CMAKE_INSTALL_PREFIX to BlockChain4Fun/build
- Generate project artifacts
- Open project and choose "install" target to deploy .DLL to running folder (build/install)
 
