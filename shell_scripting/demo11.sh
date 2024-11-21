#!/bin/bash

# print table of given number.

# initialization
# while [ condition ]
# do
#	...
#	modification
# done

# In while loop, if condition is true, loop body is repeated.
# If condition is false, it comes out of loop.


echo "enter num"
read n

i=1
while [ $i -le 10 ]
do
	res=`expr $i \* $n`
        echo "$res"
	i=`expr $i + 1`
done

###############################################      

i=1
until [ $i -gt 10 ]
do
	res=`expr $i \* $n`
	echo -e -n "$res "
	i=`expr $i + 1`
done 

