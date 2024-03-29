#include <math.h>
#include <stdlib.h>

float find_max(const float numbers[], size_t size) {
  float max = numbers[0];
  for (size_t i = 1; i < size; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  return max;
}

float find_min(const float numbers[], size_t size) {
  float min = numbers[0];
  for (size_t i = 1; i < size; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }

  return min;
}

float find_mean(const float numbers[], size_t size) {
  float sum = numbers[0];
  for (size_t i = 1; i < size; i++) {
    sum += numbers[i];
  }

  return sum / (float)size;
}

float find_max_scalar(const float numbers[], size_t size, size_t plot_width) {
  float max = find_max(numbers, size);

  if (max <= 0) {
    max = find_min(numbers, size);
  }

  float scalar = (float)plot_width / max;

  return scalar;
}
