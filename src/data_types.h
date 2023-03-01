#pragma once

#include <stdlib.h>

typedef struct{
    float* obs;
    size_t size;
}Data;

typedef struct {
    char name[50];
    Data nums;
}Series;

typedef struct {
    Series *values;
    int *numblocks;
    size_t blength;
    size_t vlength;
}Count;
