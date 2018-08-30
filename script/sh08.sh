#！/bin/sh
# Program
#   Caculate 1+2+3+...$(input)
# HIstory
#   2018-5-27 wangtao V1.0.0

read -p "Please input a num:" num

for(( i=1; i<$num; i=i+1 ))
do
        sum=$(($sum+$i))
done

echo "The result of 1+2+3+...$num is:$sum" 
