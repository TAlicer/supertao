#!/bin/bash
#Program:
#    Query the local IP
# History:
#    2018-5-27 wangtao V1.0.0


if [ $# != 1 ] ; then
    echo "Usage: $0 [eth0]"
    exit;
fi

intface=$1   # 此处$1表示脚本程序后面跟的第一个参数
read -p "Please input printing times:" times      

#for i in `seq 1 10`
for((i=1;i<=$times;i=i+1))
do
  ifconfig $intface | grep "inet addr" | cut -d: -f2 | awk '{print $1}'  #此处$1表示cut命令得到的第一列数据
done
          

