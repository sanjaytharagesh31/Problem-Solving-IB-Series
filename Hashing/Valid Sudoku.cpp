int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size();
    for(int i=0; i<n; i++) {
        unordered_set<char> s;
        for(int j=0; j<n; j++) {
            if(A[i][j] == '.')
                continue;
            if(s.find(A[i][j]) != s.end())
                return 0;
            s.insert(A[i][j]);
        }
    }
    
    for(int i=0; i<n; i++) {
        unordered_set<char> s;
        for(int j=0; j<n; j++) {
            if(A[j][i] == '.')
                continue;
            if(s.find(A[j][i]) != s.end())
                return 0;
            s.insert(A[j][i]);
        }
    }
    
    for(int i=0; i<n; i+=3) {
        for(int j=0; j<n; j+=3) {
            unordered_set<char> s;
            for(int p=i; p<i+3; p++) {
                for(int q=j; q<j+3; q++) {
                    if(A[p][q] == '.')
                        continue;
                    if(s.find(A[p][q]) != s.end())
                        return 0;
                    s.insert(A[p][q]);
                }
            }
        }
    }
    
    return 1;
}
