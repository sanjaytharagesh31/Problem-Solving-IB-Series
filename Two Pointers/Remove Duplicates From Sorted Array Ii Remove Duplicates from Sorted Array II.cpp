int Solution::removeDuplicates(vector<int> &A) {
    int len = 0;
    int cnt = 1;
    for(int i=1; i<A.size(); i++) {
        if(A[i] == A[len] && cnt == 1) {
            A[len+1] = A[i];
            len++;
            cnt++;
        }
        else if(A[i] != A[len]){
            A[len+1] = A[i];
            len++;
            cnt = 1;
        }
    }
    return len+1;
}
