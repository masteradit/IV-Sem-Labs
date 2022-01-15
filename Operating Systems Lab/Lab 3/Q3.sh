#!/bin/bash 

echo "Replacing .txt with .text"
result=`find . -depth -name *.txt`
for i in $result 
do
    mv $i ${i%.txt}.text
done
echo "Done"