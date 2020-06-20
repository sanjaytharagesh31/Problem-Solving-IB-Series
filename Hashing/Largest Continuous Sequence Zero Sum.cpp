vector<int> Solution::lszero(vector<int> &A) {
    map<int, int> mp;
    mp[0] = -1;
    int pre = 0;
    int start = 1;
    int end = 0;
    
    for(int i=0; i<A.size(); i++) {
        pre += A[i];
        if(mp.find(pre) != mp.end()) {
            if(end-start+1 < i-mp[pre]) {
                start = mp[pre]+1;
                end = i;
            }
        }
        if(mp.find(pre) == mp.end())
            mp[pre] = i;
    }
    // cout << start << " " << end << endl;
    vector<int> ans(A.begin()+start, A.begin()+end+1);
    return ans;
}
