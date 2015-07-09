#include <stdlib.h>

#include "types.h"

static node_t *node_new() {
  node_t *p = (node_t *)malloc(sizeof(node_t));
  p->next = NULL;
  return p;
}

node_t *list_create_with_data(el_t *data, int len) {
  int i = 0;
  node_t *h = node_new();
  node_t *tail = h;
  node_t *tmp = NULL;
  while(len--) {
    tmp = node_new();
    tmp->data = data[i++];
    tail->next = tmp;
    tail = tmp;
  }
  return h;
}

