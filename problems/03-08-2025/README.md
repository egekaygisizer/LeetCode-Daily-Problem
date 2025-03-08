# Minimum Recolors to Get K Consecutive Black Blocks

## Problem Statement
You are given a **0-indexed** string `blocks` of length `n`, where `blocks[i]` is either `'W'` or `'B'`, representing the color of the `i`-th block.  
The characters `'W'` and `'B'` denote the colors **white** and **black**, respectively.  

You are also given an integer `k`, which is the **desired number of consecutive black blocks**.  

In one operation, you can **recolor a white block** such that it becomes a black block.  

Return the **minimum number of operations** needed such that there is at least one occurrence of `k` consecutive black blocks.  

### **Example 1**
#### **Input**
```c
blocks = "WBBWWBBWBW";
k = 7;
```
#### **Output**
```
3
```
#### **Explanation**
One way to achieve **7 consecutive black blocks** is to **recolor the 0th, 3rd, and 4th blocks** so that:  
```
blocks = "BBBBBBBWBW"
```
It can be shown that there is **no way** to achieve `7` consecutive black blocks in **less than 3** operations.  

---

## **Constraints**
- `1 <= n <= 100`
- `blocks[i]` is either `'W'` or `'B'`.
- `1 <= k <= n`

---

## **Solution Approach**
This problem can be efficiently solved using the **Sliding Window Technique**.

### **Algorithm**
1. **Initialize a window of size `k`**:
   - Count how many **'W'** exist in the first `k` characters.
   - Store this as the initial `minOperations`.
   
2. **Slide the window across the string**:
   - Remove the leftmost character and add the next character at the right.
   - Adjust the count of `'W'` accordingly.
   - Update `minOperations` whenever a smaller value is found.

3. **Return the smallest number of recolors required**.

---

## **Complexity Analysis**
- **Time Complexity:** `O(n)`  
- **Space Complexity:** `O(1)`

Since we are iterating over the string only once while updating the count dynamically, this approach is optimal for `n ≤ 100`.

---

## **Alternative Approaches**
- **Brute Force (`O(n*k)`)**  
   - Check all possible substrings of length `k`.
   - Count the `'W'`s in each and return the minimum count.
   - **Inefficient for large `n`.**

---

## **Summary**
✅ **Sliding Window** reduces unnecessary recalculations.  
✅ We efficiently determine the **minimum recolors needed**.  
✅ The approach runs in **O(n) time complexity**, making it optimal for `n ≤ 100`.  