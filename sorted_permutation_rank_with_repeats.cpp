const long long int mod = 1000003;

int pwr(long long int a, long long int b) {
    if(a == 0)
        return 0;
    else if(b == 0)
        return 1;
    else if(b%2==0) {
        int ret = pwr(a, b/2);
        return ((ret%mod)*(ret%mod))%mod;
    }
    else {
        return ((a%mod) * (pwr(a, b-1)%mod))%mod;
    }
}

int Solution::findRank(string A) {
    int l = A.size();
    vector<long long int> fact(l+1);
    fact[0] = 1;
    for(int i=1; i<=l; i++)
        fact[i] = ((fact[i-1]%mod) * (i%mod))%mod;
    int ans = 0;
    for(int i=0; i<l; i++) {
        int cnt = 0;
        for(int j=i+1; j<l; j++) {
            if(A[i] > A[j])
                cnt++;
        }
        map<char, int> mp;
        for(int k=i; k<l; k++) {
            mp[A[k]]++;
        }
        long long int rep = 1;
        for(auto x : mp) {
            rep = ((rep%mod) * (fact[x.second]%mod))%mod;
        }
        ans = (ans + cnt%mod * fact[l-i-1]%mod * pwr(rep, mod-2)%mod )%mod;
    }
    return (ans+1)%mod;
}
