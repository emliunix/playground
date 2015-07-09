#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "llist.h"

static snode_t *node_new() {
  snode_t *p = (snode_t *)malloc(sizeof(snode_t));
  p->data = DEFAULT_DATA;
  p->next = NULL;
}

snode_t *llist_create() {
  return node_new();
}

void llist_destroy(snode_t *l) {
  snode_t *tmp = l;
  while(tmp) {
    l = l->next;
    free(tmp);
    tmp = l;
  }
}

void llist_insert_before(snode_t *l, int idx, int val) {
  snode_t *prev = l;
  snode_t *p = NULL;
  while(idx--) {
    prev = prev->next;
    assert(prev != NULL);
  }
  p = node_new();
  assert(p != NULL);
  p->data = val;
  p->next = prev->next;
  prev->next = p;
}

void llist_delete(snode_t *l, int idx) {
  snode_t *prev = l;
  snode_t *curr = NULL;
  while(idx--) {
    prev = prev->next;
    assert(prev != NULL);
  }
  curr = prev->next;
  assert(curr != NULL);
  prev->next = curr->next;
  free(curr);
}

int llist_length(snode_t *l) {
  int i;
  for(i = 0; l->next; l = l->next) ++i;
  return i;
}


/*
 * extended functionalities
 */

snode_t *llist_create_with_data(int *data, int len) {
  int i;
  snode_t *p = llist_create();
  snode_t *tail = p;
  snode_t *tmp = NULL;
  i = 0;
  while(len--) {
    tmp = node_new();
    tmp->data = data[i++];
    tail->next = tmp;
    tail = tmp;
  }
  return p;
}

void llist_append(snode_t *list, int val) {
  llist_insert_before(list, llist_length(list), val);
}

static snode_t *llist_get_node(snode_t *l, int idx) {
  l = l->next;
  while(idx--) {
    l = l->next;
    assert(l);
  }
  return l;
}

void llist_set(snode_t *list, int idx, int val) {
  llist_get_node(list, idx)->data = val;
}

int llist_get(snode_t *list, int idx) {
  return llist_get_node(list, idx)->data;
}

void llist_display(snode_t *l) {
  l = l->next;
  fputs("LList : ", stdout);
  for(; l; l = l->next)
    printf("%d ", l->data);
  putchar('\n');
}
