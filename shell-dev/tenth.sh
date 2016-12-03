#!/bin/bash

input="file.txt"
lines=`wc -l $input | awk '{print $1}'` 
if [ "$lines" -lt 10 ]; then
    exit 0;
fi
head -n 10 $input | tail -n 1
