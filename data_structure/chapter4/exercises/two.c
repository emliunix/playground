#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 100

char *string_copy(char *str);
void string_destroy(char *str);
char *get_common(char *str_a, char *str_b);

char *string_copy(char *str) {
  int len = strlen(str);
  char *p = (char *)calloc(len, sizeof(char));
  memcpy(p, str, len * sizeof(char));
  return p;
}

void string_destroy(char *str) {
  free(str);
}

void sort(char *str) {
  int i, j;
  int len = strlen(str);
  for(i = 0; i < len; ++i) {
    for(j = len - 1; j > i; --j) {
      if(str[j] < str[j-1]) {
	char tmp = str[j];
	str[j] = str[j-1];
	str[j-1] = tmp;
      }
    }
  }
}

char *get_common(char *a, char *b) {
  int i, j, k;
  char *stra = string_copy(a);
  char *strb = string_copy(b);
  char *r = calloc(SIZE, sizeof(char));
  sort(stra);
  sort(strb);
  i = j = k = 0;
  while(stra[i] && strb[j]) {
    if(stra[i] > strb[j])
      ++j;
    else if(stra[i] < strb[j])
      ++i;
    else {
      r[k++] = stra[i];
      ++i, ++j;
    }
  }
  r[k] = '\0';
  string_destroy(stra);
  string_destroy(strb);
  return r;
}

int main(int argc, char *argv[]) {
  char a[] = "abedfck";
  char b[] = "bcfkc";
  printf("%s\n", get_common(a, b));
  return 0;
}
