int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> pal(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<n; i++) {
        pal[i][i] = 1;
    }
    
    for(int i=0; i+1<n; i++) {
        if(A[i] == A[i+1])
            pal[i][i+1] = 1;
        else
            pal[i][i+1] = 0;
    }
    
    for(int i=3; i<=n; i++) {
        for(int j=0; j+i-1<n; j++) {
            if(A[j] == A[j+i-1]) {
                if(pal[j+1][j+i-2] == 1)
                    pal[j][j+i-1] = 1;
                else
                    pal[j][j+i-1] = 0;
            }
            else {
                pal[j][j+i-1] = 0;
            }
        }
    }
    
    vector<int> cut(n+1);
    
    for(int i=0; i<n; i++) {
        if(pal[0][i] == 1) {
            cut[i] = 0;
        }
        else {
            cut[i] = i;
            for(int j=i-1; j>=0; j--) {
                if(pal[j+1][i] == 1)
                    cut[i] = min(cut[i], cut[j]+1);
            }
        }
    }
    return cut[n-1];
}
