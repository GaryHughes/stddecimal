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

build_targets=()
run_tests=0

for arg in "$@"; do
	if [ "$arg" = "test" ]; then
		run_tests=1
	else
		build_targets+=("$arg")
	fi
done

# ninja doesn't guarantee command-line targets run in order, and CMake's "test" target has no
# dependency on the actual build outputs, so it must be run as its own invocation after the rest
# of the build has finished rather than alongside it.
ninja -j8 "${build_targets[@]}"

if [ "$run_tests" -eq 1 ]; then
	ninja -j8 test
fi

popd
