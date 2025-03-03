
# Problem 2161: Partition Array According to Given Pivot  

## Problem Description  
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

* Every element less than pivot appears before every element greater than pivot.
* Every element equal to pivot appears in between the elements less than and greater than pivot.
* The relative order of the elements less than pivot and the elements greater than pivot is maintained.
    -More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.

### Example 1  
**Input:**  
```plaintext
nums = [9,12,5,10,14,3,10], pivot = 10
```  
**Output:**  
```plaintext
[9,5,3,10,10,12,14]
```  
**Explanation:**  
```plaintext
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
```


## Approach

1. **Partition the array into three separate lists:**
   - `smaller[]` stores elements less than `pivot`.
   - `equal[]` stores elements equal to `pivot`.
   - `larger[]` stores elements greater than `pivot`.
2. **Merge the three lists into a single output array while preserving order.**
3. **Use dynamic memory allocation (`malloc()`)** to handle the lists efficiently and free them when done.

## Complexity Analysis

- **Time Complexity:** `O(n)`, since we iterate over the array twice (once to separate elements, once to construct the result).
- **Space Complexity:** `O(n)`, since we use three auxiliary arrays to store partitions before merging.

## Key Insights

- The problem is best solved using a **three-pass** approach: partitioning, merging, and output.
- Using dynamic memory allocation avoids modifying the input array in place.
- Maintaining the relative order of elements within each partition is crucial to satisfy the problem constraints.
- This approach ensures stability while keeping the solution efficient.