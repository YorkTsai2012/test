//g++ -g -o unbind unbind6_nfs_mnt.c -I/usr/include/tirpc -ltirpc

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <tirpc/netconfig.h>
#include <tirpc/rpc/types.h>
#include <tirpc/rpc/rpcb_clnt.h>
#include <tirpc/rpc/rpcb_prot.h>

void CommonUnbind(rpcprog_t prog_num, rpcvers_t prog_ver) {

    struct netconfig* nconf = NULL;
    if ((nconf = getnetconfigent("tcp6")) == (struct netconfig *) NULL) {
        fprintf(stderr, "getnetconfigent failed");
        exit(1);
    }

    if(rpcb_unset(prog_num, prog_ver, nconf) == FALSE) {
        fprintf(stderr, "rpcb_unset() failed");
        exit(1);
    }

    if (nconf) {
        freenetconfigent(nconf);
    }
}

int main() {

    CommonUnbind(100005, 3);
    CommonUnbind(100003, 3);
    return 0;
}
