# Problem 2873: Maximum Value of an Ordered Triplet I

- You are given a 0-indexed integer array nums.
- Return the maximum value over all triplets of indices (i, j, k) such that `i < j < k`. If all such triplets have a negative value, `return 0.`
- The value of a triplet of indices `(i, j, k)` is equal to `(nums[i] - nums[j]) * nums[k]`.

## Brute Force Approach
1. **Triple Nested Loop**:
   - Outer loop (i): 0 to n-3
   - Middle loop (j): i+1 to n-2
   - Inner loop (k): j+1 to n-1
2. **Compute Value**:
   - For each valid (i,j,k) combination:
     - Calculate `current = (nums[i] - nums[j]) * nums[k]`
     - Track maximum value found
3. **Edge Handling**:
   - Return 0 if maximum value is negative

# Complexity Analysis
Time: O(n^3) - Brute Force | 3 for loop
Space: O(1)
