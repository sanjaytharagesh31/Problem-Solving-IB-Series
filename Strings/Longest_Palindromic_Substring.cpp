//Time: O(N*N) 
//Space: O(N*N);
string Solution::longestPalindrome(string s) {
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
    int x=0, y=0;
    for(int i=0; i<l; i++) {
        for(int j=i; j<l; j++) {
            if(dp[i][j] && j-i+1 > y-x+1) {
                x = i;
                y = j;
            }
        }
    }
    return s.substr(x, y-x+1);
}

//Time: O(N*N)
//Space: O(1)

string Solution::longestPalindrome(string s) {
    int l = s.length();
    int p=0, q=0;
    for(int i=0; i<l; i++) {
        int left = i-1;
        int right = i+1;
        int x = i;
        int y = i;
        while(left>=0 && right<l && s[left] == s[right]) {
            x = left;
            y = right;
            left--;
            right++;
        }
        if(y-x+1 > q-p+1) {
            p = x;
            q = y;
        }
        else if(y-x+1 == q-p+1 && x < p) {
            p = x;
            q = y;
        }
        left = i;
        right = i+1;
        while(left>=0 && right<l && s[left]==s[right]) {
            x = left;
            y = right;
            left--;
            right++;
        }
        if(y-x+1 > q-p+1) {
            p = x;
            q = y;
        }
        else if(y-x+1 == q-p+1 && x < p) {
            p = x;
            q = y;
        }
    }
    return s.substr(p, q-p+1);
}
