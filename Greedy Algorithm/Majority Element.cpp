int Solution::majorityElement(const vector<int> &A) {
    int ele = A[0];
    int cnt = 1;
    
    for(int i=1; i<A.size(); i++) {
        if(cnt == 0) {
            ele = A[i];
            cnt++;
        }
        else if(A[i] == ele) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    return ele;
}
