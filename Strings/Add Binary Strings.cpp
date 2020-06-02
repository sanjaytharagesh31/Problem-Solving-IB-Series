
string Solution::addBinary(string A, string B) {
    int m = A.length();
    int n = B.length();
    if(m < n) {
        for(int i=0; i<n-m; i++)
            A = '0' + A;
    }
    else if(m > n) {
        for(int i=0; i<m-n; i++)
            B = '0' + B;
    }
    int l = A.length();
    char car = '0';
    vector<char> ans(l+10);
    int ind=0;
    for(int i=l-1; i>=0; i--) {
        int sum = A[i]-'0' + B[i]-'0' + car-'0';
        if(sum == 0) {
            ans[ind++] = '0';
            car = '0';
        }
        else if(sum == 1) {
            ans[ind++] = '1';
            car = '0';
        }
        else if(sum == 2) {
            ans[ind++] = '0';
            car = '1';
        }
        else {
            ans[ind++] = '1';
            car = '1';
        }
    }
    if(car == '1')
        ans[ind++] = '1';
    string res = "";
    for(int i=0; i<ind; i++)
        res += ans[i];
    reverse(res.begin(), res.end());
    return res;
}
