int Solution::minimumTotal(vector<vector<int> > &A) {
    int r = A.size();
    vector<vector<int>> arr = A;
    for(int i=1; i<r; i++) {
        for(int j=0; j<A[i].size(); j++) {
            if(j == 0)
                arr[i][j] = A[i][j] + arr[i-1][j];
            else if(j == A[i].size()-1)
                arr[i][j] = A[i][j] + arr[i-1][j-1];
            else
                arr[i][j] = A[i][j] + min(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<A[r-1].size(); i++)
        ans = min(ans, arr[r-1][i]);
    return ans;
}
