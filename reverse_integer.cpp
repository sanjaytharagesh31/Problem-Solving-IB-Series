int Solution::reverse(int A) {
    int prev = 0;
    int tmp = 0;
    while(A != 0) {
        prev = prev*10 + A%10;
        A /= 10;
        if(prev/10 != tmp)
            return 0;
        tmp = prev;
    }
    return prev;
}
