#!/bin/bash
for year in $(seq 2010 2017);
do mkdir $year
	for month in $(seq 1 12);
	do mkdir ./$year/$month;
		echo "001" > ./$year/$month/file1;
		echo "002" > ./$year/$month/file2;
	done
done
