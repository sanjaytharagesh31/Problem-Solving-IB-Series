int mod = 1e9+7;

//recursive solution
int solve(string A, int n, vector<int> &dp) {
    if(dp[n] != -1)
        return dp[n];
    else if(n == 0)
        dp[n] = 1;
    else if(n == 1) {
        if(A[n-1] != '0')
            dp[n] = 1;
        else
            dp[n] = 0;
    }
    else {
        int cnt = 0;
        if(A[n-1] > '0')
            cnt += solve(A, n-1, dp);
        if(A[n-2] == '1' || (A[n-2]=='2' && A[n-1]<='6'))
            cnt += solve(A, n-2, dp);
        dp[n] = cnt;
    }
    return dp[n];
}

int Solution::numDecodings(string A) {
    vector<int> dp(A.length()+1, 0);
    dp[0] = 1;
    if(A[0] != '0')
        dp[1] = 1;
    for(int i=2; i<=A.length(); i++) {
        if(A[i-1] > '0')
            dp[i] += dp[i-1]%mod;
        if(A[i-2] == '1' || (A[i-2] == '2' && A[i-1] <= '6'))
            dp[i] += dp[i-2]%mod;
    }
    return dp[A.length()]%mod;
}
