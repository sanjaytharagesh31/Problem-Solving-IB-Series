int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int cnt = 0;
    int n = A.size();
    for(int i=0; i<n-1; i++) {
        if(A[i+1] == A[i]) {
            cnt += abs(B[i+1] - B[i]);
        }
        else if(B[i+1] == B[i]) {
            cnt += abs(A[i+1]-A[i]);
        }
        else {
            int side_square = min(abs(A[i+1]-A[i]), abs(B[i+1]-B[i]));
            cnt += side_square;
            int hv_dist = abs(abs(A[i+1]-A[i]) - abs(B[i+1]-B[i]));
            cnt += hv_dist;
        }
    }
    return cnt;
}
