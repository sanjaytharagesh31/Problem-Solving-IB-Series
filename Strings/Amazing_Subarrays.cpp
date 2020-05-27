int Solution::solve(string A) {
    const int mod = 10003;
    int cnt = 0;
    int n = A.size();
    set<char> s{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(int i=0; i<n; i++) {
        if(s.find(A[i]) != s.end()) {
            cnt = (cnt%mod + n%mod - i%mod)%mod;
        }
    }
    return cnt%mod;
}
