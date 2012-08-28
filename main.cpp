#include <iostream>
#include <cstdlib>

#include "mergesort.hpp"
#include "bubblesort.hpp"

const int SIZE = 1000;

int* makeTestArray();

int getRandom(int n);

void printArray(const char* name, int a[], int size);

void init() {
  srand(time(NULL));
}

void sort(int a[], int size);

bool checkSort(int a[], int size);

int main(int argc, char* argv[]) {
  init();

  int* data = makeTestArray();
  //  printArray("unsorted", data, SIZE);
  sort(data, SIZE);
  // printArray("sorted", data, SIZE);
  if (checkSort(data, SIZE))
    std::cout << "OK" << std::endl;
  else
    std::cout << "Fail" << std::endl;

  delete[] data;
  return 0;
}


int* makeTestArray() {
  int* data = new int[SIZE];
  for (int i = 0; i < SIZE; i++)
    data[i] = getRandom(100);
  return data;
}

int getRandom(int n) {
  return rand() % n;
}

void printArray(const char* name, int a[], int size) {
  if (name)
    std::cout << name << ": ";
  if (size > 0)
    std::cout << a[0];
  for (int i = 1; i < size; i++)
    std::cout << "," << a[i];

  std::cout << std::endl;
}

void sort(int a[], int size) {
  //bubblesort(a, size);
  mergesort(a, size);
}

bool checkSort(int a[], int size) {
  for (int i = 0; i < size-1; i++) {
    if (a[i] > a[i+1])
      return false;
  }
  return true;
}
