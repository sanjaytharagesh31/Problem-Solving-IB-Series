string solve(int n) {
    if(n == 1)
        return "1";
    // else if(n == 2)
    //     return "11";
    // else if(n == 3)
    //     return "21";
    // else if(n == 4)
    //     return "1211";
    // else if(n == 5) 
    //     return "111221";
    else {
        string ans = "";
        string prev = solve(n-1);
        char bf = prev[0];
        int cnt = 1;
        for(int i=1; i<prev.length(); i++) {
            if(prev[i] == bf)
                cnt++;
            else {
                ans += to_string(cnt) + bf;
                cnt = 1;
                bf = prev[i];
            }
        }
        ans += to_string(cnt) + bf;
        return ans;
    }
}
string Solution::countAndSay(int A) {
    return solve(A);
}
