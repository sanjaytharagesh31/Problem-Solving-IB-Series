int Solution::isPalindrome(int A) {
    if(A < 0)
        return false;
    string str = to_string(A);
    int i = 0;
    int j = str.length()-1;
    while(i <= j) {
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
