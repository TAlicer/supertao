#!/bin/sh
# Program:
#   This program User input his first name and last name, Program shows his full name
# History：
#   2018-5-27 wangtao  V1.0.0
read -p "Please input your first name:" firstname #提示用户输入，末尾的first为变量名
read -p "Please input your last name:" lastname 
echo -e "\nYour full name is :$firstname $lastname" #结果由屏幕输出
