#!/bin/bash
#SYDNEY ANDERSON
#DATE: 2/19/2019
#BASH SCRIPT

product()
{

	for i in "$1"/*; do	
		sum=$(( $sum * $1 ))
	done
}

sum=1

if [ $# -eq 0 ]; #if no params are given
	then
	echo "Usage: $0 val [val [... ] ]"
	echo "e.g., $0 17 49 3 466"
fi
if [ $# -eq 1 ]; #if one number is given
	then
	echo "The prod of $1 is $1"
fi

if [ $# -gt 1 ]; # several inputs are given
	then
	echo -n "The prod of $@ is "
	while [ $1 ]; do
	product $1
	shift
	done
	echo  $sum
fi

