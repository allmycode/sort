#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "util.hpp"
//#include "mergesort.hpp"
#include "mergesort.hpp"
#include "sys/time.h"

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int argc, const char* argv[]) {
  srand(42);

  const int files = 7;
  const int power = 6;
  int* dt[power][files];
  int pow = 10;
  // read all data
  for (int i = 0; i < power; i++) {
    for (int j = 0; j < files; j++) {
      std::stringstream fnames;
      fnames << "tstdata" << j << "." << i + 1 << ".tst";
      std::string fname = fnames.str();
      std::ifstream f(fname.c_str(), std::ios::binary);
      dt[i][j] = new int[pow];
      for (int k = 0; k < pow && !f.eof(); k++) {
        int data = 0;
        f.read((char *)&data, sizeof(int));
        dt[i][j][k] = data;
      }
    }
    pow *= 10;
  }

  pow = 10;
  std::cout << "Start tests ..." << std::endl;
  // do tests
  for (int i = 0; i < power; i++) {
    for (int j = 0; j < files; j++) {
      timestamp_t t0 = get_timestamp();
      mergesort(dt[i][j], pow);
      timestamp_t t1 = get_timestamp();

      double secs = (t1 - t0) / 1000000.0L; 
      std::cout << "Test " << j << " on " << i << " took " << std::setprecision(4) << secs << " seconds" << std::endl;

    }
    pow *= 10;
  }
  std::cout << "Finished tests ..." << std::endl;


  // clean up
  for (int i = 0; i < power; i++) {
    for (int j = 0; j < files; j++) {
      delete[] dt[i][j];
    }
  }
  
  return 0;
}
