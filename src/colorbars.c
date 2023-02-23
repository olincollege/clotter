#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"blocks.c"
#include"colors.c"

const int num_bars =10;
const int num_colors = 4;

int main(void){
    srand((unsigned int)time(NULL));
    printf("Number of colors: %i, Number of bars: %i\n", num_colors,num_bars);

    printf("\t\t\U0000250F\n");
    for (int i = 0;i<num_bars;i++){
        float x = (float)rand()/(float)(RAND_MAX/20);
        printf("%f\t",x);
        printf("\U0000252B");
        switch(i%num_colors){
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
        blocks(&x);
        printf(RESET);
        printf("\t%f\n",x);
    }
    printf("\t\t\U00002517\n");
    return 0;
}

