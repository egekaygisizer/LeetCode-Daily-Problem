#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000000 

// Sieve of Eratosthenes for prime number detection
void sieve(bool* isPrime, int maxLimit) {
    for (int i = 0; i <= maxLimit; i++) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= maxLimit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxLimit; j += i) {
                isPrime[j] = false; // Mark all multiples of i as non-prime
            }
        }
    }
}

// Function to find the closest prime pair in a given range
int* closestPrimes(int left, int right, int* returnSize) {
    bool isPrime[MAX + 1];
    sieve(isPrime, right); // Generate primes up to 'right' using Sieve of Eratosthenes

    int prevPrime = -1, num1 = -1, num2 = -1;
    int minDiff = MAX + 1;

    // Iterate through the range to find the closest prime pair
    for (int i = left; i <= right; i++) {
        if (isPrime[i]) {
            if (prevPrime != -1 && (i - prevPrime) < minDiff) {
                num1 = prevPrime;
                num2 = i;
                minDiff = i - prevPrime; // Update the closest prime pair
            }
            prevPrime = i; // Update the previous prime
        }
    }

    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    if (num1 == -1) {
        result[0] = result[1] = -1;  // No valid prime pair found
    } else {
        result[0] = num1;
        result[1] = num2;
    }
    return result;
}

// Test function
int main() {
    int returnSize;
    int left = 10, right = 19;
    int* result = closestPrimes(left, right, &returnSize);

    printf("Output: [%d, %d]\n", result[0], result[1]);
    free(result); // Free allocated memory
    return 0;
}