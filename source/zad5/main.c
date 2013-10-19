#include <stdio.h>
#include <time.h>

void printFancyDate(struct tm * time) {
  int day = time->tm_mday;
  int month = time->tm_mon;
  int year = time->tm_year + 1900;
  int hour = time->tm_hour;
  char * tm_zone = time->tm_zone;
  printf("%i.%i.%i %i %s\n", day, month, year, hour, tm_zone);
}

int main (int argc, char * argv[]) {
  time_t gmTime;
  struct tm * gmStruct;

  time_t localTime;
  struct tm * localStruct;

  time(&gmTime);
  time(&localTime);

  /* update time for current not time zone */
  gmStruct = gmtime(&gmTime);
  printFancyDate(gmStruct);

  /* update time for local time zone */
  localStruct = localtime(&localTime);
  printFancyDate(localStruct);
  return 1;
}

