#include <stdio.h>

int checkPowersOfThree(int n) {
    int powers[20];  // Array to store powers of 3
    int i = 0, value = 1;

    // // calculate power of 3
    while (value <= 10000000) {
        powers[i] = value;
        value *= 3; 
    }

    // Try to form n by subtracting the largest possible powers of 3
    for (int j = i - 1; j >= 0; j--) {
        if (n >= powers[j]) {
            n -= powers[j];  // subtract the largest power from n
        }
    }

    return (n == 0); // Is n totally reduced to 0 ?
}

int main() {
    int test_cases[] = {12, 91, 21, 10, 30}; // Test cases
    int size = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < size; i++) {
        int n = test_cases[i];
        printf("n = %d --> %s\n", n, checkPowersOfThree(n) ? "true" : "false");
    }

    return 0;
}