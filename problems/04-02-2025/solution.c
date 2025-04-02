long long maximumTripletValue(int* nums, int numsSize) {
    
    int i,j,k;
    long long result = 0;

    for (i = 0; i < numsSize - 2; i++) {
        for (j = i+1; j < numsSize - 1; j++) {
            for(k = j+1; k < numsSize; k++) {
                long long temp = (long long)(nums[i] - nums[j]) * nums[k];
                if (temp > result) { 
                    result = temp;
                }
            }
        }
    }

    return result;
    
}