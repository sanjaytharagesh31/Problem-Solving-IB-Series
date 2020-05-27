vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int ind = n-1;
    int small_ind;
    for(int i=n-2; i>=0; i--) {
        if(A[i] < A[i+1])
            break;
        ind = i;
    }
    if(ind == 0) {
        reverse(A.begin(), A.end());
        return A;
    }
    small_ind = ind;
    for(int i=ind+1; i<n; i++) {
        if(A[i] > A[ind-1] && A[i] < A[small_ind])
            small_ind = i;
    }
    swap(A[ind-1], A[small_ind]);
    reverse(A.begin()+ind, A.end());
    return A;
}
