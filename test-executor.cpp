#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "util.hpp"
#include "mergesort.hpp"
#include "../libcpp/measurer.h"

const int TRIES = 1;
const int MIN_POWER = 5;
const int MAX_POWER = 7;
int* dt[MAX_POWER - MIN_POWER + 1][TRIES];

void prepareTestData() {
  srand(42);
  int size = pow(10, MIN_POWER);
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j < TRIES; j++) {
      int*a = dt[i][j] = new int[size];
      for (int k = 0; k < size; k++)
        a[k] = rand() % 100;
    }
    size *= 10;
  }
}

void doTests() {
  srand(42);
  int size = pow(10, MIN_POWER);
  std::cout << "Start tests ..." << std::endl;
  // do tests
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j < TRIES; j++) {
      measurer m;
      mergesort(dt[i][j], size);

      std::cout << "Test " << j << " on " << size << " took " << std::setprecision(4) << 
        m.seconds() << " seconds" << std::endl;

    }
    size *= 10;
  }

  std::cout << "Finished tests ..." << std::endl;
}

void cleanUp() {
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j < TRIES; j++) {
      delete[] dt[i][j];
    }
  }
}

int main(int argc, const char* argv[]) {

  prepareTestData();

  doTests();
  
  cleanUp();

  return 0;
}
