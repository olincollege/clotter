#include "csv2data.h"
#include "data_types.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

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

Dataframe* csv2arr(char* file_path) {

  // initialize Dataframe and number of rows
  Dataframe output; 
  
  output.num_rows = count_csv_lines(file_path);
  Series total_series[output.num_rows];
  int series_count = 0;

  int header_flag = 0;

  // initialize a file pointer to the csv
  FILE* fp = fopen(file_path, "r");

  // some error checking if it can't find the file
  if (!fp){
    printf("Can't open file\n");
    
  }

  else {
    // make a char buffer to read data into
    char buffer[BUFFER_SIZE];
    
    do {
      // reads from file into buffer
      fgets(buffer, BUFFER_SIZE, fp);

      // actually breaks at the end of file
      if(feof(fp)){
        break;
      }

      char* token = strtok(buffer, ",");
      
      // sets Dataframe length if not initialized
     // if(output.num_cols == NULL){
     //   output.num_cols = strlen(token);
     //   printf("B\n");
     // }
      
      output.num_cols = strlen(token);
    // initialize Series struct
      Series s;
      
      float array[output.num_cols];
    
      int col_count = 0;
      while (token != NULL) {
        if(header_flag == 0){
          strcpy(s.name, token);
          token = strtok(NULL, ","); // advance token to next value in column
          header_flag = 1;
        }

        array[col_count] = atof(token); // putting value into temp array
        token = strtok(NULL, ","); // advance token to next value in column
        col_count++;
        
      }

      // reset header flag to recognize next row name
      header_flag = 0;
      s.numbers = array; // check &// assigning Series numbers object temp array

      total_series[series_count] = s; // add series into Dataframe
      series_count++;

    } while (!feof(fp));
    fclose(fp);
  }
  output.columns = total_series;
  return &output;

}
