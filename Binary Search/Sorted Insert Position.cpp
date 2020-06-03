int Solution::searchInsert(vector<int> &A, int B) {
    int i = 0;
    int j = A.size()-1;
    while(i <= j) {
        int m = (i+j)/2;
        if(A[m] == B) {
            return m;
        }
        else if(B < A[m]) {
            j = m-1;
        }
        else {
            i= m+1;
        }
    }
    return i;
}
