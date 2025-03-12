#include <stdio.h>

// Function to return the maximum count between positive and negative numbers
int maximumCount(int* nums, int numsSize) {
    int posCount = 0, negCount = 0;

    // Traverse the array to count positive and negative numbers
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0)
            posCount++;  // Increment positive count if number is greater than 0
        else if (nums[i] < 0)
            negCount++;  // Increment negative count if number is less than 0
    }

    // Return the maximum of the two counts
    return (posCount > negCount) ? posCount : negCount;
}

// Main function to test the implementation
int main() {
    int nums1[] = {-2, -1, -1, 1, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output: %d\n", maximumCount(nums1, size1)); // Expected Output: 3

    int nums2[] = {-3, -2, -1, 0, 0, 1, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output: %d\n", maximumCount(nums2, size2)); // Expected Output: 3

    int nums3[] = {5, 20, 66, 1314};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Output: %d\n", maximumCount(nums3, size3)); // Expected Output: 4

    return 0;
}