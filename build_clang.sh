#!/bin/bash

set -e

build_type=Debug
build_dir=build-$build_type

# The generator, toolchain file and build type live in CMakePresets.json; this is safe to
# call every time since cmake only reconfigures when something's actually out of date.
cmake --preset ${build_type}

pushd ${build_dir}

# "check" is a real target with dependencies on the test binaries (see CMakeLists.txt), so
# ninja builds them before running ctest regardless of scheduling order - "test" here maps to
# that target rather than CMake's own dependency-free "test" target.
targets=()
for arg in "$@"; do
	if [ "$arg" = "test" ]; then
		targets+=("check")
	else
		targets+=("$arg")
	fi
done

ninja -j8 "${targets[@]}"

popd
