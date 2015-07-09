#ifndef ALIST_H
# define ALIST_H

#define MAX_SIZE 128

typedef struct {
  int data[MAX_SIZE];
  int len;
} alist_t;

extern alist_t *alist_create();
extern alist_t *alist_create_with_data(int *data, int len);
extern void alist_destroy(alist_t *list);
extern void alist_insert_before(alist_t *list, int idx, int val);
extern void alist_append(alist_t *list, int val);
extern void alist_delete(alist_t *list, int idx);
extern void alist_set(alist_t *list, int idx, int val);
/* list->data[idx] */
extern int alist_get(alist_t *list, int idx);

extern void alist_display(alist_t *list);

#endif // ALIST_H

