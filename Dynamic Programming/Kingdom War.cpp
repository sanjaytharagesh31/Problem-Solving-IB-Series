int Solution::solve(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    vector<vector<int>> arr(r+10, vector<int>(c+10, 0));
    int ans = INT_MIN;
    for(int i=r-1; i>=0; i--) {
        for(int j=c-1; j>=0; j--) {
            dp[i][j] = A[i][j]+arr[i+1][j]-arr[i+1][j+1]+arr[i][j+1];
            ans = max(ans, arr[i][j]);
        }
    }
    return ans;
}
