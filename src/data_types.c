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

/*// TODO: Add unicode chars for blocks here, increase code readiblity
typedef struct {
    // cap name at 20 characters for statc compile-time size
    char name[NAME_SPACE];
    float* numbers;
} Series;

typedef struct {
    Series* columns;
    size_t num_cols;
    size_t num_rows;
    // assumes that all columns have the same length -- afaik this is true
} Dataframe;

// WARNING: numblocks is allocated when df_to_count is called, and it should
// be freed when it is done being used.
typedef struct {
    Dataframe* dataframe;
    int* numblocks; // array containing number of 1/8 character-width blocks to plot
    // this array has length dataframe.num_cols
    // Additional peripheral values should be added to this struct such as plot name, colors
} Count;
*/
