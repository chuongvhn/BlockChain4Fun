::
::automatic build


cd build
cmake ../ -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_TOOLCHAIN_FILE=C:/Users/vohoa/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build ./ --config release --target install
cd ..