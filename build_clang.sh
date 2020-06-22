#!/bin/bash

set -e

build_type=Debug
build_dir=build-$build_type

if [ ! -d ${build_dir} ]; then
	mkdir ${build_dir}
	cd ${build_dir}
	cmake -DCMAKE_BUILD_TYPE=${build_type} -DCMAKE_TOOLCHAIN_FILE=../clang_toolchain.cmake ..
else
	cd ${build_dir}
fi

make "$@"
