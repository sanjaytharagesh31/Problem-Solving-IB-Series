int Solution::removeDuplicates(vector<int> &A) {
    int len = 0;
    for(int i=1; i<A.size(); i++) {
        if(A[i] == A[len]) {
            continue;
        }
        else {
            A[len+1] = A[i];
            len++;
        }
    }
    return len+1;
}
