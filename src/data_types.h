#pragma once

#include <stdlib.h>

typedef struct{
    float* obs;
    size_t size;
}Data;

typedef struct {
    char *name;
    Data nums;
}Series;

typedef struct {
    Series **values;
    int *numblocks;
    size_t length;
}Count;
