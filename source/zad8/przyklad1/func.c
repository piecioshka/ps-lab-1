#include <stdio.h>
#include "func.h"

int func2 (char *astr) {
  if (!astr) return 0;
  fprintf (stderr, "%s", astr);
  return 1;
}

int func1 (char *astr) {
  if (!astr) return 0;
  fprintf (stdout, "%s", astr);
  return 1;
}
