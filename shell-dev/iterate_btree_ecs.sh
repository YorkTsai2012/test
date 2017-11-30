#!/bin/bash

ZONE_ID="urn:storageos:VirtualDataCenterData:8fcbfb90-7f8d-49d5-ba6c-23688de66489"
OB_TABLE_LIST="OB_dt.table"
HOST="10.247.78.91"

function handleEveryBTree() {
        dtKey="$1"
        major="$2"
        url="http://10.247.78.91:9101/btreeIterate/$dtKey/$ZONE_ID/$major/false/false/0/0"
        #echo $url
        rm -f page.*
        leaf=`curl -s $url | fgrep BtreeChunk | awk 'BEGIN{leaf=0} { if ($2>leaf){leaf=$2;} print $3 >> "page."$2; } END{print leaf}'`
        if [ $leaf -gt 0 ]; then
                #echo $url
                echo "deep leaf:$leaf"
                for i in `seq 0 $((${leaf} - 1))`; do
                        #echo $i
                        fgrep -f page.$i page.$leaf
                done
        else
                echo $url
                echo "only-root leaf:$leaf"
        fi
}

function handleEveryDt() {
        url="$1"
        dtKey="$2"
        #echo $url
        curl -s $url | fgrep schemaType | awk --non-decimal-data '{printf("%d\n","0x"$10)}' | while read major; do handleEveryBTree $dtKey $major; done
}

function execMain() {
while read line
do
        dtKey=$line
        url="http://10.247.78.91:9101/diagnostic/PR/1/DumpAllKeys/DIRECTORYTABLE_RECORD?type=BPLUSTREE_INFO&dtId=$dtKey&zone=$ZONE_ID"
        handleEveryDt $url $dtKey
done < "$OB_TABLE_LIST"
}

execMain
