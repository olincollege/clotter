/**
 * Utilites to parse CSVs for clotter implementation
 */
#pragma once

#include "data_types.h"
#include <string.h>
static const char WHITESPACE[] = " \f\n\r\t\v";

/**
 * Counts the number of rows in a .csv by iterating through the entire file
 * 
 * @param file_path // (i.e. /data/test_02/sensor_ouput.csv)
 * @return an integer equal to the number of rows in the .csv
*/
int count_csv_lines(char* file_path);


/**
 * Counts the number of items in a row in a .csv (assuming all rows are the same size)
 * 
 * @param file_path // (i.e. /data/test_02/sensor_ouput.csv)
 * @return an integer equal to the number of items in a row, not include the header (i.e. amount of actual data)
*/
int count_row_length(char* file_path);

/**
 * Reads data from a .csv file in the following format:
 * 
 * SOURCE_1,val_1, val_2, val_3, val_4,...
 * SOURCE_2,val_1, val_2, val_3, val_4,...
 * SOURCE_3,val_1, val_2, val_3, val_4,...
 * 
 * (i.e. a row formatted .csv)
 * 
 * 
 * 
 *
 * @param file_path // (i.e. /data/test_02/sensor_ouput.csv)
 * @return a Dataframe struct  
 */
Dataframe* csv2arr(char* file_path);
