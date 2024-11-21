#!/bin/bash


# print positional params and print script name

# positional parameters (like command line args in C)
# while executing shell script on command line, we can pass additional information.
# it is called as "positional parameters".
# terminal> ./demo13.sh one two three four

# To access positional params in the script: $1 $2 $3 $4 ... $9
# List of all positional params: $*
# Shell script name: $0
# Number of positional params: $#

# shift N command is used to skip N params from left
# This will enable access to the next params.
# N+1 param will become $1
# N+2 param will become $2

echo "file name : $0"

echo "Num of postional parameter : $#"

echo "All arg : $*"


echo "1st -> $1"
echo "2nd -> $2"
echo "3rd -> $3"
echo "4th -> $4"
echo "5th -> $5"

#shift 2

#echo "1st -> $1"
#echo "2nd -> $2"
#echo "3rd -> $3"

echo "For loop : "
for var in $*
do 
	
	echo "$var "
done


