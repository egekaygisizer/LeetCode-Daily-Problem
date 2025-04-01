# Problem 2140: Solving Questions With Brainpower

- You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
- If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
- If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

# Approach
Dynamic Programming (Bottom-Up):
1. Create DP array where `dp[i]` = max points from question i to end
2. Process backwards (i = n-1 to 0):
   - If SOLVE: points[i] + dp[i + brainpower_i + 1]
   - If SKIP: dp[i + 1]
   - dp[i] = max(solve, skip)

# Complexity Analysis
Time: O(n) - Single backward pass through n questions
Space: O(n) - Storage for DP array
