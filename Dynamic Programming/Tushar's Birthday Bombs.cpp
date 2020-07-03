//Time: O(N*N)
//Space: O(N*N)
//DP approach - MLE

vector<int> Solution::solve(int A, vector<int> &B) {
    reverse(B.begin(), B.end());
    int m = B.size();
    int n = A;
    vector<vector<int>> dp(m+5, vector<int>(n+5, 0));
    vector<vector<int>> take(m+5, vector<int>(n+5, 0));
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=A; j++) {
            if(B[i-1] <= j) {
                if(dp[i-1][j] > 1+dp[i][j-B[i-1]]) {
                    dp[i][j] = dp[i-1][j];
                    take[i][j] = 0;
                }
                else {
                    dp[i][j] = 1+dp[i][j-B[i-1]];
                    take[i][j] = 1;
                }
            }
            else {
                dp[i][j] = dp[i-1][j];
                take[i][j] = 0;
            }
            // cout << take[i][j] << " ";
        }
        // cout << endl;
    }
    vector<int> ans;
    int i = m;
    int j = A;
    while(i>=0 && j>=0) {
        if(take[i][j] == 1) {
            ans.push_back(m-i);
            j = j-B[i-1];
        }
        else {
            i = i-1;
        }
    }
    return ans;
}

//Time: O(N)
//Space: O(N)
//Greedy Approach - Accepted
vector<int> Solution::solve(int A, vector<int> &B) {
    int n = B.size();
    int mn = 0;
    for(int i=0; i<n; i++) {
        if(B[mn] > B[i])
            mn = i;
    }
    int l = A/B[mn];
    vector<int> ans(l, mn);
    int total = l*B[mn];
    int ind = 0;
    for(int i=0; i<l && ind<mn; ) {
        if(total-B[ans[i]]+B[ind] <= A) {
            total = total-B[ans[i]]+B[ind];
            ans[i] = ind;
            i++;
        }
        else {
            ind++;
        }
    }
    return ans;
