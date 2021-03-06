int fact(int n) {
    int ans = 1;
    for(int i = 1; i<=n; i++)
        ans = (ans%1000003 * i%1000003)%1000003;
    return ans%1000003;
}

int Solution::findRank(string str) {
    int mod = 1000003;
    int rank  = 0;
    int l = str.length();
    string tmp = str;
    sort(tmp.begin(), tmp.end());
    
    vector<char> v(l);
    for(int i=0; i<l; i++)
        v[i] = tmp[i];
        
    for(int i=0; i<l-1; i++) {
        int pos = lower_bound(v.begin(), v.end(), str[i]) - v.begin();
        v.erase(lower_bound(v.begin(), v.end(), str[i]));
        rank = (rank%mod + (pos%mod*fact(l-i-1)%mod)%mod)%mod;
    }
    return (rank%mod+1%mod)%mod;
}
