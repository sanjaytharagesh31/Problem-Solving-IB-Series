int Solution::trailingZeroes(int A) {
    int cnt = 0;
    for(int i=5; A/i > 0; i = i*5)
        cnt += A/i;
    return cnt;
}
