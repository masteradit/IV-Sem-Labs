#!/bin/bash

echo "Enter the pattern:"
read pattern
echo "Enter the location:"
read location

ls $location/*$pattern*