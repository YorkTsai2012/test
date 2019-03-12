#!/bin/bash

function hello()

{

 echo "hello"

}

(

flock -n 200 || {

 echo "there is another one trying to stop dbfs"

 exit 1

}

# ... commands executed under lock ...

echo "in write lock"

hello

sleep 10

echo "out write lock"

) 200>/tmp/dbfs.lock



跟踪子进程

strace -f  flock_test.sh



[pid 49105] open("/tmp/dbfs.lock", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 3

[pid 49105] dup2(3, 200)                = 200

[pid 49105] close(3)                    = 0

[pid 49106] flock(200, LOCK_EX|LOCK_NB) = 0
