# Problem 1863: Sum of All Subset XOR Totals

- The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
- For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
- Given an array nums, return the sum of all XOR totals for every subset of nums. 
* Note: Subsets with the same elements should be counted multiple times.
- An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

## Aproach
OR all the numbers together and then muliply by 2 to the power of (numsSize - 1). 
There are 2 to the power of numsSize subsets and half will have any bit position set provided that bit is set in at least one element of nums[]. 
`Return 0` if maximum value is negative

# Complexity Analysis
Time: O(n)
Space: O(1)
