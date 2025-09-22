#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_COUNT 50000
#define MIN_VAL 1
#define MAX_VAL 100000

void swap (int *array, int i, int j) //swap function for bubble sort and quick sort
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int partition(int *array, int low, int high) //for quick sort
{
    int pivot = array[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, high);
    return (i + 1);
}

void generate_data(int *data_array, int count) {
    /**
    Generates an array of random numbers in memory.
    This represents the 'serial' or non-optimizable part of our program.
    **/
    printf("Generating %d random numbers...\n", count);
    for (int i = 0; i < count; i++) {
        data_array[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
    }
}

// --- Algorithm Implementations ---

void unoptimized_algorithm(int *data, int count) { //bubble sort
    /**
    TODO: Implement your chosen 'slow' or unoptimized algorithm here.
    Example: Bubble Sort for an array of numbers.
    The function should take the data array and its size as input
    and sort the array in place.
    **/
    
    // --- Your unoptimized algorithm implementation goes here ---

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (data[j] > data[j+1])
            swap(data, j, j+1);
        }
    }
}

void optimized_algorithm(int *data, int low, int high) { //quick sort
    /**
    TODO: Implement your chosen 'fast' or optimized algorithm here.
    Example: Quick Sort or Merge Sort for an array of numbers.
    The function should take the data array and its size as input
    and sort the array in place.
    **/

    // --- Your optimized algorithm implementation goes here ---
    if (low < high) {
        int pivot = partition(data, low, high);
        optimized_algorithm(data, low, pivot - 1);
        optimized_algorithm(data, pivot + 1, high);
    }
}

// --- Main Analysis ---

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for our data arrays
    int *data1 = (int *)malloc(DATA_COUNT * sizeof(int));
    int *data2 = (int *)malloc(DATA_COUNT * sizeof(int));
    
    if (data1 == NULL || data2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\n--- Running Unoptimized Version ---\n");

    // Time the entire process for the unoptimized version
    clock_t start_total_unoptimized = clock();
    
    // Serial part: Generating data in memory
    generate_data(data1, DATA_COUNT);
    
    // Processing part: This is the part we are 'optimizing'
    clock_t start_processing_unoptimized = clock();
    unoptimized_algorithm(data1, DATA_COUNT);
    clock_t end_processing_unoptimized = clock();
    
    clock_t end_total_unoptimized = clock();

    double total_processing_unoptimized = (double)(end_processing_unoptimized - start_processing_unoptimized) / CLOCKS_PER_SEC; //calculating processing time
    double total_unoptimized = (double)(end_total_unoptimized - start_total_unoptimized) / CLOCKS_PER_SEC; //calculating total time

    // TODO: Calculate the time differences for the unoptimized run in seconds.
    //       - Use variables of type 'double' to store the times.
    //       - Total time = (double)(end_total_unoptimized - start_total_unoptimized) / CLOCKS_PER_SEC;
    //       - Processing-only time = (double)(end_processing_unoptimized - start_processing_unoptimized) / CLOCKS_PER_SEC;
    //       - Print both calculated times so you can record them for your report.


    printf("\n--- Running Optimized Version ---\n");

    // Time the entire process for the optimized version
    clock_t start_total_optimized = clock();

    // Serial part: Generating data in memory
    generate_data(data2, DATA_COUNT);

    // Processing part: Using the optimized function
    clock_t start_processing_optimized = clock();
    optimized_algorithm(data2, 0, DATA_COUNT - 1);
    clock_t end_processing_optimized = clock();
    
    clock_t end_total_optimized = clock();

    double total_processing_optimized = (double)(end_processing_optimized - start_processing_optimized) / CLOCKS_PER_SEC; //calculating processing time
    double total_optimized = (double)(end_total_optimized - start_total_optimized) / CLOCKS_PER_SEC; //calculating total time

    printf("\n--- Timing Results ---\n");
    printf("Unoptimized Total Time: %.6f seconds\n", total_unoptimized);
    printf("Unoptimized Processing Time: %.6f seconds\n", total_processing_unoptimized);
    printf("Optimized Total Time: %.6f seconds\n", total_optimized);
    printf("Optimized Processing Time: %.6f seconds\n", total_processing_optimized);

    // TODO: Calculate the time differences for the optimized run in seconds.
    //       - Calculate the total execution time.
    //       - Calculate the processing-only time.
    //       - Print both calculated times so you can record them for your report.


    // --- Calculations for the Report ---
    printf("\n--- Amdahl's Law Analysis Data ---\n");

    // TODO: Students, use your calculated timing data to find the following factors.
    //       You will need to define variables for your timings (e.g., t_total_unoptimized)
    //       to perform these calculations in your code or manually for the report.
    // 1. Calculate P (Proportion of optimizable code):
    //    P = t_processing_unoptimized / t_total_unoptimized
    //
    double P = total_processing_unoptimized / total_unoptimized;
    // 2. Calculate S (Speedup of the optimized part):
    //    S = t_processing_unoptimized / t_processing_optimized
    //
    double S = total_processing_unoptimized / total_processing_optimized;
    // 3. Calculate the Measured Overall Speedup:
    //    Measured Speedup = t_total_unoptimized / t_total_optimized
    //
    double Measured_Speedup = total_unoptimized / total_optimized;
    // 4. Calculate the Theoretical Overall Speedup using Amdahl's Law:
    //    Theoretical Speedup = 1 / ((1 - P) + (P / S))
    //
    double Theoretical_Speedup = 1 / ((1 - P) + (P / S));

    // 5. Compare the Measured and Theoretical speedups in your report and discuss.

    printf("Proportion of Optimizable Code (P): %.6f\n", P);
    printf("Speedup of Optimized Part (S): %.6f\n", S);
    printf("Measured Overall Speedup: %.6f\n", Measured_Speedup);
    printf("Theoretical Overall Speedup (Amdahl's Law): %.6f\n", Theoretical_Speedup);
    // Free the allocated memory
    free(data1);
    free(data2);

    return 0;
}
