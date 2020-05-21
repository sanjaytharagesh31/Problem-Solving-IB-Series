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

//Optimized code
vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long long int sum = 0;
    long long int max_sum = -1;
    vector<int> ans;
    vector<int> tmp;
    int start = -1;
    int end = -1;
    int sz = -1;
    int s=-1, e=-1;
    for(int i=0; i<n; i++) {
        if(A[i] >= 0) {
            sum += A[i];
            if(start == -1)
                start = i;
            end = i;
        }
        else {
            if(max_sum < sum || (start!=-1 && max_sum==sum && sz<end-start+1)) {
                s = start;
                e = end;
                sz = start-end+1;
                max_sum = sum;
            }
            start = -1;
            end = -1;
            sum = 0;
        }
    }
    if(max_sum < sum){
        s = start;
        e = end;
    }
    for(int i=s; i<=e&&s!=-1; i++)
        ans.push_back(A[i]);
    return ans;
}
