#include "constants.h"
#include "csv2data.h"
#include "data_types.h"

#include <stdio.h>
#include <string.h>

int count_csv_lines(char* file_path){
  FILE* fp = fopen(file_path, "r");
  char c = '0';
  int count = 0;
  for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count++;

  fclose(fp);

  return count;
}

int count_row_length(char* file_path){
  int row_length = -1;
  FILE* fp = fopen(file_path, "r");
  char buffer[BUFFER_SIZE];

  fgets(buffer, BUFFER_SIZE, fp);
  char* token = strtok(buffer, ",");
  row_length = strlen(token);

  fclose(fp);

  return row_length; 
}

Dataframe* csv2arr(char* file_path) {
  // ironically, num_cols = number of lines in CSV
  int num_cols = count_csv_lines(file_path);

  // length of a row of csv data
  int num_rows = count_row_length(file_path);

  // size of Series pointer to malloc
  size_t sp_size = (num_rows*sizeof(float) + 20*sizeof(char)) * num_cols;

  // initialize Series pointer
  Series* series_pointer = (Series*)malloc(sp_size);
  // header flag to toggle b/w reading name and data
  int header_flag = 0;

  // initialize a file pointer to the csv
  FILE* fp = fopen(file_path, "r");

  // some error checking if it can't find the file
  if (!fp){
    printf("Can't open file\n");
    
  }
  else{
    // creating buffer for reading csv
    char buffer[BUFFER_SIZE];

    // reading csv based on how many lines it has
    for(int i = 0; i < num_cols; i++){
      size_t float_array_size = num_rows*sizeof(float);
      size_t header_size = 20*sizeof(char);
      
       
      fgets(buffer, BUFFER_SIZE, fp);
      char* token = strtok(buffer, ",");
      int num_count = 0;
       
      series_pointer[i].numbers = (float*)malloc(sizeof(float)*num_rows);
      while (token != NULL) {
        if(header_flag == 0){
          strcpy(series_pointer[i].name, token);
          
          token = strtok(NULL, ","); // advance token to next value in column
          header_flag = 1;
        }
        series_pointer[i].numbers[num_count] = atof(token); // putting value into temp array
        token = strtok(NULL, ","); // advance token to next value in column
        num_count++;
        
      }
      header_flag = 0;
    }
    
  }

  fclose(fp);

  size_t data_frame_size = 2*sizeof(size_t) + sizeof(Series*);

  Dataframe* df_pointer = (Dataframe*)malloc(data_frame_size);

  df_pointer->columns = series_pointer;
  df_pointer->num_cols = num_cols;
  df_pointer->num_rows = num_rows;
  printf("COMPLETE DATAFRAME\n");


  return df_pointer;

}
