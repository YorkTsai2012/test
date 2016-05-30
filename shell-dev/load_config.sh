
#!/bin/bash

if [ $# != 1 ]; then
	echo "$0: config_file"
	exit 1
fi

config_file="$1"
while read line;
do
	eval "$line"
done < "$config_file"

echo "IP=$IP"
echo "PORT=$PORT"
echo "NAME=$NAME"
