#include <stdio.h>

typedef struct matrix_s matrix_t;
struct matrix_s {
  int nrow, ncol;
  int *data;
};

int mat_get(matrix_t *mat, int x, int y) {
  return mat->data[y*mat->ncol + x];
}

int find_val(matrix_t *mat, int val, int *row, int *col) {
  int i;
  for(i = 0; i < mat->nrow * mat->ncol; ++i)
    if(mat->data[i] == val) {
      *row = i / mat->ncol;
      *col = i % mat->nrow;
      return 1;
    }
  return 0;
}

void main() {
  matrix_t mat;
  int row, col;
  int data[] = {1,2,3,4, 2,3,4,6, 3,4,5,7, 4,6,7,8};
  mat.ncol = mat.nrow = 4;
  mat.data = data;
  if(find_val(&mat, 5, &row, &col)) {
    printf("FOUND: (%d, %d)\n", col, row);
  } else {
    printf("NOT FOUND\n");
  }
}
