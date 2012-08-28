#include <iostream>

void mergesort(int a[], int l, int h) {
  if (h > l) {
    int size = h - l + 1;
    int m = l + (h - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m+1, h);
    int* b = new int[size+1];
    int i = l;
    int j = m+1;
    int k = 0;
    while (i <= m && j <= h)
      if (a[i] <= a[j])
        b[k++] = a[i++];
      else
        b[k++] = a[j++];

    while(i <= m)
      b[k++] = a[i++];

    while(j <= h)
      b[k++] = a[j++];

    for (k = 0; k < size; k++) {
      a[l+k] = b[k];
    }
    delete[] b;
  }
}

void mergesort(int a[], int size) {
  mergesort(a, 0, size-1);
}
