/* Программа, которая формирует списки данных по 
   определенным критериям и запускает на них различные сортировки
   для сравнения и подсчета статистики
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "sort.h"
#include "../libcpp/measurer.h"

using namespace std;

struct MeasureData {
  string sort;
  string type;
  int    size;
  double timeInSeconds;
  long   assignments;
  long   comparsions;
};


static long comparsions;
static long assignments;

static vector<MeasureData> md;

class TestInt {
public:
  int value;

  TestInt& operator= (const TestInt& rhs) {
    assignments++;
    this->value = rhs.value;
    return *this;
  }

  TestInt& operator= (const int i) {
    assignments++;
    this->value = i;
    return *this;
  }

  friend bool operator> (const TestInt& i1, const TestInt& i2);
  friend bool operator>= (const TestInt& i1, const TestInt& i2);
  friend bool operator< (const TestInt& i1, const TestInt& i2);
  friend bool operator<= (const TestInt& i1, const TestInt& i2);   
};

bool operator> (const TestInt& i1, const TestInt& i2) {
  comparsions++;
  return i1.value > i2.value;
}
bool operator>= (const TestInt& i1, const TestInt& i2)  {
  comparsions++;
  return i1.value >= i2.value;
}

bool operator< (const TestInt& i1, const TestInt& i2)  {
  comparsions++;
  return i1.value < i2.value;
}

bool operator<= (const TestInt& i1, const TestInt& i2)  {
  comparsions++;
  return i1.value <= i2.value;
}

void resetCounters() {
  assignments = 0;
  comparsions = 0;
}

void measure(const string& sort, const string& type, int size) {
  TestInt* data = new TestInt[size];
  if (type == "random") {
    for (int i = 0; i < size; i++) 
      data[i].value = rand();
  } else if (type == "sorted") {
    for (int i = 0; i < size; i++)
      data[i].value = i;
  } else if (type == "revers") {
    for (int i = 0; i < size; i++) 
      data[i] = size - i;
  }
  
  resetCounters();
  
  MeasureData dt;
  dt.sort = sort;
  dt.type = type;
  dt.size = size;

  measurer m;
  if (sort == "quick") {
    quicksort(data, size);
  } else if (sort == "merge") {
    mergesort(data, size);
  } else if (sort == "heap") {
    heapsort(data, size);
  }
  dt.timeInSeconds = m.seconds();
  dt.assignments = assignments;
  dt.comparsions = comparsions;
  
  md.push_back(dt);
  delete [] data;
}
  
int main(int argc, const char* argv[]) {
  string sorts[] = {"quick", "merge", "heap"};
  const int sortsLen = sizeof(sorts)/sizeof(string);
  string types[] = {"random", "sorted", "revers"};
  const int typesLen = sizeof(types)/sizeof(string);
  int sizes[] = {10000000};
  const int sizesLen = sizeof(sizes)/sizeof(int);
  for (int is = 0; is < sortsLen; ++is) 
    for (int it = 0; it < typesLen; ++it)
      for (int sz = 0; sz < sizesLen; ++sz) 
        measure(sorts[is], types[it], sizes[sz]);
  

  
  cout << "sort" << "\t" << "type" << "\t" << "size" << "\t"
         << "sec" << "\t" << "assign" << "\t" << "compar" 
         << "\t"<< "total" << endl;

  for (vector<MeasureData>::iterator it = md.begin(); it < md.end(); ++it)
    cout << it->sort << "\t" << it->type << "\t" << it->size << "\t"
         << it->timeInSeconds << "\t" << it->assignments << "\t" << it->comparsions 
         << "\t"<< it->assignments + it->comparsions << "\t" << (it->assignments + it->comparsions) / it->size << endl;
  return 0;
}
