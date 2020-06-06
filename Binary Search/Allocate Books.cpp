//Brute Force (TLE)
int solve(vector<int> &arr, int p, int n) {
    if(n == 1) {
        int pre = 0;
        for(int i=p; i<arr.size(); i++) {
            pre += arr[i];
        }
        // cout << p << " " << n << " " << pre << endl;
        return pre;
    }
    else {
        int ans = INT_MAX;
        int pre = 0;
        for(int i=p; i<arr.size()-n+1; i++) {
            pre += arr[i];
            int ret = solve(arr, i+1, n-1);
            ans = min(ans, max(pre, ret));
        }
        // cout << p << " " << n << " " << ans << endl;
        return ans;
    }
}

int Solution::books(vector<int> &A, int B) {
    if(A.size() < B)
        return -1;
    return solve(A, 0, B);
}
