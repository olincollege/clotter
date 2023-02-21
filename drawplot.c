#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"blocks.c"
#include"colors.c"

int width =100;

int main(void){
    srand((unsigned int)time(NULL));
    for (int i = 0;i<width;i++){
        float x = (float)rand()/(float)(RAND_MAX/20);
        switch(i%7){
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
        printf(RESET "\n");
    }


}
