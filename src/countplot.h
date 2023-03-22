#pragma once

#include "../src/data_types.h"

/*
 * Plots a Count plot in the terminal from given data in a Dataframe struct.
 *
 * Takes the number of 1/8 character Unicode blocks from the Count object
 * and plots that number of blocks. Names for each row and actual values are
 * taken from the Dataframe object that Count stores a pointer to.
 *
 * num_colors should never be zero.
 *  
 * @param count A Count struct that contains plotting information and the data.
 * @param num_colors The number of different colors the plot uses.
 *
 * @return An integer 0 if the program was successful and 1 if it was not. 
 */
int display_count(Count count, int num_colors);

/* Take a pointer for a Dataframe object and turn that object into a Count.
 *
 * This function looks into the pointer at the Dataframe and does the analysis
 * necessary to determine the number of 1/8 Unicode blocks to plot the data
 * in the terminal.
 *
 * The Dataframe object is not consumed or changed, and the Count object that
 * is returned contains the same pointer to the Dataframe.
 *
 * @param dataframe A pointer to the dataframe to be analyzed.
 * 
 * @return A Count object containing information needed to display a count plot.
 */
Count df_to_count(Dataframe* dataframe);
