# Problem 3169: Count Days Without Meetings

## Problem Description
Given a positive integer `days` representing the total number of days an employee is available for work (starting from day 1), and a 2D array `meetings` where `meetings[i] = [start_i, end_i]` represents the starting and ending days of meeting `i` (inclusive), the task is to determine the number of days when the employee is available for work but no meetings are scheduled.

## Approach
1. **Sort the Meetings:**  
   - Sort the `meetings` array by `start` time.  
   - If two meetings have the same `start` time, sort by `end` time.  

2. **Merge Overlapping Intervals:**  
   - Iterate through the sorted list and merge overlapping or consecutive meetings.  
   - Whenever a gap is detected between two consecutive meetings, count the available days.  

3. **Compute Available Days:**  
   - Subtract the total occupied days from `days` to get the number of available workdays.  

## Time Complexity
- Sorting the meetings takes **O(N log N)**.  
- Merging intervals takes **O(N)**.  
- **Overall Complexity:** **O(N log N)**  

## Space Complexity
- **O(1)** (since we are modifying the input array and using only a few extra variables).  

## Constraints
- `1 <= days <= 10^9`  
- `1 <= meetings.length <= 10^5`  
- `1 <= meetings[i][0] <= meetings[i][1] <= days`  

This solution is efficient for large values of `days`, as it does not use an array of size `days`. Instead, it processes meeting intervals directly.