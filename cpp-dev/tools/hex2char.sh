
#!/bin/bash

if [ $# -lt 1 ]; then
    echo "usage: $0 hex_str"
    exit 10
fi

hex_str="$1"
#python -c "print '$hex_str'.decode('hex')"

#echo -n 68656c6c6f0009776f726c6400 | xxd -r -p
echo -n "$hex_str" | xxd -r -p
