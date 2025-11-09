#!/bin/bash
set -e
source "config.sh"

source_path="$(realpath ..)"

docker run -it --rm -v ${source_path}:/stddecimal -w /stddecimal ${build_image_name}
