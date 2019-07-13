::
::automatic build
@echo off

cd build

cmake ../ -DCMAKE_INSTALL_PREFIX=bin -DCMAKE_TOOLCHAIN_FILE=C:\vcpkg\scripts\buildsystems\vcpkg.cmake

IF "%1"== "-g" (
	GOTO :M_EXIT
)

cmake --build ./ --config release --target install

:M_EXIT:
cd ..