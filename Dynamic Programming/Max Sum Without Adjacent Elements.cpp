int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = A[0][0];
    dp[1][0] = A[1][0];
    
    dp[0][1] = max(A[0][1], max(dp[0][0], dp[1][0]));
    dp[1][1] = max(A[1][1], max(dp[0][0], dp[1][0]));
    
    for(int i=2; i<n; i++) {
        dp[0][i] = max(max(A[0][i], 
                        max(
                        dp[0][i-2]+A[0][i],
                        dp[1][i-2]+A[0][i]
                        )
                    ),
                        max(dp[0][i-1], dp[1][i-1])
                    );
        dp[1][i] = max(max(A[1][i],
                        max(
                        dp[0][i-2]+A[1][i],
                        dp[1][i-2]+A[1][i]
                        )
                    ),
                        max(dp[0][i-1],dp[1][i-1])
                    );
    }
    // for(int i=0; i<n; i++) {
    //     cout << dp[0][i] << " " << dp[1][i] << endl;
    // }
    return max(dp[0][n-1], dp[1][n-1]);
}
