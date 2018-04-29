#!/bin/bash
# Program:
#    This program is compile linuxrom 3.0
# History:
#    2018-3-30 wangtao V1.0.0
make
mkimage -A arm -O linux -T kernel -C none -a 30008000 -e 30008040 -n "Linux Kernel" -d arch/arm/boot/zImage linuxrom-s3c2440.bin
chmod a+x linuxrom-s3c2440.bin
