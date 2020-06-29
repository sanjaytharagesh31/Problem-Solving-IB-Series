vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> res(D);
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    int ind = 0;
    while(ind < D) {
        int t = *s.begin();
        s.erase(s.begin());
        res[ind++] = t;
        s.insert(t*A);
        s.insert(t*B);
        s.insert(t*C);
    }
    return res;
}
