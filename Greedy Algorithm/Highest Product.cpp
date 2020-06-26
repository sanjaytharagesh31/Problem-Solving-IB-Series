int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int mx = INT_MIN;
    mx = max(mx, A[n-1]*A[n-2]*A[n-3]);
    mx = max(mx, A[0]*A[1]*A[n-1]);
    return mx;
}
