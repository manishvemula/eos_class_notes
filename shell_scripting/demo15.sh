#!/bin/bash

#!/bin/bash

# write a function to print fibonacci series
# write a function to do sum of two integers

# function definition:
# function fn_name()
# {
#	args are accessed as $1, $2, $3, ...
#	...
# }

# function call:
# fn_name arg1 arg2 arg3 

# function definition:
# function fn_name()
# {
#	args are accessed as $1, $2, $3, ...
#	...
#	echo result
# }

# function call:
# var=$(fn_name arg1 arg2 arg3) 


#function Defination

function msg()
{
	echo "welcome"
}
msg

function print_num()
{
	args $1 $2
}

print_num 10 20

function prime()
{
	flag=0
	i=2
	while [ $i -lt $1 ]
	do
		if [ `expr $1 % $i` -eq 0 ]
		then
			flag=1
		fi
		i=`expr $i + 1`
	done
	echo $flag
		
}

res=$( prime 13 )
echo "res= $res"

if [ $res -eq 0 ]
then
	echo "prime"
else
	echo "not prime"
fi









