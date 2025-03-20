## Problem 2226: Maximum Candies Allocated to K Children

## Problem Description
Given an array `candies` where each element represents the number of candies in a pile, we need to distribute these candies among `k` children. Each child must receive the same amount of candies, and each child can only take candies from one pile. We can divide piles into smaller sub-piles but cannot merge them.

The goal is to determine the maximum number of candies that each child can receive.

## Solution Approach
The problem is solved using **binary search** on the possible number of candies (`x`) that each child can receive.

### Steps:
1. **Define the Search Space:**  
   - The minimum possible value (`left`) is `1`, as each child must receive at least one candy.  
   - The maximum possible value (`right`) is the largest pile in `candies`, as a child cannot receive more than the largest available pile.

2. **Binary Search:**  
   - We perform binary search to find the maximum `x` such that at least `k` children can receive candies.
   - The `canDistribute()` function checks whether we can allocate at least `k` children `x` candies each.
   - If distribution is possible for a given `x`, we update `result` and try to maximize `x` (`left = mid + 1`).
   - Otherwise, we reduce `right = mid - 1` to find a feasible value.

3. **Time Complexity:**  
   - Sorting is **O(n)** (finding max in `candies`).  
   - Binary search runs in **O(log max(candies))**.  
   - Checking feasibility using `canDistribute()` runs in **O(n)**.  
   - Overall, the complexity is **O(n log max(candies))**, making it efficient for large inputs.

## Edge Cases Considered
- If `k = 0`, no children exist, so the result is `0`.
- If total candies are less than `k`, no child can receive candies (`return 0`).
- If a single pile is significantly larger, binary search efficiently determines the maximum possible split.