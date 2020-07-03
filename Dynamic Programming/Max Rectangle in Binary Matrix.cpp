//Histogram area based method
//Time: O(N*N)
//Space: O(N*N)

int findRectangle(vector<int> arr) {
    int n = arr.size();
    stack<int> s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(i == 0) {
            s.push(i);
        }
        else if(arr[i] >= arr[s.top()]) {
            s.push(i);
        }
        else {
            while(!s.empty() && arr[s.top()] > arr[i]) {
                int t = s.top();
                s.pop();
                if(s.empty()) {
                    ans = max(ans, arr[t]*(i));
                }
                else {
                    ans = max(ans, arr[t]*(i-s.top()-1));
                }
            }
        }
        s.push(i);
    }
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        if(s.empty()) {
            ans = max(ans, arr[t]*(n));
        }
        else {
            ans = max(ans, arr[t]*(n-s.top()-1));
        }
    }
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    for(int i=1; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(A[i][j] == 1)
                A[i][j] += A[i-1][j];
            else
                A[i][j] = 0;
        }
    }
    int res = 0;
    for(int i=0; i<r; i++) {
        res = max(res, findRectangle(A[i]));
    }
    return res;
}
