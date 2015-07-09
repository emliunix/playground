#include <stdlib.h>
#include <stdio.h>
#include <string.h> // memcpy
#include <assert.h>

#include "alist.h"

alist_t *alist_create() {
  alist_t *p = NULL;
  /* allocating memory */
  p = (alist_t *)malloc(sizeof(alist_t));
  assert(p != NULL); // memory not allocated

  p->len = 0;
  
  return p;
}

void alist_destroy(alist_t *l) {
  assert(l != NULL); // null pointer
  free(l->data);
  free(l);
}

void alist_insert_before(alist_t *l, int idx, int val) {
  int i;
  assert(l != NULL); // null pointer
  assert(l->len < MAX_SIZE);/* capacity worn out */
  assert(idx >= 0 && idx <= l->len ); // index out of range

  for(i = l->len; i > idx; --i)
    l->data[i] = l->data[i-1];

  l->data[idx] = val;
  ++(l->len);
}

void alist_delete(alist_t *l, int idx) {
  int i;
  assert(l != NULL); // null pointer
  assert(idx >= 0 && idx < l->len); // index out of range

  for(i = idx; i < l->len - 1; ++i)
    l->data[i] = l->data[i+1];

  --(l->len);
}

/*
 * extended funcitonalities
 */

alist_t *alist_create_with_data(int *data, int len) {
  assert(len <= MAX_SIZE);
  alist_t *p = alist_create();
  memcpy(p->data, data, len * sizeof(int));
  p->len = len;
  return p;
}

void alist_append(alist_t *list, int val) {
  alist_insert_before(list, list->len, val);
}

void alist_set(alist_t *l, int idx, int val) {
  assert(idx >= 0 && idx < l->len); // index out of range
  l->data[idx] = val;
}

int alist_get(alist_t *l, int idx) {
  assert(idx >= 0 && idx < l->len);
  return l->data[idx];
}

void alist_display(alist_t *l) {
  int i;
  printf("AList[%d] : ", l->len);
  for(i = 0; i < l->len; ++i)
    printf("%d ", l->data[i]);

  putchar('\n');
}
