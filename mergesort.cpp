#include <iostream>

void mergesort(int a[], int l, int h) {
  if (h > l) {
    int size = h - l + 1;
    int m = (l + h) / 2;
    mergesort(a, l, m);
    mergesort(a, m+1, h);
    int* b = new int[size+1];
    int i = l;
    int j = m+1;
    int bi = 0;
    while (i <= m && j <= h) {
      if (a[i] <= a[j])
        b[bi++] = a[i++];
      else
        b[bi++] = a[j++];
    }
    while(i <= m)
      b[bi++] = a[i++];

    while(j <= h)
      b[bi++] = a[j++];

    for (int k = 0; k < size; k++) {
      a[l+k] = b[k];
    }
    delete[] b;
  }
}

void mergesort(int a[], int size) {
  mergesort(a, 0, size-1);
}
