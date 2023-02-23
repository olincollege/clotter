//#include <stdio.h>
#include <string.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

char* red(char* dst,const char* str){
    // concatenate codes for string to show up as red
    strcat(dst, RED);
    strcat(dst, str);
    strcat(dst,RESET);
    return dst;
}

//    int main() {
//        printf(RED "red\n"     RESET);
//        printf(GRN "green\n"   RESET);
//        printf(YEL "yellow\n"  RESET);
//        printf(BLU "blue\n"    RESET);
//        printf(MAG "magenta\n" RESET);
//        printf(CYN "cyan\n"    RESET);
//        printf(WHT "white\n"   RESET);
//        char * test = "HELLO WORLD";
//        char dest[(int)strlen(test)];
//        printf("%s",red(dest, test));
//        return 0;
//    }
