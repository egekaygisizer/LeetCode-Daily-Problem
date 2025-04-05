int subsetXORSum(int* nums, int numsSize) 
{
    int xorSum = 0;
    int i;
    
    for (i=0; i<numsSize; i++)
    {
        xorSum |= nums[i];
    }

    xorSum = (xorSum << (numsSize-1));

    return xorSum;    
}