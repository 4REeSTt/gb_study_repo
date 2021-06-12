#!/bin/bash

if [ $# -lt 1 ];
then
	echo "Usage: $0 <file>"
	exit 1
else
	echo "file is changed"
fi

cat $1 | tr [:lower:] [:upper:] | grep -v "^$" > tmp
cat tmp > $1
rm tmp
