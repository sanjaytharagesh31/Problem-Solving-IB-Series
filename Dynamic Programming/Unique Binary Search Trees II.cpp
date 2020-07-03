map<int, int> mp;

int solve(int i, int j) {
    int n = max(0, j-i+1);
    if(mp.find(n) != mp.end()) {
        return mp[n];
    }
    if(n == 0) {
        mp[n] = 1;
        return 1;
    }
    else if(n == 1) {
        mp[n] = 1;
        return 1;
    }
    else if(n == 2) {
        mp[n] = 2;
        return 2;
    }
    else if(n == 3) {
        mp[n] = 5;
        return 5;
    }
    else {
        int ans = 0;
        for(int p=i; p<=j; p++) {
            ans = ans + solve(i, p-1) * solve(p+1, j);
        }
        mp[n] = ans;
        return ans;
    }
}

int Solution::numTrees(int A) {
    mp = map<int, int>();
    return solve(1, A);
}
