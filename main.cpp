#include <iostream>
#include <cstdlib>

const int SIZE = 10;

int* makeTestArray();

int getRandom(int n);

int main(int argc, char* argv[]) {
  srand(time(NULL));

  int* data = makeTestArray();
  for (int i = 0; i < SIZE; i++)
    std::cout << data[i] << ",";
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
