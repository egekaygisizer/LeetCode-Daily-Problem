# Problem 2529: Maximum Count of Positive and Negative Integers

## Problem Statement
Given an array `nums` sorted in non-decreasing order, return the maximum count between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in `nums` is `pos` and the number of negative integers is `neg`, then return the maximum of `pos` and `neg`.

Note that `0` is neither positive nor negative.

## Example

### Example 1:
**Input:**  
nums = [-2, -1, -1, 1, 2, 3]  
**Output:**  
3  
**Explanation:**  
There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

### Example 2:
**Input:**  
nums = [-3, -2, -1, 0, 0, 1, 2]  
**Output:**  
3  
**Explanation:**  
There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

### Example 3:
**Input:**  
nums = [5, 20, 66, 1314]  
**Output:**  
4  
**Explanation:**  
There are 4 positive integers and 0 negative integers. The maximum count among them is 4.

## Approach

1. **Traverse the Array**: Iterate through the `nums` array to count the number of positive and negative integers.
2. **Ignore Zeros**: Since `0` is neither positive nor negative, it is not counted.
3. **Compare Counts**: Return the maximum of the positive and negative counts.
4. **Time Complexity**: The solution runs in **O(n)** time complexity as it iterates through the array once.
