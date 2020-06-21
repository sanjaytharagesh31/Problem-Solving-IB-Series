//TLE Solution

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = A.size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            pq.push(A[i]+B[j]);
            if(pq.size() == n+1)
                pq.pop();
        }
    }
    
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
