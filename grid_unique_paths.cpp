int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> dp(A+10, vector<int>(B+10, 0));
    for(int i=0; i<B; i++) {
        dp[0][i] = 1;
    }
    for(int i=0; i<A; i++) {
        dp[i][0] = 1;
    }
    for(int i=1; i<A; i++) {
        for(int j=1; j<B; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[A-1][B-1];
}

//Combination approach
// int nCr(int n, int r) {
//     if(r == 0 || n == r)
//         return 1;
//     return nCr(n-1, r-1) + nCr(n-1, r);
// }

// int Solution::uniquePaths(int A, int B) {
//     return nCr(A+B-2, A-1);
// }
