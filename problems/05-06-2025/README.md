# 1920. Build Array from Permutation

## Problem Description

You are given a **zero-based permutation** array `nums`.

Your task is to build an array `ans` of the same length where:
**ans[i] = nums[nums[i]]**
for each index `0 <= i < nums.length`, and return it.

> A zero-based permutation `nums` is an array of **distinct integers** from `0` to `nums.length - 1` (inclusive).

---

## Approach

- The key idea is to avoid using extra space by encoding both the original value and the target value in the same array element.
- In the **first pass**, we store both values by modifying `nums[i]` as:  
  `nums[i] += N * (nums[nums[i]] % N)`  
  where `N` is a number greater than any element in `nums` (1000 is safe here).
- This stores the new value in a way that can be retrieved later.
- In the **second pass**, we divide each element by `N` to extract the final value:  
  `nums[i] /= N`
- This trick allows in-place transformation without extra memory allocation.

---

## Complexity

- **Time Complexity:** `O(n)`  
  The array is traversed twice — once for encoding and once for decoding.

- **Space Complexity:** `O(1)`  
  No additional space is used; transformation is done in-place.
