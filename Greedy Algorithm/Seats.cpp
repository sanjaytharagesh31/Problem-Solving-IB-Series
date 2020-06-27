int Solution::seats(string A) {
    int ans = 0;
    int MOD = 10000003;
    vector<int> tmp;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == 'x')
            tmp.push_back(i);
    }
    if(tmp.size() == 0)
        return ans;
    int med = tmp[tmp.size()/2];
    med++;
    for(int i=tmp.size()/2+1; i<tmp.size(); i++) {
        ans = ans%MOD + (tmp[i]%MOD-med%MOD+MOD)%MOD;
        med++;
    }
    med = tmp[tmp.size()/2];
    med--;
    for(int i=tmp.size()/2-1; i>=0; i--) {
        ans = ans%MOD + (med%MOD - tmp[i]%MOD + MOD)%MOD;
        med--;
    }
    return ans%MOD;
}
