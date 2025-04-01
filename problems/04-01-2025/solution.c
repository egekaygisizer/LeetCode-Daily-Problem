long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    // Dynamic Programming
    long long *dp = (long long *)malloc((questionsSize + 1) * sizeof(long long));
    
    // Start from last index.
    dp[questionsSize] = 0;
    
    for (int i = questionsSize - 1; i >= 0; i--) {
        int points = questions[i][0];
        int brainpower = questions[i][1];
        
        // if solve
        long long solve = points;
        int next = i + brainpower + 1;
        if (next < questionsSize) {
            solve += dp[next];
        }
        
        // if skip
        long long skip = dp[i + 1];
        
        // which is better?
        dp[i] = (solve > skip) ? solve : skip;
    }
    
    long long result = dp[0];
    free(dp);
    return result;
}