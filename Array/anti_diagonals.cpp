
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int>> ans;
    int r = A.size();
    int c = A[0].size();
    for(int i=0; i<c; i++) {
        vector<int> v;
        for(int j=0; j<=min(r-1, i); j++) {
            v.push_back(A[j][i-j]);
        }
        ans.push_back(v);
    }
    for(int i=1; i<r; i++) {
        vector<int> v;
        int ind = c-1;
        for(int j=i; j<r; j++) {
            v.push_back(A[j][ind--]);
        }
        ans.push_back(v);
    }
    return ans;
}

