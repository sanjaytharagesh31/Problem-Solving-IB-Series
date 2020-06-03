int Solution::sqrt(int A) {
    long int mn = 1;
    long int mx = max(1,A/2);
    long int ans = 0;
    while(mn <= mx) {
        long int mid = mn+(mx-mn)/2;
        long int sq = mid*mid;
        if(sq > A)
            mx = mid-1;
        else if(sq < A) {
            ans = mid;
            mn = mid+1;
        }
        else
            return mid;
    }
    return ans;
}
