# Problem 2460: Apply Operations to an Array  

## Problem Description  
Given a non-negative integer array, the goal is to apply a series of operations to transform the array based on specific rules. If two adjacent elements are equal, the left element is doubled, and the right element is set to zero. After processing the array, all zeros are shifted to the end while maintaining the relative order of non-zero elements.  

### Example 1  
**Input:**  
```plaintext
nums = [1,2,2,1,1,0]
```  
**Output:**  
```plaintext
[1,4,2,0,0,0]
```  
**Explanation:**  
```plaintext
We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].
```

## Approach  

1. **Modify the array in-place** by iterating through the elements and applying the transformation whenever two adjacent numbers are equal.  
2. **Rearrange the elements** by collecting all non-zero numbers in order and appending the required number of zeros at the end.  
3. **Return a new array** with the final result while ensuring memory safety using dynamic allocation.  

## Complexity Analysis  

- **Time Complexity:** `O(n)`, as the solution processes the array twice: once for modification and once for rearrangement.  
- **Space Complexity:** `O(n)`, since a new array is allocated to store the final result.  

## Key Insights  

- **In-place modification first:** This reduces unnecessary extra operations before constructing the final output.  
- **Efficient zero shifting:** Instead of swapping elements multiple times, a new array is populated directly with non-zero values first.  
- **Edge Cases Considered:** Arrays with all zeros, already processed arrays, and cases with no adjacent duplicates are properly handled.  