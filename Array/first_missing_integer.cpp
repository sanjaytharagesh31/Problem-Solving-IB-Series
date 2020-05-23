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

//Time: O(N) Space: O(1)
int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int mn = *min_element(A.begin(), A.end());
    int mx = *max_element(A.begin(), A.end());
    if(mx <= 0 || mn > 1)
        return 1;
    for(int i=0; i<n; i++) {
        int val = A[i];
        if(A[i] < mn)
            val = A[i] + abs(mn);
        else if(A[i] > mx)
            val = A[i] - mx;
        if(val > 0 && val <= n && !((A[val-1]>=0 && A[val-1]>mx) || (A[val-1]<0 && A[val-1]<mn))) { 
            if(A[val-1] < 0)
                A[val-1] = A[val-1] + mn;
            else
                A[val-1] = A[val-1] + mx;
        }
    }
    for(int i=0; i<n; i++)
        if(A[i] >= mn && A[i] <= mx)
            return i+1;

    return mx+1;
}
