int Solution::atoi(const string A) {
    int ans = 0;
    int prev = 0;
    int i = 0;
    int sign = 1;
    while(A[i] == ' ')
        i++;
    if(A[i] == '-') {
        sign = -1;
        i++;
    }
    else if(A[i] == '+') {
        sign = 1;
        i++;
    }
    for(; (A[i]>='0' && A[i]<='9'); i++) {
        // prev = ans;
        // cout << prev << " " << ans << endl;
        if((sign == 1) && (ans > INT_MAX/10 || (ans == INT_MAX/10 && A[i]-'0'>7)))
            return INT_MAX;
        else if((sign == -1) && (ans > INT_MAX/10 || (ans == INT_MAX/10 && A[i]-'0'>7)))
            return INT_MIN;
        ans = ans*10 + A[i]-'0';
    }
    return sign*ans;
}
