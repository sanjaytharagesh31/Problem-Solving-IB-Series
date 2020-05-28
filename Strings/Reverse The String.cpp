string Solution::solve(string A) {
    string ans = "";
    int l = A.length();
    stack<char> s;
    for(int i=l-1; i>=0; i--) {
        if(A[i] != ' ')
            s.push(A[i]);
        else if(A[i] == ' ' && !s.empty()) {
            while(!s.empty()) {
                ans += s.top();
                s.pop();
            }
            ans += ' ';
        }
    }
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    ans += ' ';
    return ans.substr(0, ans.length()-1);
}
