int Solution::lengthOfLastWord(const string A) {
    int l = A.length();
    int flag = -1;
    int i;
    for(i=l-1; i>=0;) {
        if(A[i] == ' ' && flag == -1)
            i--;
        else if(A[i] != ' ')
            flag = max(flag, i--);
        else
            break;
    }
    if(flag == -1)
        return 0;
    return flag - i;
}
