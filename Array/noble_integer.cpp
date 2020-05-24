int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    if(A[A.size()-1] == 0)
        return 1;
    for(int i=0; i<A.size()-1; i++) {
        if(A[i] >= 0 && A[i] < A[i+1] && A.size()-i-1 == A[i])
            return 1;
    }
    return -1;
}
