# Problem 2551: Put Marbles in Bags

## Problem Description
You have `k` bags and an array of marbles with weights `weights[i]`. You need to distribute the marbles into the bags following these rules:
1. No bag can be empty.
2. If the `i-th` and `j-th` marbles are in the same bag, all marbles between them must also be in that bag.
3. The cost of a bag containing marbles from index `i` to `j` is `weights[i] + weights[j]`.
4. The total score is the sum of costs of all bags.

Return the difference between the maximum and minimum possible scores among all possible distributions.

## Approach
The key insight is recognizing that:
- The problem reduces to selecting `k-1` split points between marbles
- Each split point between indices `i` and `i+1` contributes `weights[i] + weights[i+1]` to the total score
- To get:
  - Minimum score: select the smallest `k-1` split point sums
  - Maximum score: select the largest `k-1` split point sums

The solution involves:
1. Calculating all possible split point sums (`weights[i] + weights[i+1]`)
2. Sorting these sums
3. Taking the difference between:
   - Sum of largest `k-1` elements (for max score)
   - Sum of smallest `k-1` elements (for min score)

## Complexity
- **Time: O(n log n)** 