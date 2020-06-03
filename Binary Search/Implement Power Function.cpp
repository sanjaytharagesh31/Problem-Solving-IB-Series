long long int power(long long int x, long long int n, long long int d) {
    if(x == 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(d == 1)
        return 0;
    else {
        long long int res;
        if(n%2 == 0) {
            res = power(x, n/2, d)%d;
            res = (res*res)%d;
        }
        else {
            res = (x%d*power(x, n-1, d)%d)%d;
        }
        return (res+d)%d;
    }
}

int Solution::pow(int x, int n, int d) {
    return power(x, n, d);
}
