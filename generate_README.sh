#!/bin/bash

cp README_header.md README.md

echo "## Subset Arithmetic" >> README.md

if [ -f subset_32_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat subset_32_results.md >> README.md
    echo "" >> README.md
fi

if [ -f subset_64_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat subset_64_results.md >> README.md
    echo "" >> README.md
fi

if [ -f subset_128_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat subset_128_results.md >> README.md
    echo "" >> README.md
fi

echo "## Extended Arithmetic" >> README.md

if [ -f extended_32_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat extended_32_results.md >> README.md
    echo "" >> README.md
fi

if [ -f extended_64_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat extended_64_results.md >> README.md
    echo "" >> README.md
fi

if [ -f extended_128_results.md ]; then
    echo "|Type|Operation|Passed|Failed|Skipped|" >> README.md
    echo "|:---|:--------|:----:|:----:|:-----:|" >> README.md
    cat extended_128_results.md >> README.md
    echo "" >> README.md
fi
