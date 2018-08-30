
#!/bin/sh
# Program
#   Program shows script name, paramters...
# History
#   2018-5-27 wangtao V1.0.0
echo -e "The script name is $0\n"  # $0表示脚本程序本身，$1表示脚本程序后面跟的第一个参数
echo  "Total parameter numher is $#\n"   #  $#：表示脚本程序后面跟的参数个数

# -lt  即 less than，小于,只有在 && 左边的命令返回真,&&右边的命令才会被执行。
[ "$#" -lt 2 ] && echo -e "The number of paramter is less than 2. Stop here." && exit 0

echo -e "Your whole paramter is $@"  #  $@表示 "$1", "$2", "$3"之意，每个变量是独立的
echo -e "Your first parameter is $1"
echo -e "Your second paramter is $2"
