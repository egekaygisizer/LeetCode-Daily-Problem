# Problem 1295: Find Numbers with Even Number of Digits

## Problem Description

Given an array `nums` of integers, return how many of them contain an even number of digits.

---

## Approach

- Iterate over each number in the input array.
- For each number, count how many digits it has by dividing it repeatedly by 10 until it becomes zero.
- If the digit count is even, increment the result counter.
- Return the total count at the end.

The approach uses basic integer division to determine digit count and avoids using string conversion functions.

---

## Complexity

- **Time Complexity:** `O(n * d)`  
  Where `n` is the number of elements in the array and `d` is the number of digits in the largest number (since we divide each number digit by digit).

- **Space Complexity:** `O(1)`  
  Only a few integer variables are used regardless of input size.