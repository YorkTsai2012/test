#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <netinet/in.h>  
#include <netinet/ip.h> 
#include <sys/socket.h>  
#include <sys/types.h>  
  
int main()  
{  
    char ip[] = "192.168.0.74";  
    long r1, r2, r3;  //long  
    struct in_addr addr;  
  
    r1 = inet_addr(ip); //返回网络字节序  
    if(-1 == r1){  
        printf("inet_addr return -1/n");  
    }else{  
        printf("inet_addr ip: %ld/n", r1);  
    }  
      
    r2 = inet_network(ip);    //返回主机字节序  
    if(-1 == r2){  
        printf("inet_addr return -1/n");  
    }else{  
        printf("inet_network ip: %ld/n", r2);   
        printf("inet_network ip: %ld/n", ntohl(r2));   //ntohl: 主机字节序 ——> 网络字节序  
    }  
      
    r3 = inet_aton(ip, &addr);  //返回网络字节序  
    if(0 == r3){  
        printf("inet_aton return -1/n");  
    }else{  
        printf("inet_aton ip: %ld/n", addr.s_addr);  
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
