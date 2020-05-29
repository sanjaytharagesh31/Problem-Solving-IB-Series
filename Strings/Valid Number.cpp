int Solution::isNumber(const string A) {
    int i = 0;
    int n = A.length();
    while (i<n && A[i]==' ') { 
        i++; 
    }
    // check initial characters
    if(i == n || A[i] == 'e')
        return 0;
    else if ((A[i]=='-' || A[i]=='+') && (A[i+1]>='0' && A[i+1]<='9'))
        i+=2;
    bool expo = false;
    bool deci = false;
    while(i < n) {
        if(A[i] == '.') {
            if(expo || deci)
                return 0;
            else if(A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
            deci = true;
        }
        else if (A[i]=='e') {
            if(expo)
                return 0;
            expo = true;
            if ((A[i+1]=='-' || A[i+1]=='+') && (A[i+2]>='0' && A[i+2]<='9'))
                i+=3;
            else if (A[i+1]>='0' && A[i+1]<='9')
                i+=2;
            else
                return 0;
        }
        else if ((A[i]>='0' && A[i]<='9') || A[i] == ' ')
            i++;
        else
            return 0;
    }
    return 1;
}
