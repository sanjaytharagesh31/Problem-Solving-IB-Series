int Solution::diffPossible(const vector<int> &A, int B) {
    map<int, int> mp;
    for(int i=0; i<A.size(); i++) {
        if(mp.find(B+A[i]) != mp.end() || mp.find(A[i]-B) != mp.end())
            return 1;
        mp[A[i]] = 1;
    }
    return 0;
}
