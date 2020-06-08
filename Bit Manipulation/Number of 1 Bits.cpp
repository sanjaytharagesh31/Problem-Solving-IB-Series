//O(sizeof(int))
int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    for(int i=0; i<=31; i++) {
        if(A>>i & 1 == 1) {
            ans++;
        }
    }
    return ans;
}

//O(Numebr of 1 bits)
int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    while(A > 0) {
        ans++;
        A = A&(A-1);
    }
    return ans;
}
