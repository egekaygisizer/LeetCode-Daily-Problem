#include <stdlib.h>

int countGoodTriplets(int* arr, int n, int a, int b, int c) {
    int ans = 0, i, j, k;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) <= a) {
                for (k = j + 1; k < n; k++) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        ans++;
                }
            }
        }
    }

    return ans;
}

