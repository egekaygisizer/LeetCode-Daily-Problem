#include <stdio.h>
#include <stdlib.h>

// Binary search to check if the target number exists in the array
int binarySearch(int* arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return 1;  // find
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // not find
}

// Function to find the length of the longest Fibonacci-like subsequence
int lenLongestFibSubseq(int* arr, int arrSize) {
    int longest = 0;

    // Iterate over pairs of elements in the array
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            int a = arr[i];
            int b = arr[j];
            int fibLen = 2;

            // Try to extend the subsequence
            while (1) {
                int next = a + b;
                if (binarySearch(arr, arrSize, next)) {
                    a = b;
                    b = next;
                    fibLen++;
                } else {
                    break; // Exit the loop if next number is not found
                }
            }

            // Update the longest subsequence length
            if (fibLen > 2 && fibLen > longest) {
                longest = fibLen;
            }
        }
    }

    return longest;
}

// Test
int main(void) {
    int arr[] = {1, 3, 5, 7, 8, 13, 15, 17, 18, 19};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int result = lenLongestFibSubseq(arr, arrSize);
    printf("Longest len: %d\n", result);

    return 0;
}