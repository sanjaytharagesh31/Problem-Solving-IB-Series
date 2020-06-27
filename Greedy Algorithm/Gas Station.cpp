//O(N) Time solution

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int start = 0;
    int end = 1;
    int cur = A[0] - B[0];
    
    while(end != start || cur < 0) {
        while(cur < 0 && start != end) {
            cur = cur - A[start] + B[start];
            start = (start + 1) % n;
            if(start == 0)
                return -1;
        }
        cur += A[end] - B[end];
        end = (end + 1) % n;
    }
    return start;
}

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
