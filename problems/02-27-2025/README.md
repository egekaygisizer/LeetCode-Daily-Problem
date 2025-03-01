# Problem 873: Length of Longest Fibonacci Subsequence

## Problem Description
Given a strictly increasing array `arr` of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of `arr`. If one does not exist, return 0.

A subsequence is derived from another sequence by deleting any number of elements (including none) from the sequence, without changing the order of the remaining elements.

### Example
**Input:** `arr = [1, 2, 3, 4, 5, 6, 7, 8]`  
**Output:** `5`  
**Explanation:** The longest subsequence that is Fibonacci-like is `[1, 2, 3, 5, 8]`.

## Approach
To solve this problem, we use a **greedy simulation** approach combined with **binary search** for efficiency. Here's the step-by-step plan:

1. **Iterate Over Pairs:** For each possible pair of starting elements `(arr[i], arr[j])`, we attempt to build a Fibonacci-like sequence.
2. **Extend the Sequence:** Starting with the pair `(a, b)`, we check if the next Fibonacci number `(a + b)` exists in the array using binary search.
3. **Update the Length:** If the next number exists, we extend the sequence and continue checking for the next Fibonacci number.
4. **Track the Longest Sequence:** We keep track of the longest Fibonacci-like sequence found during the process.


## Complexity Analysis

### Time Complexity:
The time complexity is **O(N² log N)**, where `N` is the size of the array.

- We iterate over all pairs of starting elements, which takes **O(N²)**.
- For each pair, we use binary search to check for the next Fibonacci number, which takes **O(log N)**.

Thus, the overall time complexity is **O(N² log N)**.

### Space Complexity:
The space complexity is **O(1)**, as we use a constant amount of extra space.

## Key Insights

- **Binary Search Efficiency**: Using binary search to check for the next Fibonacci number significantly improves the efficiency of the solution.
  
- **Greedy Simulation**: By simulating the Fibonacci sequence for each pair of starting elements, we ensure that we find the longest possible sequence.