#include <iostream>

const int SIZE = 10;

int* makeTestArray();

int main(int argc, char* argv[]) {
  int* data = makeTestArray();
  for (int i = 0; i < SIZE; i++)
    std::cout << data[i] << ",";
  return 0;
}


int* makeTestArray() {
  int* data = new int[SIZE];
  return data;
}
