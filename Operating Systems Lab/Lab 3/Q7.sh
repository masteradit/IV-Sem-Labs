#!/bin/bash

echo "Enter the file:"
read file
sed -i '2~2d' $file