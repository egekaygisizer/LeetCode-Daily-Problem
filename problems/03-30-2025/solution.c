#include <stdio.h>
#include <stdlib.h>

int* partitionLabels(char* s, int* returnSize) {
    int* lastIndex = (int*) calloc(26, sizeof(int));
    int* ans = NULL;

    for(int i = 0; s[i] != '\0'; ++i) {
        lastIndex[s[i] - 'a'] = i;
    }

    int start = 0, end = 0, size = 0;
    for(int i = 0; s[i] != '\0'; ++i) {
        end = end > lastIndex[s[i] - 'a'] ? end : lastIndex[s[i] - 'a'];

        if (i == end) {
            ans = (int*) realloc(ans, (size + 1) * sizeof(int));
            ans[size++] = end - start + 1;
            start = i + 1;
        }
    }

    free(lastIndex);
    *returnSize = size;
    return ans;
}