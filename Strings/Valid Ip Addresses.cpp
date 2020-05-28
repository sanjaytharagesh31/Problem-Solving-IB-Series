bool isValid(int n) {
    if(n>=0 && n <=255)
        return true;
    return false;
}

bool isTrail(string s) {
    if(s.length() == 1)
        return true;
    else if(s[0] == '0')
        return false;
    else
        return true;
}
vector<string> Solution::restoreIpAddresses(string A) {
    int l = A.length();
    vector<string> ans;
    // 2 5 5 2 5 5 1 1 1 3 5
    // 0 1 2 3 4 5 6 7 8 9 10
    for(int i=0; i<l-3; i++) {
        for(int j=i+1; j<l-2; j++) {
            for(int k=j+1; k<l-1; k++) {
                string a = A.substr(0, i+1);
                string b = A.substr(i+1, j-i);
                string c = A.substr(j+1, k-j);
                string d = A.substr(k+1);
                int p, q, r, s;
                p = stoi(a);
                q = stoi(b);
                r = stoi(c);
                s = stoi(d);
                if(isTrail(a) && isTrail(b) && isTrail(c) && isTrail(d) &&
                    isValid(p) && isValid(q) && isValid(r) && isValid(s)) {
                    string tmp = a + '.' + b + '.' + c + '.' + d;
                    ans.push_back(tmp);
                }
            }
        }
    }
    return ans;
}
