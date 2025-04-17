# Problem 3396: Minimum Number of Operations to Make Elements in Array Distinct

## Problem Description

Given an integer array nums, your task is to make all the elements distinct.
You are allowed to perform the following operation any number of times:

- Remove the first 3 elements of the array.
- If fewer than 3 elements remain, remove all of them.

Return the minimum number of operations required to make the array elements distinct.

An empty array is considered to have all distinct elements.


## Approach

- Start from the beginning of the array and simulate removing the first 3 elements in each operation.
- After each removal, check if the remaining part of the array contains only distinct elements.
- Continue this process until the remaining elements are all unique.
- Return the number of operations performed.

## Complexity

* Time Complexity: O(n^2), due to nested loops when checking for duplicates.
* Space Complexity: O(1), as no additional data structures are used except counters.