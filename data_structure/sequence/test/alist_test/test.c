#include <stdlib.h>
#include <stdio.h>

#include "alist.h"

int main(int argc, char *argv[]) {
  int data[] = {1, 2, 3, 4, 5, 6, 7};
  alist_t *p = alist_create_with_data(data, 7);
  alist_display(p);
  puts("insert 100@7, 200@3, 300@0");
  alist_insert_before(p, 7, 100);
  alist_insert_before(p, 3, 200);
  alist_insert_before(p, 0, 300);
  alist_display(p);
  puts("append 400");
  alist_append(p, 400);
  alist_display(p);
  puts("delete AList[3]");
  alist_delete(p, 3);
  alist_display(p);
  puts("AList[3] = -1");
  alist_set(p, 3, -1);
  alist_display(p);
  puts("alist_get() test");
  printf("AList[3] == %d\n", alist_get(p, 3));
  return 0;
}
