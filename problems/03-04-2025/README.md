
# Problem 1780: Check if Number is a Sum of Powers of Three  

## Problem Description  

Given an integer `n`, return `true` if it is possible to represent `n` as the sum of distinct powers of three. Otherwise, return `false.`
An integer `y` is a power of three if there exists an integer `x` such that `y == 3^x.`

### Example 1  
**Input:**  
```plaintext
n = 91
```  
**Output:**  
```plaintext
true
```  
**Explanation:**  
```plaintext
91 = 3^0 + 3^2 + 3^4
```

## Approach
1. **Precompute powers of three** up to the given limit (\( 10^7 \)).
2. **Iterate from the largest power downward**, subtracting it from \( n \) if possible.
3. **If \( n \) reduces to zero**, return `true` (it can be formed).
4. **If \( n \) remains nonzero after all attempts**, return `false`.

## Key Insights
1. Every positive integer can either be represented as a sum of distinct powers of three or not.
2. The greedy approach works well because starting with the largest power of three ensures minimal steps.

## Complexity Analysis
- **Precomputing powers of three**: ` O(log n) ` (since \( 3^x \) grows exponentially)
- **Checking if n can be represented**: ` O(log n) ` (iterating through the precomputed powers)
- **Overall complexity**: ` O(log n) `
- **Space Complexity** ` O(log₃(n)) ` (To store the powers of three, array of size O(log₃(n)) is required)

