//O(N*N) Time.

bool isTri(int a, int b, int c) {
    if(a+b>c && b+c>a && a+c>b)
        return true;
    else
        return false;
}

int Solution::nTriang(vector<int> &A) {
    long long int mod = 1e9+7;
    sort(A.begin(), A.end());
    long long int n = A.size();
    long long int ans = 0;
    for(long long int i=0; i<n-2; i++) {
        long long int k = i+2;
        for(long long int j=i+1; j<n-1; j++) {
            while(k<n && isTri(A[i], A[j], A[k]))
                k++;
            if(k > j)
                ans = ans%mod + (k-j-1)%mod;
        }
    }
    return ans%mod;
}
