# 3392. Count Subarrays of Length Three With a Condition

## Problem Description

Given an integer array `nums`, return the number of subarrays of length 3 such that the sum of the first and third numbers is equal to exactly half of the second (middle) number.


---

## Approach

- Iterate over the array from index `0` to `numsSize - 3`.
- For each triplet `nums[i], nums[i+1], nums[i+2]`:
  - Check if the middle element `nums[i+1]` is even. This is necessary because only even numbers have an exact integer half.
  - Then, check if the sum of the first and third elements equals half of the middle element.
  - If both conditions are met, increment the counter.

This approach ensures we only consider valid subarrays and avoid floating point operations.

---

## Complexity

- **Time Complexity:** `O(n)`    
- **Space Complexity:** `O(1)`  
