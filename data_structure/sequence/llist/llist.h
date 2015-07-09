#ifndef LLIST_H
# define LLIST_H

#define DEFAULT_DATA -1

typedef struct snode_s snode_t; // singlely linked node type
struct snode_s {
  int data;
  snode_t *next;
};

extern snode_t *llist_create();
extern void llist_destroy(snode_t *list);
extern void llist_insert_before(snode_t *list, int idx, int val);
extern void llist_delete(snode_t *list, int idx);
extern int llist_length(snode_t *list);

extern snode_t *llist_create_with_data(int *data, int len);

extern void llist_append(snode_t *list, int val);

extern void llist_set(snode_t *list, int idx, int val);
extern int llist_get(snode_t *list, int idx);

extern void llist_display(snode_t *list);

#endif // LLIST_H

