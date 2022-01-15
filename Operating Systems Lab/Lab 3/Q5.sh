#!/bin/bash

echo "Enter the file extension to be moved:"
read extension
echo "Enter the folder where the files will be moved to:"
read folder
result=`find ./ -maxdepth 1 -name *$extension`
mkdir $folder
for i in $result
do
    mv $i $folder
done