string Solution::longestCommonPrefix(vector<string> &A) {
    int min_l = INT_MAX;
    string ans = "";
    for(int i=0; i<A.size(); i++) {
        min_l = min(min_l, (int)A[i].length());
    }
    for(int i=0; i<min_l; i++) {
        bool flag = true;
        for(int j=1; j<A.size(); j++) {
            if(A[j][i] != A[j-1][i]) {
                flag = false;
                break;
            }
        }
        if(flag){
            ans += A[0][i];
        }
    }
    return ans;
}
