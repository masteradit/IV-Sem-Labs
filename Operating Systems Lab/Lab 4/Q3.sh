#!/bin/bash 

sort(){
	list=("${!1}")
	for ((i=0; i<5; i++))
	do
			for ((j=0; j<5-i-1; j++))
			do
				if  [ "${list[j]}" \> "${list[$((j+1))]}" ]
				then
						temp=${list[j]}
						list[j]=${list[$((j+1))]}
						list[$((j+1))]=$temp
				fi
			done
	done

	echo "Sorted Array:"
	echo ${list[*]}
}


a=(${*})
echo "List before sorting:"
echo ${a[*]}
sort a[@]