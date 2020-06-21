string Solution::minWindow(string A, string B) {
    if(A.length() < B.length())
        return "";
        
    int n = A.length();
    
    map<char, int> mp;
    for(char x : B)
        mp[x]++;
        
    map<char, int> tmp;
    int s=-1, e=-1;
    int ns=-1, ne=-1;
    int len = INT_MAX;
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        if(mp[A[i]] != 0) {
            if(s == -1)
                s = i;
            tmp[A[i]]++;
            if(tmp[A[i]] <= mp[A[i]])
                cnt++;
        }
        
        if(cnt == B.length()) {
            while(mp[A[s]]==0 || tmp[A[s]] > mp[A[s]]) {
                if(tmp[A[s]] > mp[A[s]])
                    tmp[A[s]]--;
                s++;
            }
            if(i-s+1 < len) {
                ns = s;
                ne = i;
                len = ne-ns+1;
            }
        }
    }
    if(ns == -1)
        return "";
    return A.substr(ns, ne-ns+1);
}
