int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n == 0 || n == 1)
        return n;
        
    vector<int> left(n, 1);
    vector<int> right(n, 1);
    
    //do for left
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(A[j] < A[i])
                left[i] = max(left[i], left[j]+1);
        }
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=n-1; j>i; j--) {
            if(A[j] < A[i])
                right[i] = max(right[i], right[j]+1);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, left[i]+right[i]-1);
    }
    return ans;
}
