typedef long long int ll;

int Solution::paint(int B, int c, vector<int> &Arr) {
    ll mod = 10000003;
    vector<ll> A(Arr.size());
    for(int i=0; i<A.size(); i++)
        A[i] = Arr[i];
    for(int i=0; i<A.size(); i++)
        A[i] = (A[i]%mod * c%mod)%mod;
    // if(A.size() < B)
    //     return -1;
    ll ans = LLONG_MAX;
    ll mx_pg = 0;
    ll mn_pg = 0;
    for(ll x : A)
        mx_pg += x;
    while(mn_pg <= mx_pg) {
        ll m_pg = (mn_pg+mx_pg)/2;
        ll cnt = 0;
        ll pg = 0;
        for(ll i=0; i<A.size(); i++) {
            if(A[i] > m_pg) {
                cnt = INT_MAX;
                break;
            }
            pg += A[i];
            if(pg > m_pg) {
                cnt++;
                pg = A[i];
            }
        }
        cnt++;
        if(cnt <= B) {
            ans = min(ans, m_pg);
            mx_pg = m_pg-1;
        }
        else
            mn_pg = m_pg+1;
    }
    return ans%mod;
}
