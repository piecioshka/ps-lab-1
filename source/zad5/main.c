#include <stdio.h>
#include <time.h>

int main (int argc, char * argv[]) {
  time_t timer;
  /* update time for current */
  time(&timer);
  /* cast structure for string */
  char * date = ctime(&timer);
  /* print current date */
  printf("Aktualna data: %s", date);
  return 0;
}

