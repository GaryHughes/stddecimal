#!/bin/bash

set -e

build_type=Debug
build_dir=build-$build_type

if [ ! -d ${build_dir} ]; then
	mkdir ${build_dir}
	pushd ${build_dir}
	cmake -G Ninja -DCMAKE_BUILD_TYPE=${build_type} -DCMAKE_TOOLCHAIN_FILE=../clang_toolchain.cmake ..
else
	pushd ${build_dir}
fi

ninja "$@" -j8
popd
