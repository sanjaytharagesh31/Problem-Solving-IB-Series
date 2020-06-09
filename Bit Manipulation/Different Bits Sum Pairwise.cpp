int Solution::cntBits(vector<int> &A) {
    int mod = 1e9+7;
    int cnt[32] = {};
    int ans = 0;
    for(int x : A) {
        for(int i=31; i>=0; i--)
            cnt[i] += (x>>i)&1;
    }
    for(int i=0; i<32; i++) {
        ans  = ans%mod + (2*cnt[i]%mod*(A.size()%mod-cnt[i]%mod))%mod;
    }
    return ans;
}
