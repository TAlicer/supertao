#!/bin/sh
# Program
#   Repeat question ubtil user input correct answer
# History
#   2018-5-27 wangtao V1.0.0
 
until [ "$yn" == "yes" -o "$yn" == "YES" ]  # -a 逻辑与And, -o 逻辑或Or
do
      read -p "Please input yes/YES to stop the program:" yn
done

echo -e "Ok,you input correct answer."      #跳出循环，输出这句话后退出
