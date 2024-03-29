/* dateproc.c - remote procedures; called by server stub */
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "date.h"

/* return the binary date and time */
/* In Linux: 
 */

long * bindate_1_svc(void* arg1, struct svc_req *arg2) {
    static long timeval; /* must be static */
    timeval = time((long *) 0);
    return (&timeval);
}

/* In Dec Unix: long * bindate_1() {
*/

/*
long * bindate_1(void* p, CLIENT* client) {
    // must be static 
    static long timeval;
    timeval = time((long *) 0);
    return (&timeval);
}
*/
