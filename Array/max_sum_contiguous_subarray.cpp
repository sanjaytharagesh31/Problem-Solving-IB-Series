int Solution::maxSubArray(const vector<int> &A) {
    vector<int> dp(A.size(), 0);
    int ans = A[0];
    dp[0] = A[0];
    for(int i=1; i<A.size(); i++) {
        dp[i] = max(A[i], dp[i-1]+A[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}
