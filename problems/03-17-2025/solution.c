
// in this problem i think & solved 2 way of solution


// Solution 1 (Sorting Approach)
int s(const void* a, const void* b)
{
    return (*((int*)a) - *((int*)b));
}
bool divideArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), s);

    for (int i = 1; i < numsSize; i += 2)
    {
        if (nums[i] != nums[i - 1])
        {
            return false;
        }
    }

    return true;
}

// Solution 2 (Frequency Counting Approach)
bool divideArray(int* nums, int numsSize) {
    
    for(int i =0; i< numsSize; i++) {
        int freq = 0;
        for (int j = 0; j < numsSize; j++) {
            if(nums[i] == nums[j]) freq++;
        }
        if (freq % 2 == 1) {
            return false;
        }
    }

    return true;
}