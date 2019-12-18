#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>

#include "util.hpp"
#include "sort.h"
#include "../libcpp/measurer.h"

const int TRIES = 1;
const int MIN_POWER = 5;
const int MAX_POWER = 8;
int* dt[MAX_POWER - MIN_POWER + 1][TRIES];

void prepareTestData() {
  srand(4222);
  int size = pow(10, MIN_POWER);
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j < TRIES; j++) {
      int*a = dt[i][j] = new int[size];
      for (int k = 0; k < size; k++)
        a[k] = rand();
    }
    size *= 10;
  }
}

void doTests(std::string sortname) {
  int size = pow(10, MIN_POWER);
  std::cout << "Start tests " << sortname << " ..." << std::endl;
  // do tests
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j < TRIES; j++) {
      measurer m;
      if ("quick" == sortname)
        quicksort(dt[i][j], size);
      else if ("merge" == sortname)
        mergesort(dt[i][j], size);
      else
        heapsort(dt[i][j], size);

      std::cout << "Test " << j << " on " << size << " took " << std::setprecision(4) << 
        m.seconds() << " seconds" << std::endl;

    }
    size *= 10;
  }

  std::cout << "Finished tests ..." << std::endl;
}

void cleanUp() {
  for (int i = MIN_POWER; i <= MAX_POWER; i++) {
    for (int j = 0; j <= TRIES; j++) {
      delete[] dt[i][j];
    }
  }
}

int main(int argc, const char* argv[]) {

  std::string sortname = "quick";

  if (argc > 1)
    sortname = argv[1];

  prepareTestData();

  doTests(sortname);
  
  cleanUp();
  delay(100);

  return 0;
}
