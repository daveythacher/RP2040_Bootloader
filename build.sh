#!/bin/sh

git submodule update --init
cd Bootloader/lib/pico-sdk/
git submodule update --init
cd ../..
DIR=$PWD
export PICO_SDK_PATH=$PWD/lib/pico-sdk
mkdir build
cp lib/pico-sdk/external/pico_sdk_import.cmake .
cd build
cmake ..
make -j $(($(nproc) * 2))