vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    if(B > A.size())
        return {*max_element(A.begin(), A.end())};
    if(B == 1)
        return A;
    vector<int> ans;
    deque<int> q;
    for(int i=0; i<A.size(); i++) {
        while(!q.empty() && q.front() < i-B+1)
            q.pop_front();
        while(!q.empty() && A[i] > A[q.back()])
            q.pop_back();
        q.push_back(i);
        if(i>=B-1)
            ans.push_back(A[q.front()]);
    }
    return ans;
}
