unsigned int Solution::reverse(unsigned int A) {
    int ans = 0;
    for(int i=0; i<=31; i++) {
        ans += ((A>>i&1)) * (int)pow(2, 31-i);
    }
    return ans;
}
