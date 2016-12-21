#!/bin/bash

if [ $# -lt 1 ]; then
    echo "usage: $0 task_name"
    exit 1
fi

task_name="$1"

loop=10
for i in `seq 1 $loop`
do
    echo "generate a file with random size ${i}KB"
    dd if=/dev/urandom of="./${task_name}-${i}KB.file" bs=1024 count=$(($i))
done
