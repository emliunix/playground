#include <stdio.h>

#define G(data, x, y) (data)[(y) * 5 + x]

int data[] = {
  1,  2,  6,  7, 15,
  3,  5,  8, 14, 16,
  4,  9, 13, 17, 22,
  10, 12, 18, 21, 23,
  11, 19, 20, 24, 25
};

int
find_val_region(int *data, int x, int y, int offx, int offy, /* data & region */
		int val, /* target value */
		int *ox, int *oy /* output */) {

  int px, py, pval, tmpx, tmpy;
  if(offx == 0 || offy == 0) return 0;
  px = offx / 2;
  py = offy / 2;
  pval = G(data, x+px, y+py);
  if(offx == 1 && offy == 1)
    if(pval == val) {
      *ox = x;
      *oy = y;
      return 1;
    } else
      return 0;

  if(pval == val) {
    *ox = x + px;
    *oy = y + py;
    return 1;
  } else if(val < pval) {
    // top left
    if(find_val_region(data, x, y, px, py, val, &tmpx, &tmpy))
      goto FOUND;
  } else {
    // bottom right
    if(find_val_region(data, x+px, y+py, offx-px, offy-py, val, &tmpx, &tmpy))
      goto FOUND;
  }

  // top right
  if(find_val_region(data, x+px, y, offx-px, py, val, &tmpx, &tmpy))
    goto FOUND;
  // bottom left
  if(find_val_region(data, x, y+py, px, offy-py, val, &tmpx, &tmpy))
    goto FOUND;

  return 0; /* Not found */
  
 FOUND:
  *ox = tmpx;
  *oy = tmpy;
  return 1;
}

int
find_val(int *data, int offx, int offy,
	 int val,
	 int *ox, int *oy) {
  return find_val_region(data, 0, 0, offx, offy, val, ox, oy);
}

void main() {
  int i;
  for(i = 0; i < 30; ++i) {
    int x, y;
    if(find_val(data, 5, 5, i, &x, &y))
      printf("%2d: (%d, %d)\n", i, x, y);
    else
      printf("%2d: None\n", i);
  }
}
