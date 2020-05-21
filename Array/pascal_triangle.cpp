vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> v;
    if(n == 0)
        return v;
    v.push_back(vector<int>{1});
    for(int i=2; i<=n; i++) {
        vector<int> tmp;
        tmp.push_back(1);
        for(int j=1; j<i-1; j++) {
            tmp.push_back(v[i-2][j]+v[i-2][j-1]);
        }
        tmp.push_back(1);
        v.push_back(tmp);
    }
    return v;
}
