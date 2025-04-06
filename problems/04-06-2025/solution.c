/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void*a, const void* b){
    return (*(int*)a-*(int*)b);
}
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    qsort(nums,numsSize,sizeof(int),cmp);

    int* dp = (int*)malloc(numsSize*sizeof(int));
    int* prev = (int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        dp[i] = 1;
        prev[i] = -1;
    }
    
    int maxLen = 1;
    int maxIndex = 0;

    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if((nums[i] %nums[j] == 0) && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
                prev[i] = j;
            }
        }
        if(dp[i]> maxLen){ 
            maxLen = dp[i];
            maxIndex = i;
        }
    }
    int* result = (int*)malloc(maxLen*sizeof(int));
    int pos = maxLen-1;
    for(int i=maxIndex;i>=0;i=prev[i]){
        result[pos--] = nums[i];
        if(prev[i] == -1) break;
    }
    *returnSize = maxLen;
    free(dp);
    free(prev);
    return result;
}