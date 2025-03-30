# Problem 2780: Minimum Index of a Valid Split

## Problem Description
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
You are given a 0-indexed integer array nums of length n with one dominant element.
You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

## Solution Approach
1. Find the dominant element using an efficient voting algorithm
2. Count how many times this element appears in the full array
3. Scan through the array to find the first valid split point where:
   - The left part has the dominant element as its majority
   - The right part also has it as majority

## Complexity

- Time: `O(n)` - We make three passes through the array

- Space: `O(1)` - Uses only a few variables for counting