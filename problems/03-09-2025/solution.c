#include <stdio.h>

int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int count = 0;

    // Check all start point
    for (int start = 0; start < colorsSize; start++) {
        int isAlternating = 1;

        // Check window length k (Sliding Window)
        for (int i = 1; i < k; i++) {
            int curr = (start + i) % colorsSize;
            int prev = (start + i - 1) % colorsSize;

            if (colors[curr] == colors[prev]) {
                isAlternating = 0;
                break;
            }
        }

        if (isAlternating) count++;
    }

    return count;
}

int main() {
    int colors1[] = {0, 1, 0, 1, 0};
    int n1 = 5, k1 = 3;
    printf("Test 1: %d\n", numberOfAlternatingGroups(colors1, n1, k1)); 

    int colors2[] = {1, 1, 0, 1};
    int n2 = 4, k2 = 4;
    printf("Test 2: %d\n", numberOfAlternatingGroups(colors2, n2, k2)); 

    return 0;
}