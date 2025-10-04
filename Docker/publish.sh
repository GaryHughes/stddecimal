#!/bin/bash
set -e
source "config.sh"

docker push ${build_image_name}