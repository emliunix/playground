#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

int main(int argc, char *argv[]) {
  int data[] = {1, 2, 3, 4, 5, 6, 7};
  snode_t *p = llist_create_with_data(data, 7);
  llist_display(p);
  puts("insert 100@7, 200@3, 300@0");
  llist_insert_before(p, 7, 100);
  llist_insert_before(p, 3, 200);
  llist_insert_before(p, 0, 300);
  llist_display(p);
  puts("append 400");
  llist_append(p, 400);
  llist_display(p);
  puts("delete LList[3]");
  llist_delete(p, 3);
  llist_display(p);
  puts("LList[3] = -1");
  llist_set(p, 3, -1);
  llist_display(p);
  puts("llist_get() test");
  printf("LList[3] == %d\n", llist_get(p, 3));

  return 0;
}
