#!/bin/bash

ZONE_ID="urn:storageos:VirtualDataCenterData:5edd3f0e-6b53-4fcf-9c28-0bbd8199c4ef"
OB_TABLE_LIST="OB_dt.table"
HOST="10.247.99.220"

function handleEveryBTree() {
        dtKey="$1"
        major="$2"
        url="http://$HOST:9101/btreeIterate/$dtKey/$ZONE_ID/$major/false/false/0/0"
        rm -f page.*
        leaf=`curl -s $url | fgrep BtreeChunk | awk 'BEGIN{leaf=0} { if ($2>leaf){leaf=$2;} print $3 >> "page."$2; } END{print leaf}'`
        if [ $leaf -gt 0 ]; then
                timestamp=`date +%s`
                echo $timestamp
                term_log="pages_"$leaf"_ts"$timestamp
                mkdir -p $term_log
                echo $url > "$term_log/url"
                echo "deep leaf:$leaf"
                for i in `seq 0 $((${leaf} - 1))`; do
                        ret=`fgrep -f page.$i page.$leaf`
                        if [ -n "$ret" ]; then
                                echo -e "found unexpected \n $url"
                        fi
                done
                mv page.* $term_log/
        else
                echo $url
                echo "only-root leaf:$leaf"
        fi
}

function handleEveryDt() {
        url="$1"
        dtKey="$2"
        #echo $url
        curl -s $url | fgrep schemaType | awk --non-decimal-data 'END{printf("%d\n","0x"$10)}' | while read major; do handleEveryBTree $dtKey $major; done
}

function execMain() {
while read line
do
        dtKey=$line
        url="http://$HOST:9101/diagnostic/PR/1/DumpAllKeys/DIRECTORYTABLE_RECORD?type=BPLUSTREE_INFO&dtId=$dtKey&zone=$ZONE_ID"
        handleEveryDt $url $dtKey
done < "$OB_TABLE_LIST"
}

execMain
