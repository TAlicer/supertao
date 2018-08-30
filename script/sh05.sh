#!/bin/sh
# Program
#   This program show "hello" from (...by using case ...esac)
# History
#   2018-5-27 wangtao V1.0.0

case $1 in
    "hello")
        echo "Hello,how are you!"
        ;;  #每个类型的结尾使用英文输入法状态下的两个分号来表示
    "bye")
        echo "bye-bye!"
        ;;
    "")     #如果没有输入
        echo "You must input parameter,ex> {$0 someword}"
        ;;
    *)      #最后一个变量使用*来表示其他值
        echo "use $0 {hello or bye}"
        ;;
esac        #由esac来表示case语句的最终结尾
