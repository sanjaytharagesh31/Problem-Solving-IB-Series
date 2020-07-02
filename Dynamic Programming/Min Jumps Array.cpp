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

//TIme: O(N)
//Space: O(1)
//Greedy approach
int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n == 0 || n == 1)
        return 0;
    else if(A[0] == 0)
        return -1;
    int jump = 1;
    int mx = A[0];
    int rem = A[0];
    for(int i=1; i<n; i++) {
        if(i == n-1) {
            return jump;
        }
        else {
            mx = max(mx, i + A[i]);
            rem--;
            if(rem == 0) {
                jump++;
                rem = mx - i;
                if(rem <= 0)
                    return -1;
            }
        }
    }
    return jump;
}
