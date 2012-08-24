#include <iostream>

const int size = 10;

int* createData();

int main(int argc, char* argv[]) {
  int* data = createData();
  for (int i = 0; i < size; i++)
    std::cout << data[i] << ",";
  return 0;
}


int* createData() {
  int* data = new int[size];
  return data;
}
