## Commands
rpcgen date.x
gcc -c date_clnt.c
gcc -c date_svc.c
gcc -c dateproc.c
gcc -c rdate.c
gcc -o client date_clnt.o rdate.o
gcc -o server date_svc.o dateproc.o


## 疑问
为啥rpc的客户端  也要 socket bind ？