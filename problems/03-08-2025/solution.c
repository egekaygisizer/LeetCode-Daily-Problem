#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

int minimumRecolors(char* blocks, int k) {

    int blocklen = strlen(blocks);
    int minOperations = k;  // In the worst case, we convert all blocks to 'B'
    int currentW = 0;

    // Create the first window of size k
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') {
            currentW++;
        }
    }
    
    minOperations = currentW; // Assume the first window as the minimum

    // Sliding window approach
    for (int i = k; i < blocklen; i++) {
        if (blocks[i - k] == 'W') currentW--;  // If the outgoing element is 'W', decrement
        if (blocks[i] == 'W') currentW++;      // If the incoming element is 'W', increment

        if (currentW < minOperations) {
            minOperations = currentW;
        }
    }

    return minOperations;
}

int main() {
    char blocks[] = "WBBWWBBWBW";
    int k = 7;
    
    int result = minimumRecolors(blocks, k);
    printf("Minimum operations needed: %d\n", result);

    return 0;
}