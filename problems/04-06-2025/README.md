# Problem 368: Largest Divisible Subset

## Problem Description
Given a set of distinct positive integers `nums`, return the largest subset where for every pair of elements in the subset:
- `answer[i] % answer[j] == 0` OR
- `answer[j] % answer[i] == 0`

If multiple solutions exist, return any valid subset.

## Approach
1. **Sorting**:
   - First sort the array in ascending order to establish divisibility order

2. **Dynamic Programming**:
   - `dp[i]`: Length of largest divisible subset ending at nums[i]
   - `prev[i]`: Index of previous element in the subset
   - Initialize all `dp[i] = 1` and `prev[i] = -1`

3. **DP Transition**:
   - For each element nums[i], check all previous elements nums[j] (j < i)
   - If nums[i] is divisible by nums[j] and dp[j] + 1 > dp[i]:
     - Update dp[i] = dp[j] + 1
     - Set prev[i] = j
   - Track maximum subset length and its ending index

4. **Backtracking**:
   - Reconstruct the subset using the prev array starting from maxIndex

## Complexity Analysis
- Time: O(n^2)     
- |pace: O(n)       