//g++ -g -o bind bind6_nfs_mnt.c -I/usr/include/tirpc -ltirpc

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <tirpc/netconfig.h>
#include <tirpc/rpc/types.h>
#include <tirpc/rpc/rpcb_clnt.h>
#include <tirpc/rpc/rpcb_prot.h>

void CommonBind(rpcprog_t prog_num, rpcvers_t prog_ver, const char* port) {

    struct netconfig* nconf = NULL;
    struct netbuf nbuf;
    struct addrinfo* ai_tcp = NULL;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_NUMERICHOST | AI_NUMERICSERV;
    hints.ai_family = PF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int ret = getaddrinfo("::", port, &hints, &ai_tcp);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo fail|ret:%d", ret);
        exit(1);
    }

    nbuf.buf = ai_tcp->ai_addr;
    nbuf.len = nbuf.maxlen = ai_tcp->ai_addrlen;

    for (int i = 0; i < nbuf.len; i++) {
        printf("%02x", ((char*)nbuf.buf)[i]);
    }
    printf("\n");

    if ((nconf = getnetconfigent("tcp6")) == (struct netconfig *) NULL) {
        fprintf(stderr, "getnetconfigent failed");
        exit(1);
    }

    if(rpcb_set(prog_num, prog_ver, nconf, &nbuf) == FALSE) {
        fprintf(stderr, "rpcb_set() failed");
        exit(1);
    }
    if (nconf) {
        freenetconfigent(nconf);
    }
    if (ai_tcp) {
        freeaddrinfo(ai_tcp);
    }
}

int main() {

    CommonBind(100005, 3, "38465");
    CommonBind(100003, 3, "2049");
    return 0;
}
