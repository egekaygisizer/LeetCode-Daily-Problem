# Problem 2874: Maximum Value of an Ordered Triplet II

- You are given a 0-indexed integer array nums.
- Return the maximum value over all triplets of indices (i, j, k) such that `i < j < k`. If all such triplets have a negative value, `return 0.`
- The value of a triplet of indices `(i, j, k)` is equal to `(nums[i] - nums[j]) * nums[k]`.

## Optimized Approach (O(n) Time)
1. **Precompute Arrays**:
   - `leftMax[i]`: Maximum value to the left of index i
   - `rightMax[i]`: Maximum value to the right of index i

2. **Single Pass Calculation**:
   - For each middle index j (1 ≤ j ≤ n-2):
     - Use precomputed leftMax[j] and rightMax[j]
     - Calculate `(leftMax[j] - nums[j]) * rightMax[j]`
     - Track maximum value foundue is negative

# Complexity Analysis
Time: O(n) - Three linear passes through the array
Space: O(n)
