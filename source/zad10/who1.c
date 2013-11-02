#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST /* include remote machine on output */

/*!
 * show_time()
 * display human redable date time
 */
char * show_time(int timestamp) {
  struct tm tm;
  static char buffer[255];
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
  printf("%s", show_time(utbufp->ut_time)); /* login time */
  printf(" "); /* a space */
#ifdef SHOWHOST
  printf("(%s)", utbufp->ut_host); /* the host */
#endif
  printf("\n"); /* newline */
}

int main(int argc, char * argv[]) {
  struct utmp current_record; /* read info into here */
  int utmpfd; /* read from this descriptor */
  int reclen = sizeof(current_record);
  char * login = getlogin();

  if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
    perror(UTMP_FILE); /* UTMP_FILE is in utmp.h */
    exit(1);
  }

  if (argc < 2) {
    while (read(utmpfd, &current_record, reclen) == reclen) {
      show_info(&current_record);
    }
  } else {
    if (argc < 3) {
      return 0;
    }
    /* if next opts are './who.o am i' we print only single line */
    if (strcmp(argv[1], "am") == 0 && strcmp(argv[2], "i") == 0) {
      /* analyze all contents in UTMP_FILE */
      while (read(utmpfd, &current_record, reclen) == reclen) {
        /* compare each record name with current user login name */
        if (strcmp(current_record.ut_name, login) == 0) {
          /* print info about logged user */
          show_info(&current_record);
          /* exit from loop, becouse printing only one record */
          /* the same situation is in '$ who am i' command. */
          break;
        }
      }
    }
  }
  close(utmpfd);
  return 0; /* went ok */
}

