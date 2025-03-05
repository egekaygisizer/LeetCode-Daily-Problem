#include <stdio.h>


/* First i solved this way (line 16) but i learned the other is more efficiency

long long coloredCells(int n) {
    long long total = 1;
    for (int i = 0; i < n; i++){
        total += i << 2;
    } 
    return total;
}

*/

long long coloredCells(int n) {
    long long r = n;
    return 1+ 2*r*(r-1);
}

int main() {
    int test_cases[] = {1, 2, 3, 4, 5, 10, 100000}; // Example test cases
    int size = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < size; i++) {
        int n = test_cases[i];
        printf("n = %d --> %lld\n", n, coloredCells(n));
    }

    return 0;
}