int Solution::strStr(const string A, const string B) {
    int m = A.length();
    int n = B.length();
    if(n == 0 || (m==0 && n==0))
        return -1;
    vector<int> arr(n, 0);
    int ind = 0;
    for(int i=1; i<n; i++) {
        if(B[ind] == B[i])
            arr[i] = ++ind;
        else
            ind = 0;
    }
    // cout << "Array" << endl;
    // for(int x : arr)
    //     cout << x << " ";
    // cout << endl;
    int j = 0;
    int i=0;
    for(;i<m;) {
        if(A[i] == B[j]) {
            j++;
            i++;
            if(j == n)
                return i-n;
        }
        else {
            if(j > 0)
                j = arr[j-1];
            else
                i++;
        }
    }
    return -1;
}
