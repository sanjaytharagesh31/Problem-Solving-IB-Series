//Time: O(N) Space: O(N)

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int mn = *min_element(A.begin(), A.end());
    int mx = *max_element(A.begin(), A.end());
    if(mx <= 0 || mn > 1)
        return 1;
    vector<int> v(mx+10);
    for(int i=0; i<n; i++)
        if(A[i] >= 0)
            v[A[i]]++;
    
    for(int i=1; i<v.size(); i++)
        if(v[i] == 0)
            return i;
    return mx+1;
}
