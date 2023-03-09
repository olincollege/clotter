#include "csv2data.h"
#include <stdio.h>

int main() {

  char* str = "../test/test.csv";
  //printf("Number of line: %d\n", count_csv_lines(str));
  csv2arr(str);

  return 0;
}
