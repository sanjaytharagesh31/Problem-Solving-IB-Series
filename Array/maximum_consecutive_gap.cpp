int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n < 2)
        return 0;
    int max_ele = *max_element(A.begin(), A.end());
    int min_ele = *min_element(A.begin(), A.end());
    int diff = ceil((max_ele - min_ele)/(n-1.0));
    if(diff == 0)
        return 0;
    pair<int, int> inf{INT_MAX, INT_MIN};
    vector<pair<int, int>> v(n, inf);
    for(int i=0; i<n; i++) {
        v[(A[i]-min_ele)/diff].first = min(v[(A[i]-min_ele)/diff].first, A[i]);
        v[(A[i]-min_ele)/diff].second = max(v[(A[i]-min_ele)/diff].second, A[i]);
    }
    int res = 0;
    pair<int, int> prev = inf;
    for(int i=0; i<n; i++) {
        if(v[i] != inf && prev == inf)
            prev = v[i];
        else if(v[i] != inf) {
            res = max(res, abs(v[i].first - prev.second));
            prev = v[i];
        }
    }
    return res;
}
