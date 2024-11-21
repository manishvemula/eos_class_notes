#!/bin/bash

#find area of circle
#area= 3.14 * r * r


echo -n -e "enter radius: "
read rad

echo "scale=2; 3.14 * $rad * $rad" |  bc > out.txt

#echo "area= $area"

