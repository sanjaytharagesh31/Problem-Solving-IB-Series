void Solution::setZeroes(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    for(int i=0; i<r; i++) {
        bool flag = false;
        for(int j=0; j<c; j++) {
            if(A[i][j] == 0)
                flag = true;
            else if(A[i][j] == 1 && flag == true)
                A[i][j] = 2;
        }
    }

    for(int i=0; i<r; i++) {
        bool flag = false;
        for(int j=c-1; j>=0; j--) {
            if(A[i][j] == 0)
                flag = true;
            else if(A[i][j] == 1 && flag == true) 
                A[i][j] = 2;
        }
    }

    for(int j=0; j<c; j++) {
        bool flag = false;
        for(int i=0; i<r; i++) {
            if(A[i][j] == 0)
                flag = true;
            else if(A[i][j] == 1 && flag == true)
                A[i][j] = 2;
        }
    }

    for(int j=0; j<c; j++) {
        bool flag = false;
        for(int i=r-1; i>=0; i--) {
            if(A[i][j] == 0)
                flag = true;
            else if(A[i][j] == 1 && flag == true)
                A[i][j] = 2;
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(A[i][j] == 2)
                A[i][j] = 0;
        }
    }
}
