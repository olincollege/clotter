#include "constants.h"
#include "csv2data.h"
#include "data_types.h"
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

int count_csv_lines(char* file_path){
  FILE* fop = fopen(file_path, "re");
  signed char next_char = '0';
  int count = 0;
  for (next_char = (signed char)getc(fop); next_char != EOF; next_char = (signed char)getc(fop)){
        if (next_char == '\n'){ // Increment count if this character is newline
            count++;
        }

  }

  (void)fclose(fop);

  return count;
}

int count_row_length(char* file_path){
  size_t row_length = 1;
  FILE* fop = fopen(file_path, "re");
  char buffer[BUFFER_SIZE];

  (void)fgets(buffer, BUFFER_SIZE, fop);
  char* token = strtok(buffer, ",");
  row_length = strlen(token);

  (void)fclose(fop);

  return (int)row_length; 
}

Dataframe* csv2arr(char* file_path) {
  // ironically, num_cols = number of lines in CSV
  int num_cols = count_csv_lines(file_path);

  // length of a row of csv data
  int num_rows = count_row_length(file_path);

  // size of Series pointer to malloc
  // NOLINTNEXTLINE(*-magic-numbers)
  size_t sp_size = ((size_t)num_rows*sizeof(float) + 20*sizeof(char)) * (size_t)num_cols;

  // initialize Series pointer
  Series* series_pointer = (Series*)malloc(sp_size);
  // header flag to toggle b/w reading name and data
  int header_flag = 0;

  // initialize a file pointer to the csv
  FILE* fop = fopen(file_path, "re");

  // some error checking if it can't find the file
  if (!fop){
    printf("Can't open file\n");
    
  }
  else{
    // creating buffer for reading csv
    char buffer[BUFFER_SIZE];

    // reading csv based on how many lines it has
    for(int i = 0; i < num_cols; i++){
      size_t float_array_size = (size_t)num_rows*sizeof(float);
      size_t header_size = 20*sizeof(char);
      
       
      (void)fgets(buffer, BUFFER_SIZE, fop);
      char* token = strtok(buffer, ",");
      int num_count = 0;
       
      series_pointer[i].numbers = (float*)malloc(sizeof(float)*(size_t)num_rows);
      while (token != NULL) {
        if(header_flag == 0){
          strcpy(series_pointer[i].name, token);
          
          token = strtok(NULL, ","); // advance token to next value in column
          header_flag = 1;
        }
        series_pointer[i].numbers[num_count] = strtof(token, NULL); // putting value into temp array
        token = strtok(NULL, ","); // advance token to next value in column
        num_count++;
        
      }
      header_flag = 0;
    }
    
  }

  fclose(fop);

  size_t data_frame_size = 2*sizeof(size_t) + sizeof(Series*);

  Dataframe* df_pointer = (Dataframe*)malloc(data_frame_size);

  df_pointer->columns = series_pointer;
  df_pointer->num_cols = (size_t)num_cols;
  df_pointer->num_rows = (size_t)num_rows;


  return df_pointer;

}
