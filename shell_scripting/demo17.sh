#!/bin/bash


# in a given directory path, list all contents.
# if content is file, print its length.
# if content is directory

# man test
# to check if path exists         : test -e path
# to check if path is of directory: test -d path
# to check if path is of file     : test -f path

# to check if file/dir is readable  : test -r path
# to check if file/dir is writable  : test -w path
# to check if file/dir is executable: test -x path

# man stat
# to print length of file: stat -c %s path 
# to print user of file: stat -c %U path


echo -e -n "enter path :"
read path

if [ -e $path ]
then
	if [ -f $path ]
	then
		echo "It is a Regular file"
		echo -e -n "File type : " 
		stat -c %F $path
		echo "Inode No : "
		stat -c %i $path
		echo "size:"
		stat -c %s $path
	else
		echo "It is directory"

	fi
else
	echo "Path not exists "
fi









