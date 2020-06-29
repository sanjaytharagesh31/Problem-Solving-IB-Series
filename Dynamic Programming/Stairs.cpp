int Solution::climbStairs(int A) {
    if(A == 0)
        return 0;
    else if(A == 1)
        return 1;
    else if(A == 2)
        return 2;
        
    int a=1, b=2, c;
    for(int i = 3; i<=A; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
