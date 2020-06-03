vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int i = 0;
    int j = A.size();
    vector<int> ans(2, -1);
    int flag = false;
    int pos = -1;
    while(i <= j) {
        int m = i+(j-i)/2;
        if(A[m] < B)
            i = m+1;
        else if(B < A[m])
            j = m-1;
        else {
            if(m==0 || (A[m-1] < A[m])) {
                pos = m;
                break;
            }
            else {
                j = m-1;
            }
        }
    }
    ans[0] = pos;
    i = 0;
    j = A.size()-1;
    pos = -1;
    while(i <= j) {
        int m = i+(j-i)/2;
        if(A[m] < B)
            i = m+1;
        else if(B < A[m])
            j = m-1;
        else {
            if(m == A.size()-1 || (A[m] < A[m+1])) {
                pos = m;
                break;
            }
            else
                i = m+1;
        }
    }
    ans[1] = pos;
    return ans;
}
