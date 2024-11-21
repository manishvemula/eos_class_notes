#!/bin/bash

#variable declaration
num1=10
num2=20

echo "num1= $num1"

echo "num2= $num2"

res=`expr $num1 + $num2`

#echo "Add : $res"

res2=`expr $num1 - $num2`
#echo "sub : $res"

res3=`expr $num1 \* $num2`
#echo "mul : $res"

res4=`expr $num1 / $num2`
#echo "div : $res"

echo "Add : $res  Sub: $res2 Mul: $res3 Div: $res4"

