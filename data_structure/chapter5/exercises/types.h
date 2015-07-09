#ifndef TYPES_H
# define TYPES_H

typedef int el_t;
typedef struct node node_t;
struct node {
  el_t data;
  node_t *next;
};

extern node_t *list_create_with_data(el_t *data, int len);

#endif // TYPES_H
