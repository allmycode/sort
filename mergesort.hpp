template <class T>
void mergesort(T a[], size_t l, size_t h) {
  if (h - l == 2) {
    if (a[l] > a[h]) {
      T t = a[l];
      a[l] = a[h];
      a[h] = t;
    }
    return;
  }
  if (h - l == 1) return;
  if (h > l) {
    size_t size = h - l + 1;
    size_t m = l + (h - l) / 2;
    mergesort(a, l, m);
    mergesort(a, m+1, h);
    T* b = new T[size];
    size_t k = 0;
    size_t i = l;
    size_t j = m+1;
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

template <class T>
void mergesort(T a[], size_t size) {
  mergesort(a, 0, size-1);
}
