#!/bin/bash

if [ $# -lt 1 ]; then
    echo "usage: interval"
    exit 1
fi

logf="top_unas.log"

if [ -f ${logf} ]; then
    mv ${logf} ${logf}.bak
fi

interval="$1"
while(true)
do
    pid=`ps -ef | fgrep unas_ipv6.ini | fgrep -v fgrep | awk '{print $2}'`
    t=$(date | awk '{print $4}')
    echo -e "$t\t$pid" >> ${logf}
    top -p $pid -b -n 1 | grep -E 'PID|wiwo' >> ${logf}
    sleep $interval
done
