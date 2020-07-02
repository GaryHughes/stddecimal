#!/bin/bash

cp README_header.md README.md

cat README_subset_header.md >> README.md

if [ -f subset_32_results.md ]; then
    cat subset_32_results.md >> README.md
fi

if [ -f subset_64_results.md ]; then
    cat subset_64_results.md >> README.md
fi

if [ -f subset_128_results.md ]; then
    cat subset128_results.md >> README.md
fi

cat README_extended_header.md >> README.md

if [ -f extended_32_results.md ]; then
    cat extended_32_results.md >> README.md
fi

if [ -f extended_64_results.md ]; then
    cat extended_64_results.md >> README.md
fi

if [ -f extended_128_results.md ]; then
    cat extended_128_results.md >> README.md
fi

cat README_footer.md >> README.md