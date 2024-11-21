#!/bin/bash

echo "CALCULATOR"

echo -e -n "enter n1"
read n1

echo -n -e "enter n2"
read n2

echo -n -e "read operator:"
read op

case $op in
	+) res=`expr $n1 + $n2`
		echo "$res is add"
		;;
	-) res=`expr $n1 - $n2`
		echo "$res is sub"
		;;
	*) res=`expr $n1 \* $n2`
		echo "$res is mul"
		;;
	/) res=`expr $n1 / $n2`
		echo "$res is div"
		;;
	*) echo "invalid"
esac

