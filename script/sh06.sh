#!/bin/sh
# Program
#   Repet quesstion until input correct answer.
# History
#   2018-5-27 wangtao V1.0.0
             
while [ "$yn" != "yes" -a "$yn" != "YES" ]   # -a 逻辑与And, -o 逻辑或Or
   do
      read -p "Please input yes/YES to stop this program:" yn
   done

echo -e "OK,you input the correct answer."   #跳出循环，输出这句话后退出
