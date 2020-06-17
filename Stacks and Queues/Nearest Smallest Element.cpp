vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n, -1);
    stack<int> s;
    
    for(int i=0; i<n; i++) {
        if(i == 0) {
            s.push(A[i]);
            ans[i] = -1;
        }
        else {
            if(s.top() < A[i]) {
                ans[i] = s.top();
                s.push(A[i]);
            }
            else {
                while(!s.empty() && s.top() >= A[i])
                    s.pop();
                if(s.empty()) {
                    ans[i] = -1;
                    s.push(A[i]);
                }
                else {
                    ans[i] = s.top();
                    s.push(A[i]);
                }
            }
        }
    }
    return ans;
    // for(int i=0; i<n; i++) {
    //     for(int j=i-1; j>=0; j--) {
    //         if(A[j] < A[i]) {
    //             ans[i] = A[j];
    //             break;
    //         }
    //     }
    // }
    // return ans;
}
