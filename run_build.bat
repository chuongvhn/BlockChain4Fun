::
::automatic build

ECHO OFF
SET opt_1=%1
SET opt_2=%2 
SHIFT & SHIFT

:loop
IF NOT "%1"=="" (
    IF "%1"=="--clean" (
        SET do_clean=1
        SHIFT
    )
    IF "%1"=="-to_be_used_option" (
        SET to_be_used=%2
        SHIFT
    )
    SHIFT
    GOTO :loop
)

ECHO opt_1 = %opt_1%
ECHO opt_2 = %opt_2%

IF %do_clean%==1 goto CLEAN:

cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=./
cmake --build ./ --config release --target install
cd ..

CLEAN:
ECHO cleaning...