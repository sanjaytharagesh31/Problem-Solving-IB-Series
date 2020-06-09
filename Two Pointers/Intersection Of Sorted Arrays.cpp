vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int m = A.size();
    int n = B.size();
    int i = 0;
    int j = 0;
    while(i < m && j < n) {
        if(A[i] < B[j]) {
            i++;
        }
        else if(A[i] > B[j]) {
            j++;
        }
        else {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}
