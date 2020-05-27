int Solution::solve(string s) {
    int l = s.length();
    vector<vector<bool>> dp(l, vector<bool>(l, false));
    for(int i=0; i<l; i++) 
        dp[i][i] = true;
    for(int i=0; i+2-1<l; i++) {
        if(s[i] == s[i+1])
            dp[i][i+1] = true;
        else
            dp[i][i+1] = false;
    }
    for(int i=3; i<=l; i++) {
        for(int j=0; j+i-1<l; j++) {
            int st = j;
            int ed = j+i-1;
            if(s[st] == s[ed])
                dp[st][ed] = dp[st+1][ed-1];
            else
                dp[st][ed] = false;
        }
    }
    int dis = 0;
    for(int j=0; j<l; j++) {
        if(dp[0][j])
            dis = j+1;
    }
    dis = l - dis;
    return dis;
}
