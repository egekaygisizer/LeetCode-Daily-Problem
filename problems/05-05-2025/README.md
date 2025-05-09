# Domino and Tromino Tiling

## Problem Description

You are given an integer `n`. Your task is to count how many different ways you can tile a `2 x n` board using two types of tiles:

- **Domino tiles**, which cover `2 x 1` or `1 x 2` spaces (can be rotated),
- **Tromino tiles**, which are `L`-shaped and cover three squares (can also be rotated).

Return the number of distinct tilings modulo `10^9 + 7`.

> A tiling is considered **different** if there exists at least one pair of adjacent cells such that one tiling covers both and the other doesn't.

---

## Approach

- This is a dynamic programming problem.
- For small values of `n` (1 ≤ n ≤ 3), we directly return precomputed values.
- For larger `n`, we define the recurrence relation based on the observations of how new tiles can be added:
  
  Let `s[n]` be the number of ways to tile a `2 x n` board. The relation is:
  **s[n] = 2 * s[n-1] + s[n-3]**

  This is because:
- The `2 * s[n-1]` term accounts for placing a vertical domino or two trominoes in mirrored L-shapes.
- The `s[n-3]` term comes from placing an L-tromino that covers 3 columns.

- The solution uses a **rolling window** of the last three computed values to maintain constant space complexity.
- The result is returned modulo `1,000,000,007` to prevent overflow.

---

## Complexity

- **Time Complexity:** `O(n)`  
We compute each state from 4 to `n` once.

- **Space Complexity:** `O(1)`  
Only the last three computed states are stored and updated iteratively.