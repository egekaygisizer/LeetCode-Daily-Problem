#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the Longest Common Subsequence (LCS) table
void longestCommonSubsequence(char* str1, char* str2, int n, int m, int** dp) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Initialize the first row and column to 0
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; // If characters match, increase the LCS length
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]; // Take the maximum value from the top or left
            }
        }
    }
}

// Function to find the Shortest Common Supersequence (SCS)
char* shortestCommonSupersequence(char* str1, char* str2) {
    int n = strlen(str1), m = strlen(str2);
    int i = n, j = m;

    // Allocate memory for the LCS table
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int k = 0; k <= n; k++) {
        dp[k] = (int*)malloc((m + 1) * sizeof(int));
    }

    // Fill the LCS table
    longestCommonSubsequence(str1, str2, n, m, dp);

    // Allocate memory for the result string
    char* scs = (char*)malloc(sizeof(char) * (n + m + 1)); // Maximum possible length
    if (!scs) return NULL; // Check memory allocation

    int index = 0;

    // Backtrack through the LCS table to construct the SCS
    while (i > 0 && j > 0) {
        if (str1[i-1] == str2[j-1]) { // If characters match, take one of them
            scs[index++] = str1[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) { // If LCS value comes from the top, take character from str1
            scs[index++] = str1[i-1];
            i--;
        } else { // Otherwise, take character from str2
            scs[index++] = str2[j-1];
            j--;
        }
    }

    // Add remaining characters from str1 and str2
    while (i > 0) scs[index++] = str1[--i];
    while (j > 0) scs[index++] = str2[--j];

    scs[index] = '\0'; // Null-terminate the string

    // Reverse the string since we built it backwards
    for (int k = 0; k < index / 2; k++) {
        char temp = scs[k];
        scs[k] = scs[index - k - 1];
        scs[index - k - 1] = temp;
    }

    return scs;
}

int main(void) {
    char* result = shortestCommonSupersequence("abac", "cab");
    if (result != NULL) {
        printf("%s\n", result); // Print the SCS result
    } else {
        printf("Error: Memory allocation failed\n");
    }
    return 0;
}
