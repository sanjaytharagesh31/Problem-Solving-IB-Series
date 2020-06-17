//O(N) time solution
//Single pass to array

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(i == 0) {
            s.push(i);
        }
        else if(A[i] >= A[s.top()]) {
            s.push(i);
        }
        else {
            while(!s.empty() && A[s.top()] > A[i]) {
                int t = A[s.top()];
                s.pop();
                if(!s.empty())
                    ans = max(ans, t*(i-s.top()-1));
                else
                    ans = max(ans, t*(i));
            }
            s.push(i);
        }
    }
    while(!s.empty()) {
        int t = A[s.top()];
        s.pop();
        if(!s.empty())
            ans = max(ans, t*(n-s.top()-1));
        else
            ans = max(ans, t*(n));
    }
    return ans;   
}

//O(N) time solution
// Multiple passes to array
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
