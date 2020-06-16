string Solution::simplifyPath(string A) {
    stack<char> s;
    // cout << "HD" << endl;
    for(int i=0; i<A.length(); ) {
        // cout << i << endl;
        if(i+2 < A.length() && A[i] == '/' && A[i+1]=='.' && A[i+2]=='.') {
            if(!s.empty()) {
                while(s.top() != '/') {
                    s.pop();
                }
                s.pop();
            }
            i += 3;
        }
        else if(i+1 < A.length() && A[i]=='/' && isalpha(A[i+1])) {
            s.push(A[i]);
            i++;
            while(i<A.length() && A[i] != '/') {
                s.push(A[i]);
                i++;
            }
        }
        else {
            i++;
        }
    }
    string ans = "";
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans == "")
        return "/";
    return ans;
}
