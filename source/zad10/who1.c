#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST /* include remote machine on output */

char * printTime(int timestamp) {
  struct tm tm;
  char buffer[255];
  char time_s[255];
  sprintf(time_s, "%i", timestamp);
  strptime(time_s, "%s", &tm); 
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", &tm);
  return buffer;
}

/*!
 * show info()
 * displays contents of the utmp struct in human readable form
 * *note* these sizes should not be hardwired
 */
void show_info(struct utmp *utbufp) {
  if (strlen(utbufp->ut_name) == 0) return;
  if (strlen(utbufp->ut_line) == 1) return;
  if (strlen(utbufp->ut_host) == 0) return;

  printf("%-8.8s", utbufp->ut_name); /* the logname */
  printf(" "); /* a space */
  printf("%-8.8s", utbufp->ut_line); /* the tty */
  printf("\t"); /* a space */
  /* printf("%10ld", utbufp->ut_time); */ /* login time */
  printf("%s", printTime(utbufp->ut_time)); /* login time */
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

