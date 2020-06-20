vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int> > ans;
    map<string, vector<int> > mp;
    for (int i=0; i<A.size(); i++) {
        string str = A[i];
        sort(str.begin(), str.end());
        mp[str].push_back(i+1);
    }
    map<string, vector<int> >::iterator it = mp.begin();
    for(; it!=mp.end(); it++) {
        ans.push_back(it->second);
    }
    return ans;
}
