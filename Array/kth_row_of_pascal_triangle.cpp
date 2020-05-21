vector<int> Solution::getRow(int n) {
    n = n+1;
    vector<int> v;
    if(n == 0)
        return v;
    v.push_back(1);
    for(int i=2; i<=n; i++) {
        vector<int> tmp;
        tmp.push_back(1);
        for(int j=1; j<i-1; j++)
            tmp.push_back(v[j]+v[j-1]);
        tmp.push_back(1);
        v = tmp;
    }
    return v;
}
