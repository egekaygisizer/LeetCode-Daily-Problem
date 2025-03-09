# Problem 3208: Alternating Groups II

## Problem Statement

You are given a circular array `colors` representing tiles in a circle, where:
- `colors[i] == 0` represents a red tile.
- `colors[i] == 1` represents a blue tile.

An **alternating group** is defined as any contiguous sequence of `k` tiles in the circle where:
- The first and last tiles are considered adjacent (due to the circular nature).
- Every tile (except the first and last) has a different color from its left and right neighbors.

Return the number of alternating groups in the given circular array.

## Example 1:
### **Input**
```c
colors = [0,1,0,1,0], k = 3
```
### **Output**
```
3
```
### Explanation:
```
The valid alternating groups of size k = 3 are:
- [0,1,0]
- [1,0,1]
- [0,1,0]
```

## Constraints

- `1 <= colors.length <= 100`
- `colors[i]` is either `0` or `1`.
- `1 <= k <= colors.length`

---

## Approach

### Sliding Window Approach

1. **Initialize Variables**:
   - Maintain a counter `count` to store the number of valid alternating groups.
   - Use a flag `isAlternating` to check if a group satisfies the condition.

2. **First Window Check**:
   - Check the first `k` elements of `colors` to see if they alternate.
   - If valid, increase the `count`.

3. **Sliding Window**:
   - Move the window one step at a time.
   - Remove the leftmost element and add the next element in a circular manner.
   - If the new window still follows the alternating condition, increment `count`.

4. **Return the Final Count**.

---

## Complexity Analysis
-	Time Complexity: **O(n * k)**, where n is the length of colors and k is the window size.
-	Space Complexity: **O(1)**, as we only use a few integer variables.

---
