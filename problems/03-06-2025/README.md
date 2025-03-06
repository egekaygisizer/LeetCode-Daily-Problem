# Problem 2965: Find Missing and Repeated Values

## Problem Description  

You are given a `0-indexed 2D` integer matrix grid of size `n * n` with values in the range `[1, n2].` Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers `a` and `b.`

Return a 0-indexed integer array `ans` of size `2` where `ans[0]` equals to a and `ans[1]` equals to `b`.

### Example  
**Input:**  
```plaintext
grid = [[1,3],[2,2]]
```  
**Output:**  
```plaintext
[2,4]
```  
**Explanation:**  
```plaintext
Number 2 is repeated and number 4 is missing so the answer is [2,4]. 
```

## Approach
1. Use a frequency array (`freq[]`): We create an array of size `gridSize * gridSize + 1` to count occurrences of each number in the grid. This helps us track which number is repeated and which one is missing.
2. Iterate over the grid: We traverse the `gridSize x gridSize` grid and update the `freq[]` array based on the values in the grid.
3. Identify the missing and repeated numbers: After updating the frequency array, we iterate over it to find:
   - The number that appears twice (repeated).
   - The number that has a frequency of zero (missing).
4. Return the result: Store both numbers in an array and return them.

## Complexity Analysis
- Constructing the frequency array requires iterating through all elements in the `n x n` grid, which takes O(n²) time.
- Finding the repeated and missing numbers requires iterating through `freq[]`, which takes O(n²) time.
- Overall `time complexity: O(n²)`
- `Space complexity: O(n²)` due to the frequency array.

## Key Insights
- The problem guarantees that exactly one number is duplicated and one number is missing.
- A frequency array helps in detecting both the missing and repeated numbers efficiently.
- We don't need to use sorting or additional data structures, a simple counting approach is working.