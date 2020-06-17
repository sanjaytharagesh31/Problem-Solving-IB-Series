//O(2N) time solution

vector<int> fillAns(vector<int> A) {
    int n = A.size();
    vector<int> ans(n, 0);
    stack<int> s;
    
    for(int i=0; i<n; i++) {
        if(i == 0) {
            s.push(i);
            ans[i] += 1;
        }
        else {
            if(s.empty() || A[i] > A[s.top()]) {
                s.push(i);
                ans[i] += 1;
            }
            else { //s.top() >= A[i]
                ans[i] += 1;
                while(!s.empty() && A[s.top()]>=A[i]) {
                    ans[i] += ans[s.top()];
                    s.pop();
                }
                s.push(i);
            }
        }
    }
    return ans;
}

int Solution::largestRectangleArea(vector<int> &A) {
    
    vector<int> l = fillAns(A);
    reverse(A.begin(), A.end());
    vector<int> r = fillAns(A);
    reverse(r.begin(), r.end());
    reverse(A.begin(), A.end());
    int mx = INT_MIN;
    for(int i=0; i<A.size(); i++) {
        int tmp = (A[i]*l[i])+(A[i]*r[i])-A[i];
        // cout << l[i] << " " << r[i] << " " << tmp << endl;
        mx = max(mx, tmp);
    }
    return mx;
}
