//O(N*N) TIme solution

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    vector<int> net(n);
    for(int i=0; i<n; i++) {
        net[i] = A[i] - B[i];
    }
    for(int i=0; i<n; i++) {
        int tmp = 0;
        int j = i;
        do {
            tmp += net[j];
            if(tmp < 0)
                break;
            j = (j+1)%n;
        }while(j != i);
        
        if(tmp >=0 && j == i)
            return i;
    }
    return -1;
}
