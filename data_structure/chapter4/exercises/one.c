#include <stdlib.h>
#include <stdio.h>

int pattern_index(char *pattern, char *target);

int pattern_index(char *p, char *t) {
  int i, j;
  for(i = 0; t[i]; ++i) {
    for(j = 0; p[j] && t[i+j] && (p[j] == '?' || t[i+j] == p[j]); ++j);
    if(!p[j]) return i;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  char target[] = "there are";
  char pattern[] = "?re";
  printf("%d\n", pattern_index(pattern, target));
  return 0;
}
