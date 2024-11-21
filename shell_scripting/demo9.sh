#!/bin/bash

# print number of days in given month.

# case $var in
# c1|const1|case1)
#	...
#	;;
# c2|case2)
#	...
#	;;
# c3)
#	...
#	;;
# *)
# esac

echo "enter the month"
read month


case $month in
	1|jan|JAN|Jan)
		echo "31"
		;;
	2|feb)
		echo "28"
		;;
	3|march)
		echo "31"
		;;
	*)
		echo "not valid"

esac





