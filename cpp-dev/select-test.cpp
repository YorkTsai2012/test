

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int
main(void) {
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /* Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    while (true) {
        retval = select(1, &rfds, NULL, NULL, &tv);
        /* Don't rely on the value of tv now! */
        fprintf(stdout, "[%s %d]retval=%d\n", __FUNCTION__, __LINE__, retval);

        if (retval == -1) {
            perror("select()");
        } else if (retval) {
            printf("Data is available now.\n");
            /* FD_ISSET(0, &rfds) will be true. */
            if (FD_ISSET(0, &rfds)) {
                char buf[1024];
                //read data
                ssize_t n = read(0, buf, sizeof(buf)/sizeof(char));
                if (-1 == n) {
                    perror(NULL);
                    return errno;
                }
                write(1, buf, n);
            }
        } else
            printf("No data within five seconds.\n");
    }

    exit(EXIT_SUCCESS);
}
