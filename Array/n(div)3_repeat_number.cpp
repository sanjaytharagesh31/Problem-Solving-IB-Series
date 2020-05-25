int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int num1, num2;
    int cnt1, cnt2;
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0; i<n; i++) {
        if(cnt1>0 && A[i] == num1)
            cnt1++;
        else if(cnt2>0 && A[i] == num2)
            cnt2++;
        else if(cnt1 == 0) {
            cnt1++;
            num1 = A[i];
        }
        else if(cnt2 == 0) {
            cnt2++;
            num2 = A[i];
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    // cout << cnt1 << " " << cnt2 << endl;
    if(cnt1 == 0 && cnt2 == 0)
        return -1;
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0; i<n; i++) {
        if(A[i] == num1)
            cnt1++;
        if(A[i] == num2)
            cnt2++;
    }
    if(cnt1 > n/3) 
        return num1;
    else if(cnt2 > n/3)
        return num2;
    else
        return -1;
}
