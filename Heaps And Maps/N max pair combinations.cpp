//O(NlogN) time complexity

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    priority_queue<pair<int, vector<int>>> pq;
    map<vector<int>, int> mp;
    vector<int> ans;
    
    int n = A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    pq.push(make_pair(A[0]+B[0], vector<int>{0, 0}));
    mp[{0, 0}] = 1;
    
    while(ans.size() < n) {
        pair<int, vector<int>> tmp = pq.top(); pq.pop();
        ans.push_back(tmp.first);
        int i = tmp.second[0];
        int j = tmp.second[1];
        if(mp[{i+1, j}] == 0) {
            pq.push(make_pair(A[i+1]+B[j], vector<int>{i+1, j}));
            mp[{i+1, j}] = 1;
        }
        if(mp[{i, j+1}] == 0) {
            pq.push(make_pair(A[i]+B[j+1], vector<int>{i, j+1}));
            mp[{i, j+1}] = 1;
        }
        
    }
    
    return ans;
}


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
