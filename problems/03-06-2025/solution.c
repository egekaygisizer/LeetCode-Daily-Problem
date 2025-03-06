#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {

    int freq[gridSize*gridSize + 1]; 
    memset(freq, 0, sizeof(freq)); 

    // Count occurrences of each number in the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            freq[grid[i][j]]++; 
        }
    }

    // Identify the repeated and missing numbers
    int repeat, missing;
    for (int i = 1; i <= gridSize*gridSize; i++) {
        if (freq[i] == 2) repeat = i;
        if (freq[i] == 0) missing = i;
    }

    // Store results in dynamically allocated array
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));  
    result[0] = repeat;
    result[1] = missing;
    return result;   

}


int main() {
    // Define test case: grid = [[1,3], [2,2]]
    int n = 2;
    int gridData[2][2] = {{1, 3}, {2, 2}};  

    // Allocate memory for grid pointers
    int** grid = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = gridData[i][j];
        }
    }

    // Call function
    int returnSize;
    int* result = findMissingAndRepeatedValues(grid, n, NULL, &returnSize);

    // Results
    printf("Repeated Number: %d\n", result[0]);
    printf("Missing Number: %d\n", result[1]);

    // Free allocated memory
    free(result);
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}