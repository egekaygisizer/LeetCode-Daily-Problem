#include <stdio.h>
#include <stdlib.h>


int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {

    // Maximum possible size: nums1Size + nums2Size (all elements could be different)
    int** result = (int**)malloc((nums1Size + nums2Size) * sizeof(int*));  
    *returnColumnSizes = (int*)malloc((nums1Size + nums2Size) * sizeof(int));  

    int i = 0, j = 0, k = 0;

    // Merging both arrays while comparing elements
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i][0] == nums2[j][0]) {
            result[k] = (int*)malloc(2 * sizeof(int));  
            result[k][0] = nums1[i][0];  
            result[k][1] = nums1[i][1] + nums2[j][1]; 
            i++; j++;  
        } else if (nums1[i][0] < nums2[j][0]) {
            result[k] = (int*)malloc(2 * sizeof(int));  
            result[k][0] = nums1[i][0];  
            result[k][1] = nums1[i][1];  
            i++;  
        } else {
            result[k] = (int*)malloc(2 * sizeof(int));  
            result[k][0] = nums2[j][0];  
            result[k][1] = nums2[j][1];  
            j++;  
        }
        (*returnColumnSizes)[k] = 2;  
        k++;  
    }

    // Add remaining elements from nums1, if any
    while (i < nums1Size) {
        result[k] = (int*)malloc(2 * sizeof(int));  
        result[k][0] = nums1[i][0];  
        result[k][1] = nums1[i][1];
        (*returnColumnSizes)[k] = 2;  
        i++; k++;  
    }

    // Add remaining elements from nums2, if any
    while (j < nums2Size) {
        result[k] = (int*)malloc(2 * sizeof(int));  
        result[k][0] = nums2[j][0]; 
        result[k][1] = nums2[j][1];  
        (*returnColumnSizes)[k] = 2; 
        j++; k++;  
    }

    *returnSize = k;  
    return result;  
}

int main() {
    // Test case
    int nums1[3][2] = {{1, 2}, {2, 3}, {4, 5}}; 
    int nums2[3][2] = {{1, 4}, {3, 2}, {4, 1}}; 
    int nums1Size = 3, nums2Size = 3;  
    
    int **nums1Ptr = (int**)malloc(nums1Size * sizeof(int*));
    int **nums2Ptr = (int**)malloc(nums2Size * sizeof(int*));
    
    // Copying nums1 and nums2 arrays into the allocated pointers
    for (int i = 0; i < nums1Size; i++) {
        nums1Ptr[i] = nums1[i];  
    }
    for (int i = 0; i < nums2Size; i++) {
        nums2Ptr[i] = nums2[i];  
    }

    int returnSize;
    int *returnColumnSizes;

    int **result = mergeArrays(nums1Ptr, nums1Size, NULL, nums2Ptr, nums2Size, NULL, &returnSize, &returnColumnSizes);

    printf("Result:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);  
    }

    // Freeing allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);  
    }
    free(result);  
    free(returnColumnSizes); 
    free(nums1Ptr);  
    free(nums2Ptr);  

    return 0;
}