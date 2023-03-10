/**
 * Utilites to parse CSVs for clotter implementation
 */
#pragma once

#include <string.h>
#include "data_types.h"
static const char WHITESPACE[] = " \f\n\r\t\v";

/**
 * Reads data in the following format:
 * 
 * SOURCE_1,val_1, val_2, val_3, val_4,...
 * SOURCE_2,val_1, val_2, val_3, val_4,...
 * SOURCE_3,val_1, val_2, val_3, val_4,...
 * .
 * .
 * .
 *
 * @param filepath // assuming LINUX for now
 */
Dataframe* csv2arr(char* file_path);
