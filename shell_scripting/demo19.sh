#!/bin/bash


arr=("vim" "gcc" "ncal" "git")
sudo apt update

for var in ${arr[*]}
do
	sudo apt install $var
	if [ $? -eq 0 ]
	then
		echo "$var installed sucssesfully..."
	else
		echo "Error.."
	fi
done








