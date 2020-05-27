int Solution::isPalindrome(string A) {
    string str = "";
    for(int i=0; i<A.size(); i++) {
        if(isalnum(A[i])) {
            str += tolower(A[i]);
        }
    }
    string tmp = str;
    reverse(str.begin(), str.end());
    if(tmp == str)
        return 1;
    return 0;
}

//To solve in O(1) space, have 2 pointers.
