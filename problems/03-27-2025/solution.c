
int minimumIndex(int* nums, int numsSize) {
    int dominant = nums[0], count = 1;

    // Find dominant num
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == dominant) count++;
        else if(--count <= 0) {
            dominant = nums[i];
            count = 1;
        }
    }
    
    // Count dominant num
    int total = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == dominant) total++;
    }
    
    // Find available split point
    int left_count = 0;
    for(int i = 0; i < numsSize-1; i++) {
        if(nums[i] == dominant) left_count++;
        
        int right_count = total - left_count;
        
        if(left_count * 2 > (i+1) && right_count * 2 > (numsSize-i-1)) {
            return i;
        }
    }
    
    return -1;
}