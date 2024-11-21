#!/bin/bash

#accept value from user
#read

echo -e -n "enter n1"
read n1

echo -e -n  "enter n2"
read n2

res=`expr $n1 + $n2`

echo "add: $res"


