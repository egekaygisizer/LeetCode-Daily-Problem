# Problem 1092: Shortest Common Supersequence  

## Problem Description  
Given two strings `str1` and `str2`, return the shortest string that has both `str1` and `str2` as subsequences. If there are multiple valid strings, return any of them.  

A string `s` is a subsequence of string `t` if deleting some number of characters from `t` (possibly 0) results in the string `s`.  

## Example  

### Example 1  
**Input:**  
```plaintext
str1 = "abac", str2 = "cab"
```  
**Output:**  
```plaintext
"cabac"
```  
**Explanation:**  
- `str1 = "abac"` is a subsequence of `"cabac"` because we can delete the first `"c"`.  
- `str2 = "cab"` is a subsequence of `"cabac"` because we can delete the last `"ac"`.  
- The answer provided is the shortest such string that satisfies these properties.  

### Example 2  
**Input:**  
```plaintext
str1 = "aaaaaaaa", str2 = "aaaaaaaa"
```  
**Output:**  
```plaintext
"aaaaaaaa"
```  

## Approach  

To solve this problem efficiently, we use **Dynamic Programming (DP)** based on the **Longest Common Subsequence (LCS)** concept. The key idea is:  

1. **Compute LCS:** Find the longest common subsequence of `str1` and `str2`. This helps determine the overlapping part of both strings.  
2. **Construct the Shortest Common Supersequence (SCS):**  
   - Start from the end of both strings and use the LCS table to backtrack.  
   - If the current characters of `str1` and `str2` match, include them in the result.  
   - If they don’t match, take the character from the string that contributes to the maximum LCS value.  
   - Append the remaining characters from both strings if any are left.  
   - Reverse the final sequence to get the correct order.  

## Complexity Analysis  

- **Time Complexity:** `O(N * M)`, where `N` and `M` are the lengths of `str1` and `str2`. This is due to the DP table computation and backtracking.  
- **Space Complexity:** `O(N * M)`, required for storing the DP table.  

## Key Insights  

- **Using LCS to build SCS:** The longest common subsequence acts as a guide to merging the two strings optimally.  
- **Efficient Backtracking:** By keeping track of the DP table, we can construct the shortest supersequence without redundant calculations.  
- **Edge Cases Considered:** Identical strings, completely different strings, and partial overlaps are all handled by the approach.  