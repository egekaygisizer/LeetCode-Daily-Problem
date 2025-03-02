#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 /*
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {

    int** result = (int*)malloc(returnSize);

    for (int i = 0; i <nums1Size; i++) {
        for(int j = 0; j < nums2Size; j++) {
            if(nums1[i][0] == nums2[j][0]) {
                result[i][1] = nums1[i][1] + nums2[j][1];
            } else if(nums1[i][0] < nums2[j][0]) {
                result[i][1] = nums1[i][1];
            } else if(nums1[i][0] > nums2[j][0]) {
                result[i][1] = nums2[j][1];
            }
            
        }
    }
    
}
*/

int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {

// Maksimum olası boyut: nums1Size + nums2Size (tüm elemanlar farklı olabilir)
int** result = (int**)malloc((nums1Size + nums2Size) * sizeof(int*));
*returnColumnSizes = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

int i = 0, j = 0, k = 0;

while (i < nums1Size && j < nums2Size) {
if (nums1[i][0] == nums2[j][0]) {
// Aynı id varsa, değerleri topla
result[k] = (int*)malloc(2 * sizeof(int));
result[k][0] = nums1[i][0];
result[k][1] = nums1[i][1] + nums2[j][1];
i++; j++;
} else if (nums1[i][0] < nums2[j][0]) {
// Sadece nums1 elemanını ekle
result[k] = (int*)malloc(2 * sizeof(int));
result[k][0] = nums1[i][0];
result[k][1] = nums1[i][1];
i++;
} else {
// Sadece nums2 elemanını ekle
result[k] = (int*)malloc(2 * sizeof(int));
result[k][0] = nums2[j][0];
result[k][1] = nums2[j][1];
j++;
}
(*returnColumnSizes)[k] = 2;
k++;
}

// Kalan elemanları ekleyelim
while (i < nums1Size) {
result[k] = (int*)malloc(2 * sizeof(int));
result[k][0] = nums1[i][0];
result[k][1] = nums1[i][1];
(*returnColumnSizes)[k] = 2;
i++; k++;
}

while (j < nums2Size) {
result[k] = (int*)malloc(2 * sizeof(int));
result[k][0] = nums2[j][0];
result[k][1] = nums2[j][1];
(*returnColumnSizes)[k] = 2;
j++; k++;
}

*returnSize = k;  // Toplam kaç eleman eklendiği bilgisi
return result;
}

int main() {
    // Test örneği
    int nums1[3][2] = {{1, 2}, {2, 3}, {4, 5}};
    int nums2[3][2] = {{1, 4}, {3, 2}, {4, 1}};
    int nums1Size = 3, nums2Size = 3;
    
    // Bellek ayırıyoruz
    int **nums1Ptr = (int**)malloc(nums1Size * sizeof(int*));
    int **nums2Ptr = (int**)malloc(nums2Size * sizeof(int*));
    
    // nums1 ve nums2 dizilerini pointer'lara taşıyoruz
    for (int i = 0; i < nums1Size; i++) {
        nums1Ptr[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; i++) {
        nums2Ptr[i] = nums2[i];
    }

    // Sonuç için gerekli değişkenler
    int returnSize;
    int *returnColumnSizes;

    // Fonksiyonu çağırıyoruz
    int **result = mergeArrays(nums1Ptr, nums1Size, NULL, nums2Ptr, nums2Size, NULL, &returnSize, &returnColumnSizes);

    // Sonuçları yazdırıyoruz
    printf("Result:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }

    // Bellek temizliği
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    free(nums1Ptr);
    free(nums2Ptr);

    return 0;
}