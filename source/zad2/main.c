#include <stdio.h>
#include "func.h"

int main (int argc, char * argv[]) {
  printf("Uruchomiony program: %s\n", argv[0]);
  int nr = 1;
  char * arg;
  if (argc < 2) {
    fprintf(stderr, "za mala liczba argumentów\n");
  }
  while ((arg = argv[nr])) {
    printf("%s\n", arg);
    nr++;
  }
  return 1;
}
