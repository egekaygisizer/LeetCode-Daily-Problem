
#include <stdio.h>
#include <stdlib.h> 

// Function to apply operations on the given array and return the transformed array
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    
    // Step 1: Apply operations on nums (double the left element and set the right element to 0 if adjacent elements are equal)
    for (int i = 0; i < numsSize - 1; i++) {  
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;  
            nums[i + 1] = 0; 
        }
    }

    // Step 2: Shift all zeros to the end of the array
    int* result = (int*)malloc(numsSize * sizeof(int));  // Dynamically allocate memory for the result array
    int index = 0;

    // Add all non-zero elements to the new result array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            result[index++] = nums[i];  
        }
    }

    // Fill the remaining space in the result array with zeros
    while (index < numsSize) {
        result[index++] = 0;  
    }

    // Set the return size of the result array
    *returnSize = numsSize;
    return result;
}

int main() {
    
    int num[] = {1, 2, 2, 1, 1, 0};  
    int numSize = sizeof(num) / sizeof(num[0]);  // Calculate the size of the input array
    int returnSize;  

    int* result = applyOperations(num, numSize, &returnSize);

    
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);  
    }

    // Free dynamically allocated memory to avoid memory leaks
    free(result);
    
    return 0;
}