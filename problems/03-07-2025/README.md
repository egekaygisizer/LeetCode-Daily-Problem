
# Problem 2523: Closest Prime Numbers in Range

## Problem Description  

Given two positive integers `left` and `right`, find two prime numbers `num1` and `num2` such that:

- `left <= num1 < num2 <= right`
- Both `num1` and `num2` are prime numbers.
- `num2 - num1` is the smallest possible difference among all prime pairs in the given range.

If multiple pairs satisfy the conditions, return the pair with the smallest `num1`. If no such pair exists, return `[-1, -1]`.

### Example 1:
**Input:** `left = 10, right = 19`  
**Output:** `[11, 13]`  
**Explanation:**  
The prime numbers in the range `[10, 19]` are `[11, 13, 17, 19]`.  
The closest gap is `2`, achieved by `[11, 13]` and `[17, 19]`. Since `11` is the smallest, we return `[11, 13]`.

### Example 2:
**Input:** `left = 4, right = 6`  
**Output:** `[-1, -1]`  
**Explanation:**  
Only one prime (`5`) exists in the range, so no valid pair can be formed.

---

## Approach

1. **Use the Sieve of Eratosthenes** to efficiently precompute prime numbers up to `right`.
2. **Iterate through the range `[left, right]`**, storing the previous prime found.
3. **Track the closest pair** by comparing differences between consecutive prime numbers.
4. **Return the closest prime pair** or `[-1, -1]` if no valid pair exists.

---

## Key Insights

- **Using the Sieve of Eratosthenes** avoids repeatedly checking each number for primality, significantly improving efficiency.
- **Iterating only through the range `[left, right]`** minimizes unnecessary calculations.
- **Tracking the closest prime pair in a single pass** ensures an efficient `O(N)` lookup.
- **If no two primes exist in the range, returning `[-1, -1]`** is straightforward since no valid pair can be formed.

---

## Complexity Analysis

- **Sieve of Eratosthenes:** `O(N log log N)`  
  - This efficiently marks non-prime numbers up to `right`.
- **Finding the closest prime pair:** `O(N)`  
  - A single pass through `[left, right]` to find the pair.
- **Overall Complexity:** `O(N log log N)`, which is optimal for handling large values up to `10^6`.
