#!/bin/bash

s1="SunBeam"
s2="infotech"

echo "$s1 $s2"

# string concat
s3=$s1$s2
echo "$s3"   #print
echo "${s3}" #print 

# string splice - substring
str="SunBeam"
echo "${str:3}" #print 3 char onwards
echo "${str:3:2}" #print from 3rd char to onward 2 char

# convert string to upper/lower
echo "${str^^}" #convert upper case
echo "${str,,}" #  lower case

echo "${s2^}" #convert 1st char to upercase
echo "${s2,}" #convert first char to lowercase

