# Problem 2579: Count Total Number of Colored Cells  

## Problem Description  

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

* At the first minute, color any arbitrary unit cell blue.
* Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.

(![Grid Example](https://assets.leetcode.com/uploads/2023/01/10/example-copy-2.png))

### Example 1  
**Input:**  
```plaintext
n = 2
```  
**Output:**  
```plaintext
5
```  
**Explanation:**  
```plaintext
After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 
```


## Complexity Analysis

- The optimized formula-based solution runs in **O(1)** time complexity since it directly computes the result using a mathematical formula.
- The initial iterative approach (adding cells in a loop) runs in **O(n)** time complexity, making it inefficient for large values of `n`.

## Approach

1. **Observing the Pattern:**  
   - For `n = 1`, there is `1` cell.  
   - For `n = 2`, `4` more cells are added, making a total of `5`.  
   - For `n = 3`, `8` more cells are added, making a total of `13`.  
   - For `n = 4`, `12` more cells are added, making a total of `25`.  
   - The added cells follow a pattern: `4, 8, 12, 16, ...`, which corresponds to `4 * (n - 1)`.  

2. **Deriving the Formula:**  
   - The total number of cells at step `n` can be expressed as:  
     \[
     \text{coloredCells}(n) = 1 + 4(1 + 2 + ... + (n-1))
     \]
   - Using the sum formula for the first `(n-1)` natural numbers:  
     \[
     1 + 4 \times \frac{(n-1)n}{2}
     \]
   - Simplifies to:  
     \[
     2n(n-1) + 1
     \]
   - This approach provides a direct computation, eliminating the need for loops and making it much faster for large values of n.


## Key Insights

- The problem follows a structured growth pattern where, at each step, new cells are added symmetrically around the existing ones.
- Observing the number of colored cells for small values of `n` helps derive a mathematical formula.
- The sequence of colored cells follows a quadratic pattern: `1, 5, 13, 25, ...`.
- The general formula derived from the pattern is:  
  \[
  \text{coloredCells}(n) = 2n(n-1) + 1
  \]
