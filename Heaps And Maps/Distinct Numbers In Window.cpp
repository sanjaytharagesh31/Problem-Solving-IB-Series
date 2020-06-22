vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B > A.size())
        return {};
        
    map<int, int> mp;
    for(int i=0; i<B; i++)
        mp[A[i]]++;
        
    int cnt = mp.size();
    vector<int> ans;
    
    ans.push_back(cnt);
    
    int s = 0;
    for(int i=B; i<A.size(); i++) {
        mp[A[i]]++;
        if(mp[A[i]] == 1)
            cnt++;
        mp[A[s]]--;
        if(mp[A[s]] == 0)
            cnt--;
        s++;
        ans.push_back(cnt);
    }
    return ans;
}
