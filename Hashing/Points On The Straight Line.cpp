double slope(int x1, int y1, int x2, int y2) {
    if(x1 == x2)
        return (double)INT_MAX;
    return (double)(y2-y1) / (double)(x2-x1);
}

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n == 0)
        return 0;
    int mx = 0;
    for(int i=0; i<n; i++) {
        map<double, int> mp;
        int over = 0;
        for(int j=0; j<n; j++) {
            if(A[i]==A[j] && B[i]==B[j])
                over++;
            else {
                double slp = slope(A[i], B[i], A[j], B[j]);
                // cout << A[i] << B[i] << A[j] << B[j] << slp << endl;
                mp[slp]++;
            }
        }
        mx = max(mx, over);
        for(auto x : mp) { 
            mx = max(mx, x.second+over);
        }
        mp.clear();
    }
    return mx;
}
