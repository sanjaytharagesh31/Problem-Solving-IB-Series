//Time: O(N)
//Space: O(1)
//Greedy solution

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int jump = A[0];
    for(int i=1; i<n; i++) {
        if(jump == 0)
            return 0;
        else {
            jump--;
            jump = max(jump, A[i]);
        }
    }
    return 1;
}


//Time: O(N*N)
//Space: O(N)
//DP solution

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int dp[n] = {0};
    dp[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
        if(A[i] == 0) {
            dp[i] = 0;
        }
        else {
            for(int j=i+1; j<n && j<=i+A[i]; j++) {
                if(dp[j] == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }
    return dp[0];
}
