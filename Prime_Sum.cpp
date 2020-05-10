bool prime(int n) {
    if(n <= 1)
        return false;
    if(n == 2)
        return true;
    if(n%2 == 0)
        return false;
    for(int i=3; i*i <= n; i+=2) {
        if(n%i == 0)
            return false;
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int> ans(2);
    for(int i=2; i<A; i++) {
        if(prime(i) && prime(A-i)) {
            ans[0] = i;
            ans[1] = A-i;
            return ans;
        }
    }
    return ans;
}
