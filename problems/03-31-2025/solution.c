// Comparator function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to compute the difference between max and min scores
long long putMarbles(int *weights, int weightsSize, int k) {
    if (k == 1 || weightsSize == k) return 0;
    
    
    int pairSums[weightsSize - 1];
    for (int i = 0; i < weightsSize - 1; i++) {
        pairSums[i] = weights[i] + weights[i + 1];
    }
    
    // Sort the pair sums
    qsort(pairSums, weightsSize - 1, sizeof(int), compare);
    
    long long minSum = 0, maxSum = 0;
    for (int i = 0; i < k - 1; i++) {
        minSum += pairSums[i];
        maxSum += pairSums[weightsSize - 2 - i];
    }
    
    return maxSum - minSum;
}