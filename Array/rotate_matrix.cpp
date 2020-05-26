void Solution::rotate(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    for(int i=0; i<r; i++)
        for(int j=i+1; j<c; j++)
            swap(A[i][j], A[j][i]);
    for(int i=0; i<r; i++)
        reverse(A[i].begin(), A[i].end());
}
