//O(1) Space
void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int i=m-1;
    int j=n-1;
    A.resize(m+n);
    int ind = m+n-1;
    while(j >= 0) {
        if(i>=0 && B[j] < A[i]) {
            A[ind] = A[i];
            i--;
            ind--;
        }
        else {
            A[ind] = B[j];
            ind--;
            j--;
        }
    }
}

//O(M+N) space
void Solution::merge(vector<int> &A, vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int i=0;
    int j=0;
    int ind = 0;
    vector<int> ans(m+n);
    while(i<m && j<n) {
        if(A[i] < B[j])
            ans[ind++] = A[i++];
        else
            ans[ind++] = B[j++];
    }
    while(i<m)
        ans[ind++] = A[i++];
    while(j<n)
        ans[ind++] = B[j++];
    A = ans;
}
