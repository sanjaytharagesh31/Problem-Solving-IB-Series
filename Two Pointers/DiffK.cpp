//O(NlogN) Time

int bs(vector<int> &arr, int i, int j, int k) {
    while(i <= j) {
        int m = (i+j)/2;
        if(arr[m] == k) {
            return 1;
        }
        else if(arr[m] < k) {
            i = m+1;
        }
        
        else {
            j = m-1;
        }
    }
    return 0;
}

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0;
    int j = A.size()-1;
    for(int i=0; i<A.size(); i++) {
        if(bs(A, i+1, A.size()-1, A[i]+B) == 1)
            return 1;
    }
    return 0;
}

//O(N) Time
int Solution::diffPossible(vector<int> &A, int B) {
    int i=0;
    int j=1;
    while(i<A.size() && j<A.size()) {
        if(i!=j && A[j]-A[i] == B)
            return 1;
        else if(A[j]-A[i] > B) {
            i++;
        }
        else {
            j++;
        }
    }
    return 0;
}
