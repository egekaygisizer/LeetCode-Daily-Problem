/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    // Build the final value on the first iteration
    for (int i = 0; i < numsSize; ++i) {
        nums[i] += 1000 * (nums[nums[i]] % 1000);
    }
    // Modified to final value on the second iteration
    for (int i = 0; i < numsSize; ++i) {
        nums[i] /= 1000;
    }
    *returnSize = numsSize;
    return nums;
}

Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).