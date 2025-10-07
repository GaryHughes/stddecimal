FROM ubuntu:24.04

# This prevents a prompt regarding timezones.
ENV DEBIAN_FRONTEND=noninteractive

SHELL ["/bin/bash", "-c"]

RUN apt update && apt install -y \
    build-essential \
    cmake \
    curl \
    vim \
    git \
    libstdc++-14-dev \
    catch2 \
    # begin llvm.sh requirements
    lsb-release \
    wget \
    software-properties-common \
    gnupg
    # end llvm.sh requirements

#
# Clang
#
# The gcc/g++ links are there to let us build Intel Floating Point library without editing it's Makefiles.
#
RUN curl -o llvm.sh https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    yes | ./llvm.sh 21 all && \
    ln -sf /usr/lib/llvm-21/bin/clang /usr/bin && \
    ln -sf /usr/lib/llvm-21/bin/clang++ /usr/bin && \
    ln -sf /usr/lib/llvm-21/bin/clang-tidy /usr/bin && \
    ln -sf /usr/lib/llvm-21/bin/clang /usr/bin/gcc && \
    ln -sf /usr/lib/llvm-21/bin/clang++ /usr/bin/g++

#
# Intel Decimal Floating Point Math Library
#
# TODO - investigate if we need to tweak any build options
#
RUN curl -SL http://www.netlib.org/misc/intel/IntelRDFPMathLib20U2.tar.gz | tar -zx && \
    cd IntelRDFPMathLib20U2/LIBRARY && \
    sed -i '1i\#include <stdlib.h>' src/bid32_pow.c && \
    sed -i '1i\#include <stdlib.h>' src/bid64_pow.c && \
    sed -i '1i\#include <stdlib.h>' src/bid128_pow.c && \
    ./RUNLINUX && \
    ln -s gcc000libbid.a libbid.a
    
#
# Boost
#
RUN curl -SL https://archives.boost.io/release/1.89.0/source/boost_1_89_0.tar.gz | tar -zxf - && \
    cd boost_1_89_0 && \
    ./bootstrap.sh --with-toolset=clang --prefix=/usr/local && \
    ./b2 toolset=clang cxxflags="-std=c++20" install

