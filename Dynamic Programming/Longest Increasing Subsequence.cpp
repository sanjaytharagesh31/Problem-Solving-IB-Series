int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> arr(n, 1);
    int ans = 1;

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(A[j] < A[i])
                arr[i] = max(arr[i], arr[j]+1);
        }
        ans = max(ans, arr[i]);
    }
    
    return ans;
}
