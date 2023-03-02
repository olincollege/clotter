#include "../src/countplot.c"
#include "../src/data_types.h"
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include <stdlib.h>

// TODO: make tests for small parts of this file

float o[3] = {30.0,10.0,70.0};
Series val1= {.name = "TEST", .nums = {.obs = &o[0], .size= (size_t)1,}};
Series val2= {.name = "JONATHAN", .nums = {.obs = &o[1], .size= (size_t)1,}};
Series val3= {.name = "JENNIFER", .nums = {.obs = &o[2], .size= (size_t)1,}};
Series* v[3] = {&val1,&val2,&val3};

Count val = {.values = v,.numblocks=0,.length= (size_t)3};

Test(countplot,3lines){
    

    //cr_assert();
}
