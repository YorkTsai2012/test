
/*
 * ref: https://www.unf.edu/~sahuja/cnt5505/rpcexample.html
*/

/* date.x - Specification of remote date and time service
bindate() which returns the binary time and date (no args).
This file is the input to rpcgen */
program DATEPROG {  /* remote program name (not used)*/
    version DATEVERS { /* declaration of program version number*/
        long BINDATE(void) = 1; /* procedure number = 1 */
    } = 1;  /* definition of program version =1*/
} = 0x3012225;  /* remote program number (must be unique)*/
/****************************************************************/
/* rdate.c - client program for remote date service */
#include stdio.h
#include rpc/rpc.h
#include stdlib.h
#include "date.h"
int main(int argc, char *argv[]) {
    CLIENT *cl;
    char *server;
    long *lres;
    if (argc != 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(1);
    }
    server = argv[1];
    /* create client handle */
    if ((cl = clnt_create(server, DATEPROG, DATEVERS, "udp")) == NULL) {
        /* couldn't establish connection with server */
        printf("can't establish connection with host %s\n", server);
        exit(2);
    }
    /* first call the remote procedure bindate() */
    if (( lres = bindate_1(NULL, cl)) == NULL) {
        printf(" remote procedure bindate() failure\n");
        exit(3);
    }
    printf("time on host %s = %ld\n", server, *lres);
    clnt_destroy(cl); /* done with handle */
    return 0;
}
/*********************************************************************/
/* dateproc.c - remote procedures; called by server stub */
#include stdio.h
#include stdlib.h
#include rpc/rpc.h
#include "date.h"
/* return the binary date and time */
/* In Linux: long * bindate_1_svc(void* arg1, struct svc_req *arg2) {
*/

/* In Dec Unix: long * bindate_1() {
*/

long * bindate_1() {
    static long timeval; /* must be static */
    timeval = time((long *) 0);
    return (&timeval);
}
****************************************************
Commands:
rpcgen date.x
gcc -c date_clnt.c
gcc -c date_svc.c
gcc -c dateproc.c
gcc -c rdate.c
gcc -o client date_clnt.o rdate.o
gcc -o server date_svc.o dateproc.o
