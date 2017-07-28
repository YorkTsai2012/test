
//g++ rpcb_test.c -I/usr/include/tirpc -ltirpc

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <tirpc/netconfig.h>
#include <tirpc/rpc/types.h>
#include <tirpc/rpc/rpcb_clnt.h>
#include <tirpc/rpc/rpcb_prot.h>

int main() {

    rpcprog_t PROGNUM = (u_long)10005;
    rpcvers_t PROGVER = (u_long)3;
    struct netconfig* nconf = NULL;
    struct netbuf nbuf;
    //struct t_bind bind_addr;

    struct addrinfo* ai_tcp = NULL;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_flags = AI_NUMERICHOST | AI_NUMERICSERV;
    hints.ai_family = PF_INET6;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int ret = getaddrinfo("::", "38465", &hints, &ai_tcp);
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

    /* Get netconfig structure corresponding to tcp transport */
    if ((nconf = getnetconfigent("tcp6")) == (struct netconfig *) NULL) {
        fprintf(stderr, "getnetconfigent failed");
        exit(1);
    }
    /*
     * Code to open and bind file descriptor to bind_addr address
     */
    if(rpcb_set(PROGNUM, PROGVER, nconf, &nbuf) == FALSE) {
        fprintf(stderr, "rpcb_set() failed");
        exit(1);
    }
    svc_run();
    if (nconf) {
        freenetconfigent(nconf);
    }
    if (ai_tcp) {
        freeaddrinfo(ai_tcp);
    }
    return 0;
}
