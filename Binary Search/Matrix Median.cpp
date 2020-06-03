int search(vector<int> &v, int p) {
    int x = 0;
    int y = v.size()-1;
    int m;
    int pos = 0;
    while(x <= y) {
        m = (x+y)/2;
        if(p < v[m])
            y = m-1;
        else if(p >= v[m]) {
            x = m+1;
            pos = m+1;
        }
    }
    return pos;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int r  = A.size();
    int c  = A[0].size();
    int mn = INT_MAX;
    int mx = INT_MIN;
    for(int i=0; i<r; i++) {
        mn = min(mn, A[i][0]);
        mx = max(mx, A[i][c-1]);
    }
    while(mn <= mx) {
        int mid = (mn+mx)/2;
        int pos = 0;
        for(int k=0; k<r; k++)
            pos += search(A[k], mid);
        if(pos < (r*c+1)/2)
            mn = mid+1;
        else
            mx = mid-1;
    }
    return mn;
}
