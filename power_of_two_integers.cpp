int Solution::isPower(int n) {
    if(n == 0)
        return false;
    for(int i=1; i*i<=n; i++) {
        int p;
        p = log(n) / log(i);
        if(pow(i, p) == n)
            return true;
    }
    return false;
}
