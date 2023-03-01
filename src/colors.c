#include <string.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

char* red(char* dst, const char* str) {
  // concatenate codes for string to show up as red
  strcat(dst, RED);
  strcat(dst, str);
  strcat(dst, RESET);
  return dst;
}
