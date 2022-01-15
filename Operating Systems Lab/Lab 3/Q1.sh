#!/bin/bash

echo "Enter the path of the file/directory"
read a;
if [ -d "${a}" ] ; then
    echo "$a is a directory";
elif [ -f "${a}" ]; then
    echo "${a} is a file";
else
    echo "${a} is not valid";
fi