#include <stdio.h>
#include <stdlib.h>

#include "types.h"

void display_reverse(node_t *list);

static void display_reverse_helper(node_t *l) {
  if(l) {
    display_reverse_helper(l->next);
    printf("%d ", (int)(l->data));
  }
}
void display_reverse(node_t *l) {
  fputs("List(Reversed): ", stdout);
  display_reverse_helper(l->next);
  putchar('\n');
}

int main(int argc, char *argv[]) {
  el_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
  node_t *list = list_create_with_data(data, 8);
  display_reverse(list);
  return 0;
}
