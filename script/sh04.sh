#!/bin/sh
# Program
#   This program shows user's choice
# History
#   2018-5-27 wangtao V1.0.0
read -p "Please input Y/N:" yn

if [ "$yn" == "Y" ] || [ "$yn" == "y" ]; then
     echo "Clever boy! You will Continue"
     exit 0
elif [ "$yn" == "N" ] || [ "$yn" == "n" ]; then
     echo "You will interrupt the program!!!"
     exit 0
else
     echo "Please input Y/y or N/n!"
     exit 0
fi
