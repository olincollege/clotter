#include "countplot.h"
#include "csv2data.h"
#include <stdio.h>
#include <unistd.h>

/*
getopt stuff copied from here:
https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
*/

int main(int argc, char *argv[]) {
  // setting vars to write all arguments into
  char* file_path;
  char* plot_type;
  int num_colors;

  // need to set flags so we don't get a seg-fault if we try to read a value of 
  // an optional arg that was not given
  int fflag = 0;
  int cflag = 0;
  int tflag = 0;

  extern char *optarg;
  extern int optind;
  int option;
  // put ':' at the starting of the string so compiler can distinguish between '?' and ':'
  while((option = getopt(argc, argv, "c:f:t:")) != -1){ //get option from the getopt() method
      switch(option){
          
          // number of colors to be used
          case 'c':
              //num_colors = (atoi(optarg));
              break;

          // type of plot desired by user
          case 't':
              tflag = 1;
              plot_type = optarg;
              break;
  
          // path to csv file
          case 'f': 
              fflag = 1;
              file_path = optarg;
              break;
          case ':':
              printf("option needs a value\n");
              break;
          case '?': //used for some unknown options
              printf("unknown option: %c\n", optopt);
              printf("please use \"-f\" for file paths\n");
              break;
      }
  }
  for(; optind < argc; optind++){ //when some extra arguments are passed
      printf("Given extra arguments: %s\n", argv[optind]);
  }

  if(tflag){
      printf("plot type: %s\n", plot_type);
  }
  
  if(fflag){
      printf("path to csv: %s\n", file_path);
  }
  
  Dataframe *csvdata = csv2arr(file_path);
  Count c = df_to_count(csvdata);
  display_count(c,4);
  count_free(&c);
}
