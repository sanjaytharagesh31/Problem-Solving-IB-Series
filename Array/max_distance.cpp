
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    int ret = -1;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++)
        v.push_back(make_pair(A[i], i));
    sort(v.begin(), v.end());
    int arr[n];
    arr[n-1] = v[n-1].second;
    for(int i=n-2; i>=0; i--)
        arr[i] = max(arr[i+1], v[i].second);
    for(int i=0; i<n; i++)
        ret = max(ret, arr[i]-v[i].second);
    return ret;
}
