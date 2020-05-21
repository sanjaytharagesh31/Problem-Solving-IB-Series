vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> ans;
    for(int i=0; i<A.size()-1; i+=2) {
        ans.push_back(A[i+1]);
        ans.push_back(A[i]);
    }
    if(A.size()%2==1)
        ans.push_back(A[A.size()-1]);
    return ans;
}
