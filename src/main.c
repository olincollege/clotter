#include <stdio.h>
#include <unistd.h>

/*
getopt stuff copied from here:
https://www.tutorialspoint.com/getopt-function-in-c-to-parse-command-line-arguments
*/

int main(int argc, char *argv[]) {
   int option;
   // put ':' at the starting of the string so compiler can distinguish between '?' and ':'
   while((option = getopt(argc, argv, ":ic:f:t:rx")) != -1){ //get option from the getopt() method
      switch(option){
         
         // number of colors to be used
         case 'c':
            printf("number of colors: %s\n", optarg);
            break;

        // type of plot desired by user
        case 't':
            printf("plot type:: %s\n", optarg);
            break;
         case 'i':
         case 'l':

         
         case 'r':
            printf("Given Option: %c\n", option);
            break;
            
        // path to csv file
         case 'f': //here f is used for some file name
            printf("csv file: %s\n", optarg);
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
}
