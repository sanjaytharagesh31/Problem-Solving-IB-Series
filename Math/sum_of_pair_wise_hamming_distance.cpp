int Solution::hammingDistance(const vector<int> &A) {
    vector<int> bit(32, 0);
    const int mod = 1000000007;
    for(int i=0; i<A.size(); i++) {
        int num = A[i];
        int ind = 0;
        while(num > 0 && ind<32) {
            bit[ind++] += (num & 1);
            num = num >> 1;
        }
    }
    int res = 0;
    for(int i=0; i<32; i++) {
        res = (res%mod + 2 * (bit[i]%mod * (A.size() - bit[i])%mod)%mod)%mod;
    }
    return res;
}
