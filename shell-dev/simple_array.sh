#!/bin/bash


# empty array 
#arr=()

arr=("a" "b")
#append
arr+=("c")

for item in "${arr[@]}"
do
    echo $item
done
