#include "csv2data.h"
#include <stdio.h>

int main() {

  char* str = "../test/test.csv";
  //printf("Number of line: %d\n", count_csv_lines(str));
  Dataframe *data = csv2arr(str);
  printf("numcols: %zu",data->num_cols);
  printf("\nnumrows: %zu",data->num_rows);
  printf("\nfirstcol: %s", data->columns[0].name);

  //printf("Row length test: %d\n", count_row_length(str));
  return 0;
}
