#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>


void blocks(float *scale){

    char* whole_block = "\U00002588";
    int b_ = floor(*scale);
    for (int i = 0; i< b_; i++){
        printf("%s", whole_block);
    }
    char *complement = "";
    // determine complement for blocks 
    int state = (int)round((*scale - (float)b_)*8);
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
}


//    int main(void){
//        srand((int) time(NULL));
//
//        float r = 0;
//        for (float j = 0; j<5; j++){
//            printf("\n[ \t");
//            r = (float)rand()/(float)(RAND_MAX/15);
//            blocks(&r);
//            printf("\n");
//        }
//
//
//        return 0;
//    }
