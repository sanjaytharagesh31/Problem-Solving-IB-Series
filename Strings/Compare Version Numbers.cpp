pair<string, int> until(string a, int i) {
    string str = "";
    bool flag = false;
    while(i<a.length() && a[i] != '.') {
        if(a[i]-'0' != 0) {
            str += a[i];
            flag = true;
        }
        else if(flag == true)
            str += a[i];
        i++;
    }
    if(str == "")
        str = "0";
    return make_pair(str, i);
}

int Solution::compareVersion(string A, string B) {
    int i=0;
    int j=0;
    while(i<A.length() && j<B.length()) {
        pair<string, int> n1 = until(A, i);
        pair<string, int> n2 = until(B, j);
        string a = n1.first;
        string b = n2.first;
        if(a.length() < b.length())
            return -1;
        else if(a.length() > b.length())
            return 1;
        else {
            int p=0;
            while(p < a.length()) {
                if(a[p] == b[p])
                    p++;
                else if(a[p] > b[p])
                    return 1;
                else
                    return -1;
            }
            i = n1.second+1;
            j = n2.second+1;
        }
    }
    if(i < A.length()) {
        pair<string, int> n1 = until(A, i);
        if(n1.first != "0")
            return 1;
    }
    else if(j < B.length()) {
        pair<string, int> n1 = until(B, j);
        if(n1.first != "0")
            return -1;
    }
    return 0;
}
