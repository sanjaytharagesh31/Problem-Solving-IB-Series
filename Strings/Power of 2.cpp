string multiply(string A) {
    int m = A.length();
    int car = 0;
    for(int j=m-1; j>=0; j--) {
        int a = A[j]-'0';
        int prd = a*2+car;
        A[j] = '0'+(prd%10);
        car = prd/10;
    }
    if(car != 0)
        A.insert(0, 1, '0'+car);
    return A;
}

int Solution::power(string A) {
    string str = "1";
    while(1) {
        str = multiply(str);
        // cout << str <<  endl;
        if(str == A)
            return 1;
        if(str.length() > A.length())
            return 0;
    }
}
