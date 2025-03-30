# Problem 763: Partition Labels

## Problem Description
Given a string `s`, we want to partition the string into as many parts as possible so that each letter appears in at most one part. 

For example:
- The string `"ababcc"` can be partitioned into `["abab", "cc"]`, but partitions such as `["aba", "bcc"]` or `["ab", "ab", "cc"]` are invalid because some characters appear in multiple parts.
- The concatenation of all parts in order must result in the original string `s`.

The goal is to return a list of integers representing the sizes of these partitions.

## Approach
1. **Track Last Occurrence**: First, we determine the last occurrence of each character in the string. This helps us know the farthest index each character extends to.
2. **Two-Pointer Technique**: We use two pointers, `start` and `end`, to define the current partition. As we iterate through the string:
   - For each character encountered, we update `end` to be the maximum of its current value or the last occurrence of the current character.
   - When the iterator `i` reaches `end`, it means we have found a valid partition. We record the length of this partition (`end - start + 1`), reset `start` to `i + 1`, and continue the process until the end of the string.

This approach ensures that each partition contains all occurrences of the characters within it and no overlapping characters in other partitions.

## Complexity
- **Time Complexity**: **O(n)**, where `n` is the length of the string. We traverse the string twice: once to record the last occurrences and once to determine the partitions.
- **Space Complexity**: **O(1)** for the `lastIndex` array (fixed size of 26 for lowercase English letters) and **O(k)** for the output array, where `k` is the number of partitions. The auxiliary space used is constant.