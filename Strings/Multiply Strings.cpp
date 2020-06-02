string Solution::multiply(string A, string B) {
    if(A == "0" || B == "0")
        return "0";
    int m = A.length();
    int n = B.length();
    if(n > m) {
        swap(A, B);
        swap(m, n);
    }
    // A - large
    // B - small
    int pos = m+n+10;
    vector<int> ans(m+n+10, 0);
    for(int i=n-1; i>=0; i--) { //B
        int car = 0;
        int car_add = 0;
        int ind = --pos; 
        for(int j=m-1; j>=0; j--) { //A
            int a = A[j]-'0';
            int b = B[i]-'0';
            int prd = a*b+car;
            int add = prd%10 + car_add + ans[ind];
            ans[ind] = add%10;
            car_add = add/10;
            car = prd/10;
            ind--;
        }
        ans[ind] += car;
        // ind--;
        ans[ind] += car_add;
    }
    int f = 0;
    string res = "";
    for(int i=0; i<ans.size(); i++) {
        if(ans[i] != 0) {
            f = 1;
            res += to_string(ans[i]);
            // cout << ans[i] << " " ;
        }
        else if(f == 1) {
            // cout << ans[i] << " " ;
            res += to_string(ans[i]);
        }
    }
    return res;
}
