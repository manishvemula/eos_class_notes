#!/bin/bash

#leap year


echo -e -n  "enter year: "
read y

#if(y%400==0 ||( y%4==0 && y%100!=0))
if [ `expr  $y % 400` -eq 0  -o   `expr $y % 4` -eq 0   -a   `expr  $y % 100` -ne 0   ] 
then
	echo "leap year"
else
	echo "not leap year"
fi
	      
