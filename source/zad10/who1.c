#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST /* include remote machine on output */

/*
 *  show info()
 * displays contents of the utmp struct in human readable form
 * *note* these sizes should not be hardwired
 */
void show_info(struct utmp *utbufp) {
    if (strlen(utbufp->ut_name) == 0) return;
    if (strlen(utbufp->ut_host) == 0) return;

    printf("%-8.8s", utbufp->ut_name); /* the logname */
    printf(" "); /* a space */
    printf("%-8.8s", utbufp->ut_line); /* the tty */
    printf(" "); /* a space */
    printf("%10ld", utbufp->ut_time); /* login time */
    printf(" "); /* a space */
#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host); /* the host */
#endif
    printf("\n"); /* newline */
}

int main() {
    struct utmp current_record; /* read info into here */
    int utmpfd; /* read from this descriptor */
    int reclen = sizeof(current_record);

    /* printf("read from file: %s\n", UTMP_FILE); */

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE); /* UTMP_FILE is in utmp.h */
        exit(1);
    }

    while (read(utmpfd, &current_record, reclen) == reclen) {
        show_info(&current_record);
    }
    close(utmpfd);
    return 0; /* went ok */
}

