#!/bin/bash

# String operators
#	=, !=, -z
# =  equal to
# != not equal
# -z check string empty or not


str1="sunbeam "
str2="dmc"

if [ -z $str1 ]
then
	echo "str1 is empty"
else
	echo "str1 is not empty"
fi


if [ $str1 = $str2 ]
then
	echo "str1 and str2 are equal"
else
	echo "str1 and str2 are not equal"
fi

#------------------------------------------------
#check palindrome or not

echo -n "Enter string : "
read str

rstr=`echo $str | rev`

if [ $str = $rstr ]
then
	echo "String is palindrome"
else
	echo "String is not palindrome"
fi








