#include <stdio.h>

// Function to check if it's possible to distribute candies such that each child gets at least `x`
int canDistribute(int *candies, int candiesSize, long long k, long long x) {
    long long count = 0;  
    for (int i = 0; i < candiesSize; i++) {
        count += candies[i] / x; 
        if (count >= k) return 1; 
    }
    return 0;
}

// Function to find the maximum candies each child can receive using binary search
int maximumCandies(int* candies, int candiesSize, long long k) {
    if (k == 0) return 0; // If there are no children, return 0

    long long left = 1, right = 0, mid, result = 0;

    // Determine the maximum possible candy size (`right`) from the largest pile
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > right) right = candies[i];
    }

    // Binary search to find the optimal `x`
    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (canDistribute(candies, candiesSize, k, mid)) {
            result = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

// Main function for testing
int main() {
    int candies1[] = {5, 8, 6};
    int k1 = 3;
    printf("Output: %d\n", maximumCandies(candies1, 3, k1));
    int candies2[] = {2, 5};
    long long k2 = 11;
    printf("Output: %d\n", maximumCandies(candies2, 2, k2)); 

    return 0;
}