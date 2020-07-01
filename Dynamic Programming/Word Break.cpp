int Solution::wordBreak(string A, vector<string> &B) {
    set<string> s;
    for(string str : B)
        s.insert(str);
    int n = B.size();
    int l = A.length();
    vector<int> dp(l+10, 0);
    string tmp = "";
    for(int i=0; i<l; i++) {
        if(s.find(A.substr(0, i+1)) != s.end()) {
            dp[i] = 1;
        }
        else {
            int k = i-1;
            while(k >= 0) {
                if(dp[k] == 1 && s.find(A.substr(k+1, i - k)) != s.end()) {
                    dp[i] = 1;
                    break;
                }
                k--;
            }
        }
    }
    return dp[l-1];
}
