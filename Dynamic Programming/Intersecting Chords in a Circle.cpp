long long int mod = 1e9+7;
vector<long long int> dp;

long long int solve(long long int n) {
    if(dp[n] != -1)
        return dp[n];
    else if(n == 0) {
        dp[n] = 1;
        return 1;
    }
    else if(n == 2) {
        dp[n] = 1;
        return 1;
    }
    else if(n == 4) {
        dp[n] = 2;
        return 2;
    }
    else {
        long long int cnt = 0;
        for(long long int i=0; i<=n-2; i+=2) {
            cnt += (solve(i)%mod * solve(n-i-2)%mod)%mod;
        }
        dp[n] = cnt%mod;
        return cnt%mod;
    }
}

int Solution::chordCnt(int A) {
    dp = vector<long long int>(2*A+1, -1);
    solve(2*A);
    return dp[2*A];
}
