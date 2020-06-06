//Efficient Solution
int Solution::books(vector<int> &A, int B) {
    if(A.size() < B)
        return -1;
    int ans = INT_MAX;
    int mx_pg = 0;
    int mn_pg = 0;
    for(int x : A)
        mx_pg += x;
    while(mn_pg <= mx_pg) {
        int m_pg = (mn_pg+mx_pg)/2;
        int cnt = 0;
        int pg = 0;
        for(int i=0; i<A.size(); i++) {
            if(A[i] > m_pg) {
                cnt = INT_MAX;
                break;
            }
            pg += A[i];
            if(pg > m_pg) {
                cnt++;
                pg = A[i];
            }
        }
        cnt++;
        if(cnt <= B) {
            ans = min(ans, m_pg);
            mx_pg = m_pg-1;
            // break;
        }
        else if(cnt < B) {
            mx_pg = m_pg-1;
        }
        else {
            mn_pg = m_pg+1;
        }
    }
    return ans;
}

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
