#include "csv2data.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void csv2arr(char* file_path){

    // initialize a file pointer to the csv
	FILE* fp = fopen(file_path, "r");

    // some error checking if it can't find the file
	if (!fp)
		printf("Can't open file\n");

	else {
		// make a char buffer to read data into
		char buffer[BUFFER_SIZE];

		while (feof(fp) != 1)
        {
            fgets(buffer, BUFFER_SIZE, fp);
            printf("Row: %s", buffer);

            char* token = strtok(buffer, ",");

            while(token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, ",");
            }
        }

    }
}



