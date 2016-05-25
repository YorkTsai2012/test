

#include <math.h>
#include <stdio.h>


typedef struct functionDaemon {
     int id;
     //double (*funcp); // function pointer
     double  (*fp)(double);      // Function pointer
}f_daemon_t;


int main()
{
        //warning: use of GNU old-style field designator extension [-Wgnu-designator]
        f_daemon_t f = {
            id: 10,
            fp: sin,
        };

        printf("id=%d,func=%f\n", f.id, (f.fp)(3.14/6));

        return 0;
}
