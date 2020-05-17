int Solution::maxArr(vector<int> &A) {
    int maxsum = INT_MIN;
    int minsum = INT_MAX;
    int maxdif = INT_MIN;
    int mindif = INT_MAX;
    for(int i=0; i<A.size(); i++) {
        maxsum = max(maxsum, A[i]+(i+1));
        minsum = min(minsum, A[i]+(i+1));
        maxdif = max(maxdif, A[i]-(i+1));
        mindif = min(mindif, A[i]-(i+1));
    }
    return max(maxsum-minsum, maxdif-mindif);
}
