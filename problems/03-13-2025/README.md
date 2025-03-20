# Problem 3356: Zero Array Transformation II

## Problem Statement
Given an integer array `nums` of length `n` and a 2D array `queries`, where `queries[i] = [li, ri, vali]`, each query represents the following operation:

- Decrease the value at each index in the range `[li, ri]` by **at most** `vali`.
- The decrement for each index can be chosen independently.
- A **Zero Array** is an array where all elements are `0`.

Return the **minimum possible non-negative value of `k`** such that after processing the first `k` queries in sequence, `nums` becomes a Zero Array.  
If no such `k` exists, return `-1`.

---

### Example :

**Input:**  
nums = [2, 0, 2]
queries = [[0, 2, 1], [0, 2, 1], [1, 1, 3]]  
**Output:**  
2  
**Explanation:**
1. Apply first query: `[0, 2, 1]`  
   - Decrement values at indices `[0, 1, 2]` by `[1, 0, 1]` → `nums = [1, 0, 1]`
2. Apply second query: `[0, 2, 1]`  
   - Decrement values at indices `[0, 1, 2]` by `[1, 0, 1]` → `nums = [0, 0, 0]`  
   - `nums` is now a Zero Array → Minimum `k = 2`.

---

## Constraints:
- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 5 * 10^5`
- `1 <= queries.length <= 10^5`
- `queries[i].length == 3`
- `0 <= li <= ri < nums.length`
- `1 <= vali <= 5`

---

## Solution Approach

### **1. Binary Search on `k` (Minimum Query Count)**
- We use **Binary Search** to find the smallest `k` for which `nums` becomes a Zero Array.
- This reduces time complexity to **O(N log M)**.

### **2. Difference Array for Efficient Range Updates**
- Instead of iterating over every query, we use a **difference array** to apply updates in `O(1)`.
- This optimizes the update step, preventing TLE (Time Limit Exceeded).

---