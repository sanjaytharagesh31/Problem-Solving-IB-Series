vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    map<string, int> mp;
    vector<int> ans;
    int A_l = A.length();
    int B_l = 0;
    for(string x : B) {
        mp[x]++;
        B_l += x.length();
    }
    int sz = B[0].size();
    for(int i=0; i+B_l-1<A_l; i++) {
        map<string, int> map;
        int cnt = 0;
        for(int j=i; j<i+B_l; j+=sz) {
            string tmp = A.substr(j, sz);
            if(mp[tmp] > 0 && map[tmp] < mp[tmp]) {
                map[tmp]++;
                cnt+=sz;
            }
            else
                break;
        }
        if(cnt == B_l)
            ans.push_back(i);
        map.clear();
    }
    
    return ans;
}
