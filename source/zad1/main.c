#include <stdio.h>
#include "func.h"

int main () {
  func1 ("--- Hello World 1---");
  /* clear stdout buffer */
  fflush(stdout); 
  func2 ("--- Hello World 2---");
  return 1;
}
