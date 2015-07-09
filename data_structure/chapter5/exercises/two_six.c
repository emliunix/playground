#include <stdio.h>
#include <stdlib.h>

#include "types.h"

el_t max(node_t *list);

el_t max(node_t *l) {
  node_t *p = l->next;
  el_t max = p->data;
  while(p) {
    if(p->data > max)
      max = p->data;
    p = p->next;
  }
  return max;
}

int main(int argc, char *argv[]) {
  el_t data[] = {1, 2, 3, 4, 18, 6, 7, 8};
  node_t *list = list_create_with_data(data, 8);
  printf("Max: %d\n", (int)(max(list)));
  return 0;
}
