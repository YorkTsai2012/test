#!/bin/bash

if [ $# != 1 ]; then
	echo "$0 src"
	exit 1
fi

src="$1"

gcc -ansi -I../include -Wall -DMACOS -D_DARWIN_C_SOURCE  $src -o "test"  -L../lib -lapue 
