
vector<vector<int> > Solution::generateMatrix(int A) {
    vector< vector<int> > mat(A, vector<int>(A, -1));
    int k=0, l=0, r=A, c=A;
    int ind = 1;
    while(k<r && l<c) {
        for(int i=l; i<c; i++)
            mat[k][i] = ind++;
        k++;
        for(int i=k; i<r; i++)
            mat[i][c-1] = ind++;
        c--;
        if(k < r) {
            for(int i=c-1; i>=l; i--)
                mat[r-1][i] = ind++;
            r--;
        }
        if(l < c) {
            for(int i=r-1; i>=k; i--)
                mat[i][l] = ind++;
            l++;
        }
    }
    return mat;
}
