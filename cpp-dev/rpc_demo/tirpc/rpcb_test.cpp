//g++ rpcb_test.c -I/usr/include/tirpc -ltirpc

#include <stdio.h>
#include <stdlib.h>
/*
#include <tirpc/netconfig.h>
#include <tirpc/rpc/types.h>
#include <tirpc/rpc/rpcb_clnt.h>
#include <tirpc/rpc/rpcb_prot.h>
*/
#include <tirpc/netconfig.h>
#include <tirpc/rpc/types.h>
#include <tirpc/rpc/rpcb_clnt.h>
#include <tirpc/rpc/rpcb_prot.h>

int main() {

    rpcprog_t PROGNUM = (u_long)10005;
    rpcvers_t PROGVER = (u_long)3;
    struct netconfig* nconf ;
    struct netbuf* nbuf;
    struct t_bind bind_addr;

    /* Get netconfig structure corresponding to tcp transport */
    if ((nconf = getnetconfigent("tcp")) == (struct netconfig *) NULL) {
        fprintf(stderr, "getnetconfigent failed");
        exit(1);
    }
    /*
     * Code to open and bind file descriptor to bind_addr address
     */
    nbuf = &bind_addr.addr;
    if(rpcb_set(PROGNUM, PROGVER, nconf, nbuf) == FALSE ) {
        fprintf(stderr,"rpcb_set() failed");
        exit(1);
    }
    svc_run();
    return 0;
}
