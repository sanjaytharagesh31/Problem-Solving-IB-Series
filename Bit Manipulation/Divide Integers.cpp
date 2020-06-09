typedef long long int ll;

int Solution::divide(int A, int B) {
    if(B == A)
        return 1;
    // else if(B == 1 || B == -1)
    //     return A;
    else {
        ll quo = 0;
        ll divident = abs((ll)A);
        ll divisor = abs((ll)B);
        while(divident > 0) {
            divisor = abs((ll)B);
            ll cnt = 1;
            while(divisor <= divident) {
                divisor = divisor<<1;
                cnt = cnt<<1;
            }
            divisor = divisor>>1;
            cnt = cnt>>1;
            divident = divident - divisor;
            quo = quo + cnt;
        }
        if((A<0 && B<0) || (A>0 && B>0)) {
            if(quo > INT_MAX)
                return INT_MAX;
            return quo;
        }
        return -1*quo;
    }
}
