int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    pair<int, int> p = make_pair(0, 1);
    if(A.size() == 0)
        return ans;
    for(int i=0; i<A.size()-1; i++) {
        if(A[i] == p.first && A[i+1] == p.second) {
            ans++;
            p.first = !p.first;
            p.second = !p.second;
        }
    }
    if(A.back() == p.first)
        ans++;
    return ans;
}
