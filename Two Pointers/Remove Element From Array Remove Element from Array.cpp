int Solution::removeElement(vector<int> &A, int B) {
    int n = A.size();
    int len = 0;
    for(int i=0; i<n; i++) {
        if(A[i] != B) {
            A[len] = A[i];
            len++;
        }
    }
    return len;
}
