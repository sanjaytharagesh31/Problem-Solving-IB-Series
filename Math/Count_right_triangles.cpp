int Solution::solve(vector<int> &A, vector<int> &B) {
    map<int, int> x, y;
    for(int a : A)
        x[a]++;
    for(int b : B)
        y[b]++;
    
    int n = A.size();
    long long int cnt = 0;
    for(int i=0; i<n; i++) {
        cnt+= (x[A[i]]-1)*(y[B[i]]-1);
        cnt%=1000000007;
    }
    return cnt;
}
