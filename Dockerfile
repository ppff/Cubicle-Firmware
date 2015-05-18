FROM debian:testing
MAINTAINER YeastLab

RUN /bin/sh

# Install common package
RUN apt-get update

RUN apt-get update && \
    apt-get install --no-install-recommends --yes \
            git \
            ca-certificates \
            automake \
            gcc \
            make \
            binutils \
            libc6-dev \
            gcc-arm-none-eabi \
            gdb-arm-none-eabi \
            libnewlib-arm-none-eabi \
            binutils-arm-linux-gnueabi \
            autoconf \
            pkg-config \
            libusb-1.0 \
            wget

WORKDIR /home/cubicle/

RUN git clone https://github.com/texane/stlink.git

WORKDIR /home/cubicle/stlink

RUN ./autogen.sh
RUN ./configure || cat config.log
RUN make

WORKDIR      /home/cubicle/
