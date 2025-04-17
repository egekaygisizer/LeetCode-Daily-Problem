bool isDistinct(int *nums,int numsSize, int index) {
    for(int i = index; i < numsSize -1; i++) {
        for(int j = i+1; j < numsSize; j++) {
            if(nums[i] == nums[j]) return false;
        }
    }
    return true;
}

int minimumOperations(int* nums, int numsSize) {
    if (isDistinct(nums, numsSize, 0)) return 0;
    int ans = 0;

    for(int i = 0; i < numsSize;i += 3) {
        if (isDistinct(nums, numsSize, i)) return ans;
        ans++;
    }

    return ans;
}