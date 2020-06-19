vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int, int> mp;
    for(int i=0; i<A.size(); i++) {
        if(mp.find(B-A[i]) != mp.end()) {
            return {mp[B-A[i]]+1, i+1};
        }
        else {
            if(mp.find(A[i]) == mp.end())
                mp[A[i]] = i;
        }
    }
    return {};
}
