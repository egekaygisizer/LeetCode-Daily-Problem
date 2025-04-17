# Problem 2843: Count Symmetric Integers

## Problem:
Given two integers low and high, count how many numbers in this range are "symmetric". 
A number is symmetric if:
1. It has an even number of digits (like 1234 has 4 digits)
2. The sum of the first half of digits equals the sum of the second half (like 1230 where 1+2 = 3+0)

```
Example:
low = 1, high = 100
Symmetric numbers: 11, 22, 33, ..., 99 (sum matches)
Return 9
```

## Approach:
1. Check each number from low to high
2. For each number:
   a. Count its digits
   b. If odd digit count → not symmetric
   c. If even:
      - Split digits into first half and second half
      - Compare sums of both halves
3. Count all numbers where sums match

## Time Complexity: O(n) 
## Space Complexity: O(1) 

