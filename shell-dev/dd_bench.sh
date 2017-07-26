#!/bin/bash

if [ $# -lt 2 ]; then
    echo "usage: $0 begin end"
    exit 1
fi

begin="$1"
end="$2"
for i in `seq $begin $end`
do
    echo "execute task $i"
    outdir="bucket${i}"
    mkdir -p $outdir
    outf="./$outdir/4G.bench"
    mkdir -p /data/log
    outlog="/data/log/nohup${i}.log"
    nohup dd if=/dev/zero of=$outf bs=1024 count=$((4*1024*1024)) > $outlog 2>&1 &
done
