int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    for(int i=0; i<=31; i++) {
        if(A>>i & 1 == 1) {
            ans++;
        }
    }
    return ans;
}
