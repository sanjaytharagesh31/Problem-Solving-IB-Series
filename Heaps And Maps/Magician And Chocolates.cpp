int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<long long int> pq;
    for(int x : B)
        pq.push((long long int)x);
    long long int mod = 1e9+7;
    long long int ans = 0;
    while(A--) {
        long long int cho = pq.top();
        pq.pop();
        ans = (ans%mod + cho%mod);
        pq.push(cho/2);
    }
    return ans%mod;
}
