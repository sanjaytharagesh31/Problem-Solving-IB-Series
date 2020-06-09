void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int i=0;
    int j=0;
    int ind = 0;
    vector<int> ans(m+n);
    while(i<m && j<n) {
        if(A[i] < B[j])
            ans[ind++] = A[i++];
        else
            ans[ind++] = B[j++];
    }
    while(i<m)
        ans[ind++] = A[i++];
    while(j<n)
        ans[ind++] = B[j++];
    A = ans;
}
