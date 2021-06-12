#!/bin/bash

if [ $# -lt 1 ];
then
	echo "Usage: $0 <dir>"
	exit 1
else
	echo "done"
fi

ls -l $1 | awk '{print $1}' | sort | uniq 
