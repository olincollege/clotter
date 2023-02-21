#include <stdlib.h>

float find_max(float numbers[], size_t size) {
  float max = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  return max;
}

float find_min(float numbers[], size_t size) {
  float min = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }

  return min;
}
