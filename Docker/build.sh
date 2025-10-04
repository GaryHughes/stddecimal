#!/bin/bash
set -e
source "config.sh"

echo "Building docker image ${build_image_name}"
docker build . --platform ${platform} --tag ${build_image_name}
echo

echo "Build complete"
