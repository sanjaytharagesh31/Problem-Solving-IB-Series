vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long long int sum = 0;
    long long int max_sum = -1;
    vector<int> ans;
    vector<int> tmp;
    for(int i=0; i<n; i++) {
        if(A[i] >= 0) {
            sum += A[i];
            tmp.push_back(A[i]);
        }
        else {
            if(max_sum < sum || (max_sum==sum && ans.size()<tmp.size())) {
                ans = tmp;
                max_sum = sum;
            }
            tmp.clear();
            sum = 0;
        }
    }
    if(max_sum < sum) {
        ans = tmp;
    }
    return ans;
}
