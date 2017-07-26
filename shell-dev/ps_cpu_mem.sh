#!/bin/bash

if [ $# -lt 1 ]; then
    echo "usage: interval"
    exit 1
fi

pid=`ps -ef | fgrep unas_ipv6.ini | fgrep -v fgrep | awk '{print $2}'`
logf="ps_unas.log"

if [ -f ${logf} ]; then
    mv ${logf} ${logf}.bak
fi

interval="$1"
while(true)
do
    t=$(date | awk '{print $4}')
    echo $t >> ${logf}
    ps -o vsz,rss,pcpu -p $pid >> ${logf}
    sleep $interval
done
