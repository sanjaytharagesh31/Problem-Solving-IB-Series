int Solution::singleNumber(const vector<int> &A) {
    vector<int> cnt(32, 0);
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<=31; j++) {
            if((A[i]>>j)&1 == 1)
                cnt[j]++;
        }
    }
    int ans = 0;
    for(int i=0; i<32; i++) {
        if(cnt[i]%3 != 0) {
            ans = ans | (1<<i);    
        }
    }
    return ans;
}
