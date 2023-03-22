#include "constants.h"
#include "data_types.h"

#include <stdlib.h>

int dataframe_free(Dataframe* dataframe) {
  for (size_t col = 0; col < dataframe->num_cols; col++) {
    free(dataframe->columns[col].numbers);
  }

  free(dataframe->columns);
  free(dataframe);

  return 0;
}

int count_free(Count* count) {
  free(count->numblocks);
  dataframe_free(count->dataframe);

  return 0;
}

