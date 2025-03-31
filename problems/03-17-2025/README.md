# Problem 2206: Divide Array Into Equal Pairs

## Problem Description 
You are given an integer array `nums` consisting of `2 * n` integers.
 You need to divide nums into n pairs such that:  
- Each element belongs to exactly one pair.
- The elements present in a pair are equal.
`Return true` if nums can be divided into n pairs, otherwise `return false.`

## Approach   
1. **Sorting Method**: Sort the array and check if adjacent elements form valid pairs.  
2. **Frequency Method**: Count occurrences of each element and verify all counts are even.

## Time and Space Complexity 
**English**:  
| Method               | Time Complexity   | Space Complexity  |
|----------------------|-------------------|-------------------|
| Sorting              | O(n log n)        | O(1)              |
| Frequency Counting   | O(n²)             | O(1)              |