int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if(n == 0 || n == 1)
        return 0;
    int mn = A[0];
    int ans = 0;
    for(int i=1; i<n; i++) {
        ans = max(ans, A[i]-mn);
        mn = min(mn, A[i]);
    }
    return ans;
}
