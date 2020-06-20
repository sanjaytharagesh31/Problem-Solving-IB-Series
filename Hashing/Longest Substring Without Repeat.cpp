int Solution::lengthOfLongestSubstring(string A) {
    map<char, int> mp;
    int n = A.size();
    int ans = 0;
    int p = 0;
    for(int i=0; i<n; i++) {
        if(mp.find(A[i]) == mp.end()) {
            mp[A[i]] = i;
            ans = max(ans, i-p+1);
        }
        else {
            while(p<=mp[A[i]]) {
                mp.erase(A[p]);
                p++;
            }
            mp[A[i]] = i;
        }
    }
    return ans;
}
