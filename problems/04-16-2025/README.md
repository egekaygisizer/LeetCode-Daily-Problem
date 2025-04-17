# Count Good Triplets

## Problem Description

Given an array of integers `arr`, and three integers `a`, `b`, and `c`, return the number of good triplets.

A triplet `(arr[i], arr[j], arr[k])` is considered good if the following conditions are all true:
- `0 <= i < j < k < arr.length`
- `|arr[i] - arr[j]| <= a`
- `|arr[j] - arr[k]| <= b`
- `|arr[i] - arr[k]| <= c`

Where `|x|` denotes the absolute value of `x`.

### Example 1:
Input: `arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3`  
Output: `4`  
Explanation: The good triplets are (3,0,1), (3,0,1), (3,1,1), and (0,1,1)

### Example 2:
Input: `arr = [1,1,2,2,3], a = 0, b = 0, c = 1`  
Output: `0`

---

## Approach

We use a brute-force approach with three nested loops to iterate through all possible triplets `(i, j, k)` where `i < j < k`. For each triplet, we check whether it satisfies all three given conditions. If it does, we increment a counter.

## Complexity
* Time Complexity: O(n³)
Since we check all combinations of triplets using three nested loops, the time complexity is cubic. This is acceptable given the constraint n <= 100.

* 	Space Complexity: O(1)
No additional space is used except for counters and loop variables.