typedef unsigned long long int ll;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ret(2);
    ll n = A.size();
    ll s1 = 0;
    ll s2 = 0;
    for(int i=0; i<A.size(); i++) {
        s1 += (ll)A[i];
        s2 += (ll)A[i]*(ll)A[i];
    }
    ll a1, a2;
    if(n%2 == 0) {
        a1 = (n/2)*(n+1);
        a2 = (( (n*(n+1))/2 ) * (2*n+1) )/3;
    }
    else {
        a1 = n*((n+1)/2);
        a2 = (( (n*(n+1))/2 ) * (2*n+1) )/3;
    }
    if(s1 > a1) {
        ll yax = (s2-a2) / (s1-a1);
        ll y = (yax + s1-a1) / 2;
        ll x = (yax - s1+a1) / 2;
        ret[0] = y;
        ret[1] = x;
    }
    else {
        ll yax = (a2-s2) / (a1-s1);
        ll y = (yax + a1-s1) / 2;
        ll x = (yax - a1+s1) / 2;
        ret[0] = x;
        ret[1] = y;
    }
    return ret;
}
