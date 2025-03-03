#include <stdio.h>
#include <stdlib.h>

// Function to rearrange the array based on the pivot value
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    
    // Allocate memory for three separate arrays
    int* smaller = (int*)malloc(numsSize * sizeof(int)); // Stores elements smaller than pivot
    int k = 0;

    int* equal = (int*)malloc(numsSize * sizeof(int));   // Stores elements equal to pivot
    int l = 0;

    int* larger = (int*)malloc(numsSize * sizeof(int));  // Stores elements greater than pivot
    int m = 0;

    int i = 0;

    // Traverse the input array and categorize numbers into three groups
    while (i < numsSize) {
        if (nums[i] < pivot) {
            smaller[k] = nums[i];
            k++, i++;
        } else if (nums[i] == pivot) {
            equal[l] = nums[i];
            l++, i++;
        } else { // nums[i] > pivot
            larger[m] = nums[i];
            m++, i++;
        }
    }

    // Allocate memory for the final result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    int n = 0;

    // Copy elements from the 'smaller' array into 'result'
    for (int a = 0; a < k; a++) {
        result[n] = smaller[a];
        n++;
    }
    // Copy elements from the 'equal' array into 'result'
    for (int a = 0; a < l; a++) {  
        result[n] = equal[a];
        n++;
    }
    // Copy elements from the 'larger' array into 'result'
    for (int a = 0; a < m; a++) { 
        result[n] = larger[a];
        n++;
    }

    // Free allocated memory for temp arrays
    free(smaller);
    free(equal);
    free(larger);

    *returnSize = numsSize; // Return the size of the final array
    return result;
}

int main() {
    // Example input array and pivot value
    int nums[] = {9, 12, 5, 10, 14, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int pivot = 10;
    
    int returnSize;
    
    // Call the function and get the result
    int* result = pivotArray(nums, numsSize, pivot, &returnSize);
    
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    // Free allocated memory for the result array
    free(result);

    return 0;
}