#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// İlgili K kadar sorguyla diziyi sıfırlayabiliyor muyuz? Kontrol fonksiyonu
bool canMakeZero(int *nums, int numsSize, int queries[][3], int k, int queriesSize) {
    int *arr = (int *)malloc(numsSize * sizeof(int));
    memcpy(arr, nums, numsSize * sizeof(int)); // nums dizisini kopyala

    int *diff = (int *)calloc(numsSize + 1, sizeof(int)); // Difference array
    for (int i = 0; i < k; i++) {
        int l = queries[i][0], r = queries[i][1], val = queries[i][2];
        diff[l] -= val;
        diff[r + 1] += val;
    }

    int current = 0;
    for (int i = 0; i < numsSize; i++) {
        current += diff[i];  // Prefix sum ile güncellenmiş değeri bul
        if (arr[i] + current > 0) { 
            free(arr);
            free(diff);
            return false;  // Bir eleman bile sıfırlanmadıysa bu k değeri çalışmaz
        }
    }
    
    free(arr);
    free(diff);
    return true;  // Kadar adımda sıfırlayabiliyoruz
}

// Binary Search ile en küçük k'yi bul
int minQueriesToZero(int *nums, int numsSize, int queries[][3], int queriesSize) {
    int left = 0, right = queriesSize, ans = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canMakeZero(nums, numsSize, queries, mid, queriesSize)) {
            ans = mid;  // Kadar adımda sıfırlayabiliyoruz, daha küçük dene
            right = mid - 1;
        } else {
            left = mid + 1; // Daha fazla query lazım
        }
    }
    
    return ans;
}

// Test Case
int main() {
    int nums1[] = {2, 0, 2};
    int queries1[][3] = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int queriesSize1 = sizeof(queries1) / sizeof(queries1[0]);

    printf("Output: %d\n", minQueriesToZero(nums1, size1, queries1, queriesSize1)); // Expected Output: 2

    int nums2[] = {4, 3, 2, 1};
    int queries2[][3] = {{1, 3, 2}, {0, 2, 1}};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int queriesSize2 = sizeof(queries2) / sizeof(queries2[0]);

    printf("Output: %d\n", minQueriesToZero(nums2, size2, queries2, queriesSize2)); // Expected Output: -1

    return 0;
}