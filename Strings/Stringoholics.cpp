typedef long long int ll;
const int mod = 1e9+7;
const int mx = 1e5+1;
vector<int> prime(mx+10);
map<ll, ll> primePower;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll power(ll a, ll b) {
    if(b == 1)
        return a%mod;
    else if(b == 0)
        return 1;
    else {
        if(b%2 == 0) {
            ll res = power(a, b/2)%mod;
            return ((res%mod)*(res%mod))%mod;
        }
        else
            return ((a%mod)*(power(a, b-1)%mod))%mod;
    }
}

void seive() {
    prime[0] = 1;
    prime[1] = 1;
    for(int i=2; i<mx; i++) {
        if(prime[i] == 0) {
            prime[i] = i;
            for(int j=2*i; j<mx; j+=i) {
                if(prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
}

void findPrimeFactors(ll n) {
    unordered_map<ll, ll> mp;
    while(n > 1){
        mp[prime[n]]++;
        n = n / prime[n];
    }
    
    for(auto x : mp)
        primePower[x.first] = max(primePower[x.first], x.second);
}

ll lcmMOD(vector<ll> tmp) {
    seive();
    for(ll x : tmp) {
        findPrimeFactors(x);
    }
    ll ans = 1;
    for(auto x : primePower) {
        ll a = x.first;
        ll b = x.second;
        ans = ((ans%mod) * (power(a, b)%mod))%mod;
    }
    return ans%mod;
}

ll computeRepetation(string str) {
    int l = str.length();
    vector<int> tmp(l);
    tmp[0] = 0;
    int i, j;
    i = 0;
    j = 1;
    while(j < l) {
        if(str[i] == str[j]) {
            tmp[j] = i+1;
            i++;
            j++;
        }
        else {
            if(i > 0)
                i = tmp[i-1];
            else {
                tmp[j] = 0;
                j++;
            }
        }
    }
    return tmp[l-1];
}
int Solution::solve(vector<string> &A) {
    prime.clear();
    primePower.clear();
    int n = A.size();
    vector<ll> tme(n);
    for(int i=0; i<n; i++) {
        ll l = A[i].length();
        if(l == 1) {
            tme[i] = 1;
            continue;
        }
        ll cnt = 1;
        ll rot = 1;
        ll total = l;
        ll rep = computeRepetation(A[i]);
        if(rep>0 && l%(l-rep) == 0) {
            total = l-rep;
        }
        while(rot%total != 0) {
            cnt++;
            rot = (cnt*(cnt+1))/2;
        }
        tme[i] = cnt;
    }
    return lcmMOD(tme);
    // for(int i=0; i<n; i++) {
    //     ll l = A[i].length();
    //     if(l == 1) {
    //         tme[i] = 1;
    //         continue;
    //     }
    //     string tmp = A[i].substr(1)+A[i][0];
    //     ll cnt = 1;
    //     while(tmp != A[i]) {
    //         cnt++;
    //         ll pos = cnt%l;
    //         tmp = tmp.substr(pos) + tmp.substr(0, pos);
    //     }
    //     tme[i] = cnt;
    // }
    // return lcmMOD(tme);
    /*
    for(int i=0; i<n; i++)
        cout << tme[i] << " ";
    ll ans = tme[0];
    for(int i=1; i<n; i++) {
        ans = (ans*tme[i])/(gcd(ans, tme[i]));
    }
    return ans;
    */
}
