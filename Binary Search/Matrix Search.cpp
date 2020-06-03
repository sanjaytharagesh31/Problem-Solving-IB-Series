int search(vector<int> &v, int p) {
    int i = 0;
    int j = v.size()-1;
    while(i <= j) {
        int m = (i+j)/2;
        if(v[m] == p)
            return 1;
        else if(p < v[m])
            j = m-1;
        else
            i = m+1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size();
    int c = A[0].size();
    for(int i=0; i<r; i++) {
        if(B>A[i][c-1])
            continue;
        else
            return search(A[i], B);
    }
    return 0;
}
