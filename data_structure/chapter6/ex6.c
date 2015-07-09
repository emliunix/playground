#include <stdio.h>

typedef struct mat_s {
  int (*data)[][3];
  int size;
} mat_t;

int sum_diag(mat_t *mat) {
  int i, sum = 0;
  for(i = 0; i < mat->size; ++i) {
    if((*mat->data)[i][0] == (*mat->data)[i][1])
      sum += (*mat->data)[i][2];
  }
  return sum;
}

int Mdata[5][3] = {
  {0, 0, 1},
  {1, 0, 1},
  {0, 1, 1},
  {23, 23, 1},
  {50, 50, 5}
};

mat_t M = {&Mdata, 5};
/* sparse matrix */
struct s_mat {
  int nrow, ncol;
  int data[];
};

void main() {
  printf("SUM: %d\n", sum_diag(&M));
}
