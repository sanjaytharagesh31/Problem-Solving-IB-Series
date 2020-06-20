vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    map<int, vector<int>> mp;
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(mp.find(A[i]+A[j]) != mp.end()) {
                if(mp[A[i]+A[j]][0]!=i && mp[A[i]+A[j]][0]!=j && mp[A[i]+A[j]][1]!=i && mp[A[i]+A[j]][1]!=j)
                    ans.push_back({mp[A[i]+A[j]][0], mp[A[i]+A[j]][1], i, j});
            }
            else {
                mp[A[i]+A[j]] = {i, j};
            }
        }
    }
    
    if(ans.size() == 0)
        return {};
    sort(ans.begin(), ans.end());
    return ans[0];
}
