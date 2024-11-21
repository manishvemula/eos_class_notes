#!/bin/bash

# check path of file or directory and permission

# to check if path exists         : test -e path
# to check if path is of directory: test -d path
# to check if path is of file     : test -f path
# to check if path is of file has executable      : test -x path

echo "file path name"
read path

if [ -e $path ]
then
	if [ -d $path ]
	then 
		echo "directory..."
	elif [ -f $path ]
	then
		echo "regular type...."
		if [ -x $path ]
		then
			echo "file is executable"
		fi
	fi
else
	echo "does not exist"
fi


