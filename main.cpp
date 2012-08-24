#include <iostream>
#include <cstdlib>

const int SIZE = 10;

int* makeTestArray();

int getRandom(int n);

void printArray(const char* name, int a[], int size);

void init() {
  srand(time(NULL));
}

int main(int argc, char* argv[]) {
  init();

  int* data = makeTestArray();
  printArray("unsorted", data, SIZE);
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
