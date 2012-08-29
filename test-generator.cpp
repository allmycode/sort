#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "util.hpp"

int main(int argc, const char *argv[]) {
  srand(42);

  const int files = 7;
  const int power = 6;

  int pow = 10;
  for (int i = 0; i < power; i++) {
    for (int j = 0; j < files; j++) {
      std::stringstream fnames;
      fnames << "tstdata" << j << "." << i + 1 << ".tst";
      std::string fname = fnames.str();
      std::cout << "file: " << fname << std::endl;
      std::ofstream f(fname.c_str(), std::ios::binary);
      for (int k = 0; k < pow; k++) {
        int data = rand() % 100;
        f.write((const char *)&data, sizeof(int));
      }
    }
    pow *= 10;
  }

  return 0;
}
