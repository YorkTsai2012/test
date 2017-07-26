## Commands

## RPC定义 生成客户端和服务端封装 
### date.x => date.h date_clnt.c  date_svc.c
rpcgen date.x  
gcc -c date_clnt.c
gcc -c date_svc.c

## 服务端实现PRC
gcc -c dateproc.c

## 客户端建传输层 + 调用RPC
gcc -c rdate.c

## 生成客户端
gcc -o client date_clnt.o rdate.o

## 生成服务端
gcc -o server date_svc.o dateproc.o


## 疑问
为啥rpc的客户端  也要 socket bind ？
bind就是绑定IP地址到socket文件 (指定走哪张网卡)
