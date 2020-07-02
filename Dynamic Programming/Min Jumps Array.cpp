//Time: O(N*N)
//SPace: O(N)
//DP approach

int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n+10, INT_MAX);
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        for(int j=i+1; j<n && j<=i+A[i]; j++) {
            if(dp[j] != -1)
                dp[i] = min(dp[i], 1+dp[j]);
        }
        if(dp[i] == INT_MAX)
            dp[i] = -1;
    }
    return dp[0];
}
