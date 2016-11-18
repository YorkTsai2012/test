#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <arpa/inet.h>
  
// 字符串 -> 特定网络字节序的整型

int main(int argc, char *argv[]) {  
    if (argc != 2) {
        fprintf(stderr, "%s <dotted-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *ip = argv[1];

    long r1, r2, r3;  //long  
    struct in_addr addr;  
  
    r1 = inet_addr(ip); //返回网络字节序  
    if(-1 == r1){  
        printf("inet_addr return -1\n");  
    }else{  
        printf("inet_addr ip: %ld hex: %x\n", r1, r1);  
        printf("network order ip: %ld hex: %x\n", 
    }  
      
    r2 = inet_network(ip);    //返回主机字节序  
    if(-1 == r2){  
        printf("inet_addr return -1\n");  
    }else{  
        printf("host order ip: %ld | hex: %x\n", r2, r2); 
        printf("network order ip: %ld | hex: %x\n", htonl(r2), htonl(r2));   //主机->网络
    }  
      
    r3 = inet_aton(ip, &addr);  //返回网络字节序  
    if(0 == r3){  
        printf("inet_aton return -1\n");  
    }else{  
        printf("inet_aton ip: %ld | hex: %x\n", addr.s_addr, addr.s_addr);  
    }  
  
/*****  批量注释的一种方法  *****/  
#if 0    
    r3 = inet_aton(ip, addr);  
    if(0 == r3){  
        printf("inet_aton return -1/n");  
    }else{  
        printf("inet_aton ip: %ld/n", ntohl(addr.s_addr));  
    }  
#endif  
  
    return 0;  
}  
