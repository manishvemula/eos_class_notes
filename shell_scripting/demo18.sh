#!/bin/bash

# arr

#    0 1 2
arr=(1 2 3 4 5)  #array declaration

echo "All element : ${arr[*]}"
echo "All element : ${arr[@]}"

echo "Size of arra: ${#arr[*]}"

echo "arr[0] : ${arr[0]} "
echo "arr[1] : ${arr[1]} "
echo "arr[2] : ${arr[2]} "
echo "arr[3] : ${arr[3]} "


i=0
for var in ${arr[*]}
do
	echo -e -n "arr[$i] = $var"
	i=`expr $i + 1`
done

#------------------------------------------
#!/bin/bash

# declare array and input values from user.
# add all elements and display result.

# declaration is optional
declare -a arr

i=0
while [ $i -lt 5 ]
do
	echo -n "enter element $i: "
	read arr[$i]
	i=`expr $i + 1`
done

echo "number of elements: ${#arr[*]}" # print lenghth of array

sum=0
for num in ${arr[*]}
do
	sum=`expr $sum + $num`
done
echo "result: $sum"








