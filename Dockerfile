FROM ubuntu:22.04

# This prevents a prompt regarding timezones.
ENV DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    curl \
    vim \
    libtinfo5 \
    git \
    clang-tidy

#
# Clang
#
RUN curl -SL https://github.com/llvm/llvm-project/releases/download/llvmorg-14.0.0/clang+llvm-14.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz | tar --strip-components 1 -xJC /usr

#
# Intel Decimal Floating Point Math Library
#
# TODO - investigate if we need to tweak any build options
#
RUN curl -SL http://www.netlib.org/misc/intel/IntelRDFPMathLib20U2.tar.gz | tar -zx && \
    cd IntelRDFPMathLib20U2/LIBRARY && \
    sed -i -e 's/ic/clang/g' linuxbuild && \
    ./RUNLINUX
    
#
# Boost
#
RUN curl -SL https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz | tar -zxf - && \
    cd boost_1_79_0 && \
    ./bootstrap.sh --with-toolset=clang --prefix=/usr/local && \
    ./b2 toolset=clang cxxflags="-std=c++17" install

