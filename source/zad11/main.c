#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int random_between(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void test_func() {
  int rand = random_between(1, 5);
  fprintf(stderr, "losujemy liczbe ");
  for(int i = 0; i < rand; ++i) {
    fprintf(stderr, ".");
    sleep(1);
  }
  fprintf(stderr, " %d\n", rand);
}

int main() {
  time_t pre_time;
  time_t post_time;

  /* profile time */
  time(&pre_time);

  /* run looong action */
  test_func();

  /* profile time */
  time(&post_time);

  printf(" > czas losowania: %f\n", difftime(post_time, pre_time));
  return 0;
}
