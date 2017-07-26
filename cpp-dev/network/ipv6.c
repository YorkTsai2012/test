
#include <netinet/ip6.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    char* src = "2003:da8:2004:1000:a09:5292:100:3797";
    char ip[16];

    scan_ip6(src, ip);

    char buf[64];
    buf[fmt_ip6(buf,ip)]=0;

    printf("fmt ipv6:%s\n", fmt_ip6);

}
