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
    # begin llvm.sh requirements
    lsb-release \
    wget \
    software-properties-common \
    gnupg
    # end llvm.sh requirements

#
# Clang
#
RUN curl -o llvm.sh https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    yes | ./llvm.sh 15 all && \
    ln -sf /usr/lib/llvm-15/bin/clang /usr/bin && \
    ln -sf /usr/lib/llvm-15/bin/clang++ /usr/bin && \
    ln -sf /usr/lib/llvm-15/bin/clang-tidy /usr/bin

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
RUN curl -SL https://boostorg.jfrog.io/artifactory/main/release/1.80.0/source/boost_1_80_0.tar.gz | tar -zxf - && \
    cd boost_1_80_0 && \
    ./bootstrap.sh --with-toolset=clang --prefix=/usr/local && \
    ./b2 toolset=clang cxxflags="-std=c++17" install

