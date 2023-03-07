#include "../src/data_types.h"
#include "countplot.h"
#include"colors.c"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// TODO: mode into a helper function



static void blocks(int* nblocks){
    // returns a string of length 20 filled with scale many blocks, resolution 1/8.
    char *whole_block = "\U00002588";
    float scale = (float)*nblocks/8;
    int b_ = floor(scale);
    char output[21-b_];
    
    for (int i = 0; i< b_; i++){
        printf("%s", whole_block);
    }
    char *complement = "";
    // determine complement for blocks 
    int state = (int)round((scale - (float)b_)*8);
    switch(state){
        case 1:
            complement = "\U0000258F";
            break;
        case 2:
            complement = "\U0000258E";
            break;
        case 3:
            complement = "\U0000258D";
            break;
        case 4: 
            complement = "\U0000258C";
            break; 
        case 5: 
            complement = "\U0000258B";
            break;
        case 6:
            complement = "\U0000258A";
            break;
        case 7:
            complement = "\U00002589";
            break;
        case 8:
            complement = "\U00002588";
            break;
        case 0:
            // for some godforsaken reason need this case to catch float to int weirdness
            complement = "";
    }
    printf("%s",complement);
    for (int i = 0; i<20-b_;i++){
        printf(" ");
    }
}

int count(Count all, int* num_colors){
    // unsure if this will continue to work with the new structs
    // -- need length of series array
    printf("Number of colors: %i, Number of bars: %i\n", *num_colors,(int)all.length);

    printf("\t\t\U0000250F\n");
    for (int i = 0;i<(int)all.length;i++){
        // name of row
        printf("%s\t", all.values[i]->name);

        printf("\U0000252B");
        switch(i%*num_colors){
            case 6:
                printf(MAG);
                break; 
            case 5:
                printf(WHT);
                break; 
            case 4:
                printf(BLU);
                break; 
            case 3:
                printf(YEL);
                break; 
            case 2:
                printf(CYN);
                break; 
            case 1:
                printf(RED);
                break;
            case 0:
                printf(GRN);
                break;
        }
        blocks(&all.numblocks[i]);
        printf(RESET);
        // value in row
        // TODO: error catch incorrect format of data being handed off.
        printf("\t%f\n",all.values[i]->nums.obs[0]);
    }
    printf("\t\t\U00002517\n");
    return 0;
}

float o[3] = {600.0,200.0,1400.0};
int nb[3];


Series val1= {.name = "TESTtest", .nums = {.obs = &o[0], .size= (size_t)1,}};
Series val2= {.name = "JONATHAN", .nums = {.obs = &o[1], .size= (size_t)1,}};
Series val3= {.name = "JENNIFER", .nums = {.obs = &o[2], .size= (size_t)1,}};
Series* v[3] = {&val1,&val2,&val3};

Count val = {.values = v,.numblocks=0,.length= (size_t)3};
int nc = 4;
int main(void){

    for ( int j = 0; j<sizeof(nb); j++)
    {
        nb[j] = (o[j]/70)*8;
    }
    val.numblocks = nb;
    count(val,&nc);
}
