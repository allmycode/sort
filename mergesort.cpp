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
    int c = 0;
    while (i <= m && j <= h) {
      if (a[i] <= a[j])
        b[c++] = a[i++];
      else
        b[c++] = a[j++];
    }
    while(i <= m)
      b[c++] = a[i++];

    while(j <= h)
      b[c++] = a[j++];

    for (int k = 0; k < size; k++) {
      a[l+k] = b[k];
    }
    delete[] b;
  }
}

void mergesort(int a[], int size) {
  mergesort(a, 0, size-1);
}
