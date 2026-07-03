#!/bin/bash

set -e

build_type=Debug
build_dir=build-$build_type

# The generator, toolchain file and build type live in CMakePresets.json; this is safe to
# call every time since cmake only reconfigures when something's actually out of date.
cmake --preset ${build_type}

pushd ${build_dir}

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
