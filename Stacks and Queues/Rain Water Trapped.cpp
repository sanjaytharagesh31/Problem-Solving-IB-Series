//Extra Space Solution

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int left[n];
    int right[n];
    left[0] = A[0];
    for(int i=1; i<n; i++)
        left[i] = max(left[i-1], A[i]);
    right[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--)
        right[i] = max(right[i+1], A[i]);
    int ans = 0;
    for(int i=1; i<n-1; i++) {
        if(left[i-1]>A[i] && A[i]<right[i+1]) {
            ans += min(left[i-1], right[i+1])-A[i];
        }
    }
    return ans;
}
