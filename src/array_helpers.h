#include <stdlib.h>

/*
 * Given a constant array of floats and the size of the array, determine the 
 * maximum value of the set.
 * 
 * Function first initializes the max variable as the first element of the array. 
 * Then loops through all elements of the array comparing them with the current 
 * local max. Once the loop completes, the current maximum is returned
 * 
 * @param numbers constant array of floats
 * @param size size_t corresponding to the length of numbers array 
 *
 * @return max float variable containing the max of all elements in the array 
 */
float find_max(const float numbers[], size_t size);


/*
 * Given a constant array of floats and the size of the array, determine the 
 * minimum value of the set.
 * 
 * Function first initializes the min variable as the first element of the array. 
 * Then loops through all elements of the array comparing them with the current 
 * local min. Once the loop completes, the current minimum is returned
 * 
 * @param numbers constant array of floats
 * @param size size_t corresponding to the length of numbers array 
 *
 * @return min float variable containing the min of all elements in the array 
 */
float find_min(const float numbers[], size_t size);


/*
 * Given a constant array of floats and the size of the array, determine the 
 * mean value of the set.
 * 
 * Function first initializes a sum variable as the first element of the array. 
 * Then loops through all other elements of the array, adding them with the current 
 * sum. Once the loop completes, the sum is divided by the length of the array and 
 * is returned
 * 
 * @param numbers constant array of floats
 * @param size size_t corresponding to the length of numbers array 
 *
 * @return mean float variable containing the max of all elements in the array 
 */
float find_mean(const float numbers[], size_t size);

/*
 * Given a constant array of floats, the size of the constant array, and the size
 * of the plots width
 *
 */
float find_max_scalar(const float numbers[], size_t size, size_t plot_width);
