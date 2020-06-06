
int Solution::search(const vector<int> &A, int B) {
    int l = 0;
    int h = A.size()-1;
    int pivot = 0;
    if(A[h] < A[l]) {
        while(l < h) {
            int m = (l+h)/2;
            if(A[m] > A[0])
                l = m+1;
            else
                h = m;
        }
        pivot = l;
    }
    if(B>=A[pivot] && B<=A[A.size()-1]) {
        l = pivot;
        h = A.size()-1;
    }
    else if(B>=A[0]){
        l = 0;
        h = pivot-1;
    }
        
    while(l <= h) {
        int m = (l+h)/2;
        if(A[m] == B)
            return m;
        else if(A[m] < B)
            l = m+1;
        else
            h = m-1;
    }
    return -1;
}
