int Solution::titleToNumber(string A) {
    reverse(A.begin(), A.end());
    int ans = 0;
    for(int i=0; i<A.length(); i++)
        ans = ans + (A[i]-'A'+1) * pow(26, i);
    return ans;
}
