//O(N^4) Time complexity solution

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    set<vector<int>> s;
    int n = A.size();
    for(int i=0; i+3<n; i++) {
        for(int j=i+1; j+2<n; j++) {
            for(int k=j+1; k+1<n; k++) {
                for(int l=k+1; l<n; l++) {
                    if(A[i]+A[j]+A[k]+A[l] == B && s.find({A[i], A[j], A[k], A[l]}) == s.end()) {
                        ans.push_back({A[i], A[j], A[k], A[l]});
                        s.insert({A[i], A[j], A[k], A[l]});
                    }
                }
            }
        }
    }
    return ans;
}
