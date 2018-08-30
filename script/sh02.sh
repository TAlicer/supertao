
#!/bin/sh
# Program:
#   This program achieve + - x ÷
# History：
#   2018-5-27 wangtao  V1.0.0
 
echo -e "Please Input TWO numbers\n"
read -p "the first number is:" num1 #提示用户输入，末尾的num1为变量名
read -p "the second number is:" num2
product=$(($num1*$num2)) 
sum=$(($num1+$num2)) 
red=$(($num1-$num2)) 
div=$(($num1/$num2)) 
echo -e "$num1 x $num2 = $product"
echo -e "$num1 + $num2 = $sum"
echo -e "$num1 - $num2 = $red"
echo -e "$num1 ÷ $num2 = $div"
